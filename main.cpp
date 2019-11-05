#include "base.hpp"
#include "op.hpp"
#include "Mult.hpp"
#include "Div.hpp"
//#include "Pow.hpp"
#include "add.hpp"
#include "sub.hpp"
//#include "rand.hpp"
#include "ceiling.hpp"
#include "floor.hpp"
#include "abs.hpp"
#include "decorator.hpp"


int main(){

Base* op1 = new Op(7.5);
    //Base* op2 = new Op(1.4);
    
    //Base* test = new Add(op1, op2);
    Decorator* test1 = new Ceiling();
  
 return 0;
}
