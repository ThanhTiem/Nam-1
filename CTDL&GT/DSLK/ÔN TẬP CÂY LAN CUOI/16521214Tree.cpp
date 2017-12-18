#include <iostream>
#include <cmath>
using namespace std;
struct Node
{
	int key;
	Node *pLeft;;
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
	int n, x;
	cout << "\nNhap so luong phan tu cua cay: ";
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cout << "\nNhap vao phan tu thu " << i + 1 << " : ";
		cin >> x;
	}
}void XuatRLN(Tree t)
{
	if (t != NULL) {
		if (t->pRight != NULL)
			XuatRLN(t->pRight);
		if (t->pLeft != NULL)
			XuatRLN(t->pLeft);
		if (t->key != NULL)
			cout << t->key << "  ";
	}
}
void XuatNLR(Tree t)
{
	if (t != NULL) {
		if (t->key != NULL)
			cout << t->key << "  ";
		if (t->pLeft != NULL)
			XuatRLN(t->pLeft);
		if (t->pRight != NULL)
			XuatRLN(t->pRight);
	}
}
bool Check_SNT(int a)
{
	if (a < 2)
		return false;
	for (int i = 2; i < sqrt((float)a); i++) {
		if (a%i == 0)
			return false;
	}
	return true;
}
bool Check_SHT(int n)
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
void XuatNodeSNT(Tree t)
{
	if (t != NULL) {
		XuatNodeSNT(t->pLeft);
		XuatNodeSNT(t->pRight);
		if (Check_SNT(t->key) == true)
			cout << t->key << "  ";
	}
}
void XuatNodeSHT(Tree t)
{
	if (t != NULL) {
		if(t->pLeft!=NULL)
			XuatNodeSHT(t->pLeft);
		if (Check_SHT(t->key) == true)
			cout << t->key << "  ";
		if (t->pRight != NULL)
			XuatNodeSHT(t->pRight);
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
void XuatLonHonX_NhoHonY(Tree t, int x, int y)
{
	
	if (t != NULL) {
		if (t->pLeft != NULL)
			XuatLonHonX_NhoHonY(t->pLeft, x, y);
		if (t->key > x&&t->key < y)
			cout << t->key << "  ";
		if (t->pRight != NULL)
			XuatLonHonX_NhoHonY(t->pRight, x, y);
	}
}
void XuatNodeTang_K(Tree t, int k)
{
	if (t != NULL) {
		k--;
		if (t->pLeft != NULL)
			XuatNodeTang_K(t->pLeft,k);
		if (k==0)
			cout << t->key << "  ";
		if (t->pRight != NULL)
			XuatNodeTang_K(t->pRight,k);
	}
}
int ChieuCao(Tree t)
{
	if (t != NULL) {
		int a = ChieuCao(t->pLeft);
		int b = ChieuCao(t->pRight);
		return (a > b ? a : b) + 1;
	}
	return 0;
}
void XuatTheoThuTuTangK(Tree t)
{
	int h = ChieuCao(t);
	//cout << "\nChieu cao cua cay: " << h;
	for (int i = 0; i <= h - 1; i++) {
		cout << "\nTang thu: " << i << " : ";
		XuatNodeTang_K(t, i + 1);
		cout << endl;
	}
}
int DemNode1Con(Tree t)
{
	if (t != NULL) {
		int a = DemNode1Con(t->pLeft);
		int b = DemNode1Con(t->pRight);
		if ((t->pLeft != NULL&&t->pRight == NULL) || (t->pLeft == NULL&&t->pRight != NULL))
			return 1 + a + b;
		return a + b;
	}
	return 0;
}
int DemNode2Con(Tree t)
{
	if (t != NULL) {
		int a = DemNode2Con(t->pLeft);
		int b = DemNode2Con(t->pRight);
		if ((t->pLeft != NULL&&t->pRight != NULL))
			return 1 + a + b;
		return a + b;
	}
	return 0;
}
int DemNodeChan(Tree t)
{
	if (t != NULL) {
		int a = DemNodeChan(t->pLeft);
		int b = DemNodeChan(t->pRight);
		if (t->key % 2 == 0)
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
		if ((t->pLeft == NULL&&t->pRight == NULL))
			return 1 + a + b;
		return a + b;
	}
	return 0;
}
int DemNode2ConLaSNT(Tree t)
{
	if (t != NULL) {
		int a = DemNode2ConLaSNT(t->pLeft);
		int b = DemNode2ConLaSNT(t->pRight);
		if (t->pLeft != NULL&&t->pRight != NULL && Check_SNT(t->key) == true)
			return 1 + a + b;
		return a + b;
	}
	return 0;
}
bool Check_SCP(int n)
{
	if (n <= 0)
		return false;
	int S = sqrt((float)n);
	if (S*S == n)
		return true;
	return false;
}
int DemNode2ConLaSCP(Tree t)
{
	if (t != NULL) {
		int a = DemNode2ConLaSCP(t->pLeft);
		int b = DemNode2ConLaSCP(t->pRight);
		if (t->pLeft != NULL&&t->pRight != NULL && Check_SCP(t->key) == true)
			return 1 + a + b;
		return a + b;
	}
	return 0;
}
void TimMax(Tree t, int &Max)
{
	if (t == NULL)
		return;
	if (t->pLeft != NULL)
		Max = (Max > t->pLeft->key) ? Max : t->pLeft->key;
	if (t->pRight != NULL)
		Max = (Max > t->pRight->key) ? Max : t->pRight->key;
	Max = (Max > t->key) ? Max : t->key;
	TimMax(t->pLeft, Max);
	TimMax(t->pRight, Max);
}


int KiemTra(Tree t)
{
	if (t == NULL)
		return 0;
	int Left = KiemTra(t->pLeft);
	int MaxL, MaxR;
	if (t->pLeft != NULL && t->pRight != NULL)
	{
		TimMax(t->pLeft, MaxL);
		TimMax(t->pRight, MaxR);
		if (!(MaxL < t->key && t->key < MaxR))
			return 1;
	}
	else if (t->pLeft == NULL && t->pRight != NULL)
	{
		TimMax(t->pRight, MaxR);
		if (!(t->key < MaxR))
			return 1;
	}
	else if (t->pLeft != NULL && t->pRight == NULL)
	{
		TimMax(t->pLeft, MaxL);
		if (!(MaxL < t->key))
			return 1;
	}
	int Right = KiemTra(t->pRight);
	return Left + Right;
}
void XuatKqKiemTra(Tree t)
{
	int Kt = KiemTra(t);
	if (Kt == 0)
		cout<<"\nLa cay nhi phan tim kiem";
	else
		cout<<"\nKhong phai cay nhi phan tim kiem";
}
int DemNodeTangK(Tree t, int k)
{
	if (t != NULL) {
		k--;
		int a = DemNodeTangK(t->pLeft, k);
		int b = DemNodeTangK(t->pRight, k);
		if (k == 0)
			return 1 + a + b;
		return a + b;
	}
	return 0;
}
int DemNodeThapHonTangK(Tree t, int k)
{
	if (t != NULL) {
		int dem = 0;
		for (int i = 0; i < k; i++) {
			dem = dem + DemNodeTangK(t, k);
		}
		return dem;
	}
	return 0;
}
int DemNodeCaoHonTangK(Tree t, int k)
{
	if (t != NULL) {
		int dem = 0;
		for (int i = k; i < ChieuCao(t); i++) {
			dem = dem + DemNodeTangK(t, k);
		}
		return dem;
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
int TongNodeLaLe(Tree t)
{
	if (t != NULL) {
		int a = TongCacNode(t->pLeft);
		int b = TongCacNode(t->pRight);
		if (t->pLeft == NULL&&t->pRight == NULL && t->key % 2 != 0)
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
	cout << "\nXuat theo NLR: ";
	XuatNLR(t);
	cout << "\nXuat theo RLN: ";
	XuatRLN(t);
	cout << "\nCac SNT: ";
	XuatNodeSNT(t);
	cout << "\nCac SHT: ";
	XuatNodeSHT(t);
	cout << "\nCac Node chan: ";
	XuatNodeChan(t);
	int x, y;
	cout << "\nNhap node x va y: ";
	cin >> x >> y;
	XuatLonHonX_NhoHonY(t, x, y);
	int k;
	cout << "\nNhap tang thu K: ";
	cin >> k;
	cout << "\nCac node treen tang thu thu " << k << " cua cay la: ";
	XuatNodeTang_K(t, k);
	cout << "\nCac node tu tang 0 den h-1 la: ";
	XuatTheoThuTuTangK(t);
	cout << "\nSo luong Node 1 con: ";
	cout << DemNode1Con(t);
	cout << "\nSo luong node 2 con: ";
	cout << DemNode2Con(t);
	cout << "\nSo luong node chan: ";
	cout << DemNodeChan(t);
	cout << "\nSo luong node LA co gia tri chan: ";
	cout << DemNodeLaChan(t);
	cout << "\nSo luong node co 2 con la SNT: ";
	cout << DemNode2ConLaSNT(t);
	cout << "\nSo luong node co 2 con la SCP: ";
	cout << DemNode2ConLaSCP(t);
	cout << "\nSO luong node tren tang thu K: ";
	cout << DemNodeTangK(t, k);
	cout << "\nSo luong node thap hon tang k: ";
	cout << DemNodeThapHonTangK(t, k);
	cout << "\nSo luong node cao hon tang thu k la: ";
	cout << DemNodeCaoHonTangK(t, k);
	cout << "\nTong cac node trong cay: ";
	cout << TongCacNode(t);
	cout << "\nTong cac node la le: ";
	cout << TongNodeLaLe(t);
	cout << "\nChieu cao cua cay la: " << ChieuCao(t);
	XuatKqKiemTra(t);
	cout << endl;
	system("pause");
	return 0;
}