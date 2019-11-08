#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>
#include <sstream>

//using namespace std;
class Base {
    public:
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */
	virtual double evaluate() = 0;
	virtual std::string stringify() = 0;

//	namespace patch {
//		template <typename T> std::string to_string(const T& n) {
//			std::ostrinstream stm;
//			stm << n;
//			return stm.str();
//		}
//	}
};

#endif //__BASE_HPP__
