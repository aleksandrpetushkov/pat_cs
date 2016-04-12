#include "Alg.h"


class Cypher  //����� ���������� (context - �� ���������)
{

public: 
	void SetAlg(Alg* alg) //����� ��������� ���������
	{
		_alg = alg;
	}

	std::string	encryption(const std::string &s, const std::string c) //������ ��������� 
	{
		if(_alg==nullptr)
		{
			throw "Algorithm is not set";
		}
		return _alg->encryption(s, c);
	}
	std::string	decryption(const std::string &s, const std::string c)// ����� �������������
	{
		if (_alg == nullptr)
		{
			throw "Algorithm is not set";
		}
		return _alg->decryption(s, c);
	}
protected:
	Alg* _alg = nullptr;
	
};
