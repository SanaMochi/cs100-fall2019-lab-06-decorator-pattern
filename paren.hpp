#include "decorator.hpp"

class Paren: public Decorator{
	std::string string = "";
	
	Paren(std::string str){
		this->string = str;
	}
	
	virtual std::string stringify(){
		return "(" + string + ")";
	}
};
