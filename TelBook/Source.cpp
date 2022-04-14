#include <iostream>
#include <cstdio>
using namespace std;

struct person
{
    string name, number, mail;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    string a, b;
    person coolguy[3];
    coolguy[0].name = "Vasya";
    coolguy[1].name = "Petya";
    coolguy[2].name = "Vanya";
    coolguy[0].number = "2281337";
    coolguy[1].number = "1231337";
    coolguy[2].number = "3211337";
    coolguy[0].mail = "kloun@mail.ru";
    coolguy[1].mail = "wasd@mail.ru";
    coolguy[2].mail = "iort@mail.ru";
    cout << "Искать по номеру - 1. По имени - 2";
    cin >> a;
    cout << "Введите номер или имя";
    cin >> b;
    if (a == "1")
        for (int i = 0; i < 3; i++)
            if (coolguy[i].number == b)
                cout << coolguy[i].name <<' ' << coolguy[i].number <<' ' << coolguy[i].mail;
    if (a == "2")
        for (int i = 0; i < 3; i++)
            if (coolguy[i].name == b)
                cout << coolguy[i].name <<' ' << coolguy[i].number << ' ' << coolguy[i].mail;


    

    return 0;
}