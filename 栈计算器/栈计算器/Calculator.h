#pragma once
#include<iostream>
#include<math.h>
#include<stack>
using namespace std;
class Calculator {
public:
	Calculator(int sz):s(sz){}
	void Run();
	void Clear();
private:
	stack<double>s;
	void AddOperand(double value);
	bool get2Operands(double& left, double& right);
	void DoOperator(char op);
};

void Calculator::DoOperator(char op) {
	double left, right, value;
	int result;
	result = get2Operands(left, right);
	if (result == true) {
		switch (op)
		{
		case '+':value = left + right; s.push(value); break;
		case '-':value = left - right; s.push(value); break;
		case '*':value = left * right; s.push(value); break;
		case '/':if (right == 0.0) {
			cerr << "被除数为0!" << endl;
			Clear();
		}
				else
		{
				value = left / right; s.push(value); 
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

bool Calculator::get2Operands(double& left, double& right) {
	if (s.empty() == true) {
		cerr << "缺少右操作数！" << endl;
		return false;
	}
	s.pop(right);

	if (s.empty() == true) {
		cerr << "缺少左操作数！" << endl;
		return false;
	}
	s.pop(left);

	return true;
}

void Calculator::AddOperand(double value) {
	s.push(value);
}

void Calculator::Run() {
	char ch;
	double newOperand;
	while (cin >> ch, ch != '#') {
		switch (ch)
		{
		case'+':
		case'-':
		case'*':
		case'/':
			DoOperator(ch); break;
		default:
			cin.putback(ch);
			cin >> newOperand;
			AddOperand(newOperand);
			break;
		}
	}
}

void Calculator::Clear() {
	s.empty();
}