#include <iostream>
#include "Cypher.h"
#include <string>
#include "gtest\gtest.h"

using namespace std;


//*
TEST(XOR, encryption) //Тест шифровки XOR
{
	Xor _xor;
	string e_st, e_tst, c, st;

	st = "TestString"; //Открытый текст 
	e_tst = st;
	c = "KeyCypher"; //Ключ
	Cypher cp; //Объект шифратор
	cp.SetAlg(&_xor); //Устанавливается алгоритм шифрования (обычный XOR)
	e_st = cp.encryption(st, c); //Шифровка 
	
	unsigned k = 0;
	for (unsigned i = 0; i < e_tst.length(); ++i, ++k)
	{
		if (k == c.length())
		{
			k = 0;
		}
		e_tst[i] ^= c[k];

	}
	EXPECT_EQ(e_st, e_tst);
}
//*/

TEST(XOR, decryption) //Тест дешифровки XOR
{
	Xor _xor;
	string e_tst, d_st, c, st;

	st = "TestString"; //Открытый текст 
	e_tst = st;
	c = "KeyCypher"; //Ключ
	Cypher cp; //Объект шифратор

	unsigned k = 0;
	for (unsigned i = 0; i < e_tst.length(); ++i, ++k)
	{
		if (k == c.length())
		{
			k = 0;
		}
		e_tst[i] ^= c[k];

	}
	cp.SetAlg(&_xor); //Устанавливается алгоритм шифрования (обычный XOR)
	d_st = cp.decryption(e_tst, c);//Дешифровка 
		

	EXPECT_EQ("TestString", d_st);
}

TEST(CBC, encryption) //Тест шифровки CBC
{
	CBC _cbc;
	string e_st, e_tst, d_st, c, st;

	st = "TestString"; //Открытый текст 
	e_tst = st;
	c = "KeyCypher"; //Ключ
	Cypher cp; //Объект шифратор
	cp.SetAlg(&_cbc); //Устанавливается алгоритм шифрования (обычный CBC)
	e_st = cp.encryption(st, c); //Шифровка 

	for (int i = 0; i < e_tst.length(); ++i)
	{
		
		if (c.length()>i)
		{
			e_tst[i] ^= c[i];
		}
		else
		{
			e_tst[i] ^= e_tst[i - c.length()];
		}

	}


	EXPECT_EQ(e_tst, e_st);
}


TEST(CBC, decryption)  //Тетст дешифровки CBC
{
	CBC _cbc;
	string e_st, e_tst, d_st, c, st;

	st = "TestString"; //Открытый текст 
	e_tst = st;
	c = "KeyCypher"; //Ключ
	Cypher cp; //Объект шифратор
	cp.SetAlg(&_cbc); //Устанавливается алгоритм шифрования (обычный CBC)

	for (int i = 0; i < e_tst.length(); ++i)
	{

		if (c.length()>i)
		{
			e_tst[i] ^= c[i];
		}
		else
		{
			e_tst[i] ^= e_tst[i - c.length()];
		}

	}
	d_st = cp.decryption(e_tst, c);


	EXPECT_EQ(st, d_st);
}

int main(int argc, char ** argv)
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



	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	cin.get();
}