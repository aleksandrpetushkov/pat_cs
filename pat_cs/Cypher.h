#include "Alg.h"


class Cypher  //КЛасс шифрования (context - по стратегии)
{

public: 
	void SetAlg(Alg* alg) //метод установки алгоритма
	{
		_alg = alg;
	}

	std::string	encryption(const std::string &s, const std::string c) //Методе кодировки 
	{
		if(_alg==nullptr)
		{
			throw "Algorithm is not set";
		}
		return _alg->encryption(s, c);
	}
	std::string	decryption(const std::string &s, const std::string c)// Метод декодирование
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
