#include "base.hpp"

class Decorator : public Base {
	protected:
	Base* c;
	
	public:
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
