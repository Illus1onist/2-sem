#include <iostream>
#include <cstdio>
using namespace std;

//���-�� ������, ��� ��� ������� ����� ������� � �����. � ����.
int main()
{
    int a;
    long long int b=1;
    cin >> a;
    for (int i = 0; i < a; i++)
        b = b * (i + 1);
    cout << b;
    return 0;
}