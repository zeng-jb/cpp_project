
//
//三、设计性实验（提交源代码和结果视频）
//
//算数表达式的计算
//
//输入格式 : 一行一个算术表达式，可以输入若干行
//
//输出格式 : 一行一个输出结果
//
//输入样例 :
//
//2 * （3 + 4）
//
//6 + 2 * 8 / 4
//
//输出样例
//
//14
//
//10
//整形操作数
#include <iostream>
#include <stack>

using namespace std;

int Priority(char ch)               //操作符优先级
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
	stack<int> stack_num;     //保存操作数
	stack<char> stack_opt;    //保存操作符
	int i = 0, tmp = 0;
	char option;
	int num1, num2;


		cout << "请输入中缀表达式（#退出） : " << endl;
		cin >> opt;
		if (opt[i] == '#')break;                                  //如果输入#则退出循环

		while (opt[i] != '\0' || stack_opt.empty() != true)         //判断栈内元素及空否
		{
			if (opt[i] >= '0' && opt[i] <= '9')     //操作数进栈
			{
				tmp = tmp * 10 + opt[i] - '0';      //对字符串转化数值进行操作
				i++;
				if (opt[i] < '0' || opt[i] > '9')   //如果不是数
				{
					stack_num.push(tmp);            //进栈
					tmp = 0;                        //清空
				}
			}
			else                                   //操作符运算
			{
				if (stack_opt.empty() || (stack_opt.top() == '(' && opt[i] != ')') ||
					Priority(opt[i]) > Priority(stack_opt.top()))   //操作符进栈
				{
					stack_opt.push(opt[i]);                       //字符进栈
					i++;
					continue;                                    //继续往下扫描
				}

				if (stack_opt.top() == '(' && opt[i] == ')')   //操作符出栈不计算
				{
					stack_opt.pop();                              //出栈
					i++;
					continue;
				}

				if ((opt[i] == '\0' && stack_opt.empty() != true) ||          //扫描完毕
					opt[i] == ')' && stack_opt.top() != '(' ||
					Priority(opt[i]) <= Priority(stack_opt.top()))  //出栈 计算
				{
					option = stack_opt.top();                          //栈顶
					stack_opt.pop();                                    //出栈
					switch (option)
					{
					case '+':
						num1 = stack_num.top();                       //得到左操作数并出栈
						stack_num.pop();
						num2 = stack_num.top();                       //得到右操作数并出栈
						stack_num.pop();
						stack_num.push(num1 + num2);                  //计算并进栈
						break;
					case '-':                                        //以下同理
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

		cout << "计算的结果 : " << stack_num.top() << endl;
	}
	return 0;
}