#include <iostream>
#include "Cypher.h"
#include <string>
using namespace std;

int main()
{
	//*
	Xor _xor;
	CBC _cbc;

	
	string e_st, d_st, c, st;
	
	st = "Hello world"; //Открытый текст 
	c = "SuperKey"; //Ключ
	Cypher cp; //Объект шифратор
	cp.SetAlg(&_xor); //Устанавливается алгоритм шифрования (обычный XOR)
	e_st = cp.encryption(st, c); //Шифровка 
	d_st = cp.decryption(e_st, c);//Дешифровка 
	cout<< "XOR:\n" << "	Original: " << st << endl << "	Encryption: " << e_st << endl << "	Decryption: " << d_st << endl; // вывод

	cp.SetAlg(&_cbc); //Устанавливается алгоритм шифрования CBC
	e_st = cp.encryption(st, c); //Шифровка 
	d_st = cp.decryption(e_st, c);//Дешифровка 
	cout << "CBC:\n" << "	Original: " << st << endl << "	Encryption: " << e_st << endl << "	Decryption: " << d_st << endl; // вывод



	//*/
	cin.get();
}