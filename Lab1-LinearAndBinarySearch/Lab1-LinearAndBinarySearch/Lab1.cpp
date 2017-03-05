#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stdlib.h>

bool linearSearch(int key, std::vector<int>& v);
bool binarySearch(int begin, int end, int key, std::vector<int>& v);

int main() {
	srand((unsigned)time(0));
	//std::cout << "Please enter the size of array" << std::endl;
	int size;
	//std::cin >> size;
	std::vector<int> v;
	//for (int i = 0; i < size; i++) {
		//v.push_back((std::rand() % 2001) - 1000);
	//}
	v = { 5,100,6,7,8,6 };
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		//std::cout << *it << std::endl;
	//}
		int key = 100;
	//std::cout << linearSearch(key,v)<<std::endl;
	std::cout << binarySearch(0,v.size()-1,key, v) << std::endl;

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
	int center = (end-begin) / 2;
	std::cout << end << std::endl;
	if (v.at(center) == key) {
		return 1;
	}
	if (begin < end) {
		if (key < v.at(center)) {
			binarySearch(begin, center - 1, key, v);
		}
		else if (key>v.at(center)) {
			binarySearch(center + 1, end, key, v);
		}
	}
	return 0;
}
