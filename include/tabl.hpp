#pragma once
#include "bin_Search_tree.hpp"
typedef int VT;

template <class KeyT>
class TabRecord
{
public:
	Node<KeyT>* data;   //������
	VT key;				//������������� ������
	TabRecord (VT key1, Node<KeyT> *n);
	VT GetKey(void) const;			//��� ����� ���������(�������) ����� ves
	Node<KeyT>* GetData(void) const;		//�������� ������
	//friend class SortTable_Queue;
	//friend class SortTable;
	//friend class ScanTable;
};

template <class KeyT>
TabRecord<KeyT>:: TabRecord (VT key1, Node<KeyT> *n)
{
	key = key1;
	data = new Node<KeyT>(n->e.key);
	data->e.v1 = n->e.v1;
	data->e.v2 = n->e.v2;
}

template <class KeyT>
VT TabRecord<KeyT>:: GetKey(void) const			//��� ����� ���������(�������) ����� ������(ves)
{
	return key;
}

template <class KeyT>
Node<KeyT>* TabRecord<KeyT>:: GetData(void) const		//�������� ������
{
	return data;
}
////////////////////////////////////////////////////////////////////////////////////////////
template <class KeyT>
class Table
{
protected:
	int pos;	//�������
	int size;	//������ ����
	int count;	//��� ������� �������

public: 
	Table(int maxsize);
	Table();
	virtual TabRecord<KeyT>* Search (VT key1)=0;  //����� � �������� ������
	virtual void Insert(VT key1, Node<KeyT>* n)=0;
	virtual void Delete(VT key1)=0;
	int GetCount(void) const;		//��������� �������� ���-�� ������� ������� � ������� 
	virtual int GetNext(void);		//������� �� ���� ������
	virtual void Reset(void);		//������� �� ������ �������
	int IsEmpty(void) const;
	int IsFull(void) const;
	virtual int IsTablEnded(void) const;	//����� �� �������
	////////////////////////////////////////////////////
	int GetSize();		//�������� ������ �������
};

template <class KeyT>
int Table<KeyT>:: GetSize()
{
	return size;
}
template <class KeyT>
Table<KeyT>:: Table(int maxsize)
{
	if(maxsize <=0)
		throw exception ("maxsize<0");
	size = maxsize;
	pos = 0;
	count = 0;
}

template <class KeyT>
Table<KeyT>:: Table()
{
	size = 10;
	pos = 0;
	count = 0;
}

template <class KeyT>
int Table<KeyT>:: IsEmpty(void) const
{
	if (count==0){
		cout << "IsEMPTYY"<<endl;
		return 1;
	}
	return 0;
}

template <class KeyT>
int Table<KeyT>:: IsFull(void) const
{
	if (size==count){			//( = ��� �������)
		cout << "IsFULLL"<<endl;
		return 1;
	}
	return 0;
}

template <class KeyT>
int Table<KeyT>:: GetCount(void) const		//��������� �������� ���-�� ������� ������� � ������� 
{
	return count;
}

template <class KeyT>
void Table<KeyT>:: Reset(void)				//������� �� ������ �������
{
	pos = 0;
}

template <class KeyT>
int Table<KeyT>:: GetNext(void)				//������� �� ���� ������
{
	if(IsTablEnded())
		return 0;
	return pos++;
}

