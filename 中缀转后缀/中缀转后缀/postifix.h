#pragma once
#include<iostream>
#include"LinkedStack.h"
#include<math.h>
#include<string>
#include<ctype.h>
using namespace std;



//栈内操作符优先级
int isp(char op) {
	switch (op)
	{
	case '#':return 0;
	case '(':return 1;
	case '*':
	case '/':
	case '%':return 5;
	case '+':
	case '-':return 3;
	case ')':return 6;
	default:
		break;
	}
}

//栈外操作符优先级
int icp(char ch) {
	switch (ch)
	{
	case '#':return 0;
	case '(':return 6;
	case '*':
	case '/':
	case '%':return 4;
	case '+':
	case '-':return 2;
	case ')':return 1;
	default:
		break;
	}
}

void postifix(string &str) {               //ZZ中缀转后缀的算法
	char ch = '#', ch1, op;                 //操作符ch #先进栈
	int i = 0,j=0;
	LinkedStack<char>s;                     //定义char类型的链式栈
	
		s.Push(ch);                        //#进栈
		ch = str[i++];                      //读取下一个字符
		while (s.IsEmpty() == false && ch != '#') {                //栈不为空且操作符不为# 继续读取
			if (isdigit(ch)) {                                    //为操作数则直接输出
				cout << ch;
				ch = str[i++];
			}
			else {
				s.getTop(ch1);                                  //取栈顶字符
				if (isp(ch1) < icp(ch)) {                         //如果站内操作符优先级低于栈外，则将栈外操作符进栈，并读取下一个
					s.Push(ch); 
					ch = str[i++];
				}
				else if (isp(ch1) > icp(ch)) {                    //如果栈内操作符优先级高于栈外，则直接弹出栈并输出
					s.Pop(op);
					cout << op;
					
				}
				else if(isp(ch1)==icp(ch)){                      //如果优先级相同，则弹出栈不输出，为（则读取下一个
					s.Pop(op);
					if (op == '(')ch = str[i++];
				}
			}
		}

}