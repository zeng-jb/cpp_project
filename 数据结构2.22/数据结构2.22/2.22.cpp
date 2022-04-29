#include <iostream>
#define maxSize 100
using namespace std;

typedef int T;            //设置int同名类型T


struct LinkNode
{
    T data;
    LinkNode* link;
};



class LinkList               //链表类
{
public:
    LinkList();            //无参数的构造函数
    LinkList(T a[], int n); //有参数的构造函数
    ~LinkList();
    void Print();          //单链表遍历函数
    void Remove(T &x);       //单链表删除相同值的算法；
    void inversion();
private:
    LinkNode* first;        //头指针
};


LinkList::LinkList()         //无参数构造函数
{
    first = new LinkNode;
    first->link = NULL;
}

LinkList::LinkList(T a[], int n)//有参数构造函数  头插法建立单链表
{
    first = new LinkNode;
    LinkNode* s;
    first->link = NULL;
    for (int i = 0; i < n; i++) {
        s = new LinkNode;
        s->data = a[i];
        s->link = first->link;
        first->link = s;
    }
}

void LinkList::Print()            //输出链表
{
    LinkNode* p;
    p = first->link;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->link;
    }
    cout << endl;
}


void LinkList::Remove(T &x)
{
    
    LinkNode* p = first->link;
    LinkNode* del;
    while (p->link) {
        if (p->data == x) {
            del = p->link;
            p->link = del->link;
            delete del;
        }
        else p = p->link;
    }
    
   /* LinkNode* p = first->link;
    LinkNode* q;
    while (p->link) {
        if (p->data == p->link->data) {
            q = p->link;
            p->link = q->link;
            delete q;
        }
        else p = p->link;*/

}


void LinkList::inversion()        //元素倒置
{
    LinkNode* p, * q ,*t;
    int tdata;
    p = first->link;
    if (!p)return;
    q = p->link;
    if (!q)return;
    t = q->link;
    if (!t) {
        tdata = p->data;
        p->data = q->data;
        q->data = tdata;
        return;
    }
    p->link = NULL;
    while (t != NULL) {
        q->link = p;
        first->link = q;

        p = q;
        q = t;
        t = t->link;
    }
    first->link = q;
    q->link = p;
}


LinkList::~LinkList()    //析构函数删除链表
{
    LinkNode* q;
    while (first != NULL) {
        q = first;
        first = first->link;
        delete q;
    }
}


int main()
{
    int n = 10;  
    T x;
    T a[maxSize];
    cout << "输入10个数头插法建立链表" << endl;
    for (int j = 0; j < n; j++)
        cin >> a[j];
    LinkList s(a, n);         //声明S这个对象 调用有参数的构造函数；
    cout << "头插法建立链表后遍历" << endl;
    s.Print();

    s.inversion();
    cout << "元素倒置后：" << endl;
    s.Print();

    cout << "请输入想要删除的值：" << endl;
    cin >> x;

 
    s.Remove(x);
    cout << "删除输出后的结果为：" << endl;
    s.Print();
    
    
}