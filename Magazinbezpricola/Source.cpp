#include <iostream>
#include <cstdio>
using namespace std;

struct predmetstruc
{
    string name;
    int kolvocastey, cenarecepta;
    string chasti[3]; //максимум частей
};

int poiskceni(string name, predmetstruc A[], int kolvopredmetovvmagazine)
{
    int sum = 0;
    for (int i = 0; i < kolvopredmetovvmagazine; i++)
        if (name == A[i].name)
        {
            for (int j = 0; j < A[i].kolvocastey; j++)
                sum = sum + poiskceni(A[i].chasti[j], A, kolvopredmetovvmagazine);
            sum = sum + A[i].cenarecepta;
        }
    return(sum);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string a;

    predmetstruc predmet[4];
    predmet[0].name = "UberMegaMech";
    predmet[0].chasti[0]= "MegaMech";
    predmet[0].chasti[1] = "UberMech";
    predmet[0].kolvocastey = 2;
    predmet[0].cenarecepta = 1100;

    predmet[1].name = "MegaMech";
    predmet[1].chasti[0] = "Mech";
    predmet[1].kolvocastey = 1;
    predmet[1].cenarecepta = 700;

    predmet[2].name = "UberMech";
    predmet[2].kolvocastey = 0;
    predmet[2].cenarecepta = 900;

    predmet[3].name = "Mech";
    predmet[3].kolvocastey = 0;
    predmet[3].cenarecepta = 300;

    cout << "Наш ассортимент" << endl;
    for (int i = 0; i < 4; i++)
        cout << predmet[i].name << endl;



    cout << "Цену какого предмета хотите узнать";
    cin >> a;
    int cena = poiskceni(a, predmet, 4);
    cout << cena;




    return 0;
}