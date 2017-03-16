#include <vector>
#include <ctime>
#include <iostream>

void quickSort(int low, int high, std::vector<int>& v );
void insertionSort();
int main() { 
	srand((unsigned)time(0));
	int size;
	std::cout << "Enter array size: ";
	std::cin >> size;
	std::cout <<""<< std::endl;
	std::vector<int>v;
	for (int i = 0; i < size ; i++) {
		v.push_back((std::rand() % 14001) - 7000);
	}
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << (*it) << std::endl;
	}
	quickSort(0, v.size() - 1, v);

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << (*it) << std::endl;
	}

	return 0;
}
void quickSort(int low, int high, std::vector<int>& v) {
	if (low < high) {
		int pivot=(low+high)/2;
		//Find median of 3
		if (((v[low] < v[pivot]) && (v[low] > v[high])) || ((v[low] > v[pivot]) && (v[low] < v[high]))) {
			pivot = low;
		}
		else if (((v[high] < v[pivot]) && (v[high] > v[low])) || ((v[high] > v[pivot]) && (v[high] < v[low]))) {
			pivot = high;
		}
		std::swap(v[high], v[pivot]);
		pivot = high ;
		
		//Compare
		for (int i = low; i < pivot;i++) {
			if (v[i]>v[pivot]) {
				int temp = v[i];
				v.erase(v.begin() + i);
				v.insert(v.begin() + pivot, temp);
				pivot--;
				i--;
			}
		}
		quickSort(low, pivot - 1, v);
		quickSort(pivot + 1, high, v);

	}
}