#include <iostream>
#include <vector>
#include <chrono>
#include <functional>

using namespace std;

class Multiphase {
public:
	void mpnatural_merge(vector<int>& vect1, vector<int>& vect2)
	{
		for (int i = 0; i < vect2.size(); i++)
		{
			vect1.push_back(vect2[i]);
			for (int j = vect1.size() - 1; j > 0; j--)
			{
				if (vect1[j] < vect1[j - 1])
				{
					swap(vect1[j], vect1[j - 1]);
				}
				else
				{
					break;
				}
			}
		}
	}
	void mpnatural_merge_sort(int* arr, int arr_length)
	{
		vector <vector<int>> series;
		vector<int> new_series;
		for (int i = 0; i <= arr_length - 1; i++)
		{
			if (i == arr_length - 1)
			{
				new_series.push_back(arr[i]);
				series.push_back(new_series);
				new_series.clear();
			}
			else
			{
				new_series.push_back(arr[i]);
				if (arr[i] > arr[i + 1])
				{
					series.push_back(new_series);
					new_series.clear();
				}
			}
		}
		while (series.size() != 1)
		{
			mpnatural_merge(series[0], series[series.size() - 1]);
			series.pop_back();
		}
		for (int i = 0; i < arr_length; i++)
		{
			arr[i] = series[0][i];
		}
	}
	pair<int, int> mpideal_series(pair<int, int> last_count_series, int count_all_series)
	{
		int current_num = last_count_series.first + last_count_series.second;
		if (count_all_series > current_num)
		{
			mpideal_series({ last_count_series.second, current_num }, count_all_series);
		}
		else
		{
			return last_count_series;
		}
	}
	void mpseries_merge(vector <vector<int>>& series_1, vector <vector<int>>& series_2, vector <vector<int>>& series_3)
	{
		if (series_1.size() == 1 && series_2.size() == 0 && series_3.size() == 0)
		{
			return;
		}
		else if (series_2.size() == 1 && series_1.size() == 0 && series_3.size() == 0)
		{
			return;
		}
		else if (series_3.size() == 1 && series_1.size() == 0 && series_2.size() == 0)
		{
			return;
		}
		int i = series_1.size() - 1;
		int j = series_2.size() - 1;
		while (j != -1) //series_2 не пуста
		{
			mpnatural_merge(series_1[i], series_2[j]);
			series_3.push_back(series_1[i]);
			series_1.pop_back();
			series_2.pop_back();
			i--;
			j--;
		}
		mpseries_merge(series_3, series_1, series_2); //1-ый - больше серий, 2-ой - меньше серий (потом пустой), 3-ий - эндпоинт слияния
	}
	void multiphase_merge_sort(int* arr, int arr_length)
	{
		pair <int, int> ideal_pair;
		vector <int> new_series;
		vector <vector<int>> series, series_1, series_2, series_3;
		for (int i = 0; i <= arr_length - 1; i++)
		{
			if (i == arr_length - 1)
			{
				new_series.push_back(arr[i]);
				series.push_back(new_series);
				new_series.clear();
			}
			else
			{
				new_series.push_back(arr[i]);
				if (arr[i] > arr[i + 1])
				{
					series.push_back(new_series);
					new_series.clear();
				}
			}
		}
		ideal_pair = mpideal_series({ 0, 1 }, series.size());
		for (int i = 0; i < ideal_pair.second; i++)
		{
			series_1.push_back(series[i]);
		}
		for (int i = 0; i < ideal_pair.first; i++)
		{
			if (series_1.size() + i + 1 > series.size())
			{
				series_2.push_back({});
			}
			else
			{
				series_2.push_back(series[series_1.size() + i]);
			}
		}
		mpseries_merge(series_1, series_2, series_3);
		for (int i = 0; i < arr_length; i++)
		{
			arr[i] = series_1[0][i];
		}
	}
};