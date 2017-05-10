#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
class Node
{
public:
	Node(int v);
	~Node();
	int getValue();
	void setValue(int v);
	std::vector<Node> getAdj();
	std::vector<int> getWeight();
	void removeAdjNode(Node n);
	bool addAdj(Node n);
	bool addAdjWithWeight(Node n, int w);
	void setLevel(int i);
	int getLevel();
private:
	int posDetector(Node n);
	int value;
	std::vector<Node> adj;
	std::vector<int> adjWeight;
	Node* parent = nullptr;
	int level=0;
};

