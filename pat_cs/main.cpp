#include <iostream>
#include "Cypher.h"
#include <string>
using namespace std;

int main()
{
	//*
	Xor _xor;
	Alg *alg = &_xor;

	
	string e_st, d_st, c, st;
	
	st = "Hello world"; //Открытый текст 
	c = "SuperKey"; //Ключ
	Cypher cp; //Объект шифратор
	cp.SetAlg(alg); //Устанавливается алгоритм шифрования
	e_st = cp.encryption(st, c); //Шифровка 
	d_st = cp.decryption(e_st, c);//Дешифровка 
	cout << e_st << endl << d_st; // вывод
	//*/

	
	cin.get();
}