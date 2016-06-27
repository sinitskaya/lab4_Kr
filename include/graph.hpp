#pragma once
#include <iostream>
#include <ctime>
using namespace std;

template <class KeyT>
class Graph
{
public:
	
	int gsize;		 //����� ������
	KeyT **edge;		 //��������� �����, ���� ���������

	Graph(int init, int, int);       //������������� �������������
	Graph(int s);			//���������� ����� ���� ������� � -1 �� ���������
	Graph(int s, int k);	//���������� ����� �������� ������� �� 0 �� k �� ������������
	//Graph(const Graph<KeyT> &g);
	~Graph();
	Graph<KeyT>& operator =(const Graph<KeyT> &g);
	void Print();			//����� �����
};

template <class KeyT>
Graph<KeyT>:: Graph(int s)
{
	if (s<0)
		throw exception ("gsize<0");

	gsize = s;
	edge = new KeyT*[gsize*gsize];
	for(int i=0; i<gsize; i++)
		edge[i] = new KeyT[gsize];
	
	for(int i=0; i<gsize; i++)
		for(int j=0; j<gsize; j++)
		{
			if(i==j)
				edge[i][j] = -1;
			else
				edge[i][j] = INT_MAX;
		}
}

template <class KeyT>
Graph<KeyT>:: Graph(int s, int k)
{
	if (s<0)
		throw exception ("gsize<0");
	if (k<=0)
		throw exception ("k<=0");

	gsize = s;
	//srand (time(0));
	edge = new KeyT*[gsize*gsize];
	for(int i=0; i<gsize; i++)
		edge[i] = new KeyT[gsize];
	
	for(int i=0; i<gsize; i++)
		for(int j=0; j<gsize; j++)
		{
			if(i==j)
				edge[i][j] = -1;
			else
				edge[i][j] = ( rand() % k );
		}

	for(int i=0; i<gsize; i++)
		for(int j=0; j<gsize; j++)
		{
			if(edge[i][j]=edge[j][i])
				edge[i][j] = edge[j][i];
		}
		
}

template <class KeyT>
void Graph<KeyT>:: Print()
{
	for(int i=0; i<gsize; i++)
	{
		for(int j=0; j<gsize; j++)
		{
			if (edge[i][j]==INT_MAX)
				cout << "  " << "M";
			else
				cout << "  " << edge[i][j];
		}
		cout << endl;
	}
}

template <class KeyT>
Graph<KeyT>:: Graph(int init, int, int)       //������������� �������������
{
	int kol; KeyT ves;

	cout << "������� ����� ������: ";
	cin >> kol;
	if (kol<0)
		throw exception ("kol<0");
	gsize = kol;

	//������
	edge = new KeyT*[gsize*gsize];
	for(int i=0; i<gsize; i++)
		edge[i] = new KeyT[gsize];

	//���������� -1
	for(int i=0; i<gsize; i++)
		for(int j=0; j<gsize; j++)
			edge[i][j] = -1;
	//
	cout << "������� ���� �����, ����������� ������� i,j: "<< endl;
	for(int i=0; i<=gsize-2; i++)				// ��������� nn �� �����
		for(int j=i+1; j<gsize; j++)
		{
			cout << "[" << i << "]" << "[" << j << "]" << " = ";
			cin >> ves;
			edge[i][j] = ves;
		}

	//������ �������
	for(int i=0; i<=gsize-2; i++)
		for(int j=i+1; j<gsize; j++)
			edge[j][i] = edge[i][j];
}

template <class KeyT>
Graph<KeyT>:: ~Graph()
{
	if(*edge!=0)
	{
		for(int i=0; i<gsize; i++)
			delete edge[i];
		delete[] edge;
		edge = 0;
	}
	//delete [] edge[i];
	//edge = 0;
	//cout << "graph delete";
}

template <class KeyT>
Graph<KeyT>& Graph<KeyT>:: operator =(const Graph<KeyT> &g)
{
if (this != &g)
	{
		for(int i=0; i<gsize; i++)
			delete [] edge[i];
		gsize = g.gsize;

		edge = new KeyT*[gsize*gsize];
		for(int i=0; i<gsize; i++)
			edge[i] = new KeyT[gsize];
		
		for (int i=0; i<gsize; i++)
			for (int j=0; j<gsize; j++)
				edge[i][j] = g.edge[i][j];
	}
	return *this;
}