#include "decorator.hpp"
#include <iostream>
class Trunc: public Decorator{
	public:
	std::string string;
	Base* Oprand1;
	
	Trunc(){};
	
	Trunc(std::string str){
		string = str;
		this->parse();
	}
	
	void parse(){
		int num1, num2, at;
		//if its add
		//std::cout << string;
		if(string.find("+") != -1){
			at = string.find("+");
			num1 = std::stoi(string.substr(0, at));
			num2 = std::stoi(string.substr(at+1, string.size()));
			Oprand1 = new Op(num1 + num2);
			this->c = Oprand1;
			std::cout << c->stringify();
		}else{
			at = string.find("-");
			num1 = std::stoi(string.substr(0, at));
			num2 = std::stoi(string.substr(at+1, string.size()));
			Oprand1 = new Op(num1 - num2);
			this->c = Oprand1;
			//std::cout << c->stringify();
		}
		
	}
	
	virtual std::string stringify(){
		return Oprand1->stringify();
	}
};
