#include "graph.hpp"
#include "queue.hpp"
#include "kruskal.hpp"
#include "sample_kruscal_primer_func.h"
int main()
{
	try{
	setlocale(0,"");
	Graph<type> g1(8);

	int r1 = -1;
	cout << "Пользовательский ввод - 0"<< endl << "Пример - 1"<< endl;
	cin >> r1;
	if (r1 == 0)		//Пользовательский ввод
	{
		Graph<type> g2(1,1,1);
		g1 = g2;
	}
	if (r1 == 1)		//Пример
	{
		Graph<type> g2(8);
		Primer(g2);
		g1 = g2;
	}
	
	cout << "Матрица смежности:" << endl;
	g1.Print();//

	int size = g1.gsize;
	int *up = new int[size];
	type *dist = new type[size];

	for (int i=0; i<size; i++)
		up[i] = -1; 
	
	for(int i=0; i<size; i++)
		dist[i] = INT_MAX;//

	Algorithm<type>::Dijkstr(g1, dist, up);
	//Вывод
	cout << endl;
	cout << "Вывод алгоритма Дейкстра:" << endl;
	
	g1.Print();
	cout << endl;
	
	cout << "dist: ";
	for(int i=0; i<size; i++)
			cout << dist[i] << " ";
	cout << endl;

	cout << "up: ";
	for(int i=0; i<size; i++)
		cout << up[i] << " ";
	cout << endl;
	
	/*cout << "edge[i][i]: ";
	for(int i=0; i<size; i++)
		cout << g1.edge[i][i] << " ";
		*/
	cout << endl;
	system("pause");
	}
	catch(exception &e)
	{
		cout << e.what() << endl;
		system("pause"); 
		return 0;
	}
	return 0;
}