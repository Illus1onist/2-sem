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
    int N, A[20], B[20];
    cout << "������� ���������� �������� �� ����" << endl;
    cin >> N;
    cout << "������� ���� ��������� �� ���� �� ������� ����� ������ 500 ��" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        B[i] = 0;
    }
    //sort(A[0],A[N-1]);
    B[N] = 0;
    A[N] = 0;
    for (long int i = 2; i <= N; i++)
    {
        if (A[i - 2] > A[i - 1])
        {
            A[i] = A[i] + A[i - 1];
        }
        else
            A[i] = A[i] + A[i - 2];
            
    }
    B[N] = 1;

    for (long int i = N; i >= 2; i--)
    {
        if (B[i] == 1)
        {
            if (A[i - 2] > A[i - 1])
                B[i - 1] = 1;
            else
                B[i - 2] = 1;
        }
    }
    cout <<endl<< "������ ��������" << endl;
    for (long int i = 0; i < N; i++)
    {
        if (B[i] == 1)
            cout << i + 1 << ' ';
    }
    cout <<endl<<"�������� ������" << endl << A[N];
    return 0;
}