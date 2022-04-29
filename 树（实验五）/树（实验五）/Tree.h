#pragma once
/**
*    ʵ����Ŀ:
*        ��ѧ������ͳ��
*    ʵ��Ŀ��:
*        �������Ĵ洢�ṹ������ʹ���������㷨�����������
*    ʵ������:
*        ��Ƴ���ʵ�ִ�ѧ������ͳ�ơ�ĳ��ѧ�����ݴ�����ı��ļ�abc.txt�С�
*    Ҫ��������ĺ������洢�ṹ�洢����������¹���:
*    1����abc.txt�ļ���ȡ���ݵ�R������
*    2��������R������t�ĺ������洢�ṹ
*    3���������ű�ʾ�����t
*    4��������ѧԺ��רҵ��
*    5��������ѧԺ�İ���
*    6�������ѧԺ��ѧ����
*    7��������
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include<fstream>
using namespace std;
#define MAX_SIZE (100)                                          // ����¼����
#define MAX_SONS (10)                                           // ����¼���λ��

typedef struct
{
    char fname[20];                                             // ��λ����
    char sname[20];                                             // �¼���λ���ƻ�������
}RecType;

typedef struct node
{
    char data[20];                                              // ����ֵ:��λ���ƻ�������
    struct node* sons[MAX_SONS];                                // ָ���ӽ��
}TSonNode;                                                      // �����������洢�ṹ�������


/*---------------------��abc.txt�ļ�����R������---------------------*/
static void read_file(RecType R[], int& n)
{
    //FILE* fp;
    //n = 0;

    //fopen_s(fp,"abc.txt", "r");
    //if (fp == NULL)
    //{
    //    printf("���ܴ��ļ�abc.txt\n");
    //    return;
    //}
    //while (!feof(fp))                                            // ������ϵ��ļ�������(�ļ�����:���ط�0ֵ,�ļ�δ����,����0ֵ)
    //{
    //    fscanf_s(fp, "%s", R[n].fname);                           // ��fname����
    //    fscanf_s(fp, "%s", R[n].sname);                           // ��sname����
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

/*---------------------����һ�Ŷ�����---------------------*/
static TSonNode* create_tree(char root[], RecType R[], int n)
{
    TSonNode* t;
    int i, j, k;

    t = (TSonNode*)malloc(sizeof(TSonNode));                   // ���������
    strcpy_s(t->data, root);
    for (k = 0; k < MAX_SONS; k++)                               // �������ָ��������Ϊ��
    {
        t->sons[k] = NULL;
    }
    i = 0;
    j = 0;
    while (i < n)
    {
        if (strcmp(R[i].fname, root) == 0)                       // �ҵ�fnameΪroot�ļ�¼
        {
            t->sons[j] = create_tree(R[i].sname, R, n);         // �ݹ鴴������
            j++;
        }
        i++;
    }

    return t;
}

/*---------------------����������洢�ṹ---------------------*/
static void disp_tree(TSonNode* t)
{
    int i;

    if (t != NULL)
    {
        printf("%s", t->data);
        if (t->sons[0] != NULL)                                  // t���������һ������
        {
            printf("(");                                        // ���һ��������
            for (i = 0; i < MAX_SONS; i++)
            {
                disp_tree(t->sons[i]);
                if (t->sons[i + 1] != NULL)                      // �������һ������
                    printf(",");                                // ���","
                else                                            // ���û����һ������
                    break;                                      // �˳�ѭ��
            }
            printf(")");                                        // ���һ��������
        }
    }
}

/*---------------------������t---------------------*/
static void destroy_tree(TSonNode* t)
{
    int i;

    if (t != NULL)
    {
        for (i = 0; i < MAX_SONS; i++)
        {
            if (t->sons[i] != NULL)                              // ������
                destroy_tree(t->sons[i]);                       // ��������
            else                                                // û������
                break;                                          // �˳�ѭ��
        }
        free(t);                                                // �ͷŸ����
    }
}

/*---------------------��x����ָ��---------------------*/
static TSonNode* find_node(TSonNode* t, char x[])
{
    int i;
    TSonNode* p;

    if (t == NULL)
        return NULL;
    else if (strcmp(t->data, x) == 0)                            // �ҵ�ֵΪx�Ľ��
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

/*---------------------��p��ָ���ĺ��Ӹ���---------------------*/
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

/*---------------------��x��λ����һ����λ��---------------------*/
static int son_num(TSonNode* t, char x[])
{
    TSonNode* p;

    p = find_node(t, x);
    if (p == NULL)
        return 0;
    else
        return child_count(p);
}

/*---------------------������Ҷ�ӽ�����---------------------*/
static int leaf_count(TSonNode* t)
{
    int i;
    int num = 0;

    if (t == NULL)
        return 0;
    else
    {
        if (t->sons[0] == NULL)                              // tΪҶ�ӽ��
            num++;
        else                                                // t��ΪҶ�ӽ��
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

/*---------------------��x��λ�İ���---------------------*/
static int class_num(TSonNode* t, char x[])
{
    TSonNode* p;

    p = find_node(t, x);
    if (p == NULL)
        return 0;
    else
        return leaf_count(p);
}

/*---------------------������Ҷ�ӽ�����ֵ��---------------------*/
static int leaf_sum(TSonNode* t)
{
    int i;
    int sum = 0;

    if (t == NULL)
        return 0;
    else
    {
        if (t->sons[0] == NULL)                          // tΪҶ�ӽ��
            return atoi(t->data);
        else                                            // t��ΪҶ�ӽ��
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

/*---------------------��x��λ����ѧ������---------------------*/
static int stu_num(TSonNode* t, char x[])
{
    TSonNode* p;

    p = find_node(t, x);
    if (p == NULL)
        return 0;
    else
        return leaf_sum(p);
}