template <class KeyT>
int Table<KeyT>:: IsTablEnded(void) const			//����� �� �������
{
	if (pos==count)
		return 1;
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////
template <class KeyT>
class ScanTable: public Table<KeyT>
{
protected:
	TabRecord<KeyT>** recs;
public:
	ScanTable(int maxsize);///
	ScanTable();
	virtual TabRecord<KeyT>* Search(VT key1);
	virtual void Insert(VT key1, Node<KeyT> *n);
	virtual void Delete(VT key1);
	void print();
	virtual ~ScanTable();
	//friend class SortTable;
	//friend class SortTable_Queue;
};

template <class KeyT>
ScanTable<KeyT>:: ScanTable(int maxsize):Table (maxsize)
{
	if(maxsize<=0)
		throw exception("size<=0");
	recs = new TabRecord<KeyT>*[maxsize];
	for (int i = 0; i < size; i++)
			recs[i] = 0;
}

template <class KeyT>
ScanTable<KeyT>:: ScanTable(): Table()
{
	recs = new TabRecord<KeyT>*[10];
}
template <class KeyT>
ScanTable<KeyT>:: ~ScanTable()
{
	for (int i = 0; i < size; i++)
		delete recs[i];
	delete[]recs;
}

template <class KeyT>
TabRecord<KeyT>* ScanTable<KeyT>:: Search(VT key1)
{
	for (int i=0; i<count; i++)
		if(key1 == recs[i]->GetKey())
		{
			pos = i;
			return recs[i];
		}
	return 0;
}

template <class KeyT>
void ScanTable<KeyT>:: Insert(VT key1, Node<KeyT>* n)
{
	if(IsFull())
	{
		cout<< "full"<< endl;
		return;
	}
	recs[count] = new TabRecord<KeyT>(key1, n);
	count++;
}

template <class KeyT>
void ScanTable<KeyT>:: Delete(VT key1)
{
	if(Search(key1) == 0)
		return;			//pos=i
	delete recs[pos];
	recs[pos] = recs[count-1];
	count--;
}

template <class KeyT>
void ScanTable<KeyT>:: print()
{
	for(int i=0; i<count; i++)
	{
		cout <<"v1: "<<recs[i]->data->e.v1 << "; v2: "<<recs[i]->data->e.v2<< "; ves: " <<recs[i]->data->e.key<< endl;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class KeyT>
class SortTable: public ScanTable<KeyT>
{
public:
	SortTable(){};
	~SortTable();
	SortTable(int maxsize): ScanTable(maxsize){};
	SortTable(const ScanTable<KeyT> &table);

	TabRecord<KeyT>* GetMin();						//��������� ������ ������(min ves) � ��������������� ����

	TabRecord<KeyT>* Search(VT key1); //virtual
	virtual void Insert (VT key, Node<KeyT> *n);
	virtual void Delete(VT key);
	void SortData();
};

template <class KeyT>
SortTable<KeyT>:: SortTable(const ScanTable<KeyT>& table)
{
	size = table.size;	
	pos = 0;
	count = table.count;
	recs = new TabRecord<KeyT>*[size];
	for (int i=0; i<count; i++)
		recs[i] = new TabRecord<KeyT>(table.recs[i]->GetKey(), table.recs[i]->GetData());
	SortData();
}
template <class KeyT>
SortTable<KeyT>:: ~SortTable()
{
	for (int i = 0; i < size; i++)
		delete recs[i];
	delete[]recs;
}

template <class KeyT>
void SortTable<KeyT>:: Insert (VT key, Node<KeyT> *n)
{
	if(IsFull())
		return;
	Search(key);
	for(int i=count+1; i>=pos+1; i--)
		recs[i] = recs[i-1];
	count++;
	recs[pos] = new TabRecord<KeyT>(key, n);
}

template <class KeyT>
TabRecord<KeyT>* SortTable<KeyT>:: Search(VT key1)
{
	int left = 0;
	pos=0;
	int right = count-1;
	int mid;
	while(left<=right)
	{
		mid = left+(right-left)/2;
		if (key1<recs[mid]->GetKey())
		{
			right = mid-1;
			pos = left;
		}
		else if (key1>recs[mid]->GetKey())
		{
				left = mid+1;
				pos = left;
		}
		else
		{
			pos = mid;
			return recs[mid];
		}
	}
	return 0;
}

template <class KeyT>
void SortTable<KeyT>:: SortData()         //���������� �� ������
{
	for(int i=0; i<count; i++)
		for(int j=i+1; j<count; j++)
			if(recs[i]->key > recs[j]->key)
			{
				TabRecord<KeyT>* tmp = recs[i];
				recs[i] = recs[j];
				recs[j] = tmp;
			}
}

template <class KeyT>
TabRecord<KeyT>* SortTable<KeyT>:: GetMin()		//��������� ������ ������(min ves) � ��������������� ����
{
	return recs[0];
}

template <class KeyT>
void SortTable<KeyT>:: Delete(VT key)
{
	if (IsEmpty())
		return;
	if (Search(key)==0)
		throw exception("Such element doesn't exist");
	for (int i = pos; i < count - 1; i++)
		recs[i] = recs[i + 1];
	recs[count] = NULL;
	count--;
}