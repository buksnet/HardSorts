#include "MultiphaseSort.cpp"
#include "MonophaseSort.cpp"
#define arr_length 25

template <typename T>
void print_array(T arr)
{
	cout << arr[0];
	for (int i = 1; i < arr_length; i++)
		cout << ' ' << arr[i];
	cout << '\n';
}

int main() {
	srand(time(0));
	short int choice;
	cout << "Pick sorting algorythm:\n 1 - Multiphase sort\n 2 - Monophase sort" << endl;
	cin >> choice;
	switch (choice) {
	case 1: {
			Multiphase tool;
			
			int multiphase_arr[25];
			for (int i = 0; i < arr_length; i++) {
				multiphase_arr[i] = rand() % 100 - 50;
			}
			print_array(multiphase_arr);
			
			tool.mpnatural_merge_sort(multiphase_arr, arr_length);
			print_array(multiphase_arr);
			break;
		}
	case 2: {
		Monophase tool;
			srand(time(0));
			int monophase_arr[25] = {};
			for (int i = 0; i < arr_length; i++) {
				monophase_arr[i] = rand() % 100 - 50;
			}
			print_array(monophase_arr);
			tool.opnatural_merge_sort(monophase_arr, arr_length);
			print_array(monophase_arr);
		}
	}
	return 0;
}