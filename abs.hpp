#ifdef _Abs_
#define _Abs_

#include "base.hpp"
#include "decorator.hpp"
#include <cmath>

class Abs : public Decorator {
	public:
	virtual int evaluate() {
		return std::abs(this->c->evaluate());
	}
};

#endif //_Abs_
