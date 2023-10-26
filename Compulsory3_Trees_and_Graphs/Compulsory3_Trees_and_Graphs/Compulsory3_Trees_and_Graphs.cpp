#include <iostream>
#include "Tree.h"
#include"Graph.h"





using namespace std;

int main()
{
Tree tree; 
Graph graph; 

Graph::Node* node1 = graph.CreateGraph(1, 1, nullptr); 
Graph::Node* node2 = graph.CreateGraph(2, 4, node1);
Graph::Node* node3 = graph.CreateGraph(3, 6, node1);

cout << "Graph\n";
graph.connectEdge(node3, node2); 
cout << "adj nodes node3\n";
graph.adjNodes(node3); 
cout << "\n";
cout << "number of nodes\n"; 
cout << graph.verticesGraph(node1);
cout << "\n";
cout << "edges in graph\n";
cout << graph.edgeGraph(node1); 
cout << "\n";
cout << "node data\n"; 
graph.returnNodeinf(node3);
cout << "all nodes in graph\n";
graph.returnNodes(node1); 
cout << "\n";
cout << "size\n";
graph.size(node1); 
cout << "\n";
if (!graph.isEmpty(node3))
cout << "not empty"; 
cout << "\n";
graph.deleteEdge(node3, node2); 
cout << "check if edge is deleted\n";
graph.adjNodes(node2); 
cout << "\n";
graph.deleteNode(node2);
cout << "check if node is deleted\n";
graph.returnNodes(node1); 





	
	Tree::Node* root = tree.CreateNode(1, nullptr); 
	Tree::Node* child1 = tree.CreateNode(2, root);  
	Tree::Node* child2 = tree.CreateNode(3, root);
	Tree::Node* child3 = tree.CreateNode(13, root);
	Tree::Node* child4 = tree.CreateNode(4, child2);
	Tree::Node* child5 = tree.CreateNode(5, child4);

	cout << "\n\n";
	cout << "Tree\n";
	printf("list of children\n"); 
	tree.listOfChildren(root); 
	cout << "\n" << "depth\n"; 
	cout << tree.depth(root)  << "\n";
	printf("size\n"); 
	cout << tree.size(root) << "\n"; 
	tree.isRoot(root); 
	tree.isLeaf(child4);
	cout << tree.parentOfNode(root) << "\n";
	cout << tree.parentOfNode(child4) << "\n";
	printf("children of root \n"); 
	tree.childOfNode(root); 
	cout << "\n"; 
	printf("Depth of child5\n"); 
	cout << tree.depth(child5) << "\n";
	printf("height\n"); 
	cout << tree.height(root) << "\n";
	tree.deleteNode(child2);
	cout << "\n";
	cout << "check if child2 was deleted\n";

}