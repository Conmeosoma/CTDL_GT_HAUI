#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#define max 100
using namespace std;

struct Employee
{
  char Id[10];
  char firstName[30];
  char lastName[10];
  char gender[5];
  int year;
  double heSoLuong;
  double salary;
};

struct List
{
  int count;
  Employee E[max];
};

// Khởi tạo danh sách
void Initialize(List &L)
{
  L.count = -1;
}

// Kiểm tra danh sách đầy
int Full(List L)
{
  return L.count == max - 1;
}

// Kiểm tra danh sách rỗng
int Empty(List L)
{
  return L.count == -1;
}

// Nhập thông tin nhân viên
void nhapNhanVien(Employee &Nv)
{
  cin.ignore();
  cout << "Nhap ma nhan vien: ";
  cin.getline(Nv.Id, 10);
  cout << "Nhap ho cua nhan vien: ";
  cin.getline(Nv.firstName, 30);
  cout << "Nhap ten cua nhan vien: ";
  cin.getline(Nv.lastName, 10);
  cout << "Nhap gioi tinh cua nhan vien: ";
  cin.getline(Nv.gender, 5);
  cout << "Nhap nam sinh cua nhan vien: ";
  cin >> Nv.year;
  cout << "Nhap he so luong cua nhan vien: ";
  cin >> Nv.heSoLuong;
  Nv.salary = Nv.heSoLuong * 1150000;
}

// Thêm nhân viên vào danh sách
int Add(List &L, Employee X)
{
  if (Full(L))
    return 0;
  L.count++;
  L.E[L.count] = X;
  return 1;
}

// Nhập danh sách nhân viên
void nhapDS(List &L)
{
  Initialize(L);
  int n;
  cout << "Nhap so luong nhan vien: ";
  cin >> n;

  Employee X;
  for (int i = 0; i < n; i++)
  {
    cout << "\nNhap thong tin nhan vien thu " << i + 1 << ":\n";
    nhapNhanVien(X);
    if (!Add(L, X))
    {
      cout << "Danh sach da day, khong the them nhan vien!\n";
      break;
    }
  }
}

// Hiển thị danh sách nhân viên
void hien_thi_Ds(List L)
{
  if (Empty(L))
  {
    cout << "Danh sach rong!\n";
    return;
  }

  cout << setw(10) << "Ma NV"
       << setw(20) << "Ho"
       << setw(15) << "Ten"
       << setw(10) << "GT"
       << setw(10) << "Nam"
       << setw(15) << "He so"
       << setw(15) << "Luong\n";

  for (int i = 0; i <= L.count; i++)
  {
    cout << setw(10) << L.E[i].Id
         << setw(20) << L.E[i].firstName
         << setw(15) << L.E[i].lastName
         << setw(10) << L.E[i].gender
         << setw(10) << L.E[i].year
         << setw(15) << L.E[i].heSoLuong
         << setw(15) << L.E[i].salary << endl;
  }
}

// Hiển thị nhân viên trên 50 tuổi
void Tuoi(List L)
{
  bool found = false;
  int currentYear = 2025;

  cout << "Danh sach nhan vien tren 50 tuoi:\n";

  for (int i = 0; i <= L.count; i++)
  {
    int age = currentYear - L.E[i].year;
    if (age >= 50)
    {
      found = true;
      cout << setw(10) << L.E[i].Id
           << setw(20) << L.E[i].firstName
           << setw(15) << L.E[i].lastName
           << setw(10) << L.E[i].gender
           << setw(10) << L.E[i].year
           << setw(15) << L.E[i].heSoLuong
           << setw(15) << L.E[i].salary << endl;
    }
  }

  if (!found)
    cout << "Khong co nhan vien nao tren 50 tuoi.\n";
}
void findByName(List L)
{
  bool found = false;
  cout << "\nNhap ten ma ban search: ";
  string Name;
  cin >> Name;

  for (int i = 0; i <= L.count; i++)
  {
    if (strcmp(L.E[i].lastName, Name.c_str()) == 0)
    {
      found = true;
      cout << setw(10) << L.E[i].Id
           << setw(20) << L.E[i].firstName
           << setw(15) << L.E[i].lastName
           << setw(10) << L.E[i].gender
           << setw(10) << L.E[i].year
           << setw(15) << L.E[i].heSoLuong
           << setw(15) << L.E[i].salary << endl;
    }
  }
  if (!found)
  {
    cout << "Khong thay ai ten " << Name << " trong danh sach!\n";
  }
}
void insert(int k, List &L)
{
  int i;
  Employee X;
  if (!Full(L) && k <= L.count + 1 && k >= 1)
  {
    cout << "Nhap phan vien can bo sung: ";
    nhapNhanVien(X);
    for (int i = L.count; i >= k - 1; i--)
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
    cout << "Khong then chen: ds day hoac vi tri khong hop le!";
    return 0;
  }
}

int main()
{
  List L;
  int k;
  nhapDS(L);
  cout << "\n=== Danh sach nhan vien vua nhap ===\n";
  hien_thi_Ds(L);

  cout << "\n=== Nhan vien tren 50 tuoi ===\n";
  Tuoi(L);
  cout << "Tim ten trong danh sach!";
  findByName(L);
  cout << "Nhap vi tri can chen!";
  insert(L,k);

  return 0;
}
