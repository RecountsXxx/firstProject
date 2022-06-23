#include <windows.h>
#include <ctime>
#include <string>
#include <iostream>
#include <conio.h>
#include <fstream>
//Åêçàìåíöèîíàÿ ðàáîòà ïî Øèôðó Âèæåíååðà
//Êàïðèÿí Áîãäàí Êàïðèÿí
//22.06.2022
using namespace std;
string A = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZàáâãäå¸æçèéêëìíîïðñòóôõö÷øùúûüýþÿÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞß1234567890!@#$%^&*()-_=+|}{:?>,.¹;?<";
string dencrypt,encrypt;
string B, C, D, E = "";
void func(int b, int c, int* F, int* G) {
	if (b >= c)
	{
		for (int i = 0; i < (b / c); i++)
		{
			D = D + C;
		}
		for (int j = 0; j < (b % c); j++)
		{
			D = D + C[j];
		}
	}
	else
	{
		for (int s = 0; s < b; s++)
		{
			D = D + B[s];
		}
	}
	for (int k = 0; k < b; k++)
	{
		for (int n = 0; n < A.length(); n++)
		{
			if (B[k] == A[n])
			{
				F[k] = n;
			}

			if (D[k] == A[n])
			{
				G[k] = n;
			}

		}
	}
}
int main()
{
	int shifr = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ukr");
	ifstream current("current.txt");
	if (!current.is_open()) {
		cout << "Erorr currentFile" << endl;
	}
	else
		cout << "Working currentFile" << endl;
		getline(current, B);

	cout << "Ââåäèòå êëþ÷: ";
	cin >> C;
	system("cls");
	int* F = new int[B.size()];
	int* G = new int[B.size()];
	int c = C.size();
	int b = B.size();
	func(b, c, F, G);
	long int e = 0;
	system("cls");
	ofstream encryptFile("encrypt.txt");
	ofstream decryptFile("decrypt.txt");
	if (!encryptFile.is_open()) {
		cout << "Erorr encryptFile" << endl;
	}
	else
		cout << "Working encryptFile" << endl;
	if (!decryptFile.is_open()) {
		cout << "Erorr decryptFile" << endl;
	}
	else
		cout << "Working decryptFile" << endl;

		for (int u = 0; u < b; u++)
		{
			e = ((F[u] + G[u]) % A.length());
			B[u] = A[e];
			encrypt = B;
		}
		cout << endl;
		cout << "Çàøèôðîâàííîå ñëîâî: " << e << encrypt << endl;
		cout << endl;
		int variantt = 0;
		encryptFile << "Çàøèôðîâàííîå ñëîâî: " << encrypt << endl;
		cout << "Åñëè âû õîòèòå ðàçøèôðîâàòü òåêñò íàæìèòå íà 1: ";
		cin >> variantt;
		cout << endl;
		if (variantt == 1) {
			int* F = new   int[B.size()];
			int* G = new int[B.size()];
			int c = C.size();
			int b = B.size();
			func(b, c, F, G);
			for (int u = 0; u < b; u++)
			{
				e = ((F[u] - G[u]));
				if(e < 0)
					e += A.length();
				B[u] = A[e];
				dencrypt = B;
			}
			cout << "Ðàçøèôðîâàííîå ñëîâî: " << dencrypt << endl;
		    decryptFile << "Ðàçøèôðîâàííîå ñëîâî: " << dencrypt << endl;
			cout << endl;
			system("pause");

		}
		


		return 0;

	current.close();
	encryptFile.close();
	decryptFile.close();
}