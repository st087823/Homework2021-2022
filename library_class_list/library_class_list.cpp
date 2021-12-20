
#include <iostream>
#include <list> //чтобы использовать шабл класс list
#include <locale>
#include <string>

using namespace std;

struct Subscriber
{
    int num;
    string name;
    string address;

    Subscriber(int n = 0, string nm = "", string ad = "") : num(n), name(nm), address(ad) {} //констр по умолч для инициализации полей структуры struct Subscriber

    Subscriber(const Subscriber& a) // констр. копирования
    {
        num = a.num;
        name = a.name;
        address = a.address;
    }

};

ostream& operator << (ostream& st, Subscriber a) // перегрузка оператора вывода, чтобы корректно работала операция st << sub;
{
    return st << a.num << " " << a.name << " " << a.address << " " << endl;
}
istream& operator >> (istream& st, Subscriber& a) // перегрузка оператора ввода, чтобы корректно работала операция st >> sub;
{
    st >> a.num >> a.name >> a.address;
    return st;
}

ostream& operator << (ostream& st, list<Subscriber> l) // перегрузка оператора вывода списка абонентов
{
    Subscriber sub;
    list<Subscriber>::iterator i;
    for (i = l.begin(); i != l.end(); i++) 
    {
        sub = *i;
        st << sub << endl;
    }
    return st;
} 


istream& operator >> (istream& st, list<Subscriber>& l) // перегрузка оператора ввода списка
{
    Subscriber sub;
    while (st >> sub)
    {
        l.push_back(sub);
    }
    return st;
}

void menu()
{
    cout << "1 - добавить абонента\n";
    cout << "2 - удалить абонента по номеру\n";
    cout << "3 - распечатать имя и адрес абонента по номеру\n";
    cout << "4 - выйти из программы\n";
}


int main()
{
    setlocale(LC_ALL, "Russian");

    list <Subscriber> l;
    int choose = 0;
    menu(); //выводим варианты работы с list
    cin >> choose;
    while (choose >= 1 && choose < 4)
    {
        if (choose == 1) //добав эл-т в конец имеющегося списка
        {
            Subscriber a;
            cin >> a;
            l.push_back(a);
        }

        if (choose == 2) // удал эл-т
        {
            int tmp = 0;
            cin >> tmp; // удаляемый абонент

            list <Subscriber> ::iterator i; //интератор на начало списка ставим
            i = l.begin();
            int n = 0;
            for (auto x : l) // ищем нужный эл-т tmp
            {
                n++;
                if (x.num == tmp) // доходим до нужного эл-та tmp и выходим из цикла
                {
                    break;
                }
            }
            advance(i, n - 1); // сдвигает итератор i на n-1 позиций (вперед или назад)
            l.erase(i); //удаляет элемент, на который указывает итератор i;
        }

        if (choose == 3) // распечатать имя и адрес абонента по номеру
        {
            int tmp = -10;
            cin >> tmp; //считываем номер абонента, которому надо вывести имя и адрес
            for (auto x : l)
            {
                if (x.num == tmp)
                {
                    cout << x;
                }
            }
        }
        menu();
        cin >> choose;
    }
    cout << l; //выводим получившийся list
    return EXIT_SUCCESS;
}