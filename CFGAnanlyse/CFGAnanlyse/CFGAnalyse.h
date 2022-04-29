#pragma once
#include<iostream>
#include<cstring>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct CFGAnalyseNode
{
	char data;
	CFGAnalyseNode *right;
	CFGAnalyseNode *next;
	CFGAnalyseNode* createNewNode(char  data) {
		CFGAnalyseNode* newNode = (CFGAnalyseNode*)malloc(sizeof(CFGAnalyseNode));
		if (newNode == NULL) {
			cerr << "out of memory!\n";
			return NULL;
		}
		else
		{
			newNode->data = data;
			newNode->next = NULL;
			newNode->right = NULL;
			return newNode;
		}
	}
};

class CFGAnalyse
{
public:
	CFGAnalyse();
	~CFGAnalyse();

	bool isTerminal(char ch);
	bool isNonTerminal(char ch);
	void input();
	void show();

private:

	CFGAnalyseNode *first;
	CFGAnalyseNode *left;
	char S;
	int pnum = 0;
	set<char> Vn;
	set<char> Vt;
	set<char> NonTerminal;
	set<char> Terminal;
};

CFGAnalyse::CFGAnalyse()
{
	// 首先初始化Vn和Vt集合
	for (int i = 0x20; i < 0x7F; i++)
	{
		if (i >= 0x41 && i <= 0x5A)		Vn.insert(char(i));
		else	Vt.insert(char(i));
	}
}

CFGAnalyse::~CFGAnalyse()
{
	Vn.clear();
	Vt.clear();
	NonTerminal.clear();
	Terminal.clear();
}

bool CFGAnalyse::isTerminal(char ch)
{
	for (set<char>::iterator it = Vt.begin(); it != Vt.end(); it++)
		if (ch == *it) return true;
	return false;
}

bool CFGAnalyse::isNonTerminal(char ch)
{
	for (set<char>::iterator it = Vn.begin(); it != Vn.end(); it++)
		if (ch == *it) return true;
	return false;
}

void CFGAnalyse::input()
{
	left = first;

	string str;
	cin >> str;
	while(str != "$"){
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (i == 0) {
				if (pnum == 0) S = str[i];
				left->data = str[i];
				NonTerminal.insert(str[i]);
			}
			else if (i == 1 || i == 2) continue;
			else
			{
				if (str[i] == '|') {
					left = left->next;
					continue;
				}
				left = left->right;
				left->data = str[i];
				if (isNonTerminal(str[i]))	NonTerminal.insert(str[i]);
				else if (isTerminal(str[i]))	Terminal.insert(str[i]);
			}
		}
		left = first;
		left = left->next;
		pnum++;
		cin >> str;
	}
}

void CFGAnalyse::show()
{
	left = first;
	while (left->next != NULL) {
		cout << left->data;
		cout << "->";
		while (left->data!=NULL)
		{
			left = left->right;
			cout << left->data;
		}
		cout << endl;
	}
}