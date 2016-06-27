#pragma once
#include "bin_Search_tree.hpp"
#include "d-heap.hpp"
#include "tabl.hpp"

template <class KeyT>
class Queue 
{
public:
	Queue(){};
	~Queue(){};
	virtual void SetQsize(int s) = 0;
	virtual int GetQsize(void) = 0;
	virtual void Pop() = 0;						//изьятие из начала(с мин меткой)
	virtual Edge<KeyT> Top() = 0;						//изьятие ребра без удаления
	virtual void Insert(Node<KeyT>* node) {};			//вставка node
	virtual void Insert(Node<KeyT>* n, int i) {};
	virtual int IsEmpty() = 0;
	virtual void print2() {};		//вывод со списком ребер
	virtual void print1() {};
	virtual void Heapify(){};
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class KeyT>
class D_heap_Queue : public Queue<KeyT>
{
private:
	int qsize;
public:
	D_heap<KeyT> *heap;
	D_heap_Queue(int s);
	D_heap_Queue (Edge<KeyT> *n, const int nsize);			//из ребер (структура)
	D_heap_Queue(const D_heap_Queue<KeyT> &que);
	~D_heap_Queue();

	virtual void SetQsize(int s);
	virtual int GetQsize(void);

	virtual void Pop();						//изьятие из начала(с мин меткой)
	Edge<KeyT> Top();						//изьятие ребра без удаления
	virtual void Insert(Node<KeyT>* n, int i);
	int IsEmpty();

	D_heap_Queue<KeyT>& operator =(const D_heap_Queue<KeyT>& q);
	int operator ==(const D_heap_Queue<KeyT> &q)const;
	int operator !=(const D_heap_Queue<KeyT> &q)const;
	void Heapify();
	void print1();		//вывод со списком ребер
};

template <class KeyT>
void D_heap_Queue<KeyT>:: SetQsize(int s)
{
	if(s<0)
		throw exception ("gsize<0");
	qsize = s;
	heap->size = s;
}

template <class KeyT>
void D_heap_Queue<KeyT>:: Heapify()
{
	heap->Heapify();
}

template <class KeyT>
D_heap_Queue<KeyT>:: D_heap_Queue(int s)
{
	if (s<=0) 
		throw exception ("Size<=0");
	qsize = s;
	heap = new D_heap<KeyT>(qsize,2,0);       //из 0
}

/*template <class KeyT>
void D_heap_Queue<KeyT>:: Insert(Edge<KeyT> n, int i)      //вставка ребра
{
	if((i<0) || (i>qsize-1))
		throw exception ("Not correct index");

	heap->nd[i].v1 = n.v1;
	heap->nd[i].v2 = n.v2;
	heap->nd[i].ves = n.ves;
	heap->keys[i] = n.ves;
}*/

template <class KeyT>
void D_heap_Queue<KeyT>:: Insert(Node<KeyT> *n, int i)      //вставка ребра
{
	if((i<0) || (i>qsize-1))
		throw exception ("Not correct index");
	heap->nd[i].v1 = n->e.v1;
	heap->nd[i].v2 = n->e.v2;
	heap->nd[i].key = n->e.key;
	heap->keys[i] = n->e.key;
}
/*Queue:: Queue(const int *p, const int psize)
{
	if (psize<=0) 
		throw exception ("Size<=0");
	qsize = psize;
	heap = new D_heap(p,psize,2);
}*/

template <class KeyT>
D_heap_Queue<KeyT>:: D_heap_Queue(Edge<KeyT> *n, const int nsize)			//из ребер (структура)
{
	if (nsize<=0) 
		throw exception ("Size<=0");
	if(n==0)
		throw exception ("*n=0");

	qsize = nsize;
	heap = new D_heap<KeyT>(n,nsize,2);
}

template <class KeyT>
D_heap_Queue<KeyT>:: D_heap_Queue(const D_heap_Queue<KeyT> &que)
{
	qsize = que.qsize;
	int D = que.heap->GetD();

	if(que.heap->nd!=0)
	{
		heap = new D_heap<KeyT>(qsize, D, 1); 
		for(int i=0; i<qsize; i++)
		{
			heap->nd[i].v1 = que.heap->nd[i].v1;
			heap->nd[i].v2 = que.heap->nd[i].v2;
			heap->nd[i].key = que.heap->nd[i].key;
		}
	}
}

template <class KeyT>
void D_heap_Queue<KeyT>:: Pop()			//изьятие из начала(с мин меткой)
{
	if (qsize==0)
		return;
	heap->DeleteMinKey();
	qsize--;
}

template <class KeyT>
int D_heap_Queue<KeyT>:: IsEmpty()
{
	return heap->IsEmpty();   
}

template <class KeyT>
D_heap_Queue<KeyT>& D_heap_Queue<KeyT>:: operator =(const D_heap_Queue<KeyT>& q)
{
	if (this!= &q)
	{
		qsize = q.qsize;
		int D = q.heap->GetD();

		if(q.heap->nd!=0)//////////////////
		{
			delete [] heap->keys;
			heap = new D_heap<KeyT>(qsize, D, 1); 
			for(int i=0; i<qsize; i++)
			{
				heap->nd[i].v1 = q.heap->nd[i].v1;
				heap->nd[i].v2 = q.heap->nd[i].v2;
				heap->nd[i].key = q.heap->nd[i].key;
			}
		}////////////////////////////////
	}
	return *this;
}

template <class KeyT>
int D_heap_Queue<KeyT> :: operator !=(const D_heap_Queue<KeyT> &q)const
{
	return !(*this == q);
}

template <class KeyT>
int D_heap_Queue<KeyT> :: operator ==(const D_heap_Queue<KeyT> &q)const
{
	if (this != &q)
	{
		if ((qsize != q.qsize) )
			return 0;

		for (int i=0; i<qsize; i++)
			if (heap->nd[i].v1!=q.heap->nd[i].v1)
				return 0;
		for (int i=0; i<qsize; i++)
			if (heap->nd[i].v2!=q.heap->nd[i].v2)
				return 0;

		for (int i=0; i<qsize; i++)
			if (heap->keys[i]!=q.heap->keys[i])
				return 0;
	}
	return 1;
}

template <class KeyT>
D_heap_Queue<KeyT>:: ~D_heap_Queue(){
		delete heap;
}

template <class KeyT>
void D_heap_Queue<KeyT>:: print1()		//вывод со списком ребер
{
	heap->print1();
}

template <class KeyT>
Edge<KeyT> D_heap_Queue<KeyT>:: Top()			//изьятие ребра
{
	return heap->nd[0];
}

template <class KeyT>
int D_heap_Queue<KeyT>:: GetQsize(void){
	return qsize;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class KeyT>
class BSearchTree_Queue: public Queue<KeyT>
{
private:
	int qsize;
	BSearchTree<KeyT>* search_tree;
public:
	BSearchTree_Queue(int s, Node<KeyT>* node);
	virtual ~BSearchTree_Queue();
	virtual void SetQsize(int s);
	virtual int GetQsize(void);

	virtual void Pop();						//изьятие из начала(с мин меткой)
	Edge<KeyT> Top();						//изьятие  без удаления

	virtual void Insert(Node<KeyT>* node);			//вставка node
	int IsEmpty();
	//void Print();					//вывод массива
	void print1();		//вывод со списком ребер
	void print2();		// в ширину
};

template <class KeyT>
BSearchTree_Queue<KeyT>:: BSearchTree_Queue(int s, Node<KeyT>* node)
{
	if (s<=0) 
		throw exception ("Size<=0");
	if (node==0)
		throw exception ("node=0");
	qsize = s;
	search_tree = new BSearchTree<KeyT>(node);
	cout << "queue on tree create";
}

template <class KeyT>
BSearchTree_Queue<KeyT>:: ~BSearchTree_Queue(){
	//if(search_tree!=0)
		//delete search_tree;
	//cout << "queue on tree delete";
}

template <class KeyT>
void BSearchTree_Queue<KeyT>:: Insert(Node<KeyT>* node)      //вставка ребра
{
	if(node==0)
		throw exception ("node=0");
	search_tree->Insert(node);
	qsize++;
}

template <class KeyT>
void BSearchTree_Queue<KeyT>:: Pop()			//изьятие из начала(с мин меткой)
{
	if (qsize==0)
		return;
	Node<KeyT>* p = search_tree->FindMin(search_tree->root);
	search_tree->Delete(search_tree->root, p->e.key);
	qsize--;
}

template <class KeyT>
int BSearchTree_Queue<KeyT>:: IsEmpty()
{
	if (qsize==0)   
		return 1;
	else
		return 0;
}

////////////////////////////////////////////////
template <class KeyT>
void BSearchTree_Queue<KeyT>:: print1()		//вывод со списком ребер
{
	if(IsEmpty())
	{
		cout << "Пусто" << endl;
		return;
	}
	search_tree->Print1(search_tree->root);
}

template <class KeyT>
void BSearchTree_Queue<KeyT>:: print2()
{
	if(IsEmpty()){	
		cout << "Пусто" << endl;
		return;
	}
	
	queue<Node<KeyT>*> q;
	q.push(search_tree->root);
	while(!q.empty())
	{
		Node<KeyT>* tmp = q.front();
		cout << "v1: " << tmp->e.v1 << "; ";
		cout << "v2: " << tmp->e.v2 << "; ";
		cout << "ves: " << tmp->e.key << endl;

		q.pop();
		//левое поддерево
		if (tmp->left!=0)
			q.push(tmp->left);
		//правое поддерево
		if (tmp->right!=0)
			q.push(tmp->right);
	}
}
////////////////////////////////////////////////
template <class KeyT>
Edge<KeyT> BSearchTree_Queue<KeyT>:: Top()			//изьятие 
{
	Node<KeyT>* p = search_tree->FindMin(search_tree->root);
	Edge<KeyT> e; e.key = p->e.key;
	e.v1 = p->e.v1;
	e.v2 = p->e.v2;
	return 	e;
}
///////////////////////////////////////////////
template <class KeyT>
int BSearchTree_Queue<KeyT>:: GetQsize(void){
	return qsize;
}

template <class KeyT>
void BSearchTree_Queue<KeyT>:: SetQsize(int s)
{
	if(s<0)
		throw exception ("gsize<0");
	qsize = s;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class KeyT>
class SortTable_Queue : public Queue<KeyT>
{
private:
	int qsize;
	SortTable<KeyT>  *table;
public:
	SortTable_Queue();
	SortTable_Queue(int size);
	~SortTable_Queue();
	virtual void SetQsize(int s);
	virtual int GetQsize(void);
	virtual void Pop();						//изьятие из начала(с мин меткой)
	Edge<KeyT> Top();						//получение ребра
	virtual void Insert(Node<KeyT>* n);			//вставка node
	int IsEmpty();
	void print1();		//вывод со списком ребер
};

template <class KeyT>
SortTable_Queue<KeyT>:: SortTable_Queue(int size)
{
	if (size<0) 
		throw exception ("Size<0");
	table = new SortTable<KeyT>(size); //созд TabRec разм size,//констр Table: pos=0, cout=0
	qsize = 0;
}

template <class KeyT>
SortTable_Queue<KeyT>:: ~SortTable_Queue(){
	delete table;
}

template <class KeyT>
void SortTable_Queue<KeyT>:: Insert(Node<KeyT>*n)      //вставка ребра
{
	table->Insert(qsize, n);
	qsize++;
}

template <class KeyT>
void SortTable_Queue<KeyT>:: Pop()			//изьятие из начала(с мин меткой)
{
	if (IsEmpty())
		throw
		exception("Table is empty");
	table->Delete(table->GetMin()->GetKey());
	qsize--;
}

template <class KeyT>
int SortTable_Queue<KeyT>:: IsEmpty()
{
	if (qsize==0)   
		return 1;
	else
		return 0;
}

template <class KeyT>
void SortTable_Queue<KeyT>:: print1()		//вывод со списком ребер
{
	if(IsEmpty())
	{
		cout << "Пусто" << endl;
		return;
	}
	table->print();
}

template <class KeyT>
Edge<KeyT> SortTable_Queue<KeyT>:: Top()			//изьятие 
{
	if(IsEmpty())
		throw exception("is empty");
	TabRecord<KeyT> *f = table->GetMin();
	Edge<KeyT> w;
	w.key = f->data->e.key;
	w.v1 = f->data->e.v1;
	w.v2 = f->data->e.v2;
	return w;
}

template <class KeyT>
int SortTable_Queue<KeyT>:: GetQsize(void){
	return qsize;
}

template <class KeyT>
void SortTable_Queue<KeyT>:: SetQsize(int s)
{
	if(s<0)
		throw exception ("gsize<0");
	qsize = s;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class KeyT>
class Choose_Queue 
{
public:
	static void choose_Queue(Queue<KeyT>* &q, const int size, Node<KeyT>** v, const int a);
};

template <class KeyT>
void Choose_Queue<KeyT>:: choose_Queue(Queue<KeyT>* &q, const int k, Node<KeyT>** v, const int a)
{//k--size
	if(a==0)
	{
		q = new D_heap_Queue<KeyT>(k);
		int nkol=0, f=0;
		for(int i=0; i<k; i++)
		{
			q->Insert(v[i],f);
			f++;
			nkol++;
		}
		q->SetQsize(nkol);
		q->Heapify();  //сортирует по возрастанию
		q->print1();			//вывод списка ребер
	}
	if (a==1)
	{
		q = new  BSearchTree_Queue<KeyT>(k, v[0]);
		for(int i=1; i<k; i++)                        	
			{
				q->Insert(v[i]);
			}
		q->SetQsize(k);
		q->print2();
	}
	if (a==2)
	{
		q = new  SortTable_Queue<KeyT>(k);
		for(int i=0; i<k; i++)
			{
				q->Insert(v[i]);
			}
		q->SetQsize(k);
		q->print1();
	}
}