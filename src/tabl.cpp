#include "disjoint_set.h"
//реализаци€ с использованием древесной структуры с рангами

Disjoint_set:: Disjoint_set()
{
	maxsize = 10;
	p = new int[maxsize];
	h = new int[maxsize];
	for(int i=0; i<maxsize; i++)
	{
		p[i] = -1;
		h[i] = -1;
	}
}

Disjoint_set:: Disjoint_set(int s)
{
	if (s<0)
		throw exception ("size<0");

	maxsize = s;
	p = new int[maxsize];
	h = new int[maxsize];
	for(int i=0; i<maxsize; i++)
	{
		p[i] = -1;
		h[i] = -1;
	}
}

void Disjoint_set:: CreateSingleton(const int x) //создание синглтона
{
	if(x<0)
		throw exception ("CreateSingleton: x<0");
	if (x>maxsize-1)
		throw exception ("Out of range");

	p[x] = x;
	h[x] = 0;
}

void Disjoint_set:: Errors(int x)
{
	if(x<0)
		throw exception ("x<0 or y<0");
	if (x>maxsize-1)
		throw exception ("Out of range");
	if (p[x]==-1)
		throw exception ("Elemet doesnt exist in set");
}

void Disjoint_set:: Union(int x, int y)           //обьединение подмножеств
{//присоедин€ем x-родитель, у-потомок
	/*if((x<0) || (y<0))
		throw exception ("x<0 or y<0");
	if ((x>maxsize-1) || (y>maxsize-1))
		throw exception ("Out of range");
	if ((p[x]==-1) || (p[y]==-1))
		throw exception ("Elemet doesnt exist in set");
	int res = 0;
	for(int i=0; i<maxsize; i++)
		if (i==p[i])
			if((x==i))
				{
					res = 1;
					break;
				}
	if (res==0)
		throw exception ("Subset doesnt exist");*/
	Errors(x); Errors(y);
	int res = 0; //проверка существовани€ подмножеств
	for(int i=0; i<maxsize; i++)
		if (i==p[i])
			if((x==i))
				{
					res = 1;
					break;
				}
	if (res==0)
		throw exception ("Subset doesnt exist");
	//////////
	if(h[x]>h[y]){
		p[y] = x;//x больше по высоте - будет родителем другого
		//cout << "–одитель " << x << endl;
	}
	else
		if(h[x]<h[y]){
			p[x] = y;
			//cout << "–одитель " << y << endl;
		}
		else
		{
			p[y] = x;
			h[x]++;
			//cout << "–одитель " << x << endl;
		}
}

int Disjoint_set:: FindSubset(int x)     //им€ множества, которому принадлежит x
{
	Errors(x);
	int i = x, c = -1;
	if (p[x]!=x)
		while (i!=p[i])
		{
			c = p[i];
			i = p[c];
		}
	return i;
}

void Disjoint_set:: Print()
{
	//cout << "3"<<setw(15) << right << "cppstudio.com" << "1" <<endl;
	cout << "       0 1 2 3 4 5 6 7 8 9"<< endl;
	cout << "P[x]: ";
	for (int i=0; i<maxsize; i++)
		cout << p[i] << " ";
	cout << endl;
	cout << "H[x]: ";
	for (int i=0; i<maxsize; i++)
		cout << h[i] << " ";
}

int Disjoint_set:: GetMaxsize(){
	return maxsize;
}

Disjoint_set:: ~Disjoint_set()
{
	delete[] p;
	delete[] h;
	cout << "disjoint_set delete";
}