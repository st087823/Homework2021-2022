
#include <iostream>
using namespace std;
struct BNode //структура, описывающая узел дерева
{
	int data; // элемент данных
	BNode* left, * right; // указатели на сыновей
	BNode(int d, BNode* l = nullptr, BNode* r = nullptr) :
		data(d), left(l), right(r) {} // конструктор
};
void f_print(BNode* r, int indent = 0) // indent - отступ
{
	if (r == nullptr) return;
	f_print(r->right, indent + 3);
	for (int i = 0; i < indent; i++)
		cout << ' ';
	cout << r->data << endl;
	f_print(r->left, indent + 3);
}

struct BTree //описывает двоичные деревья
{
	BNode* root; // корень дерева
	BTree(BNode* p) : root(p) {} // конструктор по указателю на узел
	void print() // метод печати
	{
		f_print(root); // вызывает рекурсивную функцию
	}
};

BNode* left_knot(BNode* root) { //метод метод, возвращающий указатель на самый левый узел
	BNode* t = root;
	while (t->left != nullptr) {
		t = t->left;
	}
	return t;
}
void del_left_knot(BNode* root) { // написать метод, удаляющий самый левый узел
	BNode* t = root;
	while (t->left->left != nullptr) {
		t = t->left;
	}
	BNode* tmp = t->left->right;
	delete t->left;
	t->left = tmp;
	delete tmp;
}
void put_left_knot(BNode* root, int data) { //метод, вставляющий в дерево левого сына у самого левого узла
	BNode* t = left_knot(root); // доходим до самого левого узла
	BNode* newnode = new BNode(data); //создаем узел с искомым знаечнием
	t->left = newnode; //прикрепляем указатель на новый узел к дереву
}
BNode* left_leaf(BNode* root) { //метод, возвращающий указатель на самый левый лист
	BNode* t = left_knot(root); // доходим до самого левого узла
	while (t->left != nullptr || t->right != nullptr) { 
		if (t->left != nullptr) 
		{
			t = t->left;
		}
		else
		{
			t = t->right;
		}
	}
	return t;
}
void del_left_leaf(BNode* root) { //метод, удаляющий самый левый лист t
	BNode* t = root;
	BNode* q = t;
	while (t->left != nullptr || t->right != nullptr) {
		q = t;

		if (t->left != nullptr) {
			t = t->left;
		}
		else {
			t = t->right;
		}
	}
	if (q->left != nullptr) {
		q->left = nullptr; // после удаления указывает на nullptr
	}
	else {
		q->right = nullptr; // после удаления указывает на nullptr
	}
	delete t;
}

int main()
{
	//с помощью операции new и конструктора узла исх дерево
	BNode* p1 = new BNode(1),
		* p4 = new BNode(4),
		* p7 = new BNode(7),
		* p13 = new BNode(13),
		* p6 = new BNode(6, p4, p7),
		* p14 = new BNode(14, p13),
		* p10 = new BNode(10, nullptr, p14),
		* p3 = new BNode(3, p1, p6),
		* p8 = new BNode(8, p3, p10); //корень

	BTree t(p8);
	t.print();
	cout << endl;

	cout << left_knot(p8)->data << endl << endl;

	del_left_knot(p8);
	t.print();
	cout << endl;

	int x = 0;
	cout << "put_left_knot, value:  " << endl;
	cin >> x;
	put_left_knot(p8, x);
	t.print();
	cout << endl;

	cout << left_leaf(p8)->data << endl;

	del_left_leaf(p8);
	t.print();
	cout << endl;

	return EXIT_SUCCESS;
}
