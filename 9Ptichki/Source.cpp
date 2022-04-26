#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    //20 - макс кол-во птичек, можно повысить
    int N, A[20],B[20], length, coord = 0, k;
    cout << "¬ведите количество птичек в кормушке" << endl;
    cin >> N;
    cout << "¬ведите врем€ прилета и улета очередной птички" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        cin >> B[i];
    }
    //sort(A[0],A[N-1]);


    for (long int i = 0; i < N - 1; i++)
    {
        long int min_i = i;
        for (long int j = i + 1; j < N; j++)
        {
            if (A[j] < A[min_i])
            {
                min_i = j;
            }
        }

        if (min_i != i)
        {
            std::swap(A[i], A[min_i]);
            std::swap(B[i], B[min_i]);
        }
    }

    int t = A[N-1];
    int schetchik=0;
    for (int i = N-1; i >=0; i--)
    {
        schetchik = schetchik + 1;
        cout << t << " ";
        for (int j = N-1; j >= 0; j--)
            if (A[j] <= t && B[j] > t)
            {
                B[j] = -1;
                A[j] = -1;
            }
        int end = 1;
        for (int j = N-1; j >=0; j--)
        {
            if (A[j] != -1 && B[j] != -1 && end==1)
            {
                t = A[j];
                end = 0;
            }
        }
        if (end == 1)
            break;
    }
    cout << endl << schetchik << " фотографий надо сделать";
    return 0;
}