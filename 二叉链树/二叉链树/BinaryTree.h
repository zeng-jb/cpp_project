//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <malloc.h> 
//#include <math.h>
//#include<iostream>
//using namespace std;
//#define TRUE 1
//#define FALSE 0
//#define OK 1
//#define ERROR 0
//
//#define MAX_TREE_SIZE 100
//#define MAX_QUEUE_SIZE 5
//#define Nil ' ' 
//
//typedef char TElemtype;    //�����Ľ����������Ϊ�ַ��� 
//typedef int QElemType;    //�����еĽ����������Ϊ���� 
//
//
//typedef struct {
//    QElemType* base;    //���еĻ���ַ 
//    int front;
//    int rear;
//}SqQueue;
//
//typedef TElemtype SqBiTree[MAX_TREE_SIZE];    //����˳��洢�������Ľṹ���� 
//
//typedef struct {
//    int level;    //���Ĳ�� 
//    int order;    //һ���е����(��������) 
//}position;
//
///**-------���еĺ�������------*/
//
//int InitQueue(SqQueue*);    //��ʼ������ 
//int DestroyQueue(SqQueue*);    //���ٶ��� 
//int ClearQueue(SqQueue*);    //��ն��� 
//int QueueEmpty(SqQueue*);    //�����Ƿ�Ϊ�� 
//int GetQueueLength(SqQueue*);    //��ȡ���еĳ��� 
//int GetQueueHead(SqQueue*, QElemType*);    //��ȡ��ͷԪ�� 
//int EnterQueue(SqQueue*, QElemType);    //������в���Ԫ�� 
//int DeleteQueue(SqQueue*, QElemType*);    //�������ɾ��Ԫ�� 
//int (*QueueVisit)(QElemType);    //�������� 
//int QueueTraverse(SqQueue*, int (*) (QElemType));    //�������� 
//
//
///*---------�������ĺ�������*/
//
//int InitBiTree(SqBiTree);    //��ʼ�������� 
//int CreateBiTree(SqBiTree);    //���������� 
//int BiTreeEmpty(SqBiTree);    //�ж϶������Ƿ�Ϊ�� 
//int BiTreeDepth(SqBiTree);    //�������������� 
//int GetRoot(SqBiTree, TElemtype*);    //��ȡ�������ĸ���� 
//TElemtype GetNodeValue(SqBiTree, position);    //��ȡ���������Ԫ�� 
//int Assign(SqBiTree, position, TElemtype);    //�����Ԫ�ظ�ֵ 
//TElemtype GetParent(SqBiTree, TElemtype);    //��ȡ����˫�׽�� 
//TElemtype GetLeftChild(SqBiTree, TElemtype);    //��ȡ�������� 
//TElemtype GetRightChild(SqBiTree, TElemtype);    //��ȡ�����Һ��� 
//TElemtype GetLeftSibling(SqBiTree, TElemtype);    //��ȡ�������ֵ� 
//TElemtype GetRightSibling(SqBiTree, TElemtype);    //��ȡ�������ֵ� 
//void Move(SqBiTree, int, SqBiTree, int);    //�ƶ���� 
//int InsertChild(SqBiTree, TElemtype, int, SqBiTree);    //�����ӽ�� 
//int DeleteChild(SqBiTree, position, int);    //ɾ���ӽ�� 
//int (*TreeVisit)(TElemtype);    //�������� 
//int PreOrderTraverse(SqBiTree, int (*Visit)(TElemtype));    //������������� 
//int InOrderTraverse(SqBiTree, int (*Visit)(TElemtype));    //������������� 
//int PostOrderTraverse(SqBiTree, int (*Visit)(TElemtype));    //������������� 
//void LevelOrderTraverse(SqBiTree, int (*Visit)(TElemtype));    //������������� 
//void PrintTree(SqBiTree);    //��ӡ������ 
//
///*-----------���еĺ�������-----------*/
//
// /*��ʼ������*/
//int InitQueue(SqQueue* Q)
//{
//    //�����ڴ����� 
//    Q->base = (QElemType*)malloc(MAX_QUEUE_SIZE * sizeof(QElemType));
//    if (!Q->base)
//    {
//        printf("�洢����ʧ��.\n");
//        return ERROR;
//    }
//    Q->front = Q->rear = 0;    //�������ÿ� 
//    return OK;
//}
//
///*���ٶ���*/
//int DestroyQueue(SqQueue* Q)
//{
//    if (Q->base)
//    {
//        free(Q->base);
//    }
//    Q->front = Q->rear = 0;
//    return OK;
//}
//
///*��ն���*/
//int ClearQueue(SqQueue* Q)
//{
//    Q->front = Q->rear = 0;
//    return OK;
//}
//
///*�ж϶����Ƿ�Ϊ��*/
//int QueueEmpty(SqQueue* Q)
//{
//    if (Q->front == Q->rear)
//    {
//        return OK;
//    }
//    else
//    {
//
//        return ERROR;
//    }
//}
//
///*��ȡ���г���*/
//int GetQueueLength(SqQueue* Q)
//{
//    return (Q->rear - Q->front);
//}
//
///*��ȡ����ͷ��Ԫ��*/
//int GetQueueHead(SqQueue* Q, QElemType* e)
//{
//    if (!QueueEmpty(Q))
//    {
//        *e = *(Q->base + Q->front);
//        return OK;
//    }
//    return ERROR;
//}
//
///*ʹԪ�ؽ���*/
//int EnterQueue(SqQueue* Q, QElemType e)
//{
//    if (Q->rear == MAX_QUEUE_SIZE)    //��������,���·����ڴ�����,��realloc 
//    {
//        printf("��������,�������Ӵ洢��Ԫ...\n");
//        Q->base = (QElemType*)realloc(Q->base, MAX_QUEUE_SIZE + 1);
//        if (!Q->base)
//        {
//            printf("���Ӷ��д洢��Ԫʧ��.\n");
//            return ERROR;
//        }
//    }
//    *(Q->base + Q->rear) = e;
//    Q->rear++;
//    return OK;
//}
//
///*ɾ����ͷԪ��*/
//int DeleteQueue(SqQueue* Q, QElemType* e)
//{
//    if (QueueEmpty(Q))
//    {
//        //printf("����Ϊ��.\n");
//        return ERROR;
//    }
//    *e = *(Q->base + Q->front);
//    Q->front++;
//    return OK;
//}
//
///*��������*/
//int QueueTraverse(SqQueue* Q, int (*QV)(QElemType))
//{
//    int i = 0;
//    while (i < Q->rear)
//    {
//        (*QV)(*(Q->base + i));
//        i++;
//    }
//}
//
///*���ʶ�����Ԫ�صĺ���,��Ԫ��ֵ��ӡ����*/
//int QueueVisitFunc(QElemType e)
//{
//    printf("%d\n", e);
//}
//
///*-------�������ĺ�������-------*/
//
///*��ʼ����*/
//int InitBiTree(SqBiTree T)
//{
//    int i;
//    for (i = 0; i < MAX_TREE_SIZE; i++)
//    {
//        T[i] = Nil;    //����ֵ��Ϊ�ո� 
//    }
//
//    T[MAX_TREE_SIZE] = '\0';    //������β�����Ͻ���� 
//    return OK;
//}
//
///*������*/
//int CreateBiTree(SqBiTree T)
//{
//    int i = 0;
//    int l = 0;
//    char s[MAX_TREE_SIZE];
//    printf("�밴˳���������ֵ,�ո��ʾ�ս��,�����<=%d\n", MAX_TREE_SIZE);
//    //gets_s(s);
//    cin >> s;
//    l = strlen(s);
//    for (; i < l; i++)
//    {
//        T[i] = s[i];
//        if (i != 0 && T[(i + 1) / 2 - 1] == Nil && T[i] != Nil)
//        {
//            printf("������˫���Ҳ��Ǹ��Ľ��.\n");
//            return ERROR;
//        }
//    }
//    for (; i < MAX_TREE_SIZE; i++)
//    {
//        T[i] = Nil;
//    }
//    return OK;
//}
//
//#define ClearBiTree InitBiTree    //��˳��洢�ṹ��,ClearBiTree��InitBiTree��ȫһ�� 
//
///*�ж����Ƿ�Ϊ��*/
//int BiTreeEmpty(SqBiTree T)
//{
//    if (T[0] == Nil)
//    {
//        printf("��Ϊ��.\n");
//        return TRUE;
//    }
//    else
//    {
//        return FALSE;
//    }
//}
//
///*�����������*/
//int BiTreeDepth(SqBiTree T)
//{
//    int j = -1;
//    int i = 0;
//    if (BiTreeEmpty(T))
//    {
//        return ERROR;
//    }
//    for (i = MAX_TREE_SIZE - 1; i >= 0; i--)
//    {
//        if (T[i] != Nil)
//        {
//            break;
//        }
//    }
//    i++;
//    //printf("i = %d\n",i);
//    do
//    {
//        j++;
//    } while (i >= pow(2, j));
//    return j;
//}
//
///*��ȡ������ֵ*/
//int GetRoot(SqBiTree T, TElemtype* e)
//{
//    if (BiTreeEmpty(T))
//    {
//        return ERROR;
//    }
//    *e = T[0];
//    return OK;
//}
//
///*����λ�û�ȡĳһ����ֵ*/
//TElemtype GetNodeValue(SqBiTree T, position p)
//{
//    return T[(int)pow(2, p.level) - 1 - (int)pow(2, p.level - 1) + p.order - 1];
//}
//
///*���ݽ���λ�ø�ĳһ���Ԫ�ظ�ֵ*/
//int Assign(SqBiTree T, position p, TElemtype e)
//{
//    int i = (int)pow(2, p.level) - 1 - (int)pow(2, p.level - 1) + p.order - 1;
//    if (e != Nil && T[(i + 1) / 2 - 1] == Nil)
//    {
//        printf("��Ҫ��ֵ�Ľ��˫��Ϊ��,���Ϸ�.\n");
//        return ERROR;
//    }
//    if (e == Nil && (T[2 * i + 1] != Nil || T[2 * i + 2] != Nil))
//    {
//        printf("�����ӽ��Ľ�㸳��ֵ,���Ϸ�.\n");
//        return ERROR;
//    }
//    T[i] = e;
//    //printf("T[%d] ���޸�Ϊ: %c.\n",i,T[i]);
//    return OK;
//}
//
///*��ȡ���Ԫ�ص�˫�׽��*/
//TElemtype GetParent(SqBiTree T, TElemtype e)
//{
//    int i;
//    if (BiTreeEmpty(T))
//    {
//        return Nil;
//    }
//    for (i = 0; i < MAX_TREE_SIZE; i++)
//    {
//        if (T[i] == e)
//        {
//            return T[(i + 1) / 2 - 1];
//        }
//    }
//    printf("δ�ҵ�˫�׽��.\n");
//    return Nil;
//}
//
///*��ȡ���Ԫ�ص�����*/
//TElemtype GetLeftChild(SqBiTree T, TElemtype e)
//{
//    int i;
//    if (BiTreeEmpty(T))
//    {
//        return Nil;
//    }
//    for (i = 0; i < MAX_TREE_SIZE; i++)
//    {
//        if (T[i] == e)
//        {
//            return T[2 * i + 1];
//        }
//    }
//    printf("δ�ҵ�����.\n");
//    return Nil;
//}
//
///*��ȡ���Ԫ�ص��Һ���*/
//TElemtype GetRightChild(SqBiTree T, TElemtype e)
//{
//    int i;
//    if (BiTreeEmpty(T))
//    {
//        return Nil;
//    }
//    for (i = 0; i < MAX_TREE_SIZE; i++)
//    {
//        if (T[i] == e)
//        {
//            return T[2 * i + 2];
//        }
//    }
//    printf("δ�ҵ��Һ���.\n");
//    return Nil;
//}
//
///*��ȡ���Ԫ�ص����ֵ�*/
//TElemtype GetLeftSibling(SqBiTree T, TElemtype e)
//{
//    int i;
//    if (BiTreeEmpty(T))
//    {
//        return Nil;
//    }
//    for (i = 1; i < MAX_TREE_SIZE; i++)
//    {
//        if (T[i] == e && i % 2 == 0)
//        {
//            return T[i - 1];
//        }
//    }
//    printf("δ�ҵ����ֵ�.\n");
//    return Nil;
//}
//
///*��ȡ���Ԫ�ص����ֵ�*/
//TElemtype GetRightSibling(SqBiTree T, TElemtype e)
//{
//    int i;
//    if (BiTreeEmpty(T))
//    {
//        return Nil;
//    }
//    for (i = 1; i < MAX_TREE_SIZE; i++)
//    {
//        if (T[i] == e && i % 2 != 0)
//        {
//            return T[i + 1];
//        }
//    }
//    printf("δ�ҵ����ֵ�.\n");
//    return Nil;
//}
//
///*�Ѵ�T1��j��㿪ʼ�������Ƶ�T2��i��㿪ʼ������*/
//void Move(SqBiTree T1, int i1, SqBiTree T2, int i2)
//{
//    if (T1[2 * i1 + 1] != Nil)
//    {/*����������*/
//        Move(T1, 2 * i1 + 1, T2, 2 * i2 + 1);
//    }
//    if (T1[2 * i1 + 2] != Nil)
//    {/*����������*/
//        Move(T1, 2 * i1 + 2, T2, 2 * i2 + 2);
//    }
//    /*����������Ϊ��,˵���ý��ΪҶ�ӽ��,�����ƶ�.*/
//    T2[i2] = T1[i1];
//    T1[i1] = Nil;
//}
//
///*�����������*/
//int InsertChild(SqBiTree T, TElemtype e, int LR, SqBiTree S)
//{
//    int j, k, i = 0;
//    if (BiTreeEmpty(T))
//    {
//        return ERROR;
//    }
//    for (j = 0; j < (int)pow(2, BiTreeDepth(T)) - 1; j++)
//    {
//        if (T[j] == e)
//        {
//            break;
//        }
//    }
//    k = 2 * j + LR;    //kΪe��������Һ��ӵ����
//    if (T[k] != Nil)
//    {/*e�������Һ��Ӳ���,��e��㲻��Ҷ�ӽ��*/
//        Move(T, k, T, 2 * k + 2);
//    }
//    Move(S, i, T, k);
//}
//
///*ɾ����������*/
//int DeleteChild(SqBiTree T, position p, int LR)
//{
//    int i;
//    int k = OK;
//    SqQueue Q;
//    InitQueue(&Q);
//    i = (int)pow(2, p.level) - 1 - (int)pow(2, p.level - 1) + p.order - 1;
//    if (BiTreeEmpty(T))
//    {
//        return ERROR;
//    }
//    i = 2 * i + 1 + LR;
//    while (k)
//    {
//        if (T[2 * i + 1] != Nil)
//        {
//            EnterQueue(&Q, 2 * i + 1);
//        }
//        if (T[2 * i + 2] != Nil)
//        {
//            EnterQueue(&Q, 2 * i + 2);
//        }
//        T[i] = Nil;
//        k = DeleteQueue(&Q, &i);
//    }
//    return OK;
//}
//
///*���ʽ��Ԫ�صĺ���*/
//int TreeVisitFunc(TElemtype e)
//{
//    printf(" %c -", e);
//}
//
///*��������������ĵݹ麯��*/
//int PreTraverse(SqBiTree T, int i)
//{
//    TreeVisit(T[i]);
//    if (T[2 * i + 1] != Nil)
//    {
//        PreTraverse(T, 2 * i + 1);
//    }
//    if (T[2 * i + 2] != Nil)
//    {
//        PreTraverse(T, 2 * i + 2);
//    }
//}
//
///*�������������*/
//int PreOrderTraverse(SqBiTree T, int (*TV) (TElemtype e))
//{
//    TreeVisit = TV;
//    if (BiTreeEmpty(T))
//    {
//        return ERROR;
//    }
//    PreTraverse(T, 0);
//}
//
///*��������������ĵݹ麯��*/
//int InTraverse(SqBiTree T, int i)
//{
//    if (T[2 * i + 1] != Nil)
//    {
//        InTraverse(T, 2 * i + 1);
//    }
//    TreeVisit(T[i]);
//    if (T[2 * i + 2] != Nil)
//    {
//        InTraverse(T, 2 * i + 2);
//    }
//}
//
///*�������������*/
//int InOrderTraverse(SqBiTree T, int (*TV)(TElemtype))
//{
//    TreeVisit = TV;
//    if (BiTreeEmpty(T))
//    {
//        return ERROR;
//    }
//    InTraverse(T, 0);
//}
//
///*��������������ĵݹ麯��*/
//int PostTraverse(SqBiTree T, int i)
//{
//    if (T[2 * i + 1] != Nil)
//    {
//        PostTraverse(T, 2 * i + 1);
//    }
//    if (T[2 * i + 2] != Nil)
//    {
//        PostTraverse(T, 2 * i + 2);
//    }
//    TreeVisit(T[i]);
//}
//
///*�������������*/
//int PostOrderTraverse(SqBiTree T, int (*TV)(TElemtype))
//{
//    TreeVisit = TV;
//    if (BiTreeEmpty(T))
//    {
//        return ERROR;
//    }
//    PostTraverse(T, 0);
//}
//
///*��ӡ��*/
//void PrintTree(SqBiTree T)
//{
//    int j, k;
//    position p;
//    TElemtype e;
//    for (j = 0; j < BiTreeDepth(T); j++)
//    {
//        p.level = j + 1;
//        printf("��%d��:\n", p.level);
//        for (k = 0; k < pow(2, p.level - 1); k++)
//        {
//            p.order = k + 1;
//            e = T[(int)pow(2, p.level) - 1 - (int)pow(2, p.level - 1) + p.order - 1];
//            printf(" %d : %c ", p.order, e);
//        }
//        printf("\n");
//    }
//    printf("\n");
//}
//
///*������ں���,�Զ����������еĲ����ĵ���*/
//int main()
//{
//    /*
//    SqQueue queue;
//    InitQueue(&queue);
//    QueueEmpty(&queue);
//    ClearQueue(&queue);
//    QueueEmpty(&queue);
//    int length;
//    length = GetQueueLength(&queue);
//    printf("���г���Ϊ: %d\n",length);
//    if(1==OK)
//    {
//        printf("-----------------------------\n\n");
//    }
//    EnterQueue(&queue,1);
//    EnterQueue(&queue,2);
//    EnterQueue(&queue,3);
//    EnterQueue(&queue,4);
//    EnterQueue(&queue,5);
//    QueueEmpty(&queue);
//    length=GetQueueLength(&queue);
//    printf("The Length of the Queue is : %d.\n",length);
//    QElemType headElem;
//    if(GetQueueHead(&queue,&headElem))
//    {
//        printf("The Head of the Queue is : %d.\n",headElem);
//    }
//    QueueVisit=QueueVisitFunc;
//    QueueTraverse(&queue,QueueVisit);
//    printf("���ٶ���.\n");
//    DestroyQueue(&queue);
//    */
//
//    position p;
//    SqBiTree T;
//    SqBiTree S;
//    int depth;
//    int i;
//    TElemtype elem;
//    InitBiTree(T);
//    BiTreeEmpty(T);
//    CreateBiTree(T);
//    puts(T);
//    depth = BiTreeDepth(T);
//    printf("The Depth of the tree is %d.\n", depth);
//
//
//    GetRoot(T, &elem);
//    printf("The Root of the tree is %c.\n", elem);/*
//
//    printf("Please Enter the Level and Order of the Tree:\n");
//    scanf("%d",&p.level);
//    scanf("%d",&p.order);
//    fflush(stdin);
//    elem=GetNodeValue(T,p);
//    printf("The Node of level %d order %d is : %c \n",p.level,p.order,elem);
//    Assign(T,p,'C');*/
//    printf("--------------------------------\n\n");
//    /*
//        printf("����һ������ֵ,���ǿ����ҵ���˫��,���Ӻ��ֵ�.\n");
//        scanf("%c",&elem);
//        fflush(stdin);
//        printf("%c 's parent is : %c.\n",elem,GetParent(T,elem));
//        printf("%c 's left child is : %c.\n",elem,GetLeftChild(T,elem));
//        printf("%c 's right child is : %c.\n",elem,GetRightChild(T,elem));
//        printf("%c 's left sibling is : %c.\n",elem,GetLeftSibling(T,elem));
//        printf("%c 's right sibling is : %c.\n",elem,GetRightSibling(T,elem));*/
//
//    printf("----------------------------------\n\n");
//    /*
//    InitBiTree(S);
//    CreateBiTree(S);
//    printf("Please enter the node value where you want to insert a child.\n");
//    scanf("%c",&elem);
//    InsertChild(T,elem,1,S);
//    puts(T);
//    printf("Please enter the node position you want to delete.\n");
//    scanf("%d%d",&p.level,&p.order);
//    printf("p.level=%d,p.order=%d\n",p.level,p.order);
//    DeleteChild(T,p,0);
//    puts(T);
//    */
//    printf("--------------����������--------------------\n\n");
//    printf("�������:\n");
//    PreOrderTraverse(T, TreeVisitFunc);
//    printf("\n�������:\n");
//    InOrderTraverse(T, TreeVisitFunc);
//    printf("\n�������:\n");
//    PostOrderTraverse(T, TreeVisitFunc);
//    printf("\n");
//    printf("--------------��ӡ������--------------------\n\n");
//    PrintTree(T);
//}


////�������
//int STree_Traver_2_no(STree& T)
//{
//    stack<int> s;
//    int p = 1;
//    int b = 1;
//    do
//    {
//        while (T.bitTree[p] != '0')
//        {
//            s.push(p);
//            p = p * 2;
//        }
//        if (s.empty()) b = 0;
//        else {
//            p = s.top();
//            s.pop();
//            cout << T.bitTree[p] << " ";
//            p = p * 2 + 1;
//        }
//    } while (b != 0);
//    return 1;
//}
//����������˳��洢�ṹת���ɶ������洢�ṹ
//#include "BinTree.h"
//#include"LinkedQueue.h"
//#define MaxSize 30
//typedef char Elemtype;
//typedef ElemType SqBTree[MaxSize];
//BTNode* trans(SqBTree a, int i)
//{
//	BTNode* b;
//	if (i > MaxSize)
//		return(NULL);
//	if (a[i] == '#')	return(NULL);			//���ڵ㲻����ʱ����NULL
//	b = (BTNode*)malloc(sizeof(BTNode));	//�������ڵ�
//	b->data = a[i];
//	b->lchild = trans(a, 2 * i);					//�ݹ鴴��������
//	b->rchild = trans(a, 2 * i + 1);				//�ݹ鴴��������
//	return(b);								//���ظ��ڵ�
//}
//int main()
//{
//	BTNode* b;
//	SqBTree a;
//	ElemType s[] = "0ABCD#EF##G####################";
//	b = trans(s, 1);
//	printf("b:"); DispBTree(b); printf("\n");
//	DestroyBTree(b);
//	return 1;
//}
//pTree FindEmptyNode(pTree node, int* flag)//�����Ҳ�����root����Ŀսڵ�ĸ��ڵ�
//{
//	int TreePath = getTreePath(node);        //getTreePath(pTree)����Ϊ������Ĳ���
//	int MaxNum = Power2(TreePath) - 1; //��ø������洢�ڵ������power2���������Լ�д��һ��2�Ĵη�����
//	pTree tree[MAX_SIZE];
//	tree[0] = node;
//	int i = 1, j = 1, a = 0; //i��ʾ������j��ʾѹ��ĸ���,a��ʾ��Ҫѹ���ӽڵ�Ľڵ�
//	while (i != TreePath + 1) //ʹ�ø�whileѭ������ʽ�洢ת��Ϊ˳��洢
//	{
//		for (int k = 0; k < Power2(i - 1); k++)  //k��ʾ��i��ĵ�k���ڵ�
//		{
//			if (tree[a] == NULL)
//				tree[j++] = NULL;
//			else if (tree[a]->plchild == NULL)
//				tree[a]->plchild == NULL;
//			else if (tree[a]->plchild != NULL)
//				tree[j++] = tree[a]->plchild;
//			if (tree[a] == NULL)
//				tree[j++] = NULL;
//			else if (tree[a]->prchild == NULL)
//				tree[j++] = NULL;
//			else if (tree[a]->prchild != NULL)
//				tree[j++] = tree[a]->prchild;
//			a++;
//		}
//		i++;
//	}
//	i = 0;
//	for (i = 0; i < MAX_SIZE; i++)
//		if (tree[i] == NULL)
//			break;
//	if (i % 2 == 1) //�սڵ�Ϊ�����Ļ�����Ϊ��ڵ�
//		*flag = 0;
//	else
//		*flag = 1; //�սڵ�Ϊż���Ļ�����Ϊ�ҽڵ�
//	i = (i - 1) >> 1; //ͨ��forѭ���ҵ����ǿսڵ㣬��Ҫͨ��i = (i - 1) >> 1�ҵ��丸�ڵ㣬Ȼ��
//	return tree[i];
//}