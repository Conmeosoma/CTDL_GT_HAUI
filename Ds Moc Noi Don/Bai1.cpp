#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int n;

// khoi tao doi tuong
struct SINHVIEN
{
  string maSv;
  string hoDem;
  string ten;
  string gioiTinh;
  int namSinh;
  double diemTk;
};

// nodeee
struct Node
{
  SINHVIEN infor;
  Node *next;
};

//
typedef Node *TRO;
// khoi tao rong
void create(TRO *L)
{
  L = NULL;
}
// check rong
int Empty(TRO L)
{
  return L == NULL;
}

// tao node moi
TRO taoNode(SINHVIEN x)
{
  TRO P = new Node;
  P->infor = x;
  P->next = NULL;
  return P;
}

// them vao cuoi
void themCuoi(TRO &L, SINHVIEN x)
{
  TRO P = taoNode(x);
  if (Empty(L))
  {
    L = P;
  }
  else
  {
    TRO Q = L;
    while (Q->next != NULL)
    {
      Q = Q->next;
    }
    Q->next = P;
  }
}

// nhap danh sach sinh vien
void nhapDSSV(TRO &L)
{
  do
  {
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
  } while (n < 5);

  for (int i = 0; i < n; i++)
  {
    SINHVIEN x;
    cout << "Nhap Sv thu: " << i + 1 << ": " << endl;
    cout << "Nhap ma Sv: ";
    getline(cin, x.maSv);
    cout << "Nhap hoDem: ";
    getline(cin, x.hoDem);
    cout << "Nhap ten: ";
    getline(cin, x.ten);
    cout << "Nhap gioi tinh: ";
    getline(cin, x.gioiTinh);
    cout << "Nhap nam sinh: ";
    cin >> x.namSinh;
    cout << "Nhap diem tong ket: ";
    cin >> x.diemTk;
    themCuoi(L, x);
  }
}
// in ra thong tin
void show(TRO L)
{
  if (Empty(L))
  {
    cout << "Ds rong";
    return;
  }
  cout << "STT" << setw(5) << "Ma Sinh Vien" << setw(15) << "Ho Dem" << setw(15) << "Ten" << setw(15) << "Gioi tinh" << setw(5) << "Nam sinh" << setw(5) << "Diem tong ket" << endl;
  TRO P = L;
  int i = 0;
  while (P != NULL)
  {
    cout << i + 1 << setw(5) << P->infor.maSv << setw(15) << P->infor.hoDem << setw(15) << P->infor.ten << setw(15) << P->infor.gioiTinh << setw(5) << P->infor.namSinh << setw(5) << P->infor.diemTk << endl;
    i++;
  }
}
// xoa Sinh vien dau tien
void xoadau(TRO &L)
{
  if (Empty(L))
  {
    return;
  }
  else
  {
    TRO Q = L;
    L = L->next;
    delete Q;
  }
}

// Tinh trung binh cong tong ket
double TBC(TRO L)
{
  if (Empty(L))
  {
    return 0;
  }
  else
  {
    double tong = 0;
    int dem = 0;
    TRO P = L;
    while (P != NULL)
    {
      tong += P->infor.diemTk;
      dem++;
      P = P->next;
    }
    if (dem == 0)
    {
      return 0;
    }
    else
    {
      return tong / dem;
    }
  }
}

// Chen sinh vien
void chen_vt3(TRO &L, SINHVIEN x)
{
  TRO P = taoNode(x);
  if (Empty(L) || L->next == NULL)
  {
    themCuoi(L, x);
    cout << "Danh sach it hon 3 phan tu,chen vao cuoi";
    return;
  }
  TRO Q = L;
  int vt = 1;
  while (Q != NULL & vt < 2)
  {
    Q = Q->next;
    vt++;
  }
  P->next = Q->next;
  Q->next = P;
  cout << "Da chen sv moi vao vi tri thu 3 trong DS";
}

int main()
{
  return 0;
}
