#pragma once
#include <iostream>
#include "graph.hpp"
typedef float type;
using namespace std;

void Primer(Graph<type> & g2)
{
			//Graph<type> g2(8);
			//g2.Print();
			g2.edge[0][1] = 2;
			g2.edge[0][2] = 1;
			g2.edge[0][3] = 0;
			g2.edge[0][4] = 5;
			g2.edge[0][5] = -1;
			g2.edge[0][6] = -1;
			g2.edge[0][7] = -1;
	
			g2.edge[1][2] = 2;
			g2.edge[1][3] = -1;
			g2.edge[1][4] = 2;
			g2.edge[1][5] = 3;
			g2.edge[1][6] = -1;
			g2.edge[1][7] = -1;
	
			g2.edge[2][3] = -1;
			g2.edge[2][4] = 4;
			g2.edge[2][5] = -1;
			g2.edge[2][6] = -1;
			g2.edge[2][7] = -1;

			g2.edge[3][4] = 3;
			g2.edge[3][5] = -1;
			g2.edge[3][6] = 8;
			g2.edge[3][7] = -1;

			g2.edge[4][5] = 1;
			g2.edge[4][6] = -1;
			g2.edge[4][7] = 4;

			g2.edge[5][6] = 7;
			g2.edge[5][7] = 2;

			g2.edge[6][7] = 5;
		
			for(int i=0; i<g2.gsize; i++)
				for(int j=0; j<g2.gsize; j++)
					g2.edge[j][i] = g2.edge[i][j];
			//return g2;
}

void node(Graph<type> &g1, Node<type>**& v1, int & k1)
{
		int s = ((g1.gsize*g1.gsize));
		Node<type> **v = new Node<type>*[s];
		for(int i=0; i<s; i++)
			v[i] = new Node<type>(-1);

		cout << "Список ребер: ";
		int k = 0;
		for(int i=0; i<g1.gsize; i++)
			for(int j=0; j<i; j++)
				if ( (j!=i) && (g1.edge[i][j]!=-1) )
				{
					v[k]->e.key = g1.edge[i][j];
					v[k]->e.v1 = i;
					v[k]->e.v2 = j;
					//cout << g1.edge[i][j] << " " << "= " << v[k]->e.key << "k= "<< k<< endl;
					k++;
				}
		cout << endl;
		v1 = v;
		k1 = k;
		//return v;
}

void sort(int k, Node<type> **& v1)
{
	for(int i=0; i<k; i++)
		for(int j=i+1; j<k; j++)
			if(v1[i]->e.key > v1[j]->e.key)
			{
				Node<type>* tmp = v1[i];
				v1[i] = v1[j];
				v1[j] = tmp;
			}
}