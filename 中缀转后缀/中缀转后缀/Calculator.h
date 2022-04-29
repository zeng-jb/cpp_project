#pragma once
#include<iostream>
#include<math.h>
#include<string>
#include"LinkedStack.h"
#include"postifix.h"
using namespace std;
class Calculator {
public:
	Calculator();
	void Run();
	void Clear();
private:
	LinkedStack<int>s;
	void AddOperand(int value);
	bool get2Operands(int& left, int& right);
	void DoOperator(char op);

};

Calculator::Calculator() {

}

void Calculator::DoOperator(char op) {
	int left, right, value;
	int result;
	result = get2Operands(left, right);
	if (result == true) {
		switch (op)
		{
		case '+':value = left + right; s.Push(value); break;
		case '-':value = left - right; s.Push(value); break;
		case '*':value = left * right; s.Push(value); break;
		case '/':if (right == 0.0) {
			cerr << "������Ϊ0!" << endl;
			Clear();
		}
				else
		{
				value = left / right; s.Push(value); 
		}
			break;
		default:
			break;
		}
	}
	else {
		Clear();
	}
}

bool Calculator::get2Operands(int& left, int& right) {
	if (s.IsEmpty() == true) {
		cerr << "ȱ���Ҳ�������" << endl;
		return false;
	}
	s.Pop(right);

	if (s.IsEmpty() == true) {
		cerr << "ȱ�����������" << endl;
		return false;
	}
	s.Pop(left);

	return true;
}

void Calculator::AddOperand(int value) {
	s.Push(value);
}

void Calculator::Run() {
	char ch;
	string str;
	int i = 0;
	int newOperand=0;

	cout << "��������׺���ʽ��" << endl;
	cin >> str;
	cout << "��׺���ʽ��" << endl;
	postifix(str);
	cout << endl;
	ch = str[i];
	while (ch!='\0') {
		
		if (ch >= '0' && ch <= '9') {
			newOperand=newOperand*10+int(ch-'48');
			if (str[i + 1] < '0' || str[i + 1]>'9') { AddOperand(newOperand); newOperand = 0; };
		}
		else {
			switch (ch)
			{
			case'+':
			case'-':
			case'*':
			case'/':
				DoOperator(ch); break;
			default:
				break;
			}
		}
		ch = str[++i];
	}
}

void Calculator::Clear() {
	s.makeEmpty();
}