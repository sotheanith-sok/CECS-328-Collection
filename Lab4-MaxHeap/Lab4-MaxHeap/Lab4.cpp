#include <vector>
#include <iostream>
#include <ctime>
#include <chrono>

std::vector<int> build_MaxHeap(std::vector<int> A);
void max_heapify(std::vector<int>& A, int i, int size);
void heap_sort(std::vector<int> A);


int main() {
	srand((unsigned)time(0));
	int size;
	std::cout << "Enter array size: ";
	std::cin >> size;
	std::cout << "" << std::endl;

	//Calculate Running time for repeated 100
	auto t1 = std::chrono::high_resolution_clock::now();
	auto t2 = std::chrono::high_resolution_clock::now();
	//Quicksort
	double totalTimeForHeapSort = 0;
	for (int i = 0; i < 100; i++) {
		std::vector<int> A;
		for (int i = 0; i < size; i++) {
			A.push_back((std::rand() % 14001) - 7000);
		}
		t1 = std::chrono::high_resolution_clock::now();
		heap_sort(A);
		t2 = std::chrono::high_resolution_clock::now();
		totalTimeForHeapSort += (std::chrono::duration<double, std::nano>(t2 - t1)).count();
	}
	std::cout << "Average running for HeapSort: " << (totalTimeForHeapSort / 100) <<" nanosecond"<< std::endl;
}
std::vector<int> build_MaxHeap(std::vector<int> A) {
	for (int i = A.size(); i >=0; i--) {
		max_heapify(A, i, A.size());
	}
	return A;
}
void max_heapify(std::vector<int>& A, int i, int size) {
	int max_index = i;
	int left_index = 2*i;
	int right_index = 2*i + 1;
	//Check left child
	if ((left_index < size) && (A[left_index] > A[max_index])) {
		max_index = left_index;
	}
	//Check right child
	if ((right_index < size) && (A[right_index] > A[max_index])) {
		max_index = right_index;
	}
	//Swap
	if (max_index != i) {
		int temp = A[max_index];
		A[max_index] = A[i];
		A[i] = temp;
		max_heapify(A, max_index,size);
	}

}
void heap_sort(std::vector<int> A) {
	std::vector<int> v = build_MaxHeap(A);
	for (int i = v.size() - 1; i > 0; i--) {
		//swap with the last value
		int temp = v[i];
		v[i] = v[0];
		v[0] = temp;
		max_heapify(v, 0, i);
	}
}
