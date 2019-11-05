#ifdef _Ceiling_
#define _Ceiling_

#include "base.hpp"
#include "decorator.hpp"
#include <cmath>

class Ceiling : public Decorator {
	public:
	Ceiling() { };
	//Ceiling(Base* c) {this->c = c;}
	/*
	virtual int evaluate() {
		return ceil(this->c->evaluate());
	}*/
};

#endif //_Ceiling_
