
#include <iostream>
#include <list> //����� ������������ ���� ����� list
#include <locale>
#include <string>

using namespace std;

struct Subscriber
{
    int num;
    string name;
    string address;

    Subscriber(int n = 0, string nm = "", string ad = "") : num(n), name(nm), address(ad) {} //������ �� ����� ��� ������������� ����� ��������� struct Subscriber

    Subscriber(const Subscriber& a) // ������. �����������
    {
        num = a.num;
        name = a.name;
        address = a.address;
    }

};

ostream& operator << (ostream& st, Subscriber a) // ���������� ��������� ������, ����� ��������� �������� �������� st << sub;
{
    return st << a.num << " " << a.name << " " << a.address << " " << endl;
}
istream& operator >> (istream& st, Subscriber& a) // ���������� ��������� �����, ����� ��������� �������� �������� st >> sub;
{
    st >> a.num >> a.name >> a.address;
    return st;
}

ostream& operator << (ostream& st, list<Subscriber> l) // ���������� ��������� ������ ������ ���������
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


istream& operator >> (istream& st, list<Subscriber>& l) // ���������� ��������� ����� ������
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
    cout << "1 - �������� ��������\n";
    cout << "2 - ������� �������� �� ������\n";
    cout << "3 - ����������� ��� � ����� �������� �� ������\n";
    cout << "4 - ����� �� ���������\n";
}


int main()
{
    setlocale(LC_ALL, "Russian");

    list <Subscriber> l;
    int choose = 0;
    menu(); //������� �������� ������ � list
    cin >> choose;
    while (choose >= 1 && choose < 4)
    {
        if (choose == 1) //����� ��-� � ����� ���������� ������
        {
            Subscriber a;
            cin >> a;
            l.push_back(a);
        }

        if (choose == 2) // ���� ��-�
        {
            int tmp = 0;
            cin >> tmp; // ��������� �������

            list <Subscriber> ::iterator i; //��������� �� ������ ������ ������
            i = l.begin();
            int n = 0;
            for (auto x : l) // ���� ������ ��-� tmp
            {
                n++;
                if (x.num == tmp) // ������� �� ������� ��-�� tmp � ������� �� �����
                {
                    break;
                }
            }
            advance(i, n - 1); // �������� �������� i �� n-1 ������� (������ ��� �����)
            l.erase(i); //������� �������, �� ������� ��������� �������� i;
        }

        if (choose == 3) // ����������� ��� � ����� �������� �� ������
        {
            int tmp = -10;
            cin >> tmp; //��������� ����� ��������, �������� ���� ������� ��� � �����
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
    cout << l; //������� ������������ list
    return EXIT_SUCCESS;
}