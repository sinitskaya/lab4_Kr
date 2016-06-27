#include "d-heap.hpp"
#include <ctime>
typedef float type;

int main()
{
	try
	{
		setlocale(0,"");
		srand (time(0));
		int r2 = -1, r3 = -1;
		//D_heap<type> h(20,5);

			cout << "¬ведите арность кучи: ";
			cin >> r2;

			cout << "¬ведите кол-во эл-ов: ";
			cin >> r3;

		D_heap<type> h(r3,r2);	
	    h.Print();
		int hsize = h.size;
		for (int i=(h.size-1); i>0; i--)
		{
			h.Swap(0,i);
			h.size--;
			h.siftDown(0);
		}
		h.size = hsize;
		cout << endl << "ќтсортированный: "<< endl; h.PrintMas();
		system("pause");
	}

	catch (exception &e)
	{
		cout << endl << e.what() << endl;
		system("pause");
		return 0;
	}
	return 0;
}