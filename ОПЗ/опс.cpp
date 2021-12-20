#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int f(int a, int b, char x) // выполняет операцию x с числами a и b
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
int f2() // функцию, вводящую с клавиатуры строчку в обратной польской записи и выводящую результат этого выражения(число).
{
	stack <int> arr;
	char x = '0';
	while (cin >> x) //считываем символы до ctrZ
	{
		if (isdigit(x)) //isdigit(x) - проверяет, является введенный x - цифрой.
		{
			cin.putback(x); // положить символ обратно в поток.  т.е. если х- цифра, то putback, возвращает символ обратно в поток.
			int n = 0;
			cin >> n;
			arr.push(n); // добавляем введенное число n в стек
		}
		else //если x - опреация
		{
			int a,b = 0;
			a = arr.top(); //а - вершина стека, где лежит первое число для операции x
			arr.pop(); //удаляем верхний эл-т (удаляем первое число из стека)
			b = arr.top(); //b- новый верхний элемент? где лежит второе число для операции x
			arr.pop(); // еще раз удаляем верхний эл - т (удаляем второе чилсо из стека)
			arr.push(f(a, b, x)); //результат обратно в стек помещается
		}
	}
	return arr.top();
}

void f1() //вводящую с клавиатуры строчку в обычной математической записи и выводящую то же самое выражение, но в обратной польской записи
{
	stack <char> arr;
	char x; //вводимый символ
	while (cin >> x)
	{
		if (isdigit(x)) //isdigit(x) - проверяет, является введенный x - цифрой
		{
			cout << x << " "; 
		}
		else // x - не число
		{
			if (x == '(')
			{
				arr.push(x); //помещаем ( в стек
			}
			else if (x == ')')
			{
				while (arr.top() != '(') // ) выталкивает из стека все операции до открыва-ющей скобки "(" включительно.
				{
					cout << arr.top() << " "; 
					arr.pop(); //выводим вершину стека и удаляем ее. и так пока не встретим )
				}
				arr.pop(); //удаляем (
			}
			else //если х - операция, то кладем в стек
			{
				if (!arr.empty()) //если в стеке еще что-то лежит
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
	while (!arr.empty()) //после вввода всех символов выводим вершину стека, затем ее удаляем и тд.
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