
//
//���������ʵ�飨�ύԴ����ͽ����Ƶ��
//
//�������ʽ�ļ���
//
//�����ʽ : һ��һ���������ʽ����������������
//
//�����ʽ : һ��һ��������
//
//�������� :
//
//2 * ��3 + 4��
//
//6 + 2 * 8 / 4
//
//�������
//
//14
//
//10
//���β�����
#include <iostream>
#include <stack>

using namespace std;

int Priority(char ch)               //���������ȼ�
{
	switch (ch)
	{
	case '(':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}

int main()
{
	while (true) {

	char opt[100] = { 0 };
	stack<int> stack_num;     //���������
	stack<char> stack_opt;    //���������
	int i = 0, tmp = 0;
	char option;
	int num1, num2;


		cout << "��������׺���ʽ��#�˳��� : " << endl;
		cin >> opt;
		if (opt[i] == '#')break;                                  //�������#���˳�ѭ��

		while (opt[i] != '\0' || stack_opt.empty() != true)         //�ж�ջ��Ԫ�ؼ��շ�
		{
			if (opt[i] >= '0' && opt[i] <= '9')     //��������ջ
			{
				tmp = tmp * 10 + opt[i] - '0';      //���ַ���ת����ֵ���в���
				i++;
				if (opt[i] < '0' || opt[i] > '9')   //���������
				{
					stack_num.push(tmp);            //��ջ
					tmp = 0;                        //���
				}
			}
			else                                   //����������
			{
				if (stack_opt.empty() || (stack_opt.top() == '(' && opt[i] != ')') ||
					Priority(opt[i]) > Priority(stack_opt.top()))   //��������ջ
				{
					stack_opt.push(opt[i]);                       //�ַ���ջ
					i++;
					continue;                                    //��������ɨ��
				}

				if (stack_opt.top() == '(' && opt[i] == ')')   //��������ջ������
				{
					stack_opt.pop();                              //��ջ
					i++;
					continue;
				}

				if ((opt[i] == '\0' && stack_opt.empty() != true) ||          //ɨ�����
					opt[i] == ')' && stack_opt.top() != '(' ||
					Priority(opt[i]) <= Priority(stack_opt.top()))  //��ջ ����
				{
					option = stack_opt.top();                          //ջ��
					stack_opt.pop();                                    //��ջ
					switch (option)
					{
					case '+':
						num1 = stack_num.top();                       //�õ������������ջ
						stack_num.pop();
						num2 = stack_num.top();                       //�õ��Ҳ���������ջ
						stack_num.pop();
						stack_num.push(num1 + num2);                  //���㲢��ջ
						break;
					case '-':                                        //����ͬ��
						num1 = stack_num.top();
						stack_num.pop();
						num2 = stack_num.top();
						stack_num.pop();
						stack_num.push(num2 - num1);
						break;
					case '*':
						num1 = stack_num.top();
						stack_num.pop();
						num2 = stack_num.top();
						stack_num.pop();
						stack_num.push(num1 * num2);
						break;
					case '/':
						num1 = stack_num.top();
						stack_num.pop();
						num2 = stack_num.top();
						stack_num.pop();
						stack_num.push(num2 / num1);
						break;
					}
				}
			}
		}

		cout << "����Ľ�� : " << stack_num.top() << endl;
	}
	return 0;
}