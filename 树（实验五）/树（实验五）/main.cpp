#include"Tree.h"
#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
    TSonNode* t;
    RecType R[MAX_SIZE];
    int n;                                                      // ��¼����

    printf("(1)��abc.txt�ļ���ȡ���ݵ�R������\n");
    read_file(R, n);
    if (n == 0)                                                  // ��¼����Ϊ0ʱֱ�ӷ���
        return -1;
    printf("(2)������R������t�ĺ������洢�ṹ\n");
    t = create_tree(R[0].fname, R, n);                          // ����һ����
    printf("(3)�����t:");
    disp_tree(t);
    printf("\n");
    char ch[20] = { "�����ѧԺ" };
    printf("(4)������ѧԺ��רҵ��:%d\n", son_num(t, ch));
    printf("(5)������ѧԺ�İ���:%d\n", class_num(t, ch));
    printf("(6)������ѧԺ��ѧ����:%d\n", stu_num(t, ch));
    char ch1[20] = { "����ѧԺ" };
    printf("(����ѧԺ��ѧ����:%d\n", stu_num(t, ch1));
    printf("(7)������t\n");
    destroy_tree(t);

    return 0;
}