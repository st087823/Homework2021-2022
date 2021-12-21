#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> v)
{
    if (v.size() == 0)
    {
        cout << "empy\n";
    }
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << '\n';
}

void enlarge(vector<int>& v) // ����������� ����� ������� ��������� ���������� �� ���������.
{
    vector<int> new_v;
    vector <int> ::iterator i;
    for (i = v.begin(); i != v.end(); i++)
    {
        auto a = *i;
        i++;
        if (i == v.end()) return;
        auto b = *i;
        i = v.insert(i, (a + b) / 2);
    }
}
void del(vector<int>& v) // ��������� �������� ������� ����� ����.
{
    vector <int> ::iterator i;
    for (i = v.begin(); i != v.end(); i += 2) 
    {
        i = v.erase(i); //������� �������, �� ������� ��������� �������� i; ���������� ��������, ����������� �� �������, ������������� ����� ���������� ��������.
        if (i == v.end()) return;
    }

    /*vector<int> new_v;
    for (vector<int>::iterator i = v.begin() + 1; i < v.end(); i += 2)
    {
        new_v.push_back(*i);
    }
    v = new_v;*/
}
vector<int> concat(vector<int> v1, vector<int> v2) // ����������� ��� ������� � ������������ �� ���������
{
    for (auto x : v2)
    {
        v1.push_back(x); //� ����� ������� v1 ��������������� ��������� ��-�� v2
    }
    return v1;
}
vector<int> repeat(unsigned int n, vector<int> v) // ��������������� ����� ����� n, � ������������ ����� ������, ���������� ����������� ������� v n ���.
{
    vector<int> new_v;
    for (int i = 0; i < n; i++)
    {
        new_v = concat(new_v, v); //���������� �������� ��� ������� ���������������� ������� concat � ��������� n ��� �������� ������ v
    }
    return new_v;
}
vector<int>::iterator find_second(vector<int> v, int value) // ��������� ������ ��������������� �������� value � �������� ������ v
{
    vector<int>::iterator i;
    i = find(v.begin(), v.end(), value); //���� ������ ���������

    if (i == v.end()) return i; //��� ������ ��������
    else {
        i++;
        i = find(i, v.end(), value); //���� ������ ���������
        return i;
    }
}
vector<int>::iterator find_last(vector<int> v, int value) // ��������� ��������� ��������������� �������� � �������� ������.
{
    vector<int>::iterator i = v.begin();
    vector<int>::iterator j = find(v.begin(), v.end(), value); //���� ������ ���������
    for (unsigned int k = 0; k < v.size() && i != v.end(); ++k) 
    {
        i++;
        if (find(i, v.end(), value) != v.end())
        {
            j = find(i, v.end(), value);
        }
    }
    return j;
}

bool subseq(vector<int> v1, vector<int> v2) //�������� ������� subseq, ����������� ��� ������� � �����������, ��� ������ �� ��� �������� ����������������������  �������
{
    int i = 0;
    for (auto x : v1)
    {
        if (x == v2[i]) //������� ���-�� ��-�� ���������  � v2 � v1 ��� ������������������� ��������� (������� �����������)
        {
            i++;
        }
    }
    if (i == v2.size()) //���� ���-�� ��������� ��-�� �� v2 = ������� v2, �� �����
    {
        cout << "true\n";
        return true;
    }
    else
    {
        cout << "false\n";
        return false;
    }
}
vector<int>::iterator find_last_bound(vector<int> sort_v, int value) //������������ ������ ���������� �������� �������, �������� ���. ��������
{
    vector<int>::iterator i = sort_v.begin(); //sort_v - ��������������� ������
    i = upper_bound(sort_v.begin(), sort_v.end(), value);
    i--; //upper_bound ��������� �� �� ��� ��-�, � �� ��-� ������ ������� ��������
    if (*i != value) 
    {
        return sort_v.end(); //�� ����� ��-�
    }
    return i;
}
void find_index(vector<double> v, double x, int& i, int& j) //����������� ��������������� ������ ����� �����, �������� �������� �������� � ������������ 
//������ ���������� �������� �������, �������� ������� ��������.
{
    vector<double>::iterator a, b, c = v.begin();
    a = upper_bound(v.begin(), v.end(), x);
    b = lower_bound(v.begin(), v.end(), x);
    if (a == b)
    {
        return; // ����� � �� �������
    }
    if (++b == a)
    {
        b--;
    }
    b--;
    i = 0; //v.begin() - b
    j = 0; //distance()
    while (c != a)
    {
        j++;
        c++;
    }
    c = v.begin();
    while (c != b)
    {
        i++;
        c++;
    }
}

int main()
{

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    print(v);

    enlarge(v);
    print(v);

    del(v);
    print(v);


    vector<int> v1{ 1, 3, 5, 7, 9 };
    int arr[5]{ 0 };
    copy(v1.begin(), v1.end(), arr);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << '\n';

    vector<int> v2{ 10, 12, 14 };
    vector<int> v3 = concat(v1, v2);
    print(v1);
    print(v2);
    print(v3);
    v3 = repeat(4, v2);
    print(v3);

    vector <int> v{3, 2, 5, 9, 4, 5, 7};
    cout << *find_second(v, 1) << '\n';
    vector<int> v2{3, 2, 5, 9, 4, 5, 7, 1, 5, 8};
    cout << *find_last(v2, 5) << '\n';
    vector<int> vv{1, 2, 3, 5, 6, 7, 8, 9};
    vector<int> vv1{3, 5, 7, 8};
    subseq(vv, vv1);

    return EXIT_SUCCESS;
}