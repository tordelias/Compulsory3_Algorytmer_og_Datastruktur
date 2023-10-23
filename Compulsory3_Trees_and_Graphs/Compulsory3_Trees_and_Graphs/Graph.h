#pragma once
#include<iostream>
#include<list>
using namespace std; 
class Graph
{
	struct Node
	{
		int data;
		int numvertecies; 
		list<Node*> adjlist;

	};
	Node* CreateGraph()
	{

	}
};

