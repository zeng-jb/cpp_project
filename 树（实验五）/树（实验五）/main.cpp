#include"Tree.h"
#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
    TSonNode* t;
    RecType R[MAX_SIZE];
    int n;                                                      // 记录个数

    printf("(1)从abc.txt文件读取数据到R数组中\n");
    read_file(R, n);
    if (n == 0)                                                  // 记录个数为0时直接返回
        return -1;
    printf("(2)由数组R创建树t的孩子链存储结构\n");
    t = create_tree(R[0].fname, R, n);                          // 创建一颗树
    printf("(3)输出树t:");
    disp_tree(t);
    printf("\n");
    char ch[20] = { "计算机学院" };
    printf("(4)求计算机学院的专业数:%d\n", son_num(t, ch));
    printf("(5)求计算机学院的班数:%d\n", class_num(t, ch));
    printf("(6)求计算机学院的学生数:%d\n", stu_num(t, ch));
    char ch1[20] = { "电信学院" };
    printf("(电信学院的学生数:%d\n", stu_num(t, ch1));
    printf("(7)销毁树t\n");
    destroy_tree(t);

    return 0;
}