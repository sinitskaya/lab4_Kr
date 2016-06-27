#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Disjoint_set
{
private:
	int *h;            //����-������ ���������, ������ �������� �������� ���� x
	int *p;            //�������� ��� ���� x
	int maxsize;       //���� ��� ��������� � ���������(��������)
public:
	Disjoint_set();
	Disjoint_set(int s);
	~Disjoint_set();

	void CreateSingleton(const int x);  //�������� ���������
	void Union(int x, int y);           //����������� ��������
	int FindSubset(int x);              //��� ���������, �������� ����������� x
	void Errors(int x);                 //exceptions
	int GetMaxsize();
	void Print();
};