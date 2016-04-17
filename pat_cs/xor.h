#include "ICypher.h"

class Xor :ICypher
{
	std::string cypher(std::string const &s, std::string const &c)
	{
		std::string result;
		unsigned k=0;
		for (unsigned i = 0; i < s.length(); ++i, ++k)
		{
			if(k==c.length())
			{
				k = 0;
			}
			result[i] = s[i] ^ c[k];

		}
		return result;
	}
};
