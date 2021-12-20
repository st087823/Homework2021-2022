#include <iostream>
using namespace std;

struct SNode //���������, ����������� ���� ������
{
    int key;
    int data; // ������� ������
    SNode* left, * right; // ��������� �� �������
    SNode(int k, int d, SNode* l = nullptr, SNode* r = nullptr) :
        key(k), data(d), left(l), right(r) {} // �����������
};

void f_print(SNode* r, int d = 0) // d - ��������
{
    if (r == nullptr) return;
    f_print(r->right, d + 3);
    for (int i = 0; i < d; i++)
        cout << ' ';
    cout << r->key << "(" << r->data << ")" << endl;
    f_print(r->left, d + 3);
}

struct STree
{
    SNode* root;
    STree(SNode* p) : root(p) {} // ����������� �� ��������� �� ����
    void print() // ����� ������
    {
        f_print(root); // �������� ����������� �������
    }
    SNode* find_key_rec(SNode* p, int key) //�������� ������ ������� ����� (key) ��� ������, � ���������
    {
        if (p == nullptr) //�� ����� ����
        {
            return p;
        }
        else if (p->key == key) //����� ������ ����, �� ��������� ��������� �� ���� ���� ������
        {
            return p;
        }
        else if (p->key > key) //���� ������ �������� ���� ������ key, �� �������� �������� ��� ������ � ����� ��������� ����� ����
        {
            return find_key_rec(p->left, key);
        }
        else if (p->key < key) //���� ������ �������� ���� ������ key, �� �������� �������� ��� ������ � ������ ��������� ����� ����
        {
            return find_key_rec(p->right, key);
        }
    }
    SNode* find_key_cycle(SNode* p, int key) //�������� ������ ������� ����� � ������ (��� ����������� �������).
    {
        while (p != nullptr) //���������� ��� ���� ������
        {
            if (p->key == key) //����� ������ ����, �� ��������� ��������� �� ���� ���� ������
            {
                return p;
            }
            else if (p->key > key) // ���� ������ �������� ���� ������ key, �� �������� �������� ��� ������ � ����� ��������� ����� ����
            {
                p = p->left;
            }
            else if (p->key < key) //���� ������ �������� ���� ������ key, �� �������� �������� ��� ������ � ������ ��������� ����� ����
            {
                p = p->right;
            }
        }
        return nullptr; //�� ����� ������ ����
    }
    void push_key_rec(SNode*& p, int key, int data)//�������� ������� ����� ���� �� ����� � ������ � ������ ��������� ������ � ���� ������� ��� ������
    {
        if (p->key == key) // ���� ���� � ������ ������� ��� ����
        {
            cout << "error\n";
            return;
        }
        if (p->key > key)
        {
            if (p->left == nullptr)
            {
                p->left = new SNode(key, data); //��������� ����� ���� � ������� data � ��������� �����
                return;
            }
            else
            {
                return push_key_rec(p->left, key, data);
            }
        }
        if (p->key < key)
        {
            if (p->right == nullptr)
            {
                p->right = new SNode(key, data); //��������� ����� ���� � ������� data � ��������� �����
                return;
            }
            else
            {
                return push_key_rec(p->right, key, data); // ���������� ����� ������� �����
            }

        }
    }
    void push_key_cycle(SNode*& p, int key, int data)         //�������� ������� ����� ���� �� ����� � ������ � ������ ��������� ������ � ���� ������� � ������ (��� ����������� �������)
    {
        while (p != nullptr) //���������� ��� ���� ������
        {
            if (p->key < key)
            {
                if (p->right == nullptr)
                {
                    p->right = new SNode(key, data); //��������� ����� ���� � ������� data � ��������� �����
                    return;
                }
                else
                {
                    p = p->right; // ���� � ������ ��������� ����� ����
                    continue;
                }
            }
            if (p->key > key)
            {
                if (p->left == nullptr)
                {
                    p->left = new SNode(key, data); //��������� ����� ���� � ������� data � ��������� �����
                    return;
                }
                else
                {
                    p = p->left; // ���� � ����� ��������� ����� ����
                    continue;
                }
            }
            if (p->key == key) // ���� ���� � ������ ������� ��� ����
            {
                cout << "error\n";
                return;
            }
        }
    }
};

int main()
{
    /*SNode<int, int>* p9 = new SNode<int, int>(13, 130),
* p8 = new SNode<int, int>(7, 70),
* p7 = new SNode<int, int>(4, 40),
* p6 = new SNode<int, int>(14, 140, p9),
* p5 = new SNode<int, int>(6, 60, p7, p8),
* p4 = new SNode<int, int>(1, 10),
* p3 = new SNode<int, int>(10, 100, nullptr, p6),
* p2 = new SNode<int, int>(3, 30, p4, p5),
* p1 = new SNode<int, int>(8, 80, p2, p3);*/

    SNode* p9 = new SNode(13, 130),
        * p8 = new SNode(7, 70),
        * p7 = new SNode(4, 40),
        * p6 = new SNode(14, 140, p9),
        * p5 = new SNode(6, 60, p7, p8),
        * p4 = new SNode(1, 10),
        * p3 = new SNode(10, 100, nullptr, p6),
        * p2 = new SNode(3, 30, p4, p5),
        * p1 = new SNode(8, 80, p2, p3); //p1 - �������
    STree t(p1);
    t.print();
    cout << t.find_key_rec(p1, 6)->data << endl;
    cout << t.find_key_cycle(p1, 7)->data << endl;
    t.push_key_cycle(p1, 11, 110);
    t.print();

    t.push_key_rec(p1, 5, 50);
    t.print();
    return EXIT_SUCCESS;
}