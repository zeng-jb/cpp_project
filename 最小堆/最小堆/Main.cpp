#include"heap.h"

typedef struct Message 
{ 
	char Msg[11];     
	int P;
	friend bool operator >(Message a, Message b)  {
		return a.P > b.P;
	}
	
} ElementType;

//typedef struct HeapStruct* Minheap;
//
//struct HeapStruct
//{ 
//	ElementType* Elements;    
//	int Size; 
//};
void main() {
	
	MinHeap<Message, Message>M;
//	Minheap H;
	ElementType X;
	string ch;
	int n,i=0;
	cin >> n;

	while (n--)
	{
		cin >> ch;
		if (ch == "PUT") {
			cin >> X.Msg >> X.P;
			M.Insert(X);
		}
		else if (ch == "GET") {
			if (M.IsEmpty()) {
				cout << "EMPTY QUEUE!" << endl;
				exit(1);
			}
			else {
				M.RemoveMin(X);
				cout << X.Msg << endl;
			}
		}
	}
}