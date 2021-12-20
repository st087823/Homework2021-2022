#include <iostream>
#include <algorithm>
using namespace std;

struct BNode //структура, описывающая узел дерева
{
	int data;
	BNode* left, * right;
	BNode(int d, BNode* l = nullptr, BNode* r = nullptr) :
		data(d), left(l), right(r) {} // конструктор
};

void f_print(BNode* r, int indent = 0) { // indent - отступ
	if (r == nullptr) return;
	f_print(r->right, indent + 3); // рекурсивный вызов для левого поддерева с отступом

	for (int i = 0; i < indent; i++) // печать пробелов (indent шт)
		cout << ' ';
	cout << r->data << endl; // печать данных узла
	f_print(r->left, indent + 3); // рекурсивный вызов для правого поддерева с отступом
}
void f_del(BNode*& t) //удаление поддеревьев узла t
{
	if (t == nullptr) return;
	f_del(t->left);
	f_del(t->right);
	delete t;
	t = nullptr;
}
struct BTree
{
	BNode* root;
	BTree(BNode* p) : root(p) {}

	void print() {
		cout << "_______________" << endl;
		f_print(root);
		cout << "_______________" << endl;
	}
	void del0(BNode*& t) //уничтожающий все поддеревья узлов, данные которых равны 0
	{
		if (t == nullptr)
		{
			return;
		}
		if (t->data == 0) //если данные узла = 0, удаляем все его поддерево
		{
			f_del(t);
		}
		else // если данные узла не ноль, еще раз рекурсивно вызываем функцию для следующего узла и делаем проверку уже для него
		{
			del0(t->left);
			del0(t->right);
		}
	}
	void delLeaves(BNode*& p) //уничтожаются только те узлы, которые были листьями до этой операции
	{
		if (p == nullptr) return;
		if (p->left == nullptr && p->right == nullptr) //если текущий узел - лист, то удаляем с помощью f_del
		{
			f_del(p);
		}
		else
		{
			delLeaves(p->left); //если текущий узел не лист, рекурсивно вызываем delLeaves и продолжаем искать
			delLeaves(p->right);
		}
	}
	template <class T> void enlarge(T d, BNode* p) //принимающий объект d типа int, и заменяющий в дереве все нулевые указатели указателями на новые узлы дерева с данными d
	{
		if (p->left == nullptr) // если лист (левый), то создаем новый узел с данными d
		{
			p->left = new BNode(d);
		}
		if (p->right == nullptr)  // если лист (правый), то создаем новый узел с данными d
		{
			p->right = new BNode(d);
		}
		else ///если текущий узел не лист, рекурсивно вызываем enlarge и продолжаем искать
		{
			enlarge(d, p->left);
			enlarge(d, p->right);
		}
	}
};

int main() {
	/*BNode* p13 = new BNode(13),
		* p7 = new BNode(-7),
		* p4 = new BNode(4),
		* p14 = new BNode(14, p13),
		* p6 = new BNode(-6, p4, p7),
		* p1 = new BNode(-1),
		* p10 = new BNode(-10, p14),
		* p3 = new BNode(3, p1, p6),
		* p8 = new BNode(8, p3, p10);

	BTree t(p8);
	t.print();
	t.scale();
	t.print();
	cout << t.sum() << endl;
	cout << t.countNeg() << endl;
	cout << t.height() << endl;
	t.reflect();
	t.print();
	cout << t.mult() << endl;*/

	BNode* p7 = new BNode(55),
		* p6 = new BNode(6),
		* p5 = new BNode(5),
		* p4 = new BNode(0),
		* p3 = new BNode(3, p6, p7),
		* p0 = new BNode(1, p4, p5),
		* p25 = new BNode(25, p0, p3);
	BTree t(p25);
	t.print();
	t.del0(p25);
	t.print();
	t.delLeaves(p25);
	t.enlarge(55, p25);
	t.print();

	return EXIT_SUCCESS;
}