#ifndef MULT_H
#define MULT_H

#include "base.hpp"
#include <string>
#include <iostream>


class Mult : public Base {
	Base* Op1;
	Base* Op2;
	public:
		Mult(Base* a, Base* b) : Base() {Op1 = a; Op2 = b;}
		virtual double evaluate() {
			return (Op1->evaluate() * Op2->evaluate());
		}
		virtual std::string stringify() {
			return (std::to_string(Op1->evaluate()) + " * " + std::to_string(Op2->evaluate()));
		}
};

#endif // MULT_H
