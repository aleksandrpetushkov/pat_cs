
class Alg //Абстрактный класс алгоритм
{
public:
	virtual std::string encryption(std::string const &s, std::string const &c) = 0;
	virtual std::string decryption(std::string const &s, std::string const &c) = 0;
};



class Xor :public Alg //Класс обычного XOR кодирование
{
	std::string encryption(std::string const &s, std::string const &c) //Метод шифрования.
	{
		std::string result = s;
		unsigned k = 0;
		for (unsigned i = 0; i < s.length(); ++i, ++k)
		{
			if (k == c.length())
			{
				k = 0;
			}
			result[i] ^= c[k];

		}
		return result;
	}


	std::string decryption(std::string const &s, std::string const &c) //Метод расшифровки (в случае с хор тоже действие что и шифрование).
	{
		std::string result = s;
		unsigned k = 0;
		for (unsigned i = 0; i < s.length(); ++i, ++k)
		{
			if (k == c.length())
			{
				k = 0;
			}
			result[i] ^= c[k];

		}
		return result;
	}
};


class CBC :public Alg
{
	std::string	encryption(const std::string &s, const std::string &c) //Методе кодировки 
	{
		std::string result = s;
		int z;
		int i = 0;
		for (; i < s.length(); ++i)
		{
			if (s.length() == i)
			{
				return result;
			}
			else if (c.length()>i)
			{
				result[i] ^= c[i];
			}
			else
			{
				z = i - c.length();
				result[i] ^= result[i - c.length()];
			}

		}
		return result;

	}
	
	std::string decryption(const std::string &s, const std::string &c)
	{
		std::string result = s;
		for (int i = s.length(); i != 0; --i)
		{
			if (i>c.length())
			{
				result[i - 1] ^= result[i - c.length() - 1];
			}
			else
			{
				result[i - 1] ^= c[i - 1];
			}
		}
		return result;

	}
};

