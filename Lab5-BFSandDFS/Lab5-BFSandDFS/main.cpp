#include "Node.h"
#include <iostream>
#include <ctime>
#include <algorithm>
int main() {
	//Random Seed for srand
	srand((unsigned)time(0));

	//Get User values
	int v=0, e = 0;
	std::cout<<"Enter number of vertices:";
	std::cin >> v;
	std::cout << std::endl;
	std::cout << "Enter number of edges:";
	std::cin >> e;
	std::cout << std::endl;
	std::vector<Node> n;
	
	//Create Vertices list
	for (int i = 0 ; i < v; i++) {
		n.push_back(Node(i));
	}

	//Randomize Edges
	while (e > 0) {
				
	}




	


	return 0;
}
void BFS(Node n) {

}
void DFS(Node n) {

}
