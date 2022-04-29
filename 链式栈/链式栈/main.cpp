#include<iostream>
#include <cstring>
#include"LinkedStack.h"
using namespace std;



void main() {

	LinkedStack<char> s;
	string str;
	cin >> str;
	s.PrintMatchedPairs(str);
	/*for(int i=0;str[i]!='\0';i++)
	s.Push(str[i]);*/
	cout << s;
	system("pause");

	
}