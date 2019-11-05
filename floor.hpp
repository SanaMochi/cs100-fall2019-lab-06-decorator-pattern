#ifdef _Floor_
#define _Floor_

#include "base.hpp"
#include "decorator.hpp"
#include <cmath>

class Floor : public Decorator {
	public:
	virtual int evaluate() {
		return floor(this->c->evaluate());
	}
};

#endif //_Floor_
