#include <iostream>
#include <fstream>

#define RED true
#define BLACK false

using namespace std;

struct Node
{
	int value;
	bool color;
	Node *left;
	Node *right;
	Node *parent;
};

class RedBlackTree
{
private:
	Node *root;

	Node* createNode( int val );
	bool isLeaf( Node *node );

	Node* grandparent( Node *node );
	Node* uncle( Node *node );
	Node* brother( Node *node );

	void rotateLeft( Node *node );
	void rotateRight( Node *node );
	void replaceNode( Node *cur_node, Node *new_node );

	void insertCase1( Node* &node ); // node is root
	void insertCase2( Node* &node ); // parent is black
	void insertCase3( Node* &node ); // parent & uncle are red
	void insertCase4( Node* &node ); // parent is red, uncle is black
	void insertCase5( Node* &node ); // case4, node & parent are left

	void deleteCase1( Node *node ); // node is root
	void deleteCase2( Node *node ); // bro is red
	void deleteCase3( Node *node ); // parent & bro & bro's children are black
	void deleteCase4( Node *node ); // parent is red, bro & bro's children are black
	void deleteCase5( Node *node ); // node is left, bro & bro' right are black, bro's left is red
	void deleteCase6( Node *node ); // node is left, bro is black, bro's right is red

	Node* nextNode( Node *current_node );
	void visiting( Node *node );
	Node* minNode( Node *node );
	void deleteNode( Node *node );
	Node* searchNodeByKey( int search_key );

public:
	RedBlackTree(){ root = NULL; }

	void insert( int key );
	void deleteByKey( int key );
	void print();
};

