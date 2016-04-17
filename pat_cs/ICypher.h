#include <string>

class ICypher
{
public: 
	virtual std::string cypher(std::string const &s, std::string const &c) = 0;
};
