#include "Node.h"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <queue>
#include <string>
#include <list>
void BFS(Node* n);
void DFS(std::vector<Node>& n,int u);
void DFSVisit(Node* n);
int timer = 0;
bool cycle = 0;
std::list<Node*> list;
int main() {
	//Random Seed for srand
	srand((unsigned)time(0));

	//Get User values
	int v=0, e = 0, u=0;
	std::cout<<"Enter number of vertices:";
	std::cin >> v;
	std::cout << std::endl;
	std::cout << "Enter number of edges:";
	std::cin >> e;
	std::cout << std::endl;
	//Check edges count
	int validEdge = true;
	if (e > ((v - 1)*v))
		validEdge = false;
	while (!validEdge) {
		std::cout << "Invalid number of edges. Re-enter: ";
		std::cin >> e;
		std::cout << std::endl;
		if (e <= ((v - 1)*v))
			validEdge = true;
	}
	std::vector<Node> n;
	
	//Create Vertices list
	for (int i = 0 ; i < v; i++) {
		n.push_back(Node(i));
	}


	//Randomize Edges
	while (e > 0) {
		bool added= n.at(std::rand() % v).addAdj(&(n.at(std::rand() % v)));
		if (added == 1)
			e--;
	}

	//Print adjacency list 
	for (int i = 0; i < v; i++) {
		std::cout << "Vector: " << n.at(i).getValue()<<" => ";
		for (int j = 0; j < n.at(i).getAdj().size(); j++) {
			std::cout << "(" << (*(n.at(i).getAdj().at(j))).getValue()<<")";
		}
		std::cout << std::endl;
	}

	// Part A
	//Get desire vertex 
	std::cout << "Enter the starting vertex: ";
	std::cin >> u;
	std::cout << std::endl;
	while (u < 0 || u >= v) {
		std::cout << "Invalid vertex. Re-enter: ";
		std::cin >> u;
		std::cout << std::endl;
	}
	std::cout << "---BFS---"<<std::endl;
	BFS(&(n.at(u)));
	std::cout << "FROM vertex " << u << " TO: "<<std::endl;
	for (int i = 0; i < n.size(); i++) {
		if (i != u&&n.at(i).getLevel()>0) {
			//Distance
			std::cout << "(Vertex: " << n.at(i).getValue() << " ,Distance: " << n.at(i).getLevel() << ")" << std::endl;
			//Path
			std::cout << "Path: ";
			std::string s="";
			int f = i;
			while (n.at(f).getParent() != -1) {
				s = "(" + std::to_string(n.at(f).getValue())+") "+s;
				f = n.at(f).getParent();
			}
			std::cout << s << std::endl;
		}		
	}
	std::cout << "---DFS---" << std::endl;
	DFS(n,u);
	for (int i = 0; i < n.size(); i++) {
		std::cout <<"Vertex: "<< n.at(i).getValue()<< " (Start: " << n.at(i).getStart() << " ,End: " << n.at(i).getEnd() << ")"<< std::endl;
	}
	//Part B
	if (cycle) {
		std::cout << "Cycle detected, topological sort is impossible." << std::endl;
	}
	else {
		std::cout << "Topological Sort: ";
		for (std::list<Node*>::iterator it = list.begin(); it != list.end();++it) {
			std::cout << (*it)->getValue() << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
void BFS(Node* n) {
	n->setLevel(0);
	n->setParent(-1);
	std::queue<Node*> q;
	q.push(n);
	while (!(q.empty())) {
		n = q.front();
		q.pop();
		for (int i = 0; i < n->getAdj().size(); i++) {
			if (n->getAdj().at(i)->getParent()==-2) {
				q.push(n->getAdj().at(i));
				n->getAdj().at(i)->setParent(n->getValue());
				n->getAdj().at(i)->setLevel(n->getLevel() + 1);
			}
		}
	}
}

void DFS(std::vector<Node>& n, int u) {
	n.at(u).setParent(-1);
	DFSVisit(&(n.at(u)));
	for (int i = 0; i < n.size(); i++) {
		if (n.at(i).getStart() == -2) {
			n.at(i).setParent(-1);
			DFSVisit(&(n.at(i)));
		}
	}
}

void DFSVisit(Node*n) {
	n->setStart(timer++);
	for (int i = 0; i < n->getAdj().size(); i++) {
		if (n->getAdj().at(i)->getStart() == -2) {
			n->getAdj().at(i)->setParent(n->getValue());
			DFSVisit(n->getAdj().at(i));
		}
		else if (n->getAdj().at(i)->getEnd() == -2 && cycle==0) {
			cycle = 1;
		}
	}
	n->setEnd(timer++);
	list.push_front(n);
}
