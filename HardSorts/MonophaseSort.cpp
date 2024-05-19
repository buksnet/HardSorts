#include <iostream>
#include <vector>
using namespace std;

class Monophase {
public:
	void opnatural_merge(vector<int>& vect1, vector<int>& vect2)
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

	void opnatural_merge_sort(int* arr, int arr_length)
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
			opnatural_merge(series[0], series[series.size() - 1]);
			series.pop_back();
		}
		for (int i = 0; i < arr_length; i++)
		{
			arr[i] = series[0][i];
		}
	}
};