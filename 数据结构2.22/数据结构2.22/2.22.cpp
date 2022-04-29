#include <iostream>
#define maxSize 100
using namespace std;

typedef int T;            //����intͬ������T


struct LinkNode
{
    T data;
    LinkNode* link;
};



class LinkList               //������
{
public:
    LinkList();            //�޲����Ĺ��캯��
    LinkList(T a[], int n); //�в����Ĺ��캯��
    ~LinkList();
    void Print();          //�������������
    void Remove(T &x);       //������ɾ����ֵͬ���㷨��
    void inversion();
private:
    LinkNode* first;        //ͷָ��
};


LinkList::LinkList()         //�޲������캯��
{
    first = new LinkNode;
    first->link = NULL;
}

LinkList::LinkList(T a[], int n)//�в������캯��  ͷ�巨����������
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

void LinkList::Print()            //�������
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


void LinkList::inversion()        //Ԫ�ص���
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


LinkList::~LinkList()    //��������ɾ������
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
    cout << "����10����ͷ�巨��������" << endl;
    for (int j = 0; j < n; j++)
        cin >> a[j];
    LinkList s(a, n);         //����S������� �����в����Ĺ��캯����
    cout << "ͷ�巨������������" << endl;
    s.Print();

    s.inversion();
    cout << "Ԫ�ص��ú�" << endl;
    s.Print();

    cout << "��������Ҫɾ����ֵ��" << endl;
    cin >> x;

 
    s.Remove(x);
    cout << "ɾ�������Ľ��Ϊ��" << endl;
    s.Print();
    
    
}