#include <iostream>
using namespace std;

//khai bao mot node _list:
struct Node
{
	int Data;
	struct Node *pNext;
};
typedef struct Node NODE;
struct List
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct List LIST;

//khoi tao danh sach list:
void CreateList(LIST &l)
{
	l.pHead = l.pTail = NULL;
}
// khoi tao mot node:
NODE* CreateNode(int x)
{
	NODE *p = new NODE;
	if (p == NULL) {
		return NULL;
	}
	p->Data = x;
	p->pNext = NULL;
	return p;
}
//Them mot node:
void AddHead(LIST &l, NODE *p)
{
	if (l.pHead == NULL) {
		l.pHead = l.pTail = NULL;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AddTail(LIST &l, NODE *p)
{
	if (l.pHead == NULL){
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext =p;
		l.pTail = p;
	}
}
//Nhap du lieu cho danh sach:
void input(LIST &l, int n)
{
	CreateList(l);
	for (int i = 1; i <= n; i++) {
		int x;
		cout << "\nNhap vao data: ";
		cin >> x;
		NODE *p = CreateNode(x);
		AddHead(l, p);
	}
}

void OutPut(LIST l)
{
	for (NODE *p = l.pHead; p != NULL; p = p->pNext) {
		cout << p->Data << "\t";
	}
}
//=============Cac BT theo yeu cau=======:
int TimMax(LIST l)
{
	int Max = l.pHead->Data;
	for (NODE *p = l.pHead->pNext; p != NULL; p = p->pNext){
		if (p->Data > Max) {
			Max = p->Data;
		}
	}
	return Max;
 }
int TinhTong(LIST l)
{
	int S = 0;
	for (NODE *p = l.pHead; p != NULL; p = p->pNext) {
		S += p->Data;
	}
	return S;
}
void HoanVi(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
void SapXep(LIST &l)
{
	for (NODE *p = l.pHead; p != NULL; p = p->pNext){
		for (NODE *q = p->pNext; q != NULL; q = q->pNext){
			if (q->Data > p->Data) {
				HoanVi(q->Data, p->Data);
			}
		}
	}
}
//Them Node P sau Node Q
NODE* SearchNode (LIST l, int x)
{
	NODE *p = l.pHead;
	while (l.pHead != NULL && p->Data !=x) {
		p = p->pNext;
	}
	return p;
}
void AddAfter_Q(LIST &l, NODE*p, NODE* q)
{
	if (q != NULL) {
		p->pNext = q->pNext = p;
		if (l.pTail == q) {
			l.pTail = p;
		}
	}
	else {
		AddHead(l, p);
	}
}
void Add(LIST &l, int y, int x)
{
	NODE *p = CreateNode(y);
	NODE *Q = SearchNode(l, x);
	if (Q != NULL) {
		AddAfter_Q(l, p, Q);
	}
}
int main()
{
	LIST l;
	int n;
	cout << "\nNhap so node ban can: ";
	cin >> n;
	input(l, n);
	OutPut(l);
	int Max = TimMax(l);
	cout << "\nNode lon nhat la: " << Max;
	system("pause");
	return 0;
}