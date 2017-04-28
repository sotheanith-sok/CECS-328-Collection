#include <iostream>
int minimumNode(int h);
int main() {
	std::cout << minimumNode(15) << std::endl;
	return 0;
}

int minimumNode(int h) {
	if (h == 0) 
		return 1;
	else 
	if (h == 1)
	return 2;
	else 
		return minimumNode(h - 2) + minimumNode(h - 1) + 1;
}