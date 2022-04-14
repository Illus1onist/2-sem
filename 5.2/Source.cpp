#include <iostream>
#include <random>

using namespace std;
int main()
{
	long long int number;
	cin>> number;
	long long int zelen = 0;
	long long int param = 2;
	int i = 0;
	while (i < 62)
	{
		zelen += ((number / param) - (number / (2 * param))) * (i + 1);
		param *= 2;
		i++;
	}
	cout << zelen;

	return 0;
}
