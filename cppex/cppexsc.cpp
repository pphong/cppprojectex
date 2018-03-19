#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>

using namespace std;

struct List
{
	string Name;
	int Age;
};

bool Input(List ds[20], int &num)
{
	fstream InF("inputfile.txt", ios::in);
	if (InF.fail()) return false;
	int cou = 0;
	while (!InF.eof())
	{
		char temp[255];char a;
		InF.getline(temp, 255);
		ds[cou].Name = temp;
		fflush(stdin);
		InF >> a;
		ds[cou].Age = (int)a;
		fflush(stdin);
		cou++;
	}
	num = cou;
	return true;
}

void Output(List ds[20], int num)
{
	for (int i = 0; i <= num; i++)
		cout << ds[i].Name << "    " << ds[i].Age << endl;
}

void main()
{
	List ds[20];int num = 0;
	if (!Input(ds, num)) cout << "Failed to open this file !" << endl;
	Output(ds, num);
	system("pause");
}