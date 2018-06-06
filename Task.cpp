#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int numOfTrngls;
	double left, right, front, back, top, bottom;
	vector<int> triangleCount;
	vector<Node*> Sons;
};

Node* Root;

void createNode(Node *Parent, int y)
{
	if (Parent == NULL)
	{
		Parent = new Node;
		Parent->Sons.resize(8, nullptr);
		Root = Parent;
	}
	else 
	{
		Node *Son = new Node;
		Parent->Sons[y] = Son;
	}
}

void delAll(Node *Parent)
{
	for (int i = 0; i < 8; i++)
	{
		if (Parent->Sons[i] != NULL) delAll(Parent->Sons[i]);
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
}