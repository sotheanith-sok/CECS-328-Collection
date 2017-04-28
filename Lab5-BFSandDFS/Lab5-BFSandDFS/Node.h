#pragma once
#include <list>;
class Node
{
public:
	Node(int v);
	Node(int v, std::list<Node> list);
	~Node();
	std::string getValue();
	std::string setValue(std::string v);
	std::list<Node> getAdj();
	void removeAdjNode(Node n);
	void addAdj(Node n);
	void setLevel(int i);
	int getLevel();
private:
	std::string value;
	std::list<Node> adj;
	Node* parent = nullptr;
	int level=0;
};

