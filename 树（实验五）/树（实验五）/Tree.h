#pragma once
/**
*    实验题目:
*        大学的数据统计
*    实验目的:
*        掌握树的存储结构，熟练使用树遍历算法进行问题求解
*    实验内容:
*        设计程序，实现大学的数据统计。某大学的数据存放在文本文件abc.txt中。
*    要求采用树的孩子链存储结构存储它，完成如下功能:
*    1、从abc.txt文件读取数据到R数组中
*    2、由数组R创建树t的孩子链存储结构
*    3、采用括号表示输出树t
*    4、求计算机学院的专业数
*    5、求计算机学院的班数
*    6、求电信学院的学生数
*    7、销毁树
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include<fstream>
using namespace std;
#define MAX_SIZE (100)                                          // 最多记录个数
#define MAX_SONS (10)                                           // 最多下级单位数

typedef struct
{
    char fname[20];                                             // 单位名称
    char sname[20];                                             // 下级单位名称或者人数
}RecType;

typedef struct node
{
    char data[20];                                              // 结点的值:单位名称或者人数
    struct node* sons[MAX_SONS];                                // 指向孩子结点
}TSonNode;                                                      // 声明孩子链存储结构结点类型


/*---------------------读abc.txt文件存入R数组中---------------------*/
static void read_file(RecType R[], int& n)
{
    //FILE* fp;
    //n = 0;

    //fopen_s(fp,"abc.txt", "r");
    //if (fp == NULL)
    //{
    //    printf("不能打开文件abc.txt\n");
    //    return;
    //}
    //while (!feof(fp))                                            // 检测流上的文件结束符(文件结束:返回非0值,文件未结束,返回0值)
    //{
    //    fscanf_s(fp, "%s", R[n].fname);                           // 读fname数据
    //    fscanf_s(fp, "%s", R[n].sname);                           // 读sname数据
    //    n++;
    //}

    //fclose(fp);
    n = 0;
    ifstream infile("abc.txt", ios::in | ios::_Nocreate);
    
    if (!infile) { cerr << "open error!" << endl; exit(1); }
    while (!infile.eof())
    {
        infile >> R[n].fname;
        infile >> R[n].sname;
		n++;
    }
}

/*---------------------创建一颗二叉树---------------------*/
static TSonNode* create_tree(char root[], RecType R[], int n)
{
    TSonNode* t;
    int i, j, k;

    t = (TSonNode*)malloc(sizeof(TSonNode));                   // 创建根结点
    strcpy_s(t->data, root);
    for (k = 0; k < MAX_SONS; k++)                               // 结点所有指针域设置为空
    {
        t->sons[k] = NULL;
    }
    i = 0;
    j = 0;
    while (i < n)
    {
        if (strcmp(R[i].fname, root) == 0)                       // 找到fname为root的记录
        {
            t->sons[j] = create_tree(R[i].sname, R, n);         // 递归创建子树
            j++;
        }
        i++;
    }

    return t;
}

/*---------------------输出孩子链存储结构---------------------*/
static void disp_tree(TSonNode* t)
{
    int i;

    if (t != NULL)
    {
        printf("%s", t->data);
        if (t->sons[0] != NULL)                                  // t结点至少有一个孩子
        {
            printf("(");                                        // 输出一个左括号
            for (i = 0; i < MAX_SONS; i++)
            {
                disp_tree(t->sons[i]);
                if (t->sons[i + 1] != NULL)                      // 如果有下一个孩子
                    printf(",");                                // 输出","
                else                                            // 如果没有下一个孩子
                    break;                                      // 退出循环
            }
            printf(")");                                        // 输出一个右括号
        }
    }
}

/*---------------------销毁树t---------------------*/
static void destroy_tree(TSonNode* t)
{
    int i;

    if (t != NULL)
    {
        for (i = 0; i < MAX_SONS; i++)
        {
            if (t->sons[i] != NULL)                              // 有子树
                destroy_tree(t->sons[i]);                       // 销毁子树
            else                                                // 没有子树
                break;                                          // 退出循环
        }
        free(t);                                                // 释放根结点
    }
}

/*---------------------求x结点的指针---------------------*/
static TSonNode* find_node(TSonNode* t, char x[])
{
    int i;
    TSonNode* p;

    if (t == NULL)
        return NULL;
    else if (strcmp(t->data, x) == 0)                            // 找到值为x的结点
        return t;
    else
    {
        for (i = 0; i < MAX_SONS; i++)
        {
            if (t->sons[i] != NULL)
            {
                p = find_node(t->sons[i], x);
                if (p != NULL)
                    return p;
            }
        }
        return NULL;
    }
}

/*---------------------求p所指结点的孩子个数---------------------*/
static int child_count(TSonNode* p)
{
    int i;
    int num = 0;

    for (i = 0; i < MAX_SONS; i++)
    {
        if (p->sons[i] != NULL)
            num++;
        else
            break;
    }
    //if (t->sons[i] != NULL)
    //    num += leaf_sum(t->sons[i]);
    //else
    //    break;

    return num;
}

/*---------------------求x单位的下一级单位数---------------------*/
static int son_num(TSonNode* t, char x[])
{
    TSonNode* p;

    p = find_node(t, x);
    if (p == NULL)
        return 0;
    else
        return child_count(p);
}

/*---------------------求树中叶子结点个数---------------------*/
static int leaf_count(TSonNode* t)
{
    int i;
    int num = 0;

    if (t == NULL)
        return 0;
    else
    {
        if (t->sons[0] == NULL)                              // t为叶子结点
            num++;
        else                                                // t不为叶子结点
        {
            for (i = 0; i < MAX_SONS; i++)
            {
                if (t->sons[i] != NULL)
                    num += leaf_count(t->sons[i]);
                else
                    break;
            }
        }

        return num;
    }
}

/*---------------------求x单位的班数---------------------*/
static int class_num(TSonNode* t, char x[])
{
    TSonNode* p;

    p = find_node(t, x);
    if (p == NULL)
        return 0;
    else
        return leaf_count(p);
}

/*---------------------求树中叶子结点的数值和---------------------*/
static int leaf_sum(TSonNode* t)
{
    int i;
    int sum = 0;

    if (t == NULL)
        return 0;
    else
    {
        if (t->sons[0] == NULL)                          // t为叶子结点
            return atoi(t->data);
        else                                            // t不为叶子结点
        {
            for (i = 0; i < MAX_SONS; i++)
                if (t->sons[i] != NULL)
                    sum += leaf_sum(t->sons[i]);
                else
                    break;
        }
        return sum;
    }
}

/*---------------------求x单位的总学生人数---------------------*/
static int stu_num(TSonNode* t, char x[])
{
    TSonNode* p;

    p = find_node(t, x);
    if (p == NULL)
        return 0;
    else
        return leaf_sum(p);
}

