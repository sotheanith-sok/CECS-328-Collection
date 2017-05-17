#include "Node.h"

Node::Node(int v)
{
	value = v;
}


Node::~Node()
{
}

int Node::getValue() const
{
	return value;
}


void Node::setValue(int v)
{
	value = v;
}

void Node::setParent(int p)
{
	parent = p;
}

void Node::setStart(int p)
{
	start = p;
}

void Node::setEnd(int p)
{
	end = p;
}

std::vector<Node*> Node::getAdj()
{
	return adj;
}

void Node::removeAdjNode(Node& n)
{
	int pos = posDetector(n);
	if (pos == -1) {
		std::cout << "Edge does not exist." << std::endl;
	}
	else {
		adj.erase(adj.begin() + pos);
	}
}



bool Node::addAdj(Node* n)
{
	int pos = posDetector(*n);
	if (pos == -1 &(value!=(*n).getValue())) {
		adj.push_back(n);
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

int Node::getParent()
{
	return parent;
}
int Node::getStart()
{
	return start;
}
int Node::getEnd()
{
	return end;
}
int Node::posDetector(Node& n)
{
	int pos = -1;
	for (int i = 0; i < adj.size(); i++) {
		if (adj.at(i)->getValue() == n.getValue()) {
			pos = i;
			break;
		}
	}
	return pos;
}

bool Node::operator==(const Node & a)
{
	if (value != a.getValue()) {
		return false;
	}else{
		return true;
	}
	
}
bool Node::operator!=(const Node & a)
{
	return value!=a.getValue();
}
bool Node::operator<(const Node & a)
{
	if (value > a.getValue()) {
		return false;
	}
	else {
		return true;
	}

}
bool Node::operator>(const Node & a)
{
	if (value < a.getValue()) {
		return false;
	}
	else {
		return true;
	}

}


