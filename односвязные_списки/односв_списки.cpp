#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
    int data; // ������� ������
    Node* next; // ��������� �� ��������� ����
    Node(int d = 0, Node* n = nullptr) :
        data(d), next(n) {} // �����������

};
struct list
{
    Node* head;
    list() { head = nullptr; } // �����������, ��������� ������ ������
    
    list(const list& l) // ����������� �����������
    {
        head = copy(l.head);
    };

    list& operator= (const list& l) // ���������� ��������� ������������
    {
        if (this == &l) // �������� �� ���������������� (a=a)
        {
            return *this;
        }
        del();
        head = copy(l.head);
        // ���������� ������� ������, ����� ����� ����������� ������� � ������� ���������� ���������� �������� ������������
        return *this;
    };

    ~list() { del(); }

    void add_first(int d)
    {
        Node* tmp; // ��������� �� ����� ����
        tmp = new Node(d, head); // �������� ������ � ��������� ����
        head = tmp; // ���������� ����� ������ ������
    }

    void print()
    {
        Node* p = head; // ��������� p ��������� ��� �������� ������, ������� � ����, �� ������� ��������� head
        while (p != nullptr)
        {
            cout << p->data << "\t";
            p = p->next; // ������� � ���������� ��������
        }
    }
    void del()
    {
        Node* p = head; //tmp=p;
        Node* d = p;
        while (p != nullptr)
        {
            d = p->next;
            delete p;
            p = d;
        }
        head = nullptr;
    }
    Node* last() // ���������� ��������� �� ��������� ����
    {
        Node* tmp = head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        return tmp;
    }
    Node* prelast() // ���������� ��������� �� ������������� ����
    {
        Node* tmp = head;
        while (tmp->next->next != nullptr)
        {
            tmp = tmp->next;
        }
        return tmp;
    }
    Node* get_prt(int n) // ���������� ��������� �� n-� ����
    {
        Node* tmp = head;
        if (n <= 0)
        {
            return nullptr;
        }
        for (int i = 1; i < n; i++)
        {
            if (tmp == nullptr)
            {
                return tmp;
            }
            tmp = tmp->next;
        }
        return tmp;
    }
    void add_after_first(int d) // �������� ����� ���� ����� ����� ������� ���� ������
    {
        Node* t = new Node(d, head->next);
        head->next = t;
    }
    void add_last(int d) // �������� ����� ���� � ����� ������
    {
        Node* t = new Node(d, nullptr);
        Node* tmp = head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = t;
    }
    void del_last() // ������� ��������� ���� ������
    {
        Node* tmp = head;
        while (tmp->next->next != nullptr)
        {
            tmp = tmp->next;
        }
        delete tmp->next;
        tmp->next = nullptr;
    }

}; // ����� ��������� List

Node* copy(Node* x)
{
    if (x == nullptr) return nullptr;
    Node* y;
    y = new Node(x->data, copy(x->next));
    return y;
}

list::list(const list& l)
{
    copy(head);
}

int main()
{
    list l;
    l.add_first(3);
    l.add_first(2);
    l.add_first(1);
    l.print();
    cout << copy(l.head)->data << endl;
    l.print();
    l.del();
    l.print();
    list l2;
    l2.add_first(13);
    l2.add_first(4);
    l2 = l;

    list arr;
    arr.add_first(5);
    arr.add_first(4);
    arr.add_first(3);
    arr.print();
    cout << arr.get_prt(1)->data << endl;
    cout << arr.get_prt(2)->data << endl;
    arr.print();
    arr.add_after_first(10);
    arr.print();
    cout << endl;
    arr.add_last(6);
    arr.print();
    cout << endl;
    arr.del_last();
    arr.print();
    return EXIT_SUCCESS;
}