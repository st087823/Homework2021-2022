#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int f(int a, int b, char x) // ��������� �������� x � ������� a � b
{
	switch (x)
	{
	case '+':
		return b + a;
	case '-':
		return b - a;
	case '/':
		return b / a;
	case '*':
		return b * a;
	}
}
int f2() // �������, �������� � ���������� ������� � �������� �������� ������ � ��������� ��������� ����� ���������(�����).
{
	stack <int> arr;
	char x = '0';
	while (cin >> x) //��������� ������� �� ctrZ
	{
		if (isdigit(x)) //isdigit(x) - ���������, �������� ��������� x - ������.
		{
			cin.putback(x); // �������� ������ ������� � �����.  �.�. ���� �- �����, �� putback, ���������� ������ ������� � �����.
			int n = 0;
			cin >> n;
			arr.push(n); // ��������� ��������� ����� n � ����
		}
		else //���� x - ��������
		{
			int a,b = 0;
			a = arr.top(); //� - ������� �����, ��� ����� ������ ����� ��� �������� x
			arr.pop(); //������� ������� ��-� (������� ������ ����� �� �����)
			b = arr.top(); //b- ����� ������� �������? ��� ����� ������ ����� ��� �������� x
			arr.pop(); // ��� ��� ������� ������� �� - � (������� ������ ����� �� �����)
			arr.push(f(a, b, x)); //��������� ������� � ���� ����������
		}
	}
	return arr.top();
}

void f1() //�������� � ���������� ������� � ������� �������������� ������ � ��������� �� �� ����� ���������, �� � �������� �������� ������
{
	stack <char> arr;
	char x; //�������� ������
	while (cin >> x)
	{
		if (isdigit(x)) //isdigit(x) - ���������, �������� ��������� x - ������
		{
			cout << x << " "; 
		}
		else // x - �� �����
		{
			if (x == '(')
			{
				arr.push(x); //�������� ( � ����
			}
			else if (x == ')')
			{
				while (arr.top() != '(') // ) ����������� �� ����� ��� �������� �� �������-���� ������ "(" ������������.
				{
					cout << arr.top() << " "; 
					arr.pop(); //������� ������� ����� � ������� ��. � ��� ���� �� �������� )
				}
				arr.pop(); //������� (
			}
			else //���� � - ��������, �� ������ � ����
			{
				if (!arr.empty()) //���� � ����� ��� ���-�� �����
				{
					if (arr.top() != '(')
					{
						if (x == '+' || x == '-')
						{
							while (arr.size() > 0)
							{
								cout << arr.top() << " ";
								arr.pop();
							}
						}
						else if (x == '*' || x == '/')
						{
							while (arr.top() == '*' || arr.top() == '/')
							{
								cout << arr.top() << " ";
								arr.pop();
							}
						}
					}
				}
				arr.push(x); 
			}
		}
	}
	while (!arr.empty()) //����� ������ ���� �������� ������� ������� �����, ����� �� ������� � ��.
	{
		cout << arr.top();
		arr.pop();
	}
}
int main()
{
	cout << "result function f2 = " << f2() << endl;
	cout << "result  function f1 = " << endl;
	f1();
	return 0;
}