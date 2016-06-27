#pragma once
#include <iostream>
#include "bin_Search_tree.hpp"
const int MAX_D_HEAP_SIZE = 100000000;
//typedef float VType;

template <class KeyT>
class D_heap 
{
private:
	int d;                     //����� ��������
	int Islist(int i);         //�������� ��-�� �� ����
public:
	int size;                  //����� ��������� � ����
	KeyT *keys;      
	Edge<KeyT> *nd;

	D_heap(int s, int d);				//nd=0
	D_heap(int s, int d, int k);		//nd !=0 k - �����
	D_heap(const D_heap<KeyT> & heap);
	D_heap(Edge<KeyT> *n, const int nsize, int d);		//�� ���������
	//D_heap(const int *p, const int psize,int d);	//�� �������
	~D_heap();

	int GetD();							//�������� d
	void SetD(int d1);                  //���������� d
	void Swap(int i, int j);            //����������������
	void siftUp(int i);                 //��������
	void siftDown(int i);               //����������
	void DeleteMinKey();                //�������� � ��� ������
	void DeleteIndex(int i);            //�������� � �������� ��������
	void Heapify();                     //����������
	int MinChild(int i);                //������ ������������ �������
	void InsertKey(KeyT key);             //������� ������ �����
	int Hight();                        //���-�� �����(������)
	int IsEmpty();
	void Print();		//����� � ������� 
	void PrintMas();	//����� �������

	int operator ==(const D_heap<KeyT> &heap)const;
	int operator !=(const D_heap<KeyT> &heap)const;
	D_heap<KeyT>& operator =(const D_heap<KeyT> &heap);
	KeyT & operator [](int pos);

	void print1(void);					// ����� �� ������� �����
	//friend class Queue; 
};

template <class KeyT>
D_heap<KeyT>:: D_heap(int s, int d, int k) //nd!=0 k-�����, key=0
{
	if (s<0)
		throw exception ("Negative size");
	if (s>MAX_D_HEAP_SIZE)
		throw exception("Size more than MAX_D_HEAP_SIZE");
	if (d<2)
		throw exception ("d<2");
	
	size = s;
	this->d = d;
	this->keys = new KeyT[size];
	nd = new Edge<KeyT>[size];

	for (int i=0; i<size; i++)
	{
		keys[i] = 0;
		nd[i].v1 = -1;
		nd[i].v2 = -1;
		nd[i].key = -1;
	}
	Heapify();//+
}

template <class KeyT>
D_heap<KeyT>:: D_heap(int s, int d) //nd=0
{
	if (s<0)
		throw exception ("Negative size");
	if (s>MAX_D_HEAP_SIZE)
		throw exception("Size more than MAX_D_HEAP_SIZE");
	if (d<2)
		throw exception ("d<2");

	size = s;
	this->d = d;
	this->keys = new KeyT[size];
	nd=0;
	/*for (int i=0; i<size; i++)
		keys[i] = 0;*/

	for (int i=0; i<size; i++)
			keys[i] = 1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(10 - 1)));//( rand() %10 );
	/*cout << "Random: "; Print(); cout << endl;
	
	cout << "Heapify: "; Heapify(); Print();*/
	Heapify();//+_
}
/*D_heap:: D_heap(const int *p, const int psize, int d)//���� �� �������
{
	if (p==0)
		throw exception ("p=0");
	if (d<2)
		throw exception ("d<2");
	if (psize<0)
		throw exception ("psize < 0");

	nd=0;
	size = psize;
	this->d = d;
	keys = new int[size];

	for (int i=0; i<size; i++)
		keys[i] = p[i];
	Heapify();
}*/
//////////////////////////////////////////////////////////////////////////////
template <class KeyT>
D_heap<KeyT>:: D_heap(Edge<KeyT> *n, const int nsize, int d)//���� ��  ������� ��������
{
	if (nsize<0)
		throw exception ("Negative size");
	if (d<2)
		throw exception ("d<2");
	if(n==0) 
		throw exception ("*n=0");

	size = nsize;
	this->d = d;
	keys = new KeyT[size];
	nd = new Edge<KeyT>[size];
	for(int i=0; i<size; i++)
		keys[i] = n[i].key;

	for(int i=0; i<size; i++)
	{
		nd[i].key = n[i].key;
		nd[i].v1 = n[i].v1;
		nd[i].v2 = n[i].v2;
	}
	Heapify();//+
}
//////////////////////////////////////////////////////////////////////////
template <class KeyT>
D_heap<KeyT>::  D_heap(const D_heap<KeyT> & heap)
{
	size = heap.size;
	d = heap.d;
	nd=0;
	keys = new KeyT[size];
	for (int i=0; i<size; i++)
		keys[i] = heap.keys[i];
}

template <class KeyT>
D_heap<KeyT>:: ~D_heap(){
	delete [] keys;
	if (nd!=0)
		delete [] nd;
}

template <class KeyT>
void D_heap<KeyT>:: Swap(int i, int j)    //����������������
{
	if ((i>=size) || (j>=size) || (i<0) || (j<0))
		throw exception ("Incorrect index in swap");
	KeyT tmp;
	tmp = keys[i];
	keys [i] = keys[j];
	keys[j] = tmp;
	if(nd!=0)
	{
		Edge<KeyT> tmp2;
		tmp2 = nd[i]; 
		nd[i] = nd[j];
		nd[j] = tmp2;
	}
}

template <class KeyT>
int D_heap<KeyT>:: GetD(){
	return d;
}

template <class KeyT>
void D_heap<KeyT>:: siftUp(int i) //��������
{
	if ((i >= size) || (i<0))
		throw exception ("Incorrect index in siftUp");
	
	if (d == 0) return;
	int iparent = (i-1)/d;
	while ((iparent >=0) && (keys[iparent]>keys[i])) {
		Swap(i,iparent);
		i = iparent;
		iparent = (i-1)/d;
	}
}

template <class KeyT>
void D_heap<KeyT>:: SetD(int d1)
{
	d = d1;
}
template <class KeyT>
int D_heap<KeyT>:: MinChild(int i) 
{
	if ((i >= size) || (i<0))
		throw exception ("Incorrect index in MinChild");

	if (Islist(i))
		return -1; //���� � ���� ��� �����
	KeyT minChild = keys[i*d+1];
	int minc = i*d+1; //������ ��� ������� � ����
	for (int j=1; j<=d; j++)
		if ((minChild > keys[i*d+j]) && ((i*d+j)<size))
		{
			minChild = keys[i*d+j];
			minc = i*d+j;
		}
	return minc;
}

template <class KeyT>
void D_heap<KeyT>:: siftDown(int i) //����������
{
	if ((i<0) || (i>=size)) //>size-1//sift(0) - size=0
		throw exception ("Incorrect index in siftDown");
	/*if (size == 0)
		return;*/
	int ichild = MinChild(i); //������
	while (!Islist(i) && (keys[ichild]<keys[i]))
	{
		Swap(ichild,i);
		i = ichild;
		ichild = MinChild(i);
	}
}

template <class KeyT>
void D_heap<KeyT>:: DeleteMinKey() //�������� � ��� ������
{
	Heapify();
	if (size == 0)
		return;
	KeyT min_key = keys[0];
	keys[0] = keys[size-1];            
	/////////////////////////////////////////////////
	if(nd!=0)
		nd[0] = nd[size-1];
	//////////////////////////////////////////////
	size--;
	if (size!=0)                    //size=0 - sifd(0) i=size=error-����� �� ����
		siftDown(0);
}

template <class KeyT>
void D_heap<KeyT>:: DeleteIndex(int i)  //�������� � �������� ��������
{
	if ((i>=size)|| (i<0))
		throw exception ("Incorrect index in DeleteIndex");

	keys[i] = keys[size-1];          
	if(nd!=0)
		nd[i] = nd[size-1];
	size--;
    siftDown(i);
}

template <class KeyT>
void D_heap<KeyT>:: Heapify() //����������
{
	if ((d==0) || (size==0) || (size==1)) return;
	for (int i=(size/d); i>=0; i--)// ��� d=1, ����� �� ������
		siftDown(i);
}

template <class KeyT>
void D_heap<KeyT>:: InsertKey(KeyT key)
{
	D_heap<KeyT> heap(size++,d);
	heap = *this;
	heap.keys[heap.size-1] = key;
	heap.siftUp(size-1);
	*this = heap;
}

template <class KeyT>
void D_heap<KeyT>:: Print(){
	cout << "D_HEAP: " << endl;
	if (IsEmpty ())
	{
		cout << "IsEmpty" << endl;
		return;
	}
	int f = 1; //����
	int h = Hight(); // ������
	int i = 0; //���� � ���� ��� �������� ��-��
	int k = 0; //������ ��� �������
	while (f != (h+1)){
		f++;
		for (int j=0; j<pow(d,i); j++){
			if (k>(size-1))
				return;
			cout << keys[k] << " ";
			k++;
		}
		i++;
		cout << endl;
	}
	cout << endl;
}

template <class KeyT>
void D_heap<KeyT>:: PrintMas()
{
	for (int i=size-1; i>=0; i--)
		cout << keys[i] << " ";
	cout << endl;
}

template <class KeyT>
int D_heap<KeyT>:: Hight()
{
	if (size == 0)
	{
		cout << "not data";
		return 0;
	}
	int h=1; int i=0;
	while  (!( Islist(i) ))
	{
		i = i*d +1;
		h++;
	}
	return h;
}

template <class KeyT>
int D_heap<KeyT>:: IsEmpty()
{
	if (size<0)
		throw exception ("size<0");
	if (size == 0)
		return 1;
	else return 0;
}

template <class KeyT>
int D_heap<KeyT>:: Islist(int i)
{
	if ((i*d+1) > (size-1))
		return 1;
	else
		return 0;
}

template <class KeyT>
int D_heap<KeyT>:: operator ==(const D_heap<KeyT> &heap)const
{
	if (this != &heap)
	{
		if ((size != heap.size) || (d!=heap.d))
			return 0;
		for (int i=0; i<size; i++)
			if (keys[i]!=heap.keys[i])
				return 0;
	}
	return 1;
}

template <class KeyT>
int D_heap<KeyT>:: operator !=(const D_heap<KeyT> &heap)const
{
	return !(*this == heap);
}

template <class KeyT>
D_heap<KeyT>& D_heap<KeyT>:: operator =(const D_heap<KeyT> &heap)
{
	if (this != &heap)
	{
		delete [] keys;
		size = heap.size;
		d = heap.d;
		keys = new KeyT[size];
		for (int i=0; i<size; i++)
			keys[i] = heap.keys[i];
	}
	return *this;
}

template <class KeyT>
KeyT & D_heap<KeyT>:: operator [](int pos)
{
	if ((pos>=size) || (pos<0))
		throw exception ("Incorrect index in []");
	return keys[pos];
}
///////////////////////////////////////////////////////////////
template <class KeyT>
void D_heap<KeyT>:: print1(void) // ����� �� ������� �����
{
	cout << endl;
	for(int i=0; i<size; i++)
	{
		cout << "v1: " << nd[i].v1 << " ";
		cout << "v2: " << nd[i].v2 << " ";
		cout << "ves: " << nd[i].key << " ";
		cout << endl;
	}
}
////////////////////////////////////////////////////