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
			}
		}
	}

	int depth(struct Node* node)
	{
		if (node != nullptr)
		{
			int maxDepth = 0;
			for (Node* child : node->children)
			{
				int childDepth = depth(child);
				maxDepth = max(maxDepth, childDepth);
			}

			return maxDepth + 1;

		}
		else
			cout << "is nullptr\n";
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
			cout << "Root\n";
			return true;
		}
		else
			return false;
	}
	bool isLeaf(struct Node* leaf)
	{
		if (leaf->children.empty())
		{
			cout << "leaf\n";
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
	void deleteNode(struct Node* node)
	{
		if (node == nullptr)
			return;
		else if (node->parent != nullptr)
			node->parent->children.remove(node);

		for (Node* child : node->children)
		{
			deleteNode(child);
		}

		delete node;
	}

};

