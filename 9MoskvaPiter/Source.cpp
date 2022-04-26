#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    //20 - ���� ���-�� ����������, ����� ��������
    int N, A[20], length,coord=0,k;
    cout << "������� ���������� �������� �� ����" << endl;
    cin >> N;
    cout << "������� ����������  �� �������� �� ������" << endl;
    for (int i=0; i < N; i++)
        cin >> A[i];
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
            std::swap(A[i], A[min_i]);
    }



    cout << "������� �� ���������� ����������, ������� ����� �������� ������ �� ����� ����" << endl;
    cin >> length;
    for (int i=0; i < N; i++)
    {
        k = 0;
        for (int j=0; j < N; j++)
            if (A[j] > coord && A[j] <= coord + length && A[j] > k)
                k = A[j];
        coord = k;
        if (coord == 0)
            break;
        cout << k << " ";
    }
    return 0;
}