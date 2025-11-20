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

// ===================== Node =====================
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

  // Them cuoi
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

  // Hien thi
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

  // Tim theo ten
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

  // Xoa theo ten
  void deleteByName(string name)
  {
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
        temp = temp->next;
    }
  }

  // ===================== 1. Bubble Sort =====================
  void sortByName_Bubble()
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

  // ===================== 2. Selection Sort =====================
  void sortByName_Selection()
  {
    if (head == nullptr)
      return;
    for (Node *i = head; i->next != nullptr; i = i->next)
    {
      Node *minNode = i;
      for (Node *j = i->next; j != nullptr; j = j->next)
      {
        if (j->data.ten < minNode->data.ten)
        {
          minNode = j;
        }
      }
      SinhVien tmp = i->data;
      i->data = minNode->data;
      minNode->data = tmp;
    }
  }

  // ===================== 3. Insertion Sort =====================
  void sortByName_Insertion()
  {
    if (head == nullptr || head->next == nullptr)
      return;

    Node *sorted = nullptr;

    while (head != nullptr)
    {
      Node *current = head;
      head = head->next;

      if (sorted == nullptr || current->data.ten < sorted->data.ten)
      {
        current->next = sorted;
        sorted = current;
      }
      else
      {
        Node *t = sorted;
        while (t->next != nullptr && t->next->data.ten < current->data.ten)
        {
          t = t->next;
        }
        current->next = t->next;
        t->next = current;
      }
    }

    head = sorted;
  }
};

