#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

double const d_e = 2.718281828459;

double RecursiveDoublingSum(double const psi[], double const pdf[], double const dv, unsigned const start,unsigned const fin) {
    double sum = 0;
    const long int mid = floor((fin+start) / 2);
    if (fin - start > 1)
        sum = RecursiveDoublingSum(psi, pdf, dv, start, mid) + RecursiveDoublingSum(psi, pdf, dv, mid+1, fin);
    if (fin - start == 1)
        sum = psi[fin]*pdf[fin] + psi[start] * pdf[start];
    if (fin - start == 0)
        sum = psi[fin]*pdf[fin];
    return(sum);
}

double DoublingStep(double const psi[], double const pdf[], double const dv, unsigned const start, unsigned const fin) {
    double sum = 0;
    for (int i = 0; i < fin; i++)
        if (i % 2 == 0)
        {
            double k = pdf[i] * psi[i] + pdf[i+1] * psi[i+1];
            sum = sum + k;
        }
    return(sum);
}

double Kehen(double const psi[], double pdf[], double const dv, unsigned const start, unsigned const fin) {
    double sum = 0;
    double c = 0;
    for (int i = 0; i < fin; i++)
    {
        double y = psi[i] * pdf[i]-c;
        double t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return(sum);
}

double FMAmethod(double const psi[], double pdf[], double const dv, unsigned const start, unsigned const fin) {
    double sum = 0;
    for (int i = 0; i < fin; i++)
        sum = fma(psi[i], pdf[i], sum);
    return(sum);
}




int main()
{
    int diap = 200;
    long int const N = 1000;
    //-100 - +100
    double dv = double(diap) / N;
    double psi[N], pdf[N];
    double T = 20;
    for (int i = 0; i < N; i++)
    {
        psi[i] = (i - floor(N / 2)+3)*dv;
        pdf[i] = pow((d_e), -((i - floor(N / 2)+3)*dv)* ((i - floor(N / 2)+3) * dv) * T);
    }
    cout << fixed << setprecision(11) << RecursiveDoublingSum (psi, pdf, dv, 0, N - 1)*dv << endl;
    cout << fixed << setprecision(11) << DoublingStep (psi, pdf, dv, 0, N - 1) * dv << endl;
    cout << fixed << setprecision(11) << Kehen(psi, pdf, dv, 0, N - 1) * dv << endl;
    cout << fixed << setprecision(11) << FMAmethod(psi, pdf, dv, 0, N - 1) * dv << endl;
    return 0;
}