#include <iostream>
#include <math.h>
#define max 100;
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
}
// nhap danh sach sinh vien
void nhapDS(List &L)
{
  Initialize(L);
  Student X;
  int i = 1;
  do
  {
    cout << "Nhap sinh vien thu " << i << endl;
    nhapSv(X);
    if (!Add(L, X))
    {
      return;
    }
    i++;
  } while (1)
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
void Insert(int k, List &L)
{
  int i;
  Student X;
  if (!Full(L) && k <= L.count + 1 && k >= 1)
  {
    cout << "Nhap sinh vien can bo sung ";
    nhapSv(X);
  }
}
