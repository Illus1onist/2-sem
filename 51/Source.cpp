

#include <iostream>
using namespace std;
long long int Namm = 0, Camm = 0, Bamm = 0, Hamm = 0;
void function(int A1, int A2, int stepsleft,int Rool[])
{
	int mid = Rool[(A1-1)*4+A2-1];
	if (mid == 1)
		Camm = Camm + 1;
	if (mid == 2)
		Hamm = Hamm + 1;
	if (mid == 3)
		Namm = Namm + 1;
	if (mid == 4)
		Bamm = Bamm + 1;
	stepsleft = stepsleft - 1;
	if (stepsleft > 0)
	{
		function(A1, mid, stepsleft, Rool);
		function(mid, A2, stepsleft, Rool);
	}
	
}
	
//c-1, h-2, n-3, b-4
int main()
{
	int Rool[16];
	char T[4];
	int T1[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> T[i];
		if (T[i] == 'C')
			T1[i] = 1;
		if (T[i] == 'H')
			T1[i] = 2;
		if (T[i] == 'N')
			T1[i] = 3;
		if (T[i] == 'B')
			T1[i] = 4;
	}
	char a, b, c;
	int a1=0, b1=0, c1;
	char trash[4];
	for (int i = 0; i < 16; i++)
	{
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
		Rool[(a1-1)*4+(b1-1)] = c1;
	}

	function(T1[0], T1[1], 25, Rool);
	function(T1[1], T1[2], 25, Rool);
	function(T1[2], T1[3], 25, Rool);
	Namm = Namm + 2;
	Camm = Camm + 1;
	Bamm = Bamm + 1;
	Hamm = Hamm;
	cout << max(max(Bamm, Hamm),max(Namm,Camm))- min(min(Bamm, Hamm), min(Namm, Camm)) << endl;
	//cout << "N=" << Namm+2 <<' ' << "C=" << Camm+1 <<' ' << "B=" << Bamm+1 <<' ' << "H=" <<' ' << Hamm<<endl;
	
	return 0;
}
