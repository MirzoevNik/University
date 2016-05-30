#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
	int value;
	short height;
	Node *left;
	Node *right;
	Node *parent;
};

class AVLTree
{
private:
	Node *root;

	Node* createNode( int val );

	short getHeight( Node *node );
	short getBalance( Node *node );
	
	void fixHeight( Node *node );
	Node* doBalance( Node *node );

	Node* rotateLeft( Node *node );
	Node* rotateRight( Node *node );
	
	Node* findMin( Node* node );
	Node* removeMin( Node* node );
	Node* searchNodeByKey( int search_key );
	void insertNode( Node* &cur_root, Node *node );
	void deleteNode( Node *node );
	void visiting( Node *node );

public:
	AVLTree(){ root = NULL; }

	void insert( int key );
	void deleteByKey( int key );
	void print();
};

Node* AVLTree::createNode( int val )
{
	Node *new_node = new Node();
	new_node->value = val;
	new_node->height = 1;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

short AVLTree::getBalance( Node *node )
{
	if ( node )
	{
		short height_left, height_right;
		if ( node->right )
			height_right = node->right->height;
		else
			height_right = 0;
		if ( node->left )
			height_left = node->left->height;
		else
			height_left = 0;
		return height_right - height_left;
	}
	else
		return 0;
}
	
void AVLTree::fixHeight( Node *node )
{
	if ( node )
	{
		short height_left, height_right;
		if ( node->right != NULL )
			height_right = node->right->height;
		else
			height_right = 0;
		if ( node->left != NULL )
			height_left = node->left->height;
		else
			height_left = 0;
		node->height = ( ( height_left > height_right ) ? height_left : height_right ) + 1;
	}
}

Node* AVLTree::rotateLeft( Node *node )
{
	Node *pivot = node->right;

	node->right = pivot->left;
	pivot->parent = node->parent;
	pivot->left = node;
	node->parent = pivot;

	fixHeight( node );
	fixHeight( pivot );

	return pivot;
}
	
Node* AVLTree::rotateRight( Node *node )
{
	Node *pivot = node->left;

	node->left = pivot->right;
	pivot->parent = node->parent;
	pivot->right = node;
	node->parent = pivot;

	fixHeight( node );
	fixHeight( pivot );

	return pivot;
}

Node* AVLTree::doBalance( Node *node )
{
	fixHeight( node );

	if ( getBalance( node ) == 2 )
	{
		if ( getBalance( node->right ) < 0 )
			node->right = rotateRight( node->right );
		return rotateLeft( node );
	}

	if ( getBalance( node ) == -2 )
	{
		if ( getBalance( node->left ) > 0 )
			node->left = rotateLeft( node->left );
		return rotateRight( node );
	}

	return node;
}

void AVLTree::insertNode( Node* &cur_root, Node *node )
{
	if ( !cur_root )
	{
		cur_root = node;
		return;
	}
	if ( node->value < cur_root->value )
	{
		node->parent = cur_root;
		insertNode( cur_root->left, node );
	}
	else
	{
		node->parent = cur_root;
		insertNode( cur_root->right, node );
	}

	cur_root = doBalance( cur_root );
}

Node* AVLTree::searchNodeByKey( int search_key )
{
	Node *finded_node = root;

	while ( finded_node && finded_node->value != search_key )
	{
		if ( search_key < finded_node->value )
			finded_node = finded_node->left;
		else
			finded_node = finded_node->right;
	}

	return finded_node;
}

Node* AVLTree::findMin( Node* node )
{
	return ( node->left ? findMin( node->left ) : node );
}

Node* AVLTree::removeMin( Node* node )
{
	if( !node->left )
		return node->right;

	node->left = removeMin( node->left );

	return doBalance( node );
}

void AVLTree::deleteNode( Node* node )
{
	Node* left_child = node->left;
	Node* right_child = node->right;

	if( !right_child )
	{
		if ( left_child )
		{
			if ( !node->parent )
				root = left_child;
			else
			{
				if ( node == node->parent->left )
					node->parent->left = left_child;
				else
					node->parent->right = left_child;

				left_child->parent = node->parent;
			}
		}
		else
		{
			if ( !node->parent )
				root = NULL;
			else
			{
				if ( node == node->parent->left )
					node->parent->left = NULL;
				else
					node->parent->right = NULL;
			}
		}
		delete node;
		return;
	}

	Node* min_node = findMin( right_child );
	min_node->right = removeMin( right_child );
	min_node->left = left_child;

	if ( !node->parent )
		root = min_node;
	else
	{
		if ( node == node->parent->left )
			node->parent->left = min_node;
		else
			node->parent->right = min_node;

		min_node->parent = node->parent;
	}

	delete node;

	min_node = doBalance( min_node );
}

void AVLTree::visiting( Node *node )
{
	if ( node )
	{
		cout << node->value << " " << node->height << endl;
		visiting( node->left );
		visiting( node->right );
	}
}

void AVLTree::insert( int key )
{
	Node *new_node = createNode( key );
	insertNode( root, new_node );
}

void AVLTree::deleteByKey( int key )
{
	Node *node = searchNodeByKey( key );
	deleteNode( node );
}

void AVLTree::print()
{
	if ( root )
	{
		visiting( root );
	}
}

int main()
{
	AVLTree *avl = new AVLTree();

	ifstream in("input_avl.txt");
	while ( in.peek() != EOF )
	{
		int key;
		in >> key;
		avl->insert( key );
	}
	in.close();

	avl->print();

	int key;
	cout << "\n\nEnter deleted key: ";
	cin >> key;

	avl->deleteByKey( key );

	avl->print();

	cout << endl;

	system( "pause" );
	return 0;
}