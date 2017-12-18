//#include <iostream>
//using namespace std;
////1, khai bao cau truc du lieu danh sach lien ket don:
//
//struct Node
//{
//	int Data;
//	struct Node* pNext;
//};
//typedef struct Node NODE;
//struct List
//{
//	NODE *pHead;
//	NODE *pTail;
//};
//typedef struct List LIST;
//
//
////2, Khoi tao 1 list:
//void CreateList(LIST &l)
//{
//	l.pHead = l.pTail = NULL;
//}
////3, Tao node trong danh sach:
//NODE * CreateNode(int x)
//{
//	NODE *p = new NODE;
//	if (p == NULL) 
//	{
//		return NULL;
//	}
//	p->Data = x;
//	p->pNext = NULL;
//	return p;
//}
////4, Them NODE:
////+, Them vao dau danh sach:
//void AddHead(LIST &l, NODE *p)
//{
//	if (l.pHead == NULL)// tuc la ds rong
//	{
//		l.pHead = l.pTail = p;
//	}
//	else
//	{
//		p->pNext = l.pHead;
//		l.pHead = p;
//	}
//}
////+, them vao cuoi danh sach:
//void AddTail(LIST &l, NODE *p)
//{
//	if (l.pHead == NULL)
//	{
//		l.pHead = l.pTail = p;
//	}
//	else
//	{
//		l.pTail = p->pNext = p;
//		l.pTail = p;
//	}
//}
////5, Nhap du lieu cho danh sach:
//void Input(LIST &l, int n)
//{
//	CreateList(l);
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cout << "\nNhap vao Data: ";
//		cin >> x;
//		NODE *p = CreateNode(x);
//		AddTail(l, p);
//	}
//}
//void Output(LIST l)
//{
//	for (NODE *p = l.pHead; p != NULL; p = p->pNext)
//	{
//		cin >> p->Data;
//	}
//}
//int TimMax(LIST l)
//{
//	int max = l.pHead->Data;
//	for (NODE *p = l.pHead->pNext; p != NULL; p = p->pNext)
//	{
//		if (p->Data > max)
//		{
//			max = p->Data;
//		}
//	}
//	return max;
//}
//void HoanVi(int a, int b)
//{
//	int temp = a;
//	b = temp;
//	a = b;
//}
//void Sort(LIST &l)
//{
//	for (NODE *p = l.pHead; p != l.pTail; p = p->pNext)
//	{
//		for (NODE *q = p->pNext; q != NULL; q=q->pNext)
//		{
//			if (p->Data > q->Data)
//			{
//				HoanVi(p->Data, q->Data);
//			}
//		}
//	}
//}
//int TinhTong(LIST l)
//{
//	int Sum = 0;
//	for (NODE *p = l.pHead; p != NULL; p = p->pNext)
//	{
//		Sum += p->Data;
//	}
//	return Sum;
//}
////6, Them mot NODE p vao sau NODE q:
////void ThemSau(LIST &l, NODE *p, NODE *q)
////{
////
////}
//int main()
//{
//	LIST l;
//	int n;
//
//	cout << "\nNhap so NODE ban can nhap: ";
//	cin >> n;
//	Input(l, n);
//	Output(l);
//	int Max = TimMax(l);
//	cout << "\nMax la: " << Max;
//	system("pause");
//	return 0;
//}
#include <iostream>
using namespace std;

// 1: Khai báo cấu trúc dữ liệu danh sách liên kết đơn các số nguyên

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

// 2. Khởi tạo danh sách liên kết đơn
void Init(LIST &l)
{
	l.pHead = l.pTail = NULL;
}

// 3. Tạo Node trong danh sách
NODE* GetNode(int x) // x chính là dữ liệu đưa vào Data
{
	// Cấp phát 1 Node
	NODE *p = new NODE;

	if (p == NULL)
	{
		return NULL;
	}
	p->Data = x; // Lưu x vào data
	p->pNext = NULL; // Khởi tạo mối liên kết
	return p;
}

// 4. Thêm Node (thêm đầu hoặc cuối)

// Thêm Node p vào đầu danh sách
void AddHead(LIST &l, NODE *p)
{
	if (l.pHead == NULL) // Tức là danh sách bị rỗng
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead; // p quăng dây để tham gia vào danh sách
		l.pHead = p; // p chính thức đã đứng dầu danh sách
	}
}

// Thêm Node p vào cuối danh sách
void AddTail(LIST &l, NODE *p)
{
	if (l.pHead == NULL) // Tức là danh sách bị rỗng
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p; // l.pTail quăng dây nối với p
		l.pTail = p;
	}
}

// 5. Nhập dữ liệu cho danh sách
void InPut(LIST &l, int n)
{

	Init(l); // Khởi tạo danh sách.
	for (int i = 1; i <= n; i++)
	{
		// Mỗi lần vòng lặp chạy là ta nhập 1 Node
		int x;
		cout <<"\nNhap vao data: ";
		cin>>x;

		NODE *p = GetNode(x); // Đưa data vào Node p, tạo ra node p
		AddTail(l, p); // Thêm Node p vào cuối danh sách.
					   //AddHead(l, p);
	}
}

void OutPut(LIST l)
{
	
	for (NODE *p = l.pHead; p != NULL; p = p->pNext)
	{
		cout << p->Data << "\t";
	}
}

int TimMax(LIST l)
{
	
	int Max = l.pHead->Data;
	for (NODE *p = l.pHead->pNext; p != NULL; p = p->pNext)
	{
		if (p->Data > Max)
		{
			Max = p->Data;
		}
	}
	return Max;
}
int TinhTong(LIST l)
{
	int S = 0;
	for (NODE *p = l.pHead; p != NULL; p = p->pNext)
	{
		S += p->Data;
	}
	return S;
}
void HoanVi(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void Sort(LIST &l)
{
	for (NODE *p = l.pHead; p != l.pTail; p = p->pNext)
	{
		for (NODE *q = p->pNext; q != NULL; q = q->pNext)
		{
			if (q->Data > p->Data)
			{
				HoanVi(p->Data, q->Data);
			}
		}
	}
}
// Them motj node p vao sau node q:
void ThemSau(LIST &l, NODE *p, NODE *q)
{
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->Data == q->Data)
		{
			NODE *g = k->pNext;
			k->pNext = p; 
			p->pNext = g;
			return;
		}
	}
}
void AddAfter_Q(LIST &l, NODE *p, NODE *q)
{
	if (q != NULL)
	{
		p->pNext = q->pNext;
		q->pNext = p;
		if (l.pTail == q)
		{
			l.pTail = p;
		}
	}
	else
	{
		AddHead(l, p);
	}
}

int main()
{
	LIST l;
	int n;
	cout<<"\nBan muon nhap bao nhieu Node: ";
	cin >> n;
	InPut(l, n);
	OutPut(l);
	int Max = TimMax(l);
	cout << "\nMax la: " <<  Max;
	int Tong = TinhTong(l);
	cout << "\nTong la: " << Tong;
	float TBC = (float) Tong / n;
	cout << "\nTBC la: " << TBC << endl;
	Sort(l);
	cout << "\nDanh sach duoc sx lai: ";
	OutPut(l);

	int q, p;
	cout << "\nNhap q vao: ";
	cin >> q;
	NODE *Q = GetNode(q);
	cout << "\nNhap vao p: ";
	cin >> p;
	NODE *P = GetNode(p);
	AddAfter_Q(l, P, Q);
	ThemSau(l, Q, P);
	cout << "\nDS sau khi them la: ";
	
	OutPut(l);
	system("pause");
	return 0;
}