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
//typedef char TElemtype;    //将树的结点类型设置为字符型 
//typedef int QElemType;    //将队列的结点类型设置为整形 
//
//
//typedef struct {
//    QElemType* base;    //队列的基地址 
//    int front;
//    int rear;
//}SqQueue;
//
//typedef TElemtype SqBiTree[MAX_TREE_SIZE];    //定义顺序存储二叉树的结构数组 
//
//typedef struct {
//    int level;    //树的层号 
//    int order;    //一层中的序号(从左向右) 
//}position;
//
///**-------队列的函数声明------*/
//
//int InitQueue(SqQueue*);    //初始化队列 
//int DestroyQueue(SqQueue*);    //销毁队列 
//int ClearQueue(SqQueue*);    //清空队列 
//int QueueEmpty(SqQueue*);    //队列是否为空 
//int GetQueueLength(SqQueue*);    //获取队列的长度 
//int GetQueueHead(SqQueue*, QElemType*);    //获取队头元素 
//int EnterQueue(SqQueue*, QElemType);    //向队列中插入元素 
//int DeleteQueue(SqQueue*, QElemType*);    //向队列中删除元素 
//int (*QueueVisit)(QElemType);    //函数变量 
//int QueueTraverse(SqQueue*, int (*) (QElemType));    //遍历队列 
//
//
///*---------二叉树的函数声明*/
//
//int InitBiTree(SqBiTree);    //初始化二叉树 
//int CreateBiTree(SqBiTree);    //创建二叉树 
//int BiTreeEmpty(SqBiTree);    //判断二叉树是否为空 
//int BiTreeDepth(SqBiTree);    //计算二叉树的深度 
//int GetRoot(SqBiTree, TElemtype*);    //获取二叉树的根结点 
//TElemtype GetNodeValue(SqBiTree, position);    //获取二叉树结点元素 
//int Assign(SqBiTree, position, TElemtype);    //给结点元素赋值 
//TElemtype GetParent(SqBiTree, TElemtype);    //获取结点的双亲结点 
//TElemtype GetLeftChild(SqBiTree, TElemtype);    //获取结点的左孩子 
//TElemtype GetRightChild(SqBiTree, TElemtype);    //获取结点的右孩子 
//TElemtype GetLeftSibling(SqBiTree, TElemtype);    //获取结点的左兄弟 
//TElemtype GetRightSibling(SqBiTree, TElemtype);    //获取结点的右兄弟 
//void Move(SqBiTree, int, SqBiTree, int);    //移动结点 
//int InsertChild(SqBiTree, TElemtype, int, SqBiTree);    //插入子结点 
//int DeleteChild(SqBiTree, position, int);    //删除子结点 
//int (*TreeVisit)(TElemtype);    //函数变量 
//int PreOrderTraverse(SqBiTree, int (*Visit)(TElemtype));    //先序遍历二叉树 
//int InOrderTraverse(SqBiTree, int (*Visit)(TElemtype));    //中序遍历二叉树 
//int PostOrderTraverse(SqBiTree, int (*Visit)(TElemtype));    //后序遍历二叉树 
//void LevelOrderTraverse(SqBiTree, int (*Visit)(TElemtype));    //层序遍历二叉树 
//void PrintTree(SqBiTree);    //打印二叉树 
//
///*-----------队列的函数定义-----------*/
//
// /*初始化队列*/
//int InitQueue(SqQueue* Q)
//{
//    //分配内存区域 
//    Q->base = (QElemType*)malloc(MAX_QUEUE_SIZE * sizeof(QElemType));
//    if (!Q->base)
//    {
//        printf("存储分配失败.\n");
//        return ERROR;
//    }
//    Q->front = Q->rear = 0;    //将队列置空 
//    return OK;
//}
//
///*销毁队列*/
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
///*清空队列*/
//int ClearQueue(SqQueue* Q)
//{
//    Q->front = Q->rear = 0;
//    return OK;
//}
//
///*判断队列是否为空*/
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
///*获取队列长度*/
//int GetQueueLength(SqQueue* Q)
//{
//    return (Q->rear - Q->front);
//}
//
///*获取队列头的元素*/
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
///*使元素进队*/
//int EnterQueue(SqQueue* Q, QElemType e)
//{
//    if (Q->rear == MAX_QUEUE_SIZE)    //队列满了,重新分配内存区域,用realloc 
//    {
//        printf("队列已满,尝试增加存储单元...\n");
//        Q->base = (QElemType*)realloc(Q->base, MAX_QUEUE_SIZE + 1);
//        if (!Q->base)
//        {
//            printf("增加队列存储单元失败.\n");
//            return ERROR;
//        }
//    }
//    *(Q->base + Q->rear) = e;
//    Q->rear++;
//    return OK;
//}
//
///*删除队头元素*/
//int DeleteQueue(SqQueue* Q, QElemType* e)
//{
//    if (QueueEmpty(Q))
//    {
//        //printf("队列为空.\n");
//        return ERROR;
//    }
//    *e = *(Q->base + Q->front);
//    Q->front++;
//    return OK;
//}
//
///*遍历队列*/
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
///*访问队列中元素的函数,将元素值打印出来*/
//int QueueVisitFunc(QElemType e)
//{
//    printf("%d\n", e);
//}
//
///*-------二叉树的函数定义-------*/
//
///*初始化树*/
//int InitBiTree(SqBiTree T)
//{
//    int i;
//    for (i = 0; i < MAX_TREE_SIZE; i++)
//    {
//        T[i] = Nil;    //将初值设为空格 
//    }
//
//    T[MAX_TREE_SIZE] = '\0';    //给数组尾部加上结标致 
//    return OK;
//}
//
///*创建树*/
//int CreateBiTree(SqBiTree T)
//{
//    int i = 0;
//    int l = 0;
//    char s[MAX_TREE_SIZE];
//    printf("请按顺序输入结点的值,空格表示空结点,结点数<=%d\n", MAX_TREE_SIZE);
//    //gets_s(s);
//    cin >> s;
//    l = strlen(s);
//    for (; i < l; i++)
//    {
//        T[i] = s[i];
//        if (i != 0 && T[(i + 1) / 2 - 1] == Nil && T[i] != Nil)
//        {
//            printf("出现无双亲且不是根的结点.\n");
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
//#define ClearBiTree InitBiTree    //在顺序存储结构中,ClearBiTree和InitBiTree完全一样 
//
///*判断树是否为空*/
//int BiTreeEmpty(SqBiTree T)
//{
//    if (T[0] == Nil)
//    {
//        printf("树为空.\n");
//        return TRUE;
//    }
//    else
//    {
//        return FALSE;
//    }
//}
//
///*计算树的深度*/
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
///*获取根结点的值*/
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
///*根据位置获取某一结点的值*/
//TElemtype GetNodeValue(SqBiTree T, position p)
//{
//    return T[(int)pow(2, p.level) - 1 - (int)pow(2, p.level - 1) + p.order - 1];
//}
//
///*根据结点的位置给某一结点元素赋值*/
//int Assign(SqBiTree T, position p, TElemtype e)
//{
//    int i = (int)pow(2, p.level) - 1 - (int)pow(2, p.level - 1) + p.order - 1;
//    if (e != Nil && T[(i + 1) / 2 - 1] == Nil)
//    {
//        printf("将要赋值的结点双亲为空,不合法.\n");
//        return ERROR;
//    }
//    if (e == Nil && (T[2 * i + 1] != Nil || T[2 * i + 2] != Nil))
//    {
//        printf("将有子结点的结点赋空值,不合法.\n");
//        return ERROR;
//    }
//    T[i] = e;
//    //printf("T[%d] 已修改为: %c.\n",i,T[i]);
//    return OK;
//}
//
///*获取结点元素的双亲结点*/
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
//    printf("未找到双亲结点.\n");
//    return Nil;
//}
//
///*获取结点元素的左孩子*/
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
//    printf("未找到左孩子.\n");
//    return Nil;
//}
//
///*获取结点元素的右孩子*/
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
//    printf("未找到右孩子.\n");
//    return Nil;
//}
//
///*获取结点元素的左兄弟*/
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
//    printf("未找到左兄弟.\n");
//    return Nil;
//}
//
///*获取结点元素的右兄弟*/
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
//    printf("未找到右兄弟.\n");
//    return Nil;
//}
//
///*把从T1中j结点开始的子树移到T2中i结点开始的子树*/
//void Move(SqBiTree T1, int i1, SqBiTree T2, int i2)
//{
//    if (T1[2 * i1 + 1] != Nil)
//    {/*左子树不空*/
//        Move(T1, 2 * i1 + 1, T2, 2 * i2 + 1);
//    }
//    if (T1[2 * i1 + 2] != Nil)
//    {/*右子树不空*/
//        Move(T1, 2 * i1 + 2, T2, 2 * i2 + 2);
//    }
//    /*左右子树都为空,说明该结点为叶子结点,可以移动.*/
//    T2[i2] = T1[i1];
//    T1[i1] = Nil;
//}
//
///*插入结点或子树*/
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
//    k = 2 * j + LR;    //k为e结点的左或右孩子的序号
//    if (T[k] != Nil)
//    {/*e结点的左右孩子不空,即e结点不是叶子结点*/
//        Move(T, k, T, 2 * k + 2);
//    }
//    Move(S, i, T, k);
//}
//
///*删除结点或子树*/
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
///*访问结点元素的函数*/
//int TreeVisitFunc(TElemtype e)
//{
//    printf(" %c -", e);
//}
//
///*先序遍历二叉树的递归函数*/
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
///*先序遍历二叉树*/
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
///*中序遍历二叉树的递归函数*/
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
///*中序遍历二叉树*/
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
///*后序遍历二叉树的递归函数*/
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
///*后序遍历二叉树*/
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
///*打印树*/
//void PrintTree(SqBiTree T)
//{
//    int j, k;
//    position p;
//    TElemtype e;
//    for (j = 0; j < BiTreeDepth(T); j++)
//    {
//        p.level = j + 1;
//        printf("第%d层:\n", p.level);
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
///*程序入口函数,对二叉树及队列的操作的调用*/
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
//    printf("队列长度为: %d\n",length);
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
//    printf("销毁队列.\n");
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
//        printf("输入一个结点的值,我们可以找到其双亲,孩子和兄弟.\n");
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
//    printf("--------------遍历二叉树--------------------\n\n");
//    printf("先序遍历:\n");
//    PreOrderTraverse(T, TreeVisitFunc);
//    printf("\n中序遍历:\n");
//    InOrderTraverse(T, TreeVisitFunc);
//    printf("\n后序遍历:\n");
//    PostOrderTraverse(T, TreeVisitFunc);
//    printf("\n");
//    printf("--------------打印二叉树--------------------\n\n");
//    PrintTree(T);
//}


////中序遍历
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
//将二叉树的顺序存储结构转换成二叉链存储结构
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
//	if (a[i] == '#')	return(NULL);			//当节点不存在时返回NULL
//	b = (BTNode*)malloc(sizeof(BTNode));	//创建根节点
//	b->data = a[i];
//	b->lchild = trans(a, 2 * i);					//递归创建左子树
//	b->rchild = trans(a, 2 * i + 1);				//递归创建右子树
//	return(b);								//返回根节点
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
//pTree FindEmptyNode(pTree node, int* flag)//从左到右查找离root最近的空节点的父节点
//{
//	int TreePath = getTreePath(node);        //getTreePath(pTree)函数为获得树的层数
//	int MaxNum = Power2(TreePath) - 1; //获得该树最大存储节点个数，power2函数是我自己写的一个2的次方函数
//	pTree tree[MAX_SIZE];
//	tree[0] = node;
//	int i = 1, j = 1, a = 0; //i表示层数，j表示压入的个数,a表示需要压入子节点的节点
//	while (i != TreePath + 1) //使用该while循环将链式存储转换为顺序存储
//	{
//		for (int k = 0; k < Power2(i - 1); k++)  //k表示在i层的第k个节点
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
//	if (i % 2 == 1) //空节点为奇数的话设置为左节点
//		*flag = 0;
//	else
//		*flag = 1; //空节点为偶数的话设置为右节点
//	i = (i - 1) >> 1; //通过for循环找到的是空节点，需要通过i = (i - 1) >> 1找到其父节点，然后返
//	return tree[i];
//}