#pragma once
#include<iostream>
#include"LinkedStack.h"
#include<math.h>
#include<string>
#include<ctype.h>
using namespace std;



//ջ�ڲ��������ȼ�
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

//ջ����������ȼ�
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

void postifix(string &str) {               //ZZ��׺ת��׺���㷨
	char ch = '#', ch1, op;                 //������ch #�Ƚ�ջ
	int i = 0,j=0;
	LinkedStack<char>s;                     //����char���͵���ʽջ
	
		s.Push(ch);                        //#��ջ
		ch = str[i++];                      //��ȡ��һ���ַ�
		while (s.IsEmpty() == false && ch != '#') {                //ջ��Ϊ���Ҳ�������Ϊ# ������ȡ
			if (isdigit(ch)) {                                    //Ϊ��������ֱ�����
				cout << ch;
				ch = str[i++];
			}
			else {
				s.getTop(ch1);                                  //ȡջ���ַ�
				if (isp(ch1) < icp(ch)) {                         //���վ�ڲ��������ȼ�����ջ�⣬��ջ���������ջ������ȡ��һ��
					s.Push(ch); 
					ch = str[i++];
				}
				else if (isp(ch1) > icp(ch)) {                    //���ջ�ڲ��������ȼ�����ջ�⣬��ֱ�ӵ���ջ�����
					s.Pop(op);
					cout << op;
					
				}
				else if(isp(ch1)==icp(ch)){                      //������ȼ���ͬ���򵯳�ջ�������Ϊ�����ȡ��һ��
					s.Pop(op);
					if (op == '(')ch = str[i++];
				}
			}
		}

}