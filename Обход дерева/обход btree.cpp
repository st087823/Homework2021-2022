#include <iostream>
#include <algorithm>
using namespace std;

struct BNode //���������, ����������� ���� ������
{
	int data;
	BNode* left, * right;
	BNode(int d, BNode* l = nullptr, BNode* r = nullptr) :
		data(d), left(l), right(r) {} // �����������
};

void f_print(BNode* r, int indent = 0) { // indent - ������
	if (r == nullptr) return;
	f_print(r->right, indent + 3); // ����������� ����� ��� ������ ��������� � ��������

	for (int i = 0; i < indent; i++) // ������ �������� (indent ��)
		cout << ' ';
	cout << r->data << endl; // ������ ������ ����
	f_print(r->left, indent + 3); // ����������� ����� ��� ������� ��������� � ��������
}
void f_scale(BNode* t) { //�������� ������ ������� ���� �� 3.
	if (t == nullptr) return;
	else 
	{
		t->data = 3 * t->data;
		f_scale(t->left);
		f_scale(t ->right);
		// ����������� ����� ��� ������ � ������� ���������
	}
}
int f_sum(BNode* t) { //��������� ����� ���� ������ � ����� ������.
	if (t == nullptr) {
		return 0;
	}
	return t->data + f_sum(t ->left) + f_sum(t->right);
}
int f_count_neg(BNode* t) { //���������� ����� ����� � �������������� �������
	if (t == nullptr) {
		return 0;
	}
	if (t->data >= 0) 
	{
		return f_count_neg(t->left) + f_count_neg(t->right);
	}
	else 
	{
		return 1 + f_count_neg(t->left) + f_count_neg(t->right);
	}
}
int f_height(BNode* t) { //���������� ������ ������
	if (t == nullptr) {
		return 0;
	}
	return 1 + max(f_height(t->left), f_height(t->right));
}
void f_reflect(BNode* t) { //������ ������ �� ��� ���������� ���������
	if (t == nullptr) {
		return; 
	}
	else {
		if (t->left != nullptr || t->right != nullptr) 
		{
			swap(t->left, t->right); //������ ������ � ������� ������� � �������� ��������
			f_reflect(t->left);
			f_reflect(t->right);
		}
	}
}
int f_mult(BNode* t) { //���������� ������������ ������ � �����, � ������� ���� ��� ����.
	if (t == nullptr)
	{
		return 1;
	}
	if (t->left != nullptr && t->right != nullptr) 
	{
		return (t->data) * f_mult(t->left) * f_mult(t->right);
	}
	else 
	{
		return f_mult(t->left) * f_mult(t->right);
	}
}
int f_eval(BNode* t) { //��������� ���������, �������� ������ �������� �������
	if (t->left == nullptr && t->right == nullptr) 
	{
		return t->data;
	}
	else if (t->left != nullptr || t->right != nullptr)
	{
		if (t->data == 1) return f_eval(t->left) + f_eval(t->right);
		if (t->data == 2) return f_eval(t->left) - f_eval(t->right);
		if (t->data == 3) return f_eval(t->left) * f_eval(t->right);
		if (t->data == 4) return (float)f_eval(t->left) / f_eval(t->right);
	}
}

template <class T> BNode* f_find(T d, BNode* t) { //����������� �������� d ���� �, � ������������ ��������� �� ����� ����, ���������� ������ d
	if (t == nullptr || t->data == d){
		return t;
	}
	if (t != nullptr) {
		if (f_find(d, t->left) != nullptr)
		{
			return f_find(d, t->left);
		}
		else if (find(d, t->right) != nullptr)
		{
			return f_find(d, t->right);
		}
		else return nullptr;
	}
}
int f_min(int m, BNode* t) { //������������ ����������� �������� ������ � ����� ������
	if (t == nullptr)
	{
		return m;
	}
	else 
	{
		if (t->data < m) {
			m = t->data;
		}
		if (f_min(m, t->left) < f_min(m, t->right)) return f_min(m, t->left);
		else return f_min(m, t->right);
	}
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
	void scale() {
		f_scale(root);
	}
	int sum() {
		return f_sum(root);
	}
	int countNeg() {
		return f_count_neg(root);
	}
	int height() {
		return f_height(root);
	}
	void reflect() {
		f_reflect(root);
	}
	int mult() {
		return f_mult(root);
	}
	int eval() {
		return f_eval(root);
	}
	template <class T>
	BNode* find(T d) {
		return f_find(d, root);
	}
	int min() {
		return f_min(INT_MAX, root);
	}
};

int main() {
	BNode* p13 = new BNode(13),
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
	cout << t.mult() << endl;

	/*
	BTree q(q5);
	q.print();
	cout << "eval: " << q.eval() << endl;
	cout << "min: " << t.min() << endl;*/

	return EXIT_SUCCESS;
}