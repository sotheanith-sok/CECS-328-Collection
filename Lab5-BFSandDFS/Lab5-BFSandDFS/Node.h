#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
class Node
{
public:
	Node(int v);
	~Node();
	int getValue() const;
	void setValue(int v);
	void setParent(int p);
	void setStart(int p);
	void setEnd(int p);
	std::vector<Node*> getAdj();
	void removeAdjNode(Node& n);
	bool addAdj(Node* n);
	void setLevel(int i);
	int getLevel();
	int getParent();
	int getStart();
	int getEnd();
	bool operator== (const Node &a);
	bool operator!= (const Node &a);
	bool operator< (const Node &a);
	bool operator> (const Node &a);
	int posDetector(Node& n);
	
private:
	int value;
	int parent=-2 ;
	int level=0 ;
	int start = -2;
	int end = -2;
	std::vector<Node*> adj;
};

