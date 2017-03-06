#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm> //Sort
#include <vector>
#include<chrono>
#include <stdlib.h>

bool linearSearch(int key, std::vector<int>& v);
bool binarySearch(int begin, int end, int key, std::vector<int>& v);

int main() {
	srand((unsigned)time(0));
	std::cout << "Please enter the size of array" << std::endl;
	int size;
	std::cin >> size;
	std::vector<int> v;
	for (int i = 0; i < size; i++) {
		v.push_back((std::rand() % 2001) - 1000);
	}
	std::sort(v.begin(), v.end());
	double  linearDuration=0;
	double binaryDuration;
	for (int i = 0; i < 30; i++) {
		int key = v.at(std::rand() % v.size());
		auto t1 = std::chrono::high_resolution_clock::now();
		linearSearch(key, v);
		auto t2= std::chrono::high_resolution_clock::now();
		linearDuration = (std::chrono::duration<double, std::nano>(t2 - t1)).count();
		t1 = std::chrono::high_resolution_clock::now();
		binarySearch(0, v.size() - 1, key, v);
		t2 = std::chrono::high_resolution_clock::now();
		binaryDuration = (std::chrono::duration<double, std::nano>(t2 - t1)).count();

	}
	std::cout << "Runtime for Linear Search:" << linearDuration/30 <<" nanosecond"<< std::endl;
	std::cout << "Runtime for Binary Search:" << binaryDuration/30 << " nanosecond" << std::endl;
}
bool linearSearch(int key, std::vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		if (key == v.at(i)) {
			return 1;
		}
	}
	return 0;
}
bool binarySearch(int begin, int end, int key, std::vector<int>& v) {
	int center = (end - begin) / 2;
	if (end <= begin) {
		return 0;
	}
	else {
		if (v.at(center+begin) == key) {
			return 1;
		}
		else if (key < v.at(center+ begin)) {
			return binarySearch(begin, begin+center - 1, key, v);
		}
		else {
			return binarySearch(begin+center + 1, end, key, v);
		}
	}
}
