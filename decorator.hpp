#ifndef __Decorator__
#define __Decorator__

#include "base.hpp"

class Decorator : public Base {
	protected:
	Base* c;
	
	public:
	Decorator() { };
	virtual double evaluate() {
		return this->c->evaluate();
	}
    virtual std::string stringify() {
		return this->c->stringify();
	}
	void set_child(Base* c) {
		this->c = c;
	}
};

#endif //__Decorator__
