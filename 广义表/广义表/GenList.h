#pragma once
#include<iostream>
#include<assert.h>
#include<stdlib.h>

template<class T>
struct Items                                               //����ֵ����ṹ����
{
	int utype;                                             //=0/1/2
	union                                                  //����
	{
		int ref;                                           //utype=0������ͷ��㣬������ü���
		T value;                                           //utype=1�������ֵ��
		GenListNode<T>* hlink;                             //utype=2�����ָ���ӱ��ָ��
	}info;
	Items():utype(0),info.ref(0){}                           //���캯��
	Items(Items<T>& RL) { utype = RL.utype; info = RL.info; }   //���ƹ��캯��
};

template<class T>
struct GenListNode                                            //��������ඨ��
{
public:
	GenListNode() :utype(0),tlink(NULL) ,info.ref(0);         //���캯��
	GenListNode(GenListNode<T>& RL) {                              //���ƹ��캯��
		utype = RL.utype; tlink = RL.tlink; info = RL.info;
	}
private:
	int utype;                                             //=0/1/2
	GenListNode<T>* tlink;                                  //ָ��ͬһ����һ������ָ��
	union                                                  //����
	{
		int ref;                                           //utype=0������ͷ��㣬������ü���
		T value;                                           //utype=1�������ֵ��
		GenListNode<T>* hlink;                             //utype=2�����ָ���ӱ��ָ��
	}info;
};

template<class T>
class GenList {                                              //�������ඨ��
public:
	GenList();                                              //���캯��
	~GenList();                                             //��������
	bool Head(Items& x);                                    //���ر�ͷԪ��x
	bool Tail(GenList<T>& lt);                              //���ر�βit
	GenListNode<T>* First();                                //���ص�һ��Ԫ��
	GenListNode<T>* Next(GenListNode<T>* elem);             //���ر�Ԫ��elem��ֱ�Ӻ��Ԫ��
	void Copy(const GenList<T>& R);                         //�����ĸ���
	int Length();                                           //��������ĳ���
	int depth();                                            //����һ���ǵݹ������
	friend isstream& operator >>(istream& in, GenList<T>& L);//��Ԫ������>>
private:
	GenListNode<T>* first;                                   //������ͷָ��
	GenListNode<T>* Copy(GenListNode<T>* ls);                //����һ��lsָʾ���޹���ǵݹ��
	int Length(GenListNode<T>* ls);                          //��lsָʾ�Ĺ������
	int depth(GenListNode<T>* ls);                           //������lsָʾ�ķǵݹ�����
	bool equal(GenListNode<T>* s, GenListNode<T>* t);        //�ж�s��t����Ϊ��ͷ�ı��Ƿ����
	void Remove(GenListNode<T>* ls);                         //�ͷ���lsΪ����ͷ���Ĺ����
	void Createlist(istream& in, GenListNode<T>*& ls);       //������������������������ַ�������������һ��������ͷ���Ĺ����ṹ
};

template<class T>
GenList<T>::GenList() {
	first = new GenListNode;                                 //���캯������������ͷ���
	assert(first != NULL);
}

template<class T>
bool GenList<T>::Head(Items<T>& x) {                         //���ص�һ��Ԫ��ֵx
	if (first->tlink == NULL) return false;
	else {
		x.utype = first->tlink->utype;
		x.info = first->tlink->info;
		return true;
	}
}

template<class T>
bool GenList<T>::Tail(GenList<T>& lt) {                       //ͨ��lt���ع�������ͷԪ����������Ԫ����ɵı�
	if (first->tlink == NULL) return false;
	else {
		lt.first->utype = 0;
		lt.first->info.ref = 0;
		lt.first->tlink = Copy(first->tlink->tlink);
		return true;
	}
}

template<class T>
GenListNode<T>* GenList<T>::First() {                        //���ع�����һ��Ԫ��
	if (first->tlink == NULL) return NULL;
	else return first->tlink;
}

template<class T>
GenListNode<T>* GenList<T>::Next(GenListNode<T>* elem) {        //���ر�Ԫ��elem��ֱ�Ӻ��Ԫ��
	if (elem->tlink == NULL)return NULL;
	else return elem->tlink;
}

template<class T> 
void GenList<T>::Copy(const GenList<T>& R) {                 //��������㷨
	first = Copy(R.first);                                   //���к���������˽�к���
}
template<class T>
GenListNode<T>* GenList<T>::Copy(GenListNode<T>* ls) {      //˽�к���������һ��lsָʾ���޹���ķǵݹ��
	GenListNode<T>* q = NULL;
	if (ls != NULL) {
		q = new GenListNode<T>;                             //����ǰ�Ľ��q
		q->utype = ls->utype;                               //���ƽ������
		switch (ls->utype)                                  //����utype������Ϣ
		{
		case 0:q->info.ref = ls->info.ref; break;           //����ͷ���
		case 1:q->info.value = ls->info.value; break;       //ԭ�ӽ��
		case 2:q->info.hlink = Copy(ls->info.hlink); break; //����
		default:
			break;
		}
		q->tlink = Copy(ls->tlink);                         //����ͬһ����һ�����Ϊͷ�ı�
	}
	return q;
}

template<class T>
int GenList<T>::Length() {                                  //���к�������ǰ�������
	return Length(first);
}
template<class T>
int GenList<T>::Length(GenListNode<T>* ls) {                //˽�к���������lsΪͷָ��Ĺ������
	if (ls != NULL)return 1 + Length(ls->tlink);
	else return 0;
}

template<class T>
int GenList<T>::depth() {                                 //���к���������һ���ǵݹ���������
	return depth(first);
}
template <class T>
int GenList<T>::depth(GenListNode<T>*ls) {                //˽�к���������ǵݹ��������
	if (ls->tlink == NULL)return 1;                       //�ձ����Ϊ1��
	GenListNode<T>* temp = ls->tlink;
	int m = 0, n;
	while (temp!=NULL)                                    //temp�ڹ�������ɨ
	{
		if (temp->utype == 2) {                           //ɨ�赽���utypeΪ����ʱ
			n = depth(temp->info.hlink);                  //�����Ըý��Ϊͷ�Ĺ�������
			if (m < n)m = n;                              //ȡ������
		}
		temp = temp->tlink;
	}
	return m + 1;                                        //�������
}

template<class T>
bool equal(GenListNode<T>* s, GenListNode<T>* t) {           //˽�к�����������ȣ���������true�����򷵻�false
	int x;
	if (s->tlink == NULL && t->tlink == NULL)return true;    //��s��t���ǿձ�
	if (s->tlink != NULL && t->tlink != NULL && s->tlink->utype == t->tlink->utype) {               //������ǿ��ҽ��������ͬ
		if (s->tlink->utype == 1) {                                                                  //ԭ�ӽ�㣬�Ƚ϶�Ӧ����
			x = (s->tlink->info.value == t->tlink->info.value) ? 1 : 0;                             
		}
		else if (s->tlink->utype == 2) {                                                            //�ӱ��㣬�ݹ�Ƚ������ӱ�
			x = equal(s->tlink->info.hlink, t->tlink->info.hlink);
		}
		if (x == 1) {                                                                              //��ȣ��ݹ�Ƚ�ͬһ�����һ�����
			return equal(s->tlink, t->tlink);
		}
	}
	return false;                                                                                  //���ȣ�����false
}

template<class T>
void delvalue(GenListNode<T>* ls, T x) {                                                           //ɾ������㷨
	if (ls->tlink != NULL) {                                                                       //�ǿձ�
		GenListNode<T>* p = ls->tlink;                                                             //�Ҹ���ͷ����ĵ�һ�����
		while (p!=NULL&&(p->utype==1&&p->info.value==x))
		{
			ls->tlink = p->tlink;                                                                  //������x��㣬ɾ����pָ��ͬ�����һ�����
			delete p;
			p = ls->tlink;
		}
		if (p!=NULL) {
			if (p->utype == 2) delvalue(p->info.hlink, x);                                         //���ӱ���ɾ��
			delvalue(p, x);                                                                        //����pΪ��ͷ�������еݹ�ɾ��
		}
	}
}

template<class T>
GenList<T>::~GenList() {                     //����������������ÿ������ͷ��㶼��һ�����ü�����
	Remove(first);
}
template<class T>
void GenList<T>::Remove(GenListNode<T>* ls) {                   //˽�к������ͷ���lsΪ��ͷָ��Ĺ����
	ls->info.ref--;                                             //����ͷ�������ô�����һ
	if (ls->info.ref <= 0) {                                    //�������0
		GenListNode<T>* q;
		while (ls->tlink!=NULL)                                 //��ɨ������
		{
			q = ls->tlink;                                      //����һ�����
			if (q->utype == 2) {                                //�ݹ�ɾ���ӱ�
				Remove(q->info.hlink);
				if (q->info.hlink->info.ref <= 0) delete q->info.hlink;       //ɾ���ӱ���ͷ���
			}
			ls->tlink = q->tlink;
			delete q;
		}
	}
}

#include<string.h>
template<class T>
void GenList<T>::Createlist(istream& in, GenListNode<T>*& ls) {

}