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
	
	st = "Hello world"; //�������� ����� 
	c = "SuperKey"; //����
	Cypher cp; //������ ��������
	cp.SetAlg(alg); //��������������� �������� ����������
	e_st = cp.encryption(st, c); //�������� 
	d_st = cp.decryption(e_st, c);//���������� 
	cout << e_st << endl << d_st; // �����
	//*/

	
	cin.get();
}