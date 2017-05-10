#include "Node.h"
#include <iostream>
int main() {
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
	for (int i = 0; i < e; i++) {

	}




	


	return 0;
}
void BFS(Node n) {

}
void DFS(Node n) {

}
