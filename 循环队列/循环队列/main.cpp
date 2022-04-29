#include<iostream>
#include"SeqQueue.h"

using namespace std;
void main() {
	SeqQueue<int>Q(10);
	for (int i = 1; i <= 10; i++) {
		Q.EnQueue(i);
	}
	cout << Q << endl;

	int x;

	Q.getFront(x);
	cout << x << endl;

	x = Q.getSize();
	cout << x << endl;

	Q.makeEmpty();
	cout << Q << endl;

}