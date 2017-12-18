//#include <iostream>
//#include <string>
//using namespace std;
//
//struct Node
//{
//	int key;
//	Node *pLeft;
//	Node *pRight;
//};
//typedef struct Node *Tree;
//void CreatTree(Tree &T)
//{
//	T = NULL;
//}
//Node *CreateNodeTree(int x)
//{
//	Node *p = new Node;
//	if (p == NULL) {
//		return NULL;
//	}
//	p->pLeft = NULL;
//	p->pRight = NULL;
//	p->key = x;
//	return p;
//}
//int InsertNodeTree(Tree &T, int x)
//{
//	if (T != NULL) {
//		if (T->key == x) 
//			return 0;
//		if (T->key > x)
//			return InsertNodeTree(T->pLeft, x);
//		else
//			return InsertNodeTree(T->pRight, x);
//	}
//	T = new Node;
//	T = CreateNodeTree(x);
//	return 1;
//}
//void Input(Tree &T)
//{
//	int n, x;
//	cout << "\nNhap vao so luong phan tu cua cay: ";
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cout << "\nNhap node thu " << i << " : ";
//		cin >> x;
//		InsertNodeTree(T, x);
//	}
//}
//void NLR(Tree T)
//{
//	if (T != NULL) {
//
//		if(T->pLeft!=NULL)
//	}
//}
#include <iostream>
#include <cmath>
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
Node *CreateNodeTree(int x)
{
	Node *p = new Node;
	if (p == NULL) {
		return NULL;
	}
	p->pLeft = NULL;
	p->pRight = NULL;
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
	t = CreateNodeTree(x);
	return 1;
}
void Input(Tree &t)
{
	//int n, x;
	//cout << "\nNhap vao so luong phan tu cua cay: ";
	//cin >> n;
	int a[13] = { 52,36,21,28,11,48,39,50,78,60,84,80,90 };
	int n = 13;
	for (int i = 0; i < n; i++) {
		//cout << "\nNhap vao node thu " << i + 1 << " : ";
		//cin >> x;
		InsertNode(t, a[i]);
	}
}
void NLR(Tree t)
{
	if (t != NULL) {
		if (t->key != NULL)
			cout << "  " << t->key;
		if (t->pLeft != NULL)
			NLR(t->pLeft);
		if (t->pRight != NULL)
			NLR(t->pRight);
	}
}
void XuatNodeChan(Tree t)
{
	if (t != NULL) {
		if (t->pLeft != NULL)
			XuatNodeChan(t->pLeft);
		if (t->key % 2 == 0)
			cout << t->key << "  ";
		if (t->pRight != NULL)
			XuatNodeChan(t->pRight);
	}
}
void XuatNODEle(Tree t)
{
	if (t != NULL) {
		if (t->pLeft != NULL)
			XuatNODEle(t->pLeft);
		if (t->key % 2 != 0)
			cout << t->key << "  ";
		if (t->pRight != NULL)
			XuatNODEle(t->pRight);
	}
}
bool KT_SNT(int n)
{
	if (n <= 1)
		return false;
	for (int i = 2; i<n; i++)
		if (n%i == 0)
			return false;
	return true;
}
void XuatNodeLaSNT(Tree t)
{
	if (t != NULL) {
		XuatNodeLaSNT(t->pLeft);
		if (KT_SNT(t->key) == true)
			cout << t->key << "  ";
		XuatNodeLaSNT(t->pRight);
	}
}
bool KT_SHT(int n)
{
	int S = 0;
	for (int i = 1; i < n; i++) {
		if (n%i == 0)
			S += i;
	}
	if (S == n)
		return true;
	return false;
}
void XuatNode_SHT(Tree t)
{
	if (t != NULL) {
		XuatNode_SHT(t->pLeft);
		if (KT_SHT(t->key) == true)
			cout << t->key << "  ";
		XuatNode_SHT(t->pRight);
	}
}
void XuatLonHonX_NhoHonY(Tree t, int x, int y)
{
	if (t != NULL) {
		XuatNode_SHT(t->pLeft);
		if (t->key > x && t->key < y)
			cout << t->key << "  ";
		XuatNode_SHT(t->pRight);
	}

}
void XuatTangK(Tree t, int k)
{
	if (t != NULL) {
		k--;
		if(t->pLeft!=NULL)
			XuatTangK(t->pLeft, k);
		if (k == 0)
			cout << t->key << "  ";
		if (t->pRight != NULL)
			XuatTangK(t->pRight, k);
	}
}
int ChieuCaoCay(Tree t)
{
	if (t != NULL) {
		int a = ChieuCaoCay(t->pLeft);
		int b = ChieuCaoCay(t->pRight);
		//return (a > b ? a : b) + 1;
		if (a > b) return a + 1;
		return b + 1;
	}
}
void XuatTheoThuTuTang_k(Tree t)
{
	int h = ChieuCaoCay(t);
	cout << "\nChieu cao cua cay: " << h;
	for (int i = 0; i <= h-1; i++) {
		cout << "\nTang thu: " << i << " : ";
		XuatTangK(t, i+1);
		cout << endl;
	}
}
int DemNodeCo1Con(Tree t)
{
	if (t != NULL) {
		int a = DemNodeCo1Con(t->pLeft);
		int b = DemNodeCo1Con(t->pRight);
		if ((t->pLeft != NULL && t->pRight == NULL) || (t->pLeft != NULL && t->pRight == NULL))
			return 1 + a + b;
		return a + b;
	}
	return 0;
}
int DemNodeCo2Con(Tree t)
{
	if (t != NULL) {
		int a = DemNodeCo2Con(t->pLeft);
		int b = DemNodeCo2Con(t->pRight);
		if (t->pLeft != NULL&&t->pRight != NULL)
			return 1 + a + b;
		return a + b;
	}
	return 0;
}
int DemNodeChan(Tree t)
{
	if (t != NULL) {
		int a = DemNodeCo2Con(t->pLeft);
		int b = DemNodeCo2Con(t->pRight);
		if (t->pLeft != NULL&&t->pRight != NULL)
			return 1 + a + b;
		return a + b;
	}
	return 0;
}
int DemNodeLaChan(Tree t)
{
	if (t != NULL) {
		int a = DemNodeLaChan(t->pLeft);
		int b = DemNodeLaChan(t->pRight);
		if (t->key % 2 == 0 &&t->pLeft==NULL&&t->pRight==NULL)
			return 1 + a + b;
		return a + b;
	}
	return 0;
}
bool Check_SNT(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i < sqrt(x); i++) {
		if (x%i == 0)
			return false;
	}
	return true;
}
int DemNodeSNT(Tree t)
{
	if (t != NULL) {
		int a = DemNodeSNT(t->pLeft);
		int b = DemNodeSNT(t->pRight);
		if ((Check_SNT(t->key) == true&&(t->pLeft!=NULL&&t->pRight==NULL)) || (Check_SNT(t->key)==true &&(t->pLeft==NULL&&t->pRight==NULL)))
			return 1 + a + b;
		return a + b;
	}
	return 0;
}
bool Check_SCP(int n) 
{
	if (n <= 0)
		return true;
	int S = sqrt((double)n);
	if (S*S == n)
		return true;
	return false;
}
int DemSoChinhPhuong(Tree t)
{
	if (t != NULL) {
		int a = DemSoChinhPhuong(t->pLeft);
		int b = DemSoChinhPhuong(t->pRight);
		if (Check_SCP(t->key) == true)
			if (t->pLeft != NULL && t->pRight != NULL)
				return 1 + a + b;
		return a + b;
	}
	return 0;
}
int DemNodeTang_K(Tree t, int k)
{
	if (t != NULL) {
		k--;
		int a = DemNodeTang_K(t->pLeft, k);
		int b = DemNodeTang_K(t->pRight, k);
		if (k == 0)
			return 1 + a + b;
		return a + b;
	}
	return 0;
}
int DemNodeThapHonTang_k(Tree t, int k)
{
	if (t != NULL) {
		k--;
		int Dem = 0;
		for (int i = 0; i < k; i++) {
			Dem += DemNodeTang_K(t, k);
		}
		return Dem;
	}
	return 0;
}
int ChieuCaoCuaCay(Tree t)
{
	if (t != NULL) {
		int a = ChieuCaoCuaCay(t->pLeft);
		int b = ChieuCaoCuaCay(t->pRight);
		return (a > b ? a : b) + 1;
	}
	return 0;
}
int DemNodeCaoHonTang_k(Tree t, int k)
{
	if (t != NULL) {
		int Dem = 0;
		for (int i = 0; i < ChieuCaoCuaCay(t); i++) {
			Dem += DemNodeTang_K(t, k);
		}
		return Dem;
	}
	return 0;
}
int TongCacNode(Tree t)
{
	if (t != NULL) {
		int a = TongCacNode(t->pLeft);
		int b = TongCacNode(t->pRight);
		if (t->key != NULL)
			return t->key + a + b;
		return a + b;
	}
	return 0;
}
int TongNodeLa(Tree t)
{
	if (t != NULL) {
		int a = TongNodeLa(t->pLeft);
		int b = TongNodeLa(t->pRight);
		if (t->pLeft == NULL&&t->pRight == NULL)
			return t->key + a + b;
		return a + b;
	}
	return 0;
}
int TongNode1Con(Tree t)
{
	if (t != NULL) {
		int a = TongNode1Con(t->pLeft);
		int b = TongNode1Con(t->pRight);
		if (t->pLeft != NULL&&t->pRight != NULL)
			return t->key + a + b;
		return a + b;
	}
	return 0;
}
int TongNode2Con(Tree t)
{
	if (t != NULL) {
		int a = TongNode2Con(t->pLeft);
		int b = TongNode2Con(t->pRight);
		if ((t->pLeft != NULL&&t->pRight == NULL) || (t->pLeft == NULL&&t->pRight != NULL))
			return t->key + a + b;
		return a + b;
	}
	return 0;
}
int TongNodeLe(Tree t)
{
	if (t != NULL) {
		int a = TongNodeLe(t->pLeft);
		int b = TongNodeLe(t->pRight);
		if (t->key%2 == 0)
			return t->key + a + b;
		return a + b;
	}
	return 0;
}
int TongNodeLaChan(Tree t)
{
	if (t != NULL) {
		int a = TongNodeLaChan(t->pLeft);
		int b = TongNodeLaChan(t->pRight);
		if (t->key % 2 == 0)
			if (t->pLeft == NULL&&t->pRight == NULL)
				return t->key + a + b;
		return a + b;
	}
	return 0;
}
int TongNode1Con_SNT(Tree t)
{
	if (t != NULL) {
		int a = TongNode1Con_SNT(t->pLeft);
		int b = TongNode1Con_SNT(t->pRight);
		if (Check_SNT(t->key)==true)
			if ((t->pLeft != NULL&&t->pRight == NULL)|| (t->pLeft != NULL&&t->pRight == NULL))
				return t->key + a + b;
		return a + b;
	}
	return 0;
}
int TongNode2Con_SCP(Tree t)
{
	if (t != NULL) {
		int a = TongNode1Con_SNT(t->pLeft);
		int b = TongNode1Con_SNT(t->pRight);
		if (Check_SCP(t->key) == true)
			if (t->pLeft != NULL && t->pRight != NULL)
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
	cout << "\nXuat Node theo NLR: ";
	NLR(t);
	cout << "\nCac Node co gia tri la so chan: ";
	XuatNodeChan(t);
	cout << "\nCac Node co gia tri la so le: ";
	XuatNODEle(t);
	cout << "\nCac node co gia tri la so nguyen to: ";
	XuatNodeLaSNT(t);
	cout << "\nCac node co gia tri la so hoan thien la: ";
	XuatNode_SHT(t);
	int x, y;
	cout << "\nNhap vao x, y: ";
	cin >> x >> y;
	cout << "\nGia tri node lon hon x va nho hon y la: ";
	XuatLonHonX_NhoHonY(t, x, y);
	int k;
	cout << "\nNhap vao tang K can xuat: ";
	cin >> k;
	cout << "\nCac node trên tang thu " << k << " cua cay la: ";
	XuatTangK(t, k);
	cout << "\nXuat theo thu tu tang tu 0 den h-1 la: ";
	XuatTheoThuTuTang_k(t);
	cout << "\nSo node co dung mot con la: "<<DemNodeCo1Con(t);
	cout << "\nSo node co dung 2 con la: ";
	cout << DemNodeCo2Con(t);
	cout << "\nSo luong node co gia tri la so chan la: ";
	cout << DemNodeChan(t);
	cout << "\nSo luong node la ma thong tin tai do co gia tri la node chan la: ";
	cout << DemNodeLaChan(t);
	cout << "\nSO node la co gia tri la SNT la: ";
	cout << DemNodeSNT(t);
	cout << "\nDo node co dung 2 con la so chinh phuong: ";
	cout << DemSoChinhPhuong(t);
	cout << "\nSo luong node tren tang thu " << k << " cua cay la: ";
	cout << DemNodeTang_K(t, k);
	cout << "\nSo luong node THAP hon tang thu " << k << " cua cay la: ";
	cout << (t, k);
	cout << "\nSo luong node CAO hon tang thu " << k << " cua cay la: ";
	cout << DemNodeCaoHonTang_k(t, k);
	cout << "\nTong cac node trong cay la: ";
	cout << TongCacNode(t);
	cout << "\nTong cac node la trong cay: ";
	cout << TongNodeLa(t);
	cout << "\nTong cac node co dung mot con la: ";
	cout << TongNode1Con(t);
	cout << "\nTong cac node co dung 2 con la: ";
	cout << TongNode2Con(t);
	cout << "\nTong cac node le la: ";
	cout << TongNodeLe(t);
	cout << "\nTong cac node la co gia tri la so chan: ";
	cout << TongNodeLaChan(t);
	cout << "\nTong cac node co dung 1 con co gia tri la SNT: ";
	cout << TongNode1Con_SNT(t);
	cout << "\nTong cac node co dung 2 con ma thong tin tai do co gia tri la SCP: ";
	cout << TongNode2Con_SCP(t);
	//cout<<"\nTong"
	system("pause");
	return 0;
}