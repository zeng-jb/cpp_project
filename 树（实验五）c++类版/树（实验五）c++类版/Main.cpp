#include"Tree.h"
void menu() {
	cout << "\t\t1�� �� abc.txt �ļ������ݵ��������С�\n\
		2�� ������Ҵ��������ĺ������洢�ṹ��\n\
		3�� �������ű�ʾ���������\n\
		4�� ������ѧԺ��רҵ����\n\
		5�� ������ѧԺ�İ�����\n\
		6�� �����ѧԺ��ѧ������\n\
		7�� ����������\n\
		�������˳���"<< endl;
}
void main() {

	Tree<char>T;								//����Ϊchar����
	menu();
	int i;

	while (1)
	{
		cout << "�����������ţ�" << endl;
		cin >> i;
		switch (i)
		{
		case 1:
			T.readFile();						//��abc.txt�ж�ȡ��R������
			cout << "���ļ���ȡ�ɹ���" << endl;
			break;
		case 2:
			T.createTree();						//������Rд����
			cout << "�����ɹ���" << endl;
			break;
		case 3:
			cout<<"�����ʽ���" << endl;
			T.displayTree();					//�����
			cout << endl;
			break;
		case 4:
			cout << "�����ѧԺ��רҵ��Ϊ��";
			cout << T.sonNum() << endl;			//�����רҵ��
			break;
		case 5:
			cout << "�����ѧԺ�İ���Ϊ��";
			cout << T.classNum() << endl;		//�����ѧԺ�༶
			break;
		case 6:
			cout << "����ѧԺ��ѧ����Ϊ��";
			cout << T.studentNum() << endl;		//����ѧԺѧ��
			break;
		case 7:
			T.destroyTree();					//������
			cout << "���ٳɹ�~��" << endl;
			break;
		default:
			exit(0);							//������ֹ����
		}
	}
}