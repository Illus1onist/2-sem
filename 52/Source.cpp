
#include <iostream>
#include <cstring>
using namespace std;

//c-1, h-2, n-3, b-4
int main()
{
	int Rool[16];
	string str;
	long long int itog[4];
	long int pairsnumber[16];
	long int newpairsnumber[16];
	cin >> str;

	int T1[20];
	for (int i = 0; i < str.length(); i++)
	{
		itog[i] = 0;
		
		if (str[i] == 'C')
			T1[i] = 1;
		if (str[i] == 'H')
			T1[i] = 2;
		if (str[i] == 'N')
			T1[i] = 3;
		if (str[i] == 'B')
			T1[i] = 4;
	}
	char a, b, c;
	int a1 = 0, b1 = 0, c1;
	char trash[4];
	for (int i = 0; i < 16; i++)
	{
		pairsnumber[i] = 0;
		newpairsnumber[i] = 0;
		cin >> a >> b;
		cin >> trash[0];
		cin >> trash[1];

		cin >> c;
		if (a == 'C')
			a1 = 1;
		if (a == 'H')
			a1 = 2;
		if (a == 'N')
			a1 = 3;
		if (a == 'B')
			a1 = 4;
		if (b == 'C')
			b1 = 1;
		if (b == 'H')
			b1 = 2;
		if (b == 'N')
			b1 = 3;
		if (b == 'B')
			b1 = 4;
		if (c == 'C')
			c1 = 1;
		if (c == 'H')
			c1 = 2;
		if (c == 'N')
			c1 = 3;
		if (c == 'B')
			c1 = 4;
		Rool[(a1 - 1) * 4 + (b1 - 1)] = c1;
	}
	for (int j = 0; j < str.length()-1; j++)
		pairsnumber[(T1[j]-1) * 4 + T1[j+1] - 1] = pairsnumber[(T1[j] - 1) * 4 + T1[j + 1] - 1] + 1;

	
	int k = 40;
	for (int j = 0; j < k-1; j++)
	{
		for (int i = 0; i < 16; i++)
		{
			newpairsnumber[i] = 0;
		}
		for (int i = 0; i < 16; i++)
		{
			newpairsnumber[(i / 4) * 4 + Rool[i] - 1] = newpairsnumber[(i / 4)*4 + Rool[i] - 1] + pairsnumber[i];
			newpairsnumber[(Rool[i] - 1) * 4 + i % 4] = newpairsnumber[(Rool[i] - 1) * 4 + i % 4] + pairsnumber[i];
		}
		for (int i = 0; i < 16; i++)
		{
			pairsnumber[i] = newpairsnumber[i];
		}
	}
	for (int i = 0; i < 16; i++)
	{
		int o = Rool[i]-1;
		itog[o] = itog[o] + pairsnumber[i];
	}

	pairsnumber[(T1[3]-1) * 4 + T1[0]-1] = pairsnumber[(T1[3] - 1) * 4 + T1[0] - 1] + 1;

	cout << endl;
	for (int i = 0; i < 4; i++)
		itog[i] = itog[i]+(pairsnumber[i * 4 + 0] + pairsnumber[i * 4 + 1] + pairsnumber[i * 4 + 2] + pairsnumber[i * 4 + 3] + pairsnumber[0 * 4 + i] + pairsnumber[1 * 4 + i] + pairsnumber[2 * 4 + i] + pairsnumber[3 * 4 + i])/2;
	cout<< max(max(itog[0], itog[1]), max(itog[2], itog[3])) - min(min(itog[0], itog[1]), min(itog[2], itog[3])) << endl;
	return 0;
}