Node* RedBlackTree::createNode( int val )
{
	Node *new_node = new Node();
	new_node->value = val;
	new_node->color = RED;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

bool RedBlackTree::isLeaf( Node *node )
{
	if ( !node->left && !node->right )
		return true;
	else
		return false;
}

Node* RedBlackTree::grandparent( Node *node )
{
	if ( ( !node ) || ( !node->parent ) )
		return NULL;
	else
		return node->parent->parent;
}

Node* RedBlackTree::uncle( Node *node )
{
	Node *gr_par = grandparent( node );
	if ( !gr_par )
		return NULL;
	if ( node->parent == gr_par->left )
		return gr_par->right;
	else
		return gr_par->left;
}

Node* RedBlackTree::brother( Node *node )
{
	if ( node == node->parent->left )
		return node->parent->right;
	else
		return node->parent->left;
}

void RedBlackTree::rotateLeft( Node *node )
{
    Node *pivot = node->right;
	
    pivot->parent = node->parent;
    if ( node->parent ) 
	{
        if ( node->parent->left == node )
            node->parent->left = pivot;
        else
            node->parent->right = pivot;
    }		
	
    node->right = pivot->left;
    if ( pivot->left )
        pivot->left->parent = node;

    node->parent = pivot;
    pivot->left = node;
}

void RedBlackTree::rotateRight( Node *node )
{
    Node *pivot = node->left;
	
    pivot->parent = node->parent;
    if ( node->parent ) 
	{
        if ( node->parent->left == node )
            node->parent->left = pivot;
        else
            node->parent->right = pivot;
    }		
	
    node->left = pivot->right;
    if ( pivot->right )
        pivot->right->parent = node;

    node->parent = pivot;
    pivot->right = node;
}

void RedBlackTree::replaceNode( Node *cur_node, Node *new_node )
{
	if ( new_node != cur_node )
	{
		if ( cur_node->parent )
		{
			if ( cur_node->parent->left == cur_node )
				cur_node->parent->left = new_node;
			else
				cur_node->parent->right = new_node;

			new_node->parent = cur_node->parent;
		}
		else
		{
			root = new_node;
		}

		delete cur_node;
	}
}

void RedBlackTree::insertCase1( Node* &node ) 
{
	if ( !node->parent ) 
	{
		node->color = BLACK;
    } 
	else 
	{
		insertCase2( node);
    }
}

void RedBlackTree::insertCase2( Node* &node )
{
	if ( node->parent->color == BLACK )
	{
		return;
	}
	else
	{
		insertCase3( node );
	}
}

void RedBlackTree::insertCase3( Node* &node ) 
{
    Node *node_uncle = uncle( node );
    Node *gr_par;

    if ( ( node_uncle ) 
		&& ( node_uncle->color == RED ) 
		&& ( node->parent->color == RED) ) 
	{
        node->parent->color = BLACK;
        node_uncle->color = BLACK;
        gr_par = grandparent( node );
        gr_par->color = RED;
        insertCase1( gr_par );
    } 
	else 
	{
        insertCase4( node );
    }
}

void RedBlackTree::insertCase4( Node* &node )
{
	 Node* gr_par = grandparent( node );

	if ( ( node == node->parent->right ) 
	   && (node->parent == gr_par->left) ) 
	{
		rotateLeft( node->parent );
		node = node->left;
	} 
	else if ( ( node == node->parent->left ) 
		   && ( node->parent == gr_par->right ) ) 
	{
		rotateRight( node->parent);
		node = node->right;
	}

	insertCase5( node );
}

void RedBlackTree::insertCase5( Node* &node )
{
	Node *gr_par = grandparent( node );

	node->parent->color = BLACK;
	gr_par->color = RED;

	if ( ( node == node->parent->left ) 
	  && ( node->parent == gr_par->left ) ) 
	{
		rotateRight( gr_par );
	} 
	else if ( ( node == node->parent->right ) 
		   && ( node->parent == gr_par->right ) ) 
	{
		rotateLeft( gr_par );
	}
}

void RedBlackTree::deleteCase1( Node *node )
{
	if ( node->parent )
		deleteCase2( node );
}

void RedBlackTree::deleteCase2( Node *node )
{
	Node *bro = brother( node );

	if ( bro->color == RED ) 
	{
		node->parent->color = RED;
		bro->color = BLACK;
		if ( node == node->parent->left )
			rotateLeft( node->parent );
		else
			rotateRight( node->parent );
	} 

	deleteCase3( node );
}

void RedBlackTree::deleteCase3( Node *node )
{
	Node *bro = brother( node );

	if ( ( node->parent->color == BLACK ) &&
	     ( bro->color == BLACK ) &&
	     ( bro->left->color == BLACK ) &&
	     ( bro->right->color == BLACK ) )
	{
		bro->color = RED;
		deleteCase1( node->parent );
	} 
	else
		deleteCase4( node );
}

void RedBlackTree::deleteCase4( Node *node )
{
	Node *bro = brother( node );

	if ( ( node->parent->color == RED) &&
		 ( bro->color == BLACK) &&
	     ( bro->left->color == BLACK) &&
	     ( bro->right->color == BLACK) ) 
	{
		bro->color = RED;
		node->parent->color = BLACK;
	} 
	else
		deleteCase5( node );
}

void RedBlackTree::deleteCase5( Node *node )
{
	Node *bro = brother( node );

	if ( bro->color == BLACK) 
	{
		if ( ( node == node->parent->left) &&
		     ( bro->right->color == BLACK) &&
		     ( bro->left->color == RED ) ) 
		{
			bro->color = RED;
			bro->left->color = BLACK;
			rotateRight( bro );
		} 
		else if ( ( node == node->parent->right) &&
		          ( bro->left->color == BLACK) &&
		          ( bro->right->color == RED ) ) 
		{
			bro->color = RED;
			bro->right->color = BLACK;
			rotateLeft( bro );
		}
	}

	deleteCase6( node );
}

void RedBlackTree::deleteCase6( Node *node )
{
	Node *bro = brother( node );

	bro->color = node->parent->color;
    node->parent->color = BLACK;

	if ( node == node->parent->left) 
	{
        bro->right->color = BLACK;
		rotateLeft( node->parent );
	} 
	else 
	{
		bro->left->color = BLACK;
		rotateRight( node->parent );
	}
}

void RedBlackTree::visiting( Node *node )
{
	if ( node )
	{
		cout << node->value << " ";
		if ( node->color == RED )
			cout << " is red\n";
		else
			cout << " is black\n";
		visiting( node->left );
		visiting( node->right );
	}
}

void RedBlackTree::print()
{
	if ( root )
	{
		visiting( root );
	}
}

void RedBlackTree::insert( int key )
{
	Node *new_node_parent = NULL;
	Node *find_new_node_parent = root;
	Node *new_node = createNode( key );

	while ( find_new_node_parent )
	{
		new_node_parent = find_new_node_parent;
		if ( new_node->value < find_new_node_parent->value )
			find_new_node_parent = find_new_node_parent->left;
		else
			find_new_node_parent = find_new_node_parent->right;
	}

	new_node->parent = new_node_parent;
	if ( !new_node_parent )
	{
		root = new_node;
	}
	else
	{
		if ( new_node->value < new_node_parent->value )
			new_node_parent->left = new_node;
		else
			new_node_parent->right = new_node;
	}

	insertCase1( new_node );
}

Node* RedBlackTree::searchNodeByKey( int search_key )
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

Node* RedBlackTree::minNode( Node *node )
{
	Node *start_node = node;
	Node *min_node = NULL;

	while ( start_node )
	{
		min_node = start_node;
		start_node = start_node->left;
	}

	return min_node;
}

Node* RedBlackTree::nextNode( Node *current_node )
{
	if ( current_node->right )
		return minNode( current_node->right );

	Node *next_node = current_node->parent;

	while ( next_node && current_node == next_node->right )
	{
		current_node = next_node;
		next_node = current_node->parent;
	}

	return next_node;
}

void RedBlackTree::deleteNode( Node *node )
{
	Node *main_child = NULL;
	Node *deleted_node = NULL;

	if ( node->left == NULL || node->right == NULL )
		deleted_node = node;
	else
		deleted_node = nextNode( node );

	if ( deleted_node->left )
		main_child = deleted_node->left;
	else
		main_child = deleted_node->right;

	if ( main_child )
		main_child->parent = deleted_node->parent;

	if ( ! deleted_node->parent )
	{
		root = main_child;
	}
	else
	{
		if ( deleted_node == deleted_node->parent->left )
			deleted_node->parent->left = main_child;
		else
			deleted_node->parent->right = main_child;
	}

	if ( deleted_node != node )
		node->value = deleted_node->value;

	delete deleted_node;
	deleteCase1( node );
}

void RedBlackTree::deleteByKey( int key )
{
	Node *node = searchNodeByKey( key );
	deleteNode( node );
}

int main()
{
	RedBlackTree *rbt = new RedBlackTree();

	ifstream in("input.txt");
	while ( in.peek() != EOF )
	{
		int key;
		in >> key;
		rbt->insert( key );
	}
	in.close();

	rbt->print();

	int key;
	cout << "\n\nEnter deleted key :";
	cin >> key;

	rbt->deleteByKey( key );

	rbt->print();

	cout << endl;

	system( "pause" );
	return 0;
}