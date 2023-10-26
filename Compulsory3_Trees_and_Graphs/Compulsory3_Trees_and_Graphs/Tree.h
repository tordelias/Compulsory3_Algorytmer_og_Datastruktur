#pragma once
#include <iostream>
#include <list>

using namespace std; 

class Tree
{


public:

	struct Node
	{
		int data;
		Node* parent;
		list<Node*> children;


	};


	Node* CreateNode(int data, Node* Parentnode)
	{
		Node* newnode = new Node();
		newnode->data = data;
		newnode->parent = Parentnode;
		if (Parentnode != nullptr)
		{
			Parentnode->children.push_back(newnode);
		}
		return newnode;
	}

	void listOfChildren(struct Node* node)
	{
		if (node != nullptr)
		{
			auto it = node->children.begin();
			while (it != node->children.end())
			{
				listOfChildren(*it);
				cout << " " << (*it)->data;
				++it;
				//depth pre order
			}
		}
	}

	int height(struct Node* node)
	{
		if (node != nullptr)
		{
			int maxDepth = 0;
			for (Node* child : node->children)
			{
				int childDepth = height(child);
				maxDepth = max(maxDepth, childDepth);
			}

			return maxDepth + 1;

		}
		else
			cout << "is nullptr\n";
	}
	int depth(struct Node* node)
	{
		int currentDepth = 1;
		while (node->parent != nullptr)
		{
			node = node->parent;
			currentDepth++;
		}
		return currentDepth;
	}
	int size(struct Node* node)
	{
		if (node != nullptr)
		{
			auto it = node->children.begin();
			int listSize = 1;
			for (Node* child : node->children) {
				listSize += size(child);
			}
			return listSize;
		}
		else
			cout << "is nullptr\n";

	}
	bool isEmpty(struct Node* node)
	{
		if (node != nullptr)
			return false;
		else
			return true;
	}
	bool isRoot(struct Node* node)
	{
		if (node->parent == nullptr)
		{
			return true;
		}
		else
			return false;
	}
	bool isLeaf(struct Node* leaf)
	{
		if (leaf->children.empty())
		{
			return true;
		}
		else
			return false;
	}
	int parentOfNode(struct Node* node)
	{

		if (node->parent != nullptr)
			return node->parent->data;
		else
			cout << "root\n";
		return NULL;

	}

	int childOfNode(struct Node* node)
	{
		if (!node->children.empty())
		{
			auto it = node->children.begin();
			while (it != node->children.end())
			{
				cout << " " << (*it)->data;
				++it;
			}

		}
		else
			cout << "isLeaf\n";
		return NULL;

	}
	void deleteNode(Node* node)
	{
		Node* child; 
		if (node == nullptr)
			return;

		while (!node->children.empty())
		{
			child = node->children.front();
			node->children.pop_front();
			deleteNode(child);
		}

		if (node->parent != nullptr)
		{
			node->parent->children.remove(node);
		}
		delete node;
	}
	//void callthisdeleteplease(Node* node)
	//{
	//	if (node->parent != nullptr)
	//	{
	//		node->parent->children.remove(node);
	//	}
	//	deleteNode(node);
	//}

	//void deleteNode(Node* node)
	//{
	//	if (node == nullptr)
	//		return;


	//	for (Node* child : node->children)
	//	{
	//		deleteNode(child);
	//	}

	//	delete node;
	//}


	Node* getRoot(struct Node* node)
	{
		while (node->parent != nullptr)
		{
			node = node->parent;
		}

		return node;

	}



};

