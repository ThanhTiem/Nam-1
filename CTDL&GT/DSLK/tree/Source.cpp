#include <iostream>
#include <string>
using namespace std;

struct Node
{
	int key;
	Node *pLeft;
	Node *pRight;
};
typedef struct Node *Tree;
void CreateTree(Tree &t)
{
	t = NULL;
}
Node *CreateNode(int x)
{
	Node *p = new Node;
	if (p == NULL) {
		return NULL;
	}
	p->pLeft = p->pRight = NULL;
	p->key = x;
	return p;
}
int InsertNode(Tree &t, int x)
{
	if (t != NULL) {
		if (t->key == x) 
			return 0;
		if (t->key > x) 
			return InsertNode(t->pLeft, x);
		else 
			return InsertNode(t->pRight, x);
	}
	t = new Node;
	t = CreateNode(x);
	return 1;
}
void Input(Tree &t)
{
	int n, x;
	cout << "\nNhap vao so luong node: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\nNhap gia tri node thu " << i + 1 << " :";
		cin >> x;
		InsertNode(t, x);
	}
}
void LNR(Tree t)
{
	if (t != NULL) {
		LNR(t->pLeft);
		cout << "\t" << t->key;
		LNR(t->pRight);
	}
}
void XuatNodeChan(Tree t)
{
	if (t != NULL) {
		if (t->pLeft != NULL)
			XuatNodeChan(t->pLeft);
		if (t->key % 2 == 0)
			cout << "  " << t->key;
		if (t->pRight != NULL)
			XuatNodeChan(t->pRight);
	}
	
}
void XuatNodeLe(Tree t)
{
	if (t != NULL) {
		if (t->pLeft != NULL)
			XuatNodeLe(t->pLeft);
		if (t->key % 2 != 0)
			cout << "  " << t->key;
		if (t->pRight != NULL)
			XuatNodeLe(t->pRight);
	}
	
}
void TinhTongNodeLa(Tree t,int &S)
{
	
	if (t != NULL)
	{
		if (t->pLeft == NULL&&t->pRight == NULL)
			S += t->key;
		TinhTongNodeLa(t->pLeft, S);
		TinhTongNodeLa(t->pRight, S);
	}
}
int TinhTongCacNode(Tree t)
{
	if (t != NULL)
	{
		int a = TinhTongCacNode(t->pLeft);
		int b = TinhTongCacNode(t->pRight);
		if (t->key != NULL)
			return t->key + a + b;
		return a + b;
	}
	return 0;
}
bool KT_SNT(int a)
{
	if (a < 2)
		return false;
	for (int i = 2; i < sqrt(a); i++) {
		if (a%i == 0)
			return false;
	}
	return true;
}
int XuatSNT(Tree t)
{
	if (t != NULL) {
		int a = XuatSNT(t->pLeft);
		int b = XuatSNT(t->pRight);
		if (KT_SNT(t->key) == true)
			return 1 + a + b;
		return a + b;
	}
	return 0;
	
}
int TinhTongCacNode_SNT(Tree t)
{
	if (t != NULL) {
		int a = TinhTongCacNode_SNT(t->pLeft);
		int b = TinhTongCacNode_SNT(t->pRight);
		if (KT_SNT(t->key) == true)
			return t->key + a + b;
		return a + b;
	}
	return 0;
}

int main()
{
	Tree t;
	CreateTree(t);
	Input(t);
	cout << "\ncac node chan tren cay: ";
	XuatNodeChan(t);
	cout << "\nCac node le tren cay la: ";
	XuatNodeLe(t);
	cout << "\nSX theo LNR la: ";
	LNR(t);
	int S = 0;
	
	TinhTongNodeLa(t, S);
	cout << "\nTong cua cac node la: " << S;
	
	int n=TinhTongCacNode(t);
	cout << "\nTong cac node la: " << n;
	int a= XuatSNT(t);
	cout << "\nCac node co gia tri la SNT: " << a;
	
	int m = TinhTongCacNode_SNT(t);
	cout << "\nTong cac node co gia tri la SNT la: "<<m;
	system("pause");
	return 0;
}