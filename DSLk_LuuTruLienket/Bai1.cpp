#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstring>
#define max 100
using namespace std;
struct Student
{
  char Id[10];
  char firstName[30];
  char lastName[10];
  char gender[5];
  int year;
  double Score;
};

struct List
{
  int count;
  Student E[max];
};
// khoi tao danh sach
void Initialize(List &L)
{
  L.count = -1;
}
// Kiem tra danh sach xem co DAY hay k
int Full(List L)
{
  return L.count == max - 1;
}
// Kiem tra danh sach xem co rong hay k
int Empty(List &L)
{
  return L.count == -1;
}
// Nhap thong tin 1  sinh vien
void nhapSv(Student &Sv)
{
  cout << "Nhap ma sinh vien: ";
  fflush(stdin);
  gets(Sv.Id);
  cout << "Nhap ho sinh vien: ";
  fflush(stdin);
  gets(Sv.firstName);
  cout << "Nhap ten sinh vien: ";
  fflush(stdin);
  gets(Sv.lastName);
  cout << "Nhap gioi tinh cua sinh vien: ";
  fflush(stdin);
  gets(Sv.gender);
  cout << "Nhap nam sinh cua sinh vien: ";
  cin >> Sv.year;
  cout << "Nhap diem trung binh cua sinh vien: ";
  cin >> Sv.Score;
  cin.ignore();
}
// them sinh vien vao cuoi danh sach
int Add(List &L, Student X)
{
  if (Full(L))
    return 0;
  L.count++;
  L.E[L.count] = X;
  return 1;
}

// nhap danh sach sinh vien
void nhapDS(List &L)
{
  Initialize(L);
  int n;
  cout << "Nhap so luong sinh vien: ";
  cin >> n;
  Student X;
  for (int i = 0; i < n; i++)
  {
    cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
    nhapSv(X);
    if (!Add(L, X))
    {
      cout << "Danh sach da day, khong the them sinh vien!\n";
      break;
    }
  }
}
// hien thi danh sach
void hien_thi_Ds(List L)
{
  cout << setw(5) << "STT";
  cout << setw(10) << "MA SINHVIEN";
  cout << setw(30) << "Ho Dem";
  cout << setw(25) << "Ten";
  cout << setw(5) << "Gioi tinh";
  cout << setw(10) << "Nam Sinh";
  cout << setw(10) << "Diem TK\n";
  for (int i = 0; i <= L.count; i++)
  {
    cout << setw(5) << (i + 1);
    cout << setw(10) << L.E[i].Id;
    cout << setw(30) << L.E[i].firstName;
    cout << setw(25) << L.E[i].lastName;
    cout << setw(5) << L.E[i].gender;
    cout << setw(10) << L.E[i].year;
    cout << setw(10) << L.E[i].Score;
  }
}
// xoa sinh vien dau tien trong danh sach
void del_First(List &L)
{
  if (Empty(L))
  {
    return;
  }
  for (int i = 1; i <= L.count; i++)
  {
    L.E[i - 1] = L.E[i];
  }
  L.count--;
}
// them 1 sinh vien vao vi tri k trong danh sach
int Insert(int k, List &L)
{
  int i;
  Student X;
  if (!Full(L) && k <= L.count + 1 && k >= 1)
  {
    cout << "Nhap sinh vien can bo sung ";
    nhapSv(X);
    for (i = L.count; i >= k - 1; i--)
    {
      L.E[i + 1] = L.E[i];
    }
    L.E[k - 1] = X;
    L.count++;
    cout << "Da chen sinh vien vao vi tri " << k << "!\n";
    return 1;
  }
  else
  {
    cout << " Khong the chen: danh sach day hoac vi tri khong hop le";
    return 0;
  }
}
void SelectionSort_ByName(List &L)
{
  for (int i = 0; i < L.count; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j <= L.count; j++)
    {
      if (strcmp(L.E[j].lastName, L.E[minIndex].lastName) < 0)
      {
        minIndex = j;
      }
    }
    if (minIndex != i)
    {
      Student temp = L.E[i];
      L.E[i] = L.E[minIndex];
      L.E[minIndex] = temp;
    }
  }
}
int main()
{
  List L;
  int chon;
  int k;
  do
  {
    cout << "+++++MENU+++++" << endl;
    cout << "1.Nhap moi n phan tu cho danh sach\n";
    cout << "2.Xoa sinh vien dau tien trong danh sach\n";
    cout << "3.Chen sinh vien vao vi tri bat ki\n";
    cout << "4.Sap xep theo chieu cua tang dan theo ten sinh vien\n";
    cout << "5. Hien thi danh sach\n";
    cout << "6.Thoat\n";
    cout << "Nhap lua chon cua ban: ";
    cin >> chon;
    switch (chon)
    {
    case 1:
      nhapDS(L);

      break;
    case 2:
      del_First(L);

      break;
    case 3:
      cout << "Nhap vi tri bo sung: ";
      cin >> k;
      Insert(k, L);

      break;
    case 4:
      SelectionSort_ByName(L);

      break;
    case 5:
      hien_thi_Ds(L);

      break;
    case 6:
      cout << "Thoat chuong trinh!";

      break;

    default:
      cout << "Lua chon khong hop le";
      break;
    }
  } while (chon != 6);
  return 0;
}
