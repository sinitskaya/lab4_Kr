#pragma once
#include "bin_Search_tree.hpp"
#include "disjoint_set.h"
#include "queue.hpp"
#include "graph.hpp"

template <class KeyT>
class Algorithm
{
public:
	static void Kruskal(Graph<KeyT> & g1, Queue<KeyT> *& q);
	static void Dijkstr(Graph<KeyT> &g1, KeyT*& dist, int*& up);
};

template <class KeyT>
void Algorithm<KeyT>:: Kruskal(Graph<KeyT> & g1, Queue<KeyT>*& q)
{

	int kol = q->GetQsize();
	Edge<KeyT> *newn = new Edge<KeyT>[kol];					 //миним ост дер
	for(int i=0; i<kol; i++)
	{
		newn[i].v1 = -1;
		newn[i].v2 = -1;
		newn[i].key = -1;
	}

	Disjoint_set d(g1.gsize); //0 до 7
	for( int i=0; i<=g1.gsize-1; i++)
		d.CreateSingleton(i);

	int t = 0, l = 0, f=0;                      
//	cout << "v1: " << bv.v1 << "v2: " << bv.v2 << "ves: " << bv.ves;
	while( (!q->IsEmpty()) && (l<kol) ) //&& (t<size-1)
	{
		Edge<KeyT> bv = q->Top();
		int r = d.FindSubset(bv.v1); f = d.FindSubset(bv.v2);
		//cout << "d.FindSubset(bv.v1): " << r << "  d.FindSubset(bv.v2): " << f << endl;
		if(r!=f)
		{
			d.Union( d.FindSubset(bv.v1), d.FindSubset(bv.v2) );
			newn[t].v1 = bv.v1;
			newn[t].v2 = bv.v2;
			newn[t].key = bv.key;
			t++;
		}
		l++;
		q->Pop();
	} cout << endl;
	cout << "Минимальное остовное дерево: " << endl; 
	for(int i=0; i<t; i++)
		cout << "v1: " << newn[i].v1 << "  v2: " << newn[i].v2 << "  ves: " << newn[i].key << endl;
	delete [] newn;
}

template <class KeyT>
void Algorithm<KeyT>:: Dijkstr(Graph<KeyT> &g1, KeyT*& dist, int*& up)
{
	int r0 = 0;
	dist[r0] = 0;
	while (r0<g1.gsize)
	{
		for(int i=0; i<g1.gsize;i++)
		{
			if((i==r0) || /*(g1.edge[i][r0]==0) ||*/ (g1.edge[i][r0]==-1))
				continue;

			KeyT k=dist[i], r=dist[r0], f=g1.edge[i][r0];
			KeyT delta = k - (r + f);
			if (delta>0)
			{
				dist[i] = r+f;	//dist[i] - delta;
				g1.edge[i][i] = dist[i];
				up[i] = r0;
			}
			
			g1.edge[r0][i] = -1;
			//пошагово
			/*int size = g1.gsize;
			for(int i=0; i<size; i++)
				cout << dist[i] << " ";
			cout << endl;
			g1.Print();
			cout << endl;
			for(int i=0; i<size; i++)
				cout << up[i] << " ";
			cout << endl;*/
		}
		r0++;
	}
}