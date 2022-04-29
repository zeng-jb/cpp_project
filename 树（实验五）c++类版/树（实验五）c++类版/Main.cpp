#include"Tree.h"
void menu() {
	cout << "\t\t1） 从 abc.txt 文件读数据到Ｒ数组中。\n\
		2） 由数组Ｒ创建树ｔ的孩子链存储结构。\n\
		3） 采用括号表示输出树ｔ。\n\
		4） 求计算机学院的专业数。\n\
		5） 求计算机学院的班数。\n\
		6） 求电信学院的学生数。\n\
		7） 求销毁树。\n\
		其他）退出。"<< endl;
}
void main() {

	Tree<char>T;								//类型为char的类
	menu();
	int i;

	while (1)
	{
		cout << "请输入操作序号：" << endl;
		cin >> i;
		switch (i)
		{
		case 1:
			T.readFile();						//从abc.txt中读取到R数组中
			cout << "从文件读取成功！" << endl;
			break;
		case 2:
			T.createTree();						//从数组R写入树
			cout << "创建成功！" << endl;
			break;
		case 3:
			cout<<"广义表方式输出" << endl;
			T.displayTree();					//输出树
			cout << endl;
			break;
		case 4:
			cout << "计算机学院的专业数为：";
			cout << T.sonNum() << endl;			//计算机专业数
			break;
		case 5:
			cout << "计算机学院的班数为：";
			cout << T.classNum() << endl;		//计算机学院班级
			break;
		case 6:
			cout << "电信学院的学生数为：";
			cout << T.studentNum() << endl;		//电信学院学生
			break;
		case 7:
			T.destroyTree();					//销毁树
			cout << "销毁成功~！" << endl;
			break;
		default:
			exit(0);							//其他中止操作
		}
	}
}