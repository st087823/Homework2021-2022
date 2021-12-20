#include <iostream>
using namespace std;

struct SNode //структура, описывающая узел дерева
{
    int key;
    int data; // элемент данных
    SNode* left, * right; // указатели на сыновей
    SNode(int k, int d, SNode* l = nullptr, SNode* r = nullptr) :
        key(k), data(d), left(l), right(r) {} // конструктор
};

void f_print(SNode* r, int d = 0) // d - смещение
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
    STree(SNode* p) : root(p) {} // конструктор по указателю на узел
    void print() // метод печати
    {
        f_print(root); // вызывает рекурсивную функцию
    }
    SNode* find_key_rec(SNode* p, int key) //алгоритм поиска нужного ключа (key) без циклов, с рекурсией
    {
        if (p == nullptr) //не нашли ключ
        {
            return p;
        }
        else if (p->key == key) //нашли нужынй ключ, то вовращаем указатель на этот узел дерева
        {
            return p;
        }
        else if (p->key > key) //если данные текущего узла больше key, то вызываем рекурсию для поиска в левом поддереве этого узла
        {
            return find_key_rec(p->left, key);
        }
        else if (p->key < key) //если данные текущего узла меньше key, то вызываем рекурсию для поиска в правом поддереве этого узла
        {
            return find_key_rec(p->right, key);
        }
    }
    SNode* find_key_cycle(SNode* p, int key) //алгоритм поиска нужного ключа с циклом (без рекурсивных вызовов).
    {
        while (p != nullptr) //перебираем все узлы дерева
        {
            if (p->key == key) //нашли нужынй ключ, то вовращаем указатель на этот узел дерева
            {
                return p;
            }
            else if (p->key > key) // если данные текущего узла больше key, то вызываем рекурсию для поиска в левом поддереве этого узла
            {
                p = p->left;
            }
            else if (p->key < key) //если данные текущего узла меньше key, то вызываем рекурсию для поиска в правом поддереве этого узла
            {
                p = p->right;
            }
        }
        return nullptr; //не нашли нужный ключ
    }
    void push_key_rec(SNode*& p, int key, int data)//алгоритм вставки новой пары из ключа и данных в дерево двоичного поиска в виде функции без циклов
    {
        if (p->key == key) // если ключ с такими данными уже есть
        {
            cout << "error\n";
            return;
        }
        if (p->key > key)
        {
            if (p->left == nullptr)
            {
                p->left = new SNode(key, data); //вставляем новый узел с данными data в найденное место
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
                p->right = new SNode(key, data); //вставляем новый узел с данными data в найденное место
                return;
            }
            else
            {
                return push_key_rec(p->right, key, data); // продолжаем поиск нужного места
            }

        }
    }
    void push_key_cycle(SNode*& p, int key, int data)         //алгоритм вставки новой пары из ключа и данных в дерево двоичного поиска в виде функции с циклом (без рекурсивных вызовов)
    {
        while (p != nullptr) //перебираем все узлы дерева
        {
            if (p->key < key)
            {
                if (p->right == nullptr)
                {
                    p->right = new SNode(key, data); //вставляем новый узел с данными data в найденное место
                    return;
                }
                else
                {
                    p = p->right; // ищем в правом поддереве этого узла
                    continue;
                }
            }
            if (p->key > key)
            {
                if (p->left == nullptr)
                {
                    p->left = new SNode(key, data); //вставляем новый узел с данными data в найденное место
                    return;
                }
                else
                {
                    p = p->left; // ищем в левом поддереве этого узла
                    continue;
                }
            }
            if (p->key == key) // если ключ с такими данными уже есть
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
        * p1 = new SNode(8, 80, p2, p3); //p1 - вершина
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