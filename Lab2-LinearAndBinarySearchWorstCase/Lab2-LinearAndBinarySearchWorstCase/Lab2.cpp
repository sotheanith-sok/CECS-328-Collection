#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <chrono>

bool linearSearch(int key, std::vector<int>& v);
bool binarySearch(int begin, int end, int key, std::vector<int>& v);

int main() {
	srand((unsigned)time(0));
	int size = 100000;
	std::vector<int> v;
	for (int i = 0; i < size-1; i++) {
		v.push_back((std::rand() % 10001) - 5000);
	}
	int key = 7000;
	v.push_back(7000);

	//Calculation for 10^5
	std::cout << "-Calculated Result for 10^5-" << std::endl;
	double TimePerLine1 = 0;
	double TimePerLine2 = 0;
	//Linear Search
	auto t1 = std::chrono::high_resolution_clock::now();
	linearSearch(key, v);
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << "	Runtime for worst case of Linear Search:" << (std::chrono::duration<double,std::nano>(t2-t1)).count() << " ns" << std::endl;
	TimePerLine1 = (std::chrono::duration<double, std::nano>(t2 - t1)).count() / ((double)size);
	std::cout << "	Time Per Instruction:"<<TimePerLine1<< " ns/instruction"<< std::endl;	
	//Binary Search
	std::sort(v.begin(),v.end());
	t1 = std::chrono::high_resolution_clock::now();
	binarySearch(0, v.size() - 1, key, v);
	t2 = std::chrono::high_resolution_clock::now();
	TimePerLine2 = (std::chrono::duration<double, std::nano>(t2 - t1)).count() / std::log2(size);
	std::cout << "	Runtime for worst case of Binary Search:" << (std::chrono::duration<double, std::nano>(t2 - t1)).count() << " ns" << std::endl;
	std::cout << "	Time Per Instruction:" << TimePerLine2 << " ns/instruction" << std::endl;
	std::cout << std::endl;

	//Predict value for 10^7
	size = 10000000;
	std::cout << "-Predicted Running time for 10^7-" << std::endl;
	std::cout << "	Linear = " << size * TimePerLine1  << " ns" << std::endl;
	std::cout << "	Binary = " << std::log2(size)*TimePerLine2 << " ns" << std::endl;
	std::cout << std::endl;

	//Actual Running time:
	std::cout << "-Actual Running time for 10^7-" << std::endl;
	std::vector<int> x;
	for (int i = 0; i < size - 1; i++) {
		x.push_back((std::rand() % 10001) - 5000);
	}
	key = 7000;
	x.push_back(7000);
	//Linear Search
	t1 = std::chrono::high_resolution_clock::now();
	linearSearch(key, x);
	t2 = std::chrono::high_resolution_clock::now();
	std::cout << "	Runtime for worst case of Linear Search:" << (std::chrono::duration<double, std::nano>(t2 - t1)).count() << " ns" << std::endl;
	//Binary Search
	t1 = std::chrono::high_resolution_clock::now();
	binarySearch(0, x.size() - 1, key, x);
	t2 = std::chrono::high_resolution_clock::now();
	std::cout << "	Runtime for worst case of Binary Search:" << (std::chrono::duration<double, std::nano>(t2 - t1)).count() << " ns" << std::endl;
	
	return 0;

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
	if (end < begin) {
		return 0;
	}
	else {
		if (v.at(center + begin) == key) {
			return 1;
		}
		else if (key < v.at(center + begin)) {
			return binarySearch(begin, begin + center - 1, key, v);
		}
		else {
			return binarySearch(begin + center + 1, end, key, v);
		}
	}
}
