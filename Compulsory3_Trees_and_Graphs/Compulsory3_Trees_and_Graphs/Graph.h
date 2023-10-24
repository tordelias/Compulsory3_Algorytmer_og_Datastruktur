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
		int numvertecies; 
		list<Node*> adjlist;

	};
	Node* CreateGraph(int data, int weight, Node* head)
	{
		Node* newNode = new Node;
		newNode->data = data; 
		newNode->cost = weight; 
		
		if(head != nullptr)
		newNode->adjlist.push_back(head); 

		return newNode; 
	}
	void returnNodeinf()
	{

	}
	void adjNodes()
	{

	}
	void verticesGraph()
	{

	}
	void edgeGraph()
	{

	}
	int size()
	{

	}
	bool isEmpty()
	{

	}
	void deleteNode()
	{

	}
	void deleteEdge()
	{

	}
};

