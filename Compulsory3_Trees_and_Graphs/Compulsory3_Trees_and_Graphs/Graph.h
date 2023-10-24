#pragma once
#include<iostream>
#include<list>
using namespace std; 
class Graph
{
public: 
	struct Node
	{
		int data, cost;
		list<Node*> adjlist;
		bool visited = false; 

	};
	Node* CreateGraph(int data, int weight, Node* head)
	{
		Node* newNode = new Node;
		newNode->data = data; 
		newNode->cost = weight; 
		
		if(head != nullptr)
		{
			newNode->adjlist.push_back(head);
			head->adjlist.push_back(newNode);
		}
		return newNode; 
	}

	int returnNodeinf(struct Node* node)
	{
		return node->data; 

	}
	void connectEdge(struct Node* nodeA, struct Node* nodeB)
	{
		nodeA->adjlist.push_back(nodeB); 
		nodeB->adjlist.push_back(nodeA); 
	}
	void adjNodes(struct Node* node)
	{
		auto it = node->adjlist.begin(); 
		while (it != node->adjlist.end())
		{
			cout << (*it)->data << " "; 
			++it; 
		}

	}
	int verticesGraph(struct Node* node)
	{
		int count = 0;
		list<Node*> listOfVertices;
		listOfVertices.push_front(node);

		node->visited = true;

		while (!listOfVertices.empty())
		{
			Node* currentNode = listOfVertices.front();
			listOfVertices.pop_front();
			++count;

			for (Node* adj : currentNode->adjlist)
			{

				if (!adj->visited)
				{
					adj->visited = true;
					listOfVertices.push_front(adj);
				}
			}
		}

		resetVisited(node);

		return count;
	}
	void returnNodes(struct Node* node)
	{
		list<Node*> listOfVertices;
		listOfVertices.push_front(node);

		node->visited = true;

		while (!listOfVertices.empty())
		{
			Node* currentNode = listOfVertices.front();
			listOfVertices.pop_front();
			cout << " " << currentNode->data;

			for (Node* adj : currentNode->adjlist)
			{

				if (!adj->visited)
				{
					adj->visited = true;
					listOfVertices.push_front(adj);
				}
			}
		}

		resetVisited(node);

	}
private:
	void resetVisited(struct Node* node)
	{
		list<Node*> listOfVertices;
		listOfVertices.push_front(node);

		while (!listOfVertices.empty())
		{
			Node* currentNode = listOfVertices.front();
			listOfVertices.pop_front();
			if (currentNode->visited)
			{
				currentNode->visited = false;

				for (Node* adj : currentNode->adjlist)
				{
					if (adj->visited)
					{
						listOfVertices.push_front(adj);
					}
				}
			}
		}

	}
public: 
	int edgeGraph(struct Node* node)
	{
		int count = 0;
		list<Node*> listOfVertices;
		listOfVertices.push_front(node);

		while (!listOfVertices.empty())
		{
			Node* currentNode = listOfVertices.front();
			listOfVertices.pop_front();
			if (!currentNode->visited)
			{
				currentNode->visited = true;
				count += currentNode->adjlist.size();

				for (Node* adj : currentNode->adjlist)
				{
					if (!adj->visited)
					{
						listOfVertices.push_front(adj);
					}
				}
			}
		}
		resetVisited(node);

		return count;

	}
	int size(struct Node* node)
	{
		return node->adjlist.size(); 
	}
	bool isEmpty(struct Node* node)
	{
		if (node->adjlist.empty())
			return true;
		else
			return false; 
	}
	void deleteNode(struct Node* node)
	{
		if (node != nullptr)
		{
			for (Node* adj : node->adjlist)
			{
				adj->adjlist.remove(node); 
			}
			node->adjlist.clear(); 
		}
		delete node; 

	}
	void deleteEdge(struct Node* node1, struct Node* node2)
	{
		if (node1 != nullptr && node2 != nullptr)
		{
			node1->adjlist.remove(node2);
			node2->adjlist.remove(node1);
		}
	}
};

