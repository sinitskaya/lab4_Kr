#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Disjoint_set
{
private:
	int *h;            //ранг-высота поддерева, корнем которого является узел x
	int *p;            //родитель для узла x
	int maxsize;       //макс кол элементов в множестве(мощность)
public:
	Disjoint_set();
	Disjoint_set(int s);
	~Disjoint_set();

	void CreateSingleton(const int x);  //создание синглтона
	void Union(int x, int y);           //обьединение множеств
	int FindSubset(int x);              //имя множества, которому принадлежит x
	void Errors(int x);                 //exceptions
	int GetMaxsize();
	void Print();
};