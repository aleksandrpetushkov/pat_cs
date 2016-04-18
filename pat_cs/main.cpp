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



	//*/
	cin.get();
}