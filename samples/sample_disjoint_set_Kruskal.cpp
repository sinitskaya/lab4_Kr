#include "disjoint_set.h"
#include "graph.hpp"
#include "queue.hpp"
#include "kruskal.hpp"
#include "sample_kruscal_primer_func.h"

int main()
{
	try{
	setlocale(0,"");
	Graph<type> g1(8);
	int s = ((g1.gsize*g1.gsize));
	Node<type> **v = new Node<type>*[s];
	int k = 0;

	int r2 = -1;
	cout << "�������: �� ���� - 0"<< endl << "�� ��������� �������� - 1"<< endl << "�� �������� - 2"<< endl;
	cin >> r2;

	int r1 = -1;
	cout << "���������������� ���� - 0"<< endl << "������ - 1"<< endl;
	cin >> r1;
	if (r1 == 0)		//���������������� ����
	{
		Graph<type> g2(1,1,1);
		g1 = g2;
	}
	if (r1 == 1)		//������
	{
		Graph<type> g2(8);
		Primer(g2);
		g1 = g2;
	}
	////////////////////////////////////
	cout << "������� ���������:" << endl;
	g1.Print();
	cout << endl;
	node(g1,v,k);
	if(r2==2)
		{sort(k,v);}

	Queue<type> *q;
	Choose_Queue<type>:: choose_Queue(q,k,v,r2);
	Algorithm<type>::Kruskal(g1,q);
	system("pause");
	}

	catch(exception &e)
	{
		cout << e.what() << endl;
		//system("pause");
		return 0;
	}
	return 0;
}