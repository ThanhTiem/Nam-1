#include <iostream>
using namespace std;

struct Node
{
	Node *pLeft;
	Node *pRight;
	int key;
};
typedef Node* Tree;
void CreateTree(Tree &T)
{
	T = NULL;
}
Node* CreateTNode(int x)
{
	Node *p = new Node;
	if (p == NULL)
	{
		return NULL;
	}
	p->pLeft = NULL;
	p->pRight = NULL;
	p->key = x;
	return p;
}
int InsertNode(Tree &Root, int x)
{
	if (Root == NULL){
		Root = CreateTNode(x);
	}
	Tree T = Root;
	while (T) {
		if (T->key == x) return 0;
		if (T->key > x) {
			if (T->pLeft == NULL){
				T->pLeft = CreateTNode(x);
			}
			else {
				T->pLeft = T;
			}
		}
		else {
			if (T->pRight == NULL) {
				T->pRight = CreateTNode(x);
			}
			else {
				T = T->pRight;
			}
		}
	}
	return 1;
}
int InsertLamLai(Tree &Root, int x)
{
	if (Root == NULL) {
		Root = CreateTNode(x);
	}
	Tree T = Root;
	while (T) {
		if (T->key == x) {
			return 0;
		}
		if (T->key > x) {
			if (T->pLeft == NULL) {
				T->pLeft = CreateTNode(x);
			}
			else {
				T = T->pLeft;
			}
		}
		else {
			if (T->pRight == NULL) {
				T->pRight = CreateTNode(x);
			}
			else {
				T = T->pRight;
			}
		}
	}
	return 1;
}
int InsertNodeDeQuy(Tree &T, int x)
{
	if (T->key == x) return 0;
	if (T->key > x) return InsertNodeDeQuy(T->pLeft, x);
	else return InsertNodeDeQuy(T->pRight, x);
	T = new Node;
	T = CreateTNode(x);
	return 1;
}
void InputTree(Tree &k)
{
	int x, n;
	cout << "\nNhap gia tri cua n: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\nNhap gia tri thu " << i + 1 << " : ";
		cin >> x;
		InsertNodeDeQuy(k, x);
	}
}

