#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int numOfSons = 0;
	double left, right, front, back, top, bottom;
	vector<int> triangleCount;
	vector<Node*> Sons;
};

Node* createNode(Node *Parent, int y)
{
	if (Parent == NULL)
	{
		Parent = new Node;
		Parent->Sons.resize(8, nullptr);
		return Parent;
	}
	Node *Son = new Node;
	Parent->Sons[y] = Son;
	Parent->numOfSons++;
	return Son;
}

void delAll(Node *Parent)
{
	if (Parent->numOfSons > 0) {
		for (int i = 0; i < 8; i++)
		{
			if (Parent->Sons[i] != NULL) delAll(Parent->Sons[i]);
		}
	}
	delete Parent;
}

void remNode(Node *Parent, int y)
{
	if (Parent->Sons[y] != NULL)
	{
		delAll(Parent->Sons[y]);
	}
	Parent->Sons[y] = NULL;
	Parent->numOfSons--;
}