#include "Node.h"

Node::Node(int v)
{
	value = v;
}


Node::~Node()
{
}

int Node::getValue()
{
	return value;
}


void Node::setValue(int v)
{
	value = v;
}

std::vector<Node> Node::getAdj()
{
	return adj;
}

std::vector<int> Node::getWeight()
{
	return adjWeight;
}


void Node::removeAdjNode(Node n)
{
	int pos = posDetector(n);
	if (pos == -1) {
		std::cout << "Edge does not exist." << std::endl;
	}
	else {
		adj.erase(adj.begin() + pos);
		adjWeight.erase(adjWeight.begin() + pos);
	}
}



bool Node::addAdj(Node n)
{
	int pos = posDetector(n);
	if (pos = -1) {
		adj.push_back(n);
		adjWeight.push_back(1);
		return 1;
	}
	else
		return 0;
	
}

bool Node::addAdjWithWeight(Node n, int w)
{	
	int pos = posDetector(n);
	if (pos = -1) {
		adj.push_back(n);
		adjWeight.push_back(w);
		return 1;
	}
	else
		return 0;
}

void Node::setLevel(int i)
{
	level = i;
}

int Node::getLevel()
{
	return level;
}

int Node::posDetector(Node n)
{
	int pos = -1;
	for (int i = 0; i < adj.size(); i++) {
		if (adj[i].getValue() == n.getValue()) {
			pos = i;
		}
	}
	return pos;
}
