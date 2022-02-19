#include <iostream>
#include <cstdio>
#include <random>
#include <time.h>
//для оченб больших значений поля раскомментировать два поля ниже и (возможно) добавить/удалить пару нулей;
//#pragma comment(linker, "/STACK:2000000000")
//#pragma comment(linker, "/HEAP:200000000")
using namespace std;
mt19937 rnd(time(NULL));
long int const height = 1, width = 200;

int initialization(short int A[])
{
    for (long int i = 0; i < height * width; i++)
    {
        if ((rnd() % 100) < 80)
            A[i] = 1;
        else
            A[i] = 0;
    }
    return (A[height * width]);
}

int Givingmove(short int A[(height * width)])
{
    uniform_int_distribution<int> distrib(3, 6);
    for (long int i = 0; i < height; i++)
        for (long int j = 0; j < width; j++)
        {
            if (A[i * width + j] == 1)
            {
                A[i * width + j] = 5 + rnd() % 2;
                if (j == 0 || j == width - 1)
                    A[i * width + j] = 2;
            }
        }
    return (A[height * width]);
}

int Moving(short int A[(height * width)])
{
    long int k = 0;
    for (long int i = 0; i < height; i++)
        for (long int j = 1; j < width - 1; j++)
        {

            if (A[(i)*width + j] == 5 && A[(i)*width + j - 1] == 0)
            {
                A[(i)*width + j - 1] = 1;
                A[i * width + j] = 0;
                k = k + 1;
            }
            else if (A[(i)*width + j] == 5 && A[(i)*width + j - 1] != 0)
                A[i * width + j] = 2;

            if (A[(i)*width + j] == 6 && A[(i)*width + j + 1] == 0)
            {
                A[(i)*width + j + 1] = 1;
                A[i * width + j] = 0;
                k = k + 1;
            }
            else if (A[(i)*width + j] == 6 && A[(i)*width + j + 1] != 0)
                A[i * width + j] = 2;
        }
    if (k != 0)
        return (A[height * width]);
    if (k == 0)
    {
        A[0] = 9;
        return (A[height * width]);
    }
}


int Stop(short int A[(height * width)])
{
    for (long int i = 0; i < height; i++)
        for (long int j = 0; j < width; j++)
        {
            if (A[i * width + j] == 1)
            {
                
                if (j > 0)
                    if (A[(i)*width + j - 1] > 0)
                        A[i * width + j] = 2;
                if (j < width - 1)
                    if (A[(i)*width + j + 1] > 0)
                        A[i * width + j] = 2;
                if (j == 0 || j == width - 1)
                    A[i * width + j] = 2;
            }
        }
    return (A[height * width]);
}

int main()
{

    //    cout << rnd() << ' ' << rnd() << endl;
    //    uniform_int_distribution<int> distrib(1, 10);
    //    cout << distrib(rnd) << endl;
    long long int d = 0;
    long int it = 1000;
    for (int f = 0; f < it; f++)
    {

        short int A[height * width]; //глобальный массив
        //значение ячейки 0 - ничего 1 - что-то есть (для начальной инициализации) 2 - не движется 3,4,5,6 - скорости: вверх, вниз, влево, вправо 

        initialization(A);
        long int s = 0;
        while (true)
        {
            Stop(A);
            Givingmove(A);
            Moving(A);
            
            s = s + 1;
            if (A[0] == 9)
                break;
        }
        d = d + s;
    }
    cout << (d) / it;
    return 0;
}