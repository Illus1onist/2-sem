#include <iostream>
#include <cstring>
using namespace std;


void AnalyzingString(string str, char alphabet[], int& alphabetlength)
{
	for (int i = 0; i < str.length(); i++)
	{
		int flag = 0;
		for (int j = 0; j < alphabetlength; j++)
			if (flag == 0 and alphabet[j] == str[i])
			{
				flag = 1;
				break;
			}
		if (flag == 0)
		{
			alphabet[alphabetlength] = str[i];
			alphabetlength = alphabetlength + 1;
		}
	}
}

void MakingAllMassivesReady(long long int itog[], long int pairsnumber[], long int newpairsnumber[])
{
	for (int j = 0; j < 256 * 256; j++)
	{
		if (j < 256)
			itog[j] = 0;
		pairsnumber[j] = 0;
		newpairsnumber[j] = 0;
	}
}

void MakingRools(int& alphabetlength, char alphabet[],int Rool[])
{
	char a[3];
	char trash[2];
	int schet = 0;
	while (schet < alphabetlength * alphabetlength)
	{

		cin >> a[0] >> a[1] >> trash[0] >> trash[1] >> a[2];

		for (int i = 0; i < 3; i++)
		{
			int flag = 0;
			for (int j = 0; j < alphabetlength; j++)
				if (flag == 0 and alphabet[j] == a[i])
				{
					flag = 1;
					break;
				}
			if (flag == 0)
			{
				alphabet[alphabetlength] = a[i];
				alphabetlength = alphabetlength + 1;
			}
		}
		Rool[a[0] * 256 + a[1]] = a[2];
		schet = schet + 1;
	}
}

void PairInitialization(string str, long int pairsnumber[])
{
	for (int j = 0; j < str.length() - 1; j++)
		pairsnumber[(str[j]) * 256 + str[j + 1]] = pairsnumber[(str[j]) * 256 + str[j + 1]] + 1;

}

void Iterations(long int pairsnumber[], long int newpairsnumber[], int& alphabetlength, char alphabet[], int& k, int Rool[])
{
	for (int s = 0; s < k - 1; s++)
	{
		for (int i = 0; i < alphabetlength; i++)
			for (int j = 0; j < alphabetlength; j++)
				newpairsnumber[alphabet[i] * 256 + alphabet[j]] = 0;

		for (int i = 0; i < alphabetlength; i++)
			for (int j = 0; j < alphabetlength; j++)
			{
				newpairsnumber[alphabet[i] * 256 + Rool[alphabet[i] * 256 + alphabet[j]]] = newpairsnumber[alphabet[i] * 256 + Rool[alphabet[i] * 256 + alphabet[j]]] + pairsnumber[alphabet[i] * 256 + alphabet[j]];
				newpairsnumber[Rool[alphabet[i] * 256 + alphabet[j]] * 256 + alphabet[j]] = newpairsnumber[Rool[alphabet[i] * 256 + alphabet[j]] * 256 + alphabet[j]] + pairsnumber[alphabet[i] * 256 + alphabet[j]];
			}

		for (int i = 0; i < alphabetlength; i++)
			for (int j = 0; j < alphabetlength; j++)
				pairsnumber[alphabet[i] * 256 + alphabet[j]] = newpairsnumber[alphabet[i] * 256 + alphabet[j]];
	}
}

void MakingSum(long int pairsnumber[], string str,  long int newpairsnumber[], int& alphabetlength, char alphabet[], int Rool[], long long int itog[])
{
	for (int i = 0; i < alphabetlength; i++)
		for (int j = 0; j < alphabetlength; j++)
		{
			itog[Rool[alphabet[i] * 256 + alphabet[j]]] = itog[Rool[alphabet[i] * 256 + alphabet[j]]] + pairsnumber[alphabet[i] * 256 + alphabet[j]];
		}
	// соединяем цепь
	pairsnumber[(str[str.length() - 1]) * 256 + str[0]] = pairsnumber[(str[str.length() - 1]) * 256 + str[0]] + 1;

	//считаем символы по парам
	long long int summapar = 0;
	for (int i = 0; i < alphabetlength; i++)
	{

		summapar = 0;
		for (int j = 0; j < alphabetlength; j++)
		{
			summapar = summapar + pairsnumber[alphabet[i] * 256 + alphabet[j]];
			summapar = summapar + pairsnumber[alphabet[j] * 256 + alphabet[i]];
		}
		itog[alphabet[i]] = itog[alphabet[i]] + summapar / 2;
	}
}

void MaxMinusMin(long long int itog[], char alphabet[], int& alphabetlength)
{
	//В итогах теперь хранятся все итоги (кто бы мог подумать), ищем максимальное и минимальное
	long long int minit = itog[alphabet[0]];
	for (int i = 0; i < alphabetlength; i++)
		if (itog[alphabet[i]] < minit)
			minit = itog[alphabet[i]];

	long long int maxit = 0;
	for (int i = 0; i < alphabetlength; i++)
		if (itog[alphabet[i]] > maxit)
			maxit = itog[alphabet[i]];
	cout << maxit - minit;
}



int main()
{
	int Rool[256*256];
	string str;
	long long int itog[256];
	long int pairsnumber[256*256];
	long int newpairsnumber[256*256];
	char alphabet[256];
	int alphabetlength=0;
	cin >> str;
	//считываем строку и в первый раз обновляем алфавит
	AnalyzingString(str, alphabet, alphabetlength);

	//подготоавливаем массивы и заполняем их нолями
	MakingAllMassivesReady(itog, pairsnumber, newpairsnumber);
	
	//считывание правил и добавление алфавита
	MakingRools(alphabetlength, alphabet, Rool);
	
	//инициализация пар из строки символов
	PairInitialization(str, pairsnumber);

	//самое главное! Алгоритм итерационного добавления пар вплоть до предпоследней итерации. Один из аргументов (k) - количество итераций.
	int k = 10;
	Iterations(pairsnumber, newpairsnumber, alphabetlength, alphabet, k, Rool);

	//суммирование целиком: и серединок, генерируемых предпоследней итерацией, и символов в самой предпоследней итерации 
	MakingSum(pairsnumber, str, newpairsnumber, alphabetlength, alphabet, Rool, itog);
	
	//поиск максимального, минимального и вывод разности
	MaxMinusMin(itog, alphabet, alphabetlength);
	
	
	return 0;
}
