#include <iostream>
#include <list>


using namespace std; 

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
	return newnode; 
}
void listOfChildren(struct Node* root)
{
	if (root != nullptr)
	{
		auto it = root->children.begin();
		while(it != root->children.end())
		{
			listOfChildren(*it);
			cout << " " << (*it)->data; 
			++it; 
		}
	}
}
int depth(struct Node* root)
{
	if (root != nullptr)
	{
		int maxDepth = 0; 
		for (Node* child : root->children)
		{
			int childDepth = depth(child); 
			maxDepth = max(maxDepth, childDepth); 
		}

		return maxDepth + 1;

	}
	else
		cout << "is nullptr\n";
}
int size(struct Node* root)
{
	if (root != nullptr)
	{
		auto it = root->children.begin();
		int listSize = 1; 
		for (Node* child : root->children) {
			listSize += size(child);
		}
		return listSize; 
	}
	else
		cout << "is nullptr\n";

}
bool isEmpty(struct Node* root)
{
	if (root != nullptr)
		return false;
	else
		return true; 
}
bool isRoot(struct Node* root)
{
	if (root->parent == nullptr)
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
int parentOfNode(struct Node* root)
{

	if (root->parent != nullptr)
		return root->parent->data;
	else
		cout << "root\n";
	return NULL; 
 
}

int childOfNode(struct Node* root)
{
	if (!root->children.empty())
	{
		auto it = root->children.begin();
		while (it != root->children.end())
		{
			cout << " " << (*it)->data;
			++it;
		}

	}
	else
		cout << "isLeaf\n";
		return NULL; 

}
void deleteNode(struct Node* root)
{
	if (root == nullptr)
		return; 
	else if(root->parent != nullptr)
	root->parent->children.remove(root);

	for (Node* child : root->children)
	{
		deleteNode(child);
	}

	delete root; 
}


int main()
{
	Node* root = CreateNode(1, nullptr); 
	root->children.push_back(CreateNode(2, root));
	root->children.push_back(CreateNode(3, root));
	root->children.back()->children.push_back(CreateNode(4, root->children.back()));
	root->children.back()->children.back()->children.push_back(CreateNode(5, root->children.back()));

	cout << "list of children\n"; 
	listOfChildren(root); 
	cout << "\n" << "depth\n"; 
	cout << depth(root)  << "\n";
	cout << "size\n";
	cout << size(root) << "\n"; 
	isRoot(root); 
	isLeaf(root->children.back()->children.back()->children.back());
	cout << parentOfNode(root) << "\n";
	cout << parentOfNode(root->children.back()->children.back()) << "\n";
	childOfNode(root); 
	deleteNode(root->children.front());
	cout << "\n";
	childOfNode(root);

}


