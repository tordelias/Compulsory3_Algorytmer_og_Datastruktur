#include <iostream>
#include "Tree.h"


using namespace std;

int main()
{
	Tree tree; 
	
	Tree::Node* root = tree.CreateNode(1, nullptr); 
	Tree::Node* child1 = tree.CreateNode(2, root); 
	Tree::Node* child2 = tree.CreateNode(3, root);
	Tree::Node* child3 = tree.CreateNode(13, root);
	Tree::Node* child4 = tree.CreateNode(4, child2);
	Tree::Node* child5 = tree.CreateNode(5, child4);

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

}