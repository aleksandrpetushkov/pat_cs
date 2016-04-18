#include <iostream>
#include "Cypher.h"
#include <string>
#include "gtest\gtest.h"

using namespace std;


//*
TEST(XOR, encryption) //���� �������� XOR
{
	Xor _xor;
	string e_st, e_tst, c, st;

	st = "TestString"; //�������� ����� 
	e_tst = st;
	c = "KeyCypher"; //����
	Cypher cp; //������ ��������
	cp.SetAlg(&_xor); //��������������� �������� ���������� (������� XOR)
	e_st = cp.encryption(st, c); //�������� 
	
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

TEST(XOR, decryption) //���� ���������� XOR
{
	Xor _xor;
	string e_tst, d_st, c, st;

	st = "TestString"; //�������� ����� 
	e_tst = st;
	c = "KeyCypher"; //����
	Cypher cp; //������ ��������

	unsigned k = 0;
	for (unsigned i = 0; i < e_tst.length(); ++i, ++k)
	{
		if (k == c.length())
		{
			k = 0;
		}
		e_tst[i] ^= c[k];

	}
	cp.SetAlg(&_xor); //��������������� �������� ���������� (������� XOR)
	d_st = cp.decryption(e_tst, c);//���������� 
		

	EXPECT_EQ("TestString", d_st);
}

TEST(CBC, encryption) //���� �������� CBC
{
	CBC _cbc;
	string e_st, e_tst, d_st, c, st;

	st = "TestString"; //�������� ����� 
	e_tst = st;
	c = "KeyCypher"; //����
	Cypher cp; //������ ��������
	cp.SetAlg(&_cbc); //��������������� �������� ���������� (������� CBC)
	e_st = cp.encryption(st, c); //�������� 

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


TEST(CBC, decryption)  //����� ���������� CBC
{
	CBC _cbc;
	string e_st, e_tst, d_st, c, st;

	st = "TestString"; //�������� ����� 
	e_tst = st;
	c = "KeyCypher"; //����
	Cypher cp; //������ ��������
	cp.SetAlg(&_cbc); //��������������� �������� ���������� (������� CBC)

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
	
	st = "Hello world"; //�������� ����� 
	c = "SuperKey"; //����
	Cypher cp; //������ ��������
	cp.SetAlg(&_xor); //��������������� �������� ���������� (������� XOR)
	e_st = cp.encryption(st, c); //�������� 
	d_st = cp.decryption(e_st, c);//���������� 
	cout<< "XOR:\n" << "	Original: " << st << endl << "	Encryption: " << e_st << endl << "	Decryption: " << d_st << endl; // �����

	cp.SetAlg(&_cbc); //��������������� �������� ���������� CBC
	e_st = cp.encryption(st, c); //�������� 
	d_st = cp.decryption(e_st, c);//���������� 
	cout << "CBC:\n" << "	Original: " << st << endl << "	Encryption: " << e_st << endl << "	Decryption: " << d_st << endl; // �����



	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	cin.get();
}