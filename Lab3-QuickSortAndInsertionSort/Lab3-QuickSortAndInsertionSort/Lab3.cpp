#include <vector>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <chrono>

void quickSort(int a, int b, std::vector<int>& v );
void insertionSort(std::vector<int>);
int main() { 
	srand((unsigned)time(0));
	int size;
	std::cout << "Enter array size: ";
	std::cin >> size;
	std::cout <<""<< std::endl;
	
	//Calculate Running time for repeated 100
	auto t1= std::chrono::high_resolution_clock::now();
	auto t2 = std::chrono::high_resolution_clock::now();
	//Quicksort
	double totalTimeForQuickSort = 0;
	for (int i = 0; i < 100; i++) {
		std::vector<int> v;
		for (int i = 0; i < size; i++) {
			v.push_back((std::rand() % 14001) - 7000);
		}
		t1 = std::chrono::high_resolution_clock::now();
		quickSort(0, v.size() - 1, v);

		t2 = std::chrono::high_resolution_clock::now();
		totalTimeForQuickSort += (std::chrono::duration<double, std::nano>(t2 - t1)).count();
	}
	//InsertionSort
	double totalTimeForInsertionSort = 0;
	for (int i = 0; i < 100; i++) {
		std::vector<int>v;
		for (int i = 0; i < size; i++) {
			v.push_back((std::rand() % 14001) - 7000);
		}
		t1 = std::chrono::high_resolution_clock::now();
		insertionSort(v);
		t2 = std::chrono::high_resolution_clock::now();
		totalTimeForInsertionSort += (std::chrono::duration<double, std::nano>(t2 - t1)).count();
	}
	std::cout << "Average running for Quicksort: " << (totalTimeForQuickSort / 100) << std::endl;
	std::cout << "Average running for InsertionSort: " << (totalTimeForInsertionSort / 100) << std::endl;
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
				v.insert(v.begin()+pivot, temp);
				pivot--;
				i--;
			}
		}
		quickSort(low, pivot - 1, v);
		quickSort(pivot + 1, high, v);

	}
}
void insertionSort(std::vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int k = 0; k < i; k++) {
			if (v[k] >= v[i]) {
				int temp = v[i];
				v.erase(v.begin() + i);
				v.insert(v.begin() + k,temp);
				break;
			}
		}
	}
}