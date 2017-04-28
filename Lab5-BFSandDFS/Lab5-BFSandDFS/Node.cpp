#include "Node.h"

Node::Node(int v)
{
	value = v;
}

Node::Node(int v, std::list<Node> list)
{
	value = v;
	adj = list;
}

Node::~Node()
{
}

std::string Node::getValue()
{
	return value;
}

std::string Node::setValue(std::string v)
{
	value = v;
}

std::list<Node> Node::getAdj()
{
	return adj;
}

void Node::removeAdjNode(Node n)
{
	adj.remove(n);
}

void Node::addAdj(Node n)
{
	adj.push_back(n);
}

void Node::setLevel(int i)
{
	level = i;
}

int Node::getLevel()
{
	return level;
}
