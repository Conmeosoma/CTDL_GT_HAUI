#include <iostream>
#include <string>
using namespace std;

// ===================== Cau truc sinh vien =====================
struct SinhVien
{
  string maSV;
  string hoDem;
  string ten;
  string gioiTinh;
  float diemTK;
};

// ===================== Node cua danh sach lien ket =====================
struct Node
{
  SinhVien data;
  Node *next;
  Node(SinhVien sv)
  {
    data = sv;
    next = nullptr;
  }
};

// ===================== Danh sach lien ket don =====================
struct LinkedList
{
  Node *head = nullptr;

  // Them cuoi danh sach
  void addLast(SinhVien sv)
  {
    Node *p = new Node(sv);
    if (head == nullptr)
    {
      head = p;
      return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
      temp = temp->next;
    temp->next = p;
  }

  // Hien thi danh sach
  void display()
  {
    cout << "\n===== DANH SACH SINH VIEN =====\n";
    Node *temp = head;
    while (temp != nullptr)
    {
      cout << temp->data.maSV << " - "
           << temp->data.hoDem << " - "
           << temp->data.ten << " - "
           << temp->data.gioiTinh << " - "
           << temp->data.diemTK << endl;
      temp = temp->next;
    }
  }

  // Tim sinh vien co ten X
  void findByName(string name)
  {
    cout << "\n===== TIM SINH VIEN TEN " << name << " =====\n";
    Node *temp = head;
    bool found = false;

    while (temp != nullptr)
    {
      if (temp->data.ten == name)
      {
        found = true;
        cout << temp->data.maSV << " - "
             << temp->data.hoDem << " - "
             << temp->data.ten << " - "
             << temp->data.gioiTinh << " - "
             << temp->data.diemTK << endl;
      }
      temp = temp->next;
    }

    if (!found)
      cout << "Khong tim thay sinh vien!\n";
  }

  // Xoa sinh vien theo ten
  void deleteByName(string name)
  {
    if (head == nullptr)
      return;

    // Neu node dau tien can xoa
    while (head != nullptr && head->data.ten == name)
    {
      Node *del = head;
      head = head->next;
      delete del;
    }

    Node *temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
      if (temp->next->data.ten == name)
      {
        Node *del = temp->next;
        temp->next = del->next;
        delete del;
      }
      else
      {
        temp = temp->next;
      }
    }
  }

  // Sap xep theo ten tang dan (Bubble sort)
  void sortByName()
  {
    if (head == nullptr)
      return;

    for (Node *i = head; i->next != nullptr; i = i->next)
    {
      for (Node *j = i->next; j != nullptr; j = j->next)
      {
        if (i->data.ten > j->data.ten)
        {
          SinhVien temp = i->data;
          i->data = j->data;
          j->data = temp;
        }
      }
    }
  }
};

// ===================== Tao du lieu mac dinh =====================
void taoDanhSach(LinkedList &list)
{
  list.addLast({"SV1001", "Tran Hong", "Quan", "Nam", 8.0});
  list.addLast({"SV1002", "Nguyen Thu", "Lan", "Nu", 6.8});
  list.addLast({"SV1003", "Nguyen Van", "Binh", "Nam", 6.4});
  list.addLast({"SV1004", "Bui Thi", "Ha", "Nu", 7.3});
  list.addLast({"SV1005", "Tran Hoai", "Son", "Nam", 8.9});
}

// ===================== MAIN =====================
int main()
{
  LinkedList list;

  // 1. Tao danh sach mac dinh
  taoDanhSach(list);

  cout << "\n=== DANH SACH BAN DAU ===";
  list.display();

  // 2. Tim sinh vien ten Ha
  list.findByName("Ha");

  // 3. Xoa sinh vien ten Lan
  list.deleteByName("Lan");
  cout << "\n=== DANH SACH SAU KHI XOA TEN LAN ===";
  list.display();

  // 4. Sap xep danh sach theo ten tang dan
  list.sortByName();
  cout << "\n=== DANH SACH SAU KHI SAP XEP TEN TANG DAN ===";
  list.display();

  return 0;
}
