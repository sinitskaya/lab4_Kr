#pragma once
#include <iostream>
#include <queue>
using namespace std;

template <class KeyT>
struct Edge
{
	KeyT key; // ves = key
	int v1; //������� 1
	int v2; //������� 2
};

template <class KeyT>
class Node
{
public:
	int hight;
	Edge<KeyT> e;
	Node* right;
	Node* left;
	Node* parent;
	Node(KeyT key1)
	{
		e.key = key1;
		hight = 1;
		left = 0;
		right = 0;
		parent = 0;
	}
	Node(){}
	~Node(){}
};

template <class KeyT>
class BSearchTree
{
public:
	Node<KeyT> *root;
	BSearchTree();
	BSearchTree(KeyT startkey);
	BSearchTree(Node<KeyT>* root_);
	~BSearchTree();

	Node<KeyT>* FindKey(Node<KeyT> *root_, KeyT key1); //����� � �������� ������
	Node<KeyT>* FindMin(Node<KeyT> * node);			//����� ����� ����
	Node<KeyT>* FindMax(Node<KeyT> * node);			//����� ���� ����
	Node<KeyT>* FindNext(Node<KeyT>* node);			//����� ��������� �� ��������
	Node<KeyT>* FindPred(Node<KeyT>* node);			//����� ����������� �� ��������

	KeyT GetNodeKey(Node<KeyT>* node);					//�������� �������� �����
	void Insert(Node<KeyT>* node);						//�������
	void Delete(Node<KeyT>* root_, KeyT key1);			//��������
	void DeleteRoot();		//�������� �����

	//void Copy(Node const *root_, Node* tmp);

	void Print(Node<KeyT> *root_);			//������ //����� � ������� � ������ �������
	void Print1(Node<KeyT> *root_);			//������ //����� � ������
	//friend class BSearchTree_Queue;

	//BSearchTree(int s, Node* node);
	//BSearchTree(const Node* & node);
};

template <class KeyT>
BSearchTree<KeyT>:: BSearchTree()
{
	root = new Node<KeyT>(0);
}

template <class KeyT>
BSearchTree<KeyT>:: BSearchTree(KeyT startkey)
{
	root = new Node<KeyT>(startkey);
}

template <class KeyT>
BSearchTree<KeyT>:: BSearchTree(Node<KeyT>* root_)
{
	if(root_==0)
		throw exception ("root_=0");
	root = root_;
}

template <class KeyT>
BSearchTree<KeyT>:: ~BSearchTree()
{
	delete root;
	if (root!=NULL) root = NULL;
	//cout << "tree delete";
}
/*
BSearchTree:: BSearchTree(const Node* & node)
{
	Copy(node,root);
}*/

template <class KeyT>
Node<KeyT>* BSearchTree<KeyT>:: FindKey(Node<KeyT> *root_, KeyT key1) //����� � �������� ������
{
	if(root_==0)
		//return NULL;
		throw exception ("root=0");

	while ((root_) && (root_->e.key != key1))
		if (key1 < root_->e.key)
			root_ = root_->left;
		else
			root_ = root_->right;
	return root_;
}

template <class KeyT>
Node<KeyT>* BSearchTree<KeyT>:: FindMin(Node<KeyT> * root_)	//����� ��� ����
{
	if (root_ == 0)
		return NULL;
	while(root_->left)
		root_ = root_->left;
	return root_;
}

template <class KeyT>
Node<KeyT>* BSearchTree<KeyT>:: FindMax(Node<KeyT> *root_)	//����� ���� ����
{
	if (root_ == 0)
		return NULL;
	while(root_->right)
		root_ = root_->right;
	return root_;
}

template <class KeyT>
Node<KeyT>* BSearchTree<KeyT>:: FindNext(Node<KeyT>* node) //����� ��������� �� ��������
{
	if (node == 0)
		return NULL;
	if (node->right!=0)
		return FindMin(node->right);

	while((node->parent) && (node->parent->right == node))
		node = node->parent;
	return node->parent;
}

template <class KeyT>
Node<KeyT>* BSearchTree<KeyT>:: FindPred(Node<KeyT>* node)//left / max //����� ����������� �� ��������
{
	if (node == 0)
	{
		cout << "NULL";
		return NULL;
	}
	if (node->left!=0)
		return FindMax(node->left);

	while((node->parent) && (node->parent->left == node))
		node = node->parent;
	return node ->parent;
}

template <class KeyT>
void BSearchTree<KeyT>:: Insert(Node<KeyT>* node)  /////�������
{
	if(node == 0)
		throw exception ("node = 0");
	if (root == 0){			//���� ������ ������
		root = node;
		return;
	}

	Node<KeyT>* x = root;
	Node<KeyT>* y = x;
	while(x!=0)
	{
		y = x;
		if (x->e.key <= node->e.key) //����� � ������
			x = x->right;
		else
			x = x->left;			//����� � �����
	}
	if (y->e.key <= node->e.key)
		y->right = node;
	else
		 y->left = node;
	node->parent = y;
}

