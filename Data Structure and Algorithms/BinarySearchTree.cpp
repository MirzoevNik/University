#include <iostream>

using namespace std;

class BinarySearchTree
{
private:
	int key;
	BinarySearchTree* left;
	BinarySearchTree* right;
	BinarySearchTree* parent;
	bool is_exist;

	BinarySearchTree* minNode();
	BinarySearchTree* nextNode( BinarySearchTree *current_node );
	BinarySearchTree* createNode( int x );

public:
	BinarySearchTree();

	void insertNode( int node_key );
	BinarySearchTree* searchNodeByKey( int search_key );
	void deleteNode( BinarySearchTree *node );

	void printPr();
	void printSim();
	void printObr();
};

BinarySearchTree::BinarySearchTree()
{
	this->is_exist = false;
}

BinarySearchTree* BinarySearchTree::createNode( int x )
{
	BinarySearchTree *new_node = new BinarySearchTree();
	new_node->key = x;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = NULL;
	new_node->is_exist = true;

	return new_node;
}

void BinarySearchTree::insertNode( int node_key )
{
	BinarySearchTree *new_node_parent = NULL;
	BinarySearchTree *find_new_node_parent = this;
	BinarySearchTree *new_node = createNode( node_key );

	while ( find_new_node_parent && find_new_node_parent->is_exist )
	{
		new_node_parent = find_new_node_parent;
		if ( new_node->key < find_new_node_parent->key )
			find_new_node_parent = find_new_node_parent->left;
		else
			find_new_node_parent = find_new_node_parent->right;
	}

	new_node->parent = new_node_parent;
	if ( !new_node_parent )
	{
		this->key = new_node->key;
		this->left = new_node->left;
		this->right = new_node->right;
		this->parent = new_node->parent;
		this->is_exist = new_node->is_exist;
	}
	else
	{
		if ( new_node->key < new_node_parent->key )
			new_node_parent->left = new_node;
		else
			new_node_parent->right = new_node;
	}
}

BinarySearchTree* BinarySearchTree::searchNodeByKey( int search_key )
{
	BinarySearchTree *finded_node = this;

	while ( finded_node && finded_node->key != search_key )
	{
		if ( search_key < finded_node->key )
			finded_node = finded_node->left;
		else
			finded_node = finded_node->right;
	}

	return finded_node;
}

BinarySearchTree* BinarySearchTree::minNode()
{
	BinarySearchTree *start_node = this;
	BinarySearchTree *min_node = NULL;

	while ( start_node )
	{
		min_node = start_node;
		start_node = start_node->left;
	}

	return min_node;
}

BinarySearchTree* BinarySearchTree::nextNode( BinarySearchTree *current_node )
{
	if ( current_node->right )
		return current_node->right->minNode();

	BinarySearchTree *next_node = current_node->parent;

	while ( next_node && current_node == next_node->right )
	{
		current_node = next_node;
		next_node = current_node->parent;
	}

	return next_node;
}

void BinarySearchTree::deleteNode( BinarySearchTree *node )
{
	BinarySearchTree *next_node = NULL;
	BinarySearchTree *deleted_node = NULL;

	if ( node->left == NULL || node->right == NULL )
		deleted_node = node;
	else
		deleted_node = nextNode( node );

	if ( deleted_node->left )
		next_node = deleted_node->left;
	else
		next_node = deleted_node->right;

	if ( next_node )
		next_node->parent = deleted_node->parent;

	if ( !( deleted_node->parent ) )
	{
		this->key = next_node->key;
		this->left = next_node->left;
		this->right = next_node->right;
		this->parent = next_node->parent;
		this->is_exist = next_node->is_exist;
	}
	else
	{
		if ( deleted_node == deleted_node->parent->left )
			deleted_node->parent->left = next_node;
		else
			deleted_node->parent->right = next_node;
	}

	if ( deleted_node != node )
		node->key = deleted_node->key;

	delete deleted_node;

}

void BinarySearchTree::printPr()
{
	if( this )	
	{
		cout << this->key << " ";
		this->left->printPr();
		this->right->printPr();
	}
}
	
void BinarySearchTree::printSim()
{
	if( this )	
	{
		this->left->printSim();
		cout << this->key << " ";
		this->right->printSim();
	}
}
	
void BinarySearchTree::printObr()
{
	if( this )	
	{
		this->left->printObr();
		this->right->printObr();
		cout << this->key << " ";
	}
}

int main()
{
	BinarySearchTree *tree = new BinarySearchTree();

	tree->insertNode( 5 );
	tree->insertNode( 6 );
	tree->insertNode( 2 );
	tree->insertNode( 8 );

	tree->printPr();
	cout << endl;

	tree->printSim();
	cout << endl;

	tree->printObr();
	cout << endl;

	tree->deleteNode( tree->searchNodeByKey(5) );

	tree->printPr();
	cout << endl;

	system("pause");
	return 0;
}