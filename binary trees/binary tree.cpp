
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
	f_print(r->right, indent + 3); // рекурсивный вызов для ?левого? поддерева с отступом
	for (int i = 0; i < indent; i++) // печать пробелов в количестве indent штук
		cout << ' ';
	cout << r->data << endl; // печать данных узла
	f_print(r->left, indent + 3);// рекурсивный вызов для ?правого? поддерева с отступом
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
	while (t->left != nullptr) { //все время заходим в левое поддерево до самого левого узела
		t = t->left;
	}
	return t;
}
void del_left_knot(BNode* root) { // написать метод, удаляющий самый левый узел
	BNode* t = root;
	while (t->left->left != nullptr) { //доходим до родителя самого левого узла
		t = t->left;
	}
	BNode* tmp = t->left->right; //запоминаем правое поддерево самого левого узла, который будем удалять
	delete t->left; //удаляем самый левый узел 
	t->left = tmp; //присваиваем образовавшийся висячий указатель tmp.
	delete tmp;
}
void put_left_knot(BNode* root, int data) { //метод, вставляющий в дерево левого сына у самого левого узла
	BNode* t = left_knot(root); // доходим до самого левого узла
	BNode* newnode = new BNode(data); //создаем узел с искомым знаечнием
	t->left = newnode; //прикрепляем указатель на новый узел к дереву
}
BNode* left_leaf(BNode* root) { //метод, возвращающий указатель на самый левый лист
	BNode* t = left_knot(root); // доходим до самого левого узла
	while (t->left != nullptr || t->right != nullptr) { //до тех пор пока указатель на правое или левое поддерево текущего узла не равен nullptr
		if (t->left != nullptr) 
		{
			t = t->left; //продолжаем поиск
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
	} //находим (родителя?) самого левый лист, т.к. в последний раз t - успеваает поменять знаечние и указывает нп=а слл, а  q не успевает присвоится ещещ пвз
	if (q->left != nullptr) {
		q->left = nullptr; // зануляем указатели, если это левый потомок родителя слл
	}
	else {
		q->right = nullptr; // зануляем указатели, если это правый потомок родителя слл
	}
	delete t; // удаляем лист
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