/*
void BSearchTree :: Copy(Node const *root_, Node* tmp)
{
	if (root_ == 0)
		return;
	if(tmp == 0) { cout << "tmp = 0" << endl; return; }
	tmp->e.key = root_->e.key;
	tmp->e.v1 = root_->e.v1;
	tmp->e.v2 = root_->e.v2;

	if(root_->left !=0)
		tmp->left = new Node;
	else 
		tmp->left = 0;//////////
	if(root_->right != 0)
		tmp->right = new Node;
	else
		tmp->right = 0;//////////
	if(root_->parent != 0)
		tmp->parent = new Node;
	else 
		tmp->parent = 0;//////////
	Copy(root_->left, tmp->left);
	Copy(root_->right, tmp->right);
	Copy(root->parent, tmp->parent);
}*/

template <class KeyT>
void BSearchTree<KeyT>:: DeleteRoot() //�������� �����
{
	if(root==0) throw exception ("root=0");
	Node<KeyT>* t = FindNext(root);
	if(t!=0)
	{
		Node<KeyT>* t1 = new Node<KeyT>(t->e.key);
		t1->e.v1 = t->e.v1;
		t1->e.v2 = t->e.v2;

		Delete(t, t->e.key);

		if(root->right!=0) 
			root->right->parent = t1;
		if(root->left!=0)
			root->left->parent = t1;//

		t1->left = root->left;
		t1->right = root->right;
		root = t1;
	}
	else
	{
		Node<KeyT>* t3 = FindPred(root);
		if(t3==0)
			delete root;
		else
		{
			cout << "Pred" << endl;
			Node<KeyT>* t1 = new Node<KeyT>(t3->e.key);
			t1->e.v1 = t3->e.v1;
			t1->e.v2 = t3->e.v2;

			Delete(t3, t3->e.key);

			if(root->right!=0)
				root->right->parent = t1;
			if(root->left!=0)
				root->left->parent = t1;//

			t1->left = root->left;
			t1->right = root->right;
			root = t1;
		}
	}
}

template <class KeyT>
void BSearchTree<KeyT>:: Delete(Node<KeyT>* root_, KeyT key1) //��������
{
	if(root_==0) throw exception ("delete root_=0");
	Node<KeyT>* x = FindKey(root_, key1);
	
	//list
	if(x == 0)
		return;
	if((x->left == 0) && (x->right == 0))
	{
		if(x->parent!=0)///
		{
			if(x->parent->right == x)
				x->parent->right = 0;
			else
				x->parent->left = 0;
			delete x;
			return;
		}///�� ������
		else
		{
			DeleteRoot();
			return;
		}
	}//

	//1 �������
	if((x->left==0) && (x->right!=0))
	{
		if(x->parent!=0) //new
		{
			Node<KeyT>* y = x->right;
			y->parent = x->parent;

			if(x->parent->right==x)//���� ��� ������ ��������
				x->parent->right = y;
			else
				x->parent->left = y;
			delete x;
			return;
		}
		//////////////////////new
		else
		{
			DeleteRoot();
			return;
		}
		///////////////////////////new
	}
	if((x->left!=0) && (x->right==0))
	{
		if(x->parent!=0) //new
		{
			Node<KeyT>* y = x->left;
			y->parent = x->parent;
			if(x->parent->left==x)//���� ��� ������ ��������
				x->parent->left = y;
			else
				x->parent->right = y;
			delete x;
			return;
		}
		else
		{
			DeleteRoot();
			return;
		}
	}//1 �������

	//2 �������
	Node<KeyT>* y = FindMin(x->right);
	x->e.key = y->e.key;
	y->parent->left = y->right;
	// � � ��� ������� �������
	if(y->right!=0)
		y->right->parent = y->parent;
	delete y;
	//2 �������
}

template <class KeyT>
void BSearchTree<KeyT>:: Print(Node<KeyT>*root_) //������ //����� � ������ �������
{
	if (root_ == 0)	return;
	cout << root_->e.key << " ";
	Print(root_->left);
	Print(root_->right);
}

template <class KeyT>
void BSearchTree<KeyT>:: Print1(Node<KeyT>* root_) //������ //����� � ������
{
	if(root_==0){	
		cout << "������ �����" << endl;
		return; }
	
	queue<Node<KeyT>*> q;
	q.push(root_);
	while(!q.empty())
	{
		Node<KeyT>* tmp = q.front();
		//cout << "v1: " << tmp->e.v1 << "; ";
		//cout << "v2: " << tmp->e.v2 << "; ";
		cout << "ves: " << tmp->e.key << endl;

		q.pop();
		//����� ���������
		if (tmp->left!=0)
			q.push(tmp->left);
		//������ ���������
		if (tmp->right!=0)
			q.push(tmp->right);
	}
}

template <class KeyT>
KeyT BSearchTree<KeyT>:: GetNodeKey(Node<KeyT>* node) //�������� �������� �����
{
	return node->e.key; 
}