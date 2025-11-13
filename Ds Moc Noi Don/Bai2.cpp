#include <iostream>
#include <string>
using namespace std;

// ======================= Cau truc mat hang =======================
struct MatHang
{
  string maHang;
  string tenHang;
  string donVi;
  int donGia;
  int soLuong;
};

// ======================= Node cua danh sach =======================
struct Node
{
  MatHang data;
  Node *next;
  Node(MatHang mh)
  {
    data = mh;
    next = nullptr;
  }
};

// ======================= Linked List =======================
struct LinkedList
{
  Node *head = nullptr;

  // Them cuoi danh sach
  void addLast(MatHang mh)
  {
    Node *p = new Node(mh);
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
    cout << "\n=== DANH SACH MAT HANG ===\n";
    Node *temp = head;
    while (temp != nullptr)
    {
      cout << temp->data.maHang << " - "
           << temp->data.tenHang << " - "
           << temp->data.donVi << " - "
           << temp->data.donGia << " - "
           << temp->data.soLuong << endl;
      temp = temp->next;
    }
  }

  // Tim mat hang co don gia nho nhat
  void findMinPrice()
  {
    if (head == nullptr)
    {
      cout << "Danh sach rong!\n";
      return;
    }
    Node *temp = head;
    Node *minNode = head;

    while (temp != nullptr)
    {
      if (temp->data.donGia < minNode->data.donGia)
        minNode = temp;
      temp = temp->next;
    }

    cout << "\n=== MAT HANG CO DON GIA NHO NHAT ===\n";
    cout << minNode->data.maHang << " - "
         << minNode->data.tenHang << " - "
         << minNode->data.donVi << " - "
         << minNode->data.donGia << " - "
         << minNode->data.soLuong << endl;
  }

  // Xoa vi tri thu k
  void deleteAt(int k)
  {
    if (head == nullptr || k <= 0)
      return;

    if (k == 1)
    {
      Node *del = head;
      head = head->next;
      delete del;
      return;
    }

    Node *temp = head;
    for (int i = 1; temp != nullptr && i < k - 1; i++)
    {
      temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr)
      return;

    Node *del = temp->next;
    temp->next = del->next;
    delete del;
  }

  // Sap xep tang dan theo so luong (Bubble sort)
  void sortByQuantity()
  {
    if (head == nullptr)
      return;

    for (Node *i = head; i->next != nullptr; i = i->next)
    {
      for (Node *j = i->next; j != nullptr; j = j->next)
      {
        if (i->data.soLuong > j->data.soLuong)
        {
          MatHang temp = i->data;
          i->data = j->data;
          j->data = temp;
        }
      }
    }
  }
};

// ======================= Tao du lieu mac dinh =======================
void taoDanhSach(LinkedList &list)
{
  list.addLast({"H0001", "But chi", "Cai", 12000, 50});
  list.addLast({"H0002", "Hop but", "Chiec", 13000, 40});
  list.addLast({"H0003", "Gom tay", "Cai", 10000, 30});
  list.addLast({"H0004", "Thuoc ke", "Cai", 7000, 60});
  list.addLast({"H0005", "Muc viet", "Lo", 15000, 55});
}

// ======================= MAIN =======================
int main()
{
  LinkedList list;

  // 1. Tao danh sach mac dinh
  taoDanhSach(list);

  cout << "==== DANH SACH BAN DAU ====";
  list.display();

  // 2. Tim mat hang co don gia nho nhat
  list.findMinPrice();

  // 3. Xoa vi tri thu 2
  list.deleteAt(2);
  cout << "\n==== DANH SACH SAU KHI XOA VI TRI 2 ====";
  list.display();

  // 4. Sap xep tang dan theo so luong
  list.sortByQuantity();
  cout << "\n==== DANH SACH SAU KHI SAP XEP TANG DAN THEO SO LUONG ====";
  list.display();

  return 0;
}
