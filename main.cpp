#include "base.hpp"
#include "op.hpp"
#include "Mult.hpp"
#include "Div.hpp"
//#include "Pow.hpp"
#include "add.hpp"
#include "sub.hpp"
//#include "container.hpp"
//#include "vector.hpp"
//#include "sort.hpp"
//#include "selectionSort.hpp"
//#include "list.hpp"
//#include "Bubble_sort.hpp"
#include "paren.hpp"
#include "trunc.hpp"
#include "decorator.hpp"
#include <iostream>

int main(){
	Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);
    
    Decorator* dec = new Decorator(TreeC);
    Decorator* d2 = new Decorator(TreeC);
    Paren* p = new Paren(dec);
    Trunc * t = new Trunc(d2);
    //Add* a = new Add(three, t);
    //Paren* paren = dec;
    //Paren* paren = dec;
    std::cout << p->stringify() << std::endl;
    //std::cout << "T: " << t->stringify() << std::endl;
    //std::cout << a->stringify() << std::endl;
   
   /*
    Base* test = new Trunc("5-7");
    test->set_child(test);
    std::cout << test->stringify();
*/
    
 /*
    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);
    
    std::cout << container->at(0)->evaluate() << ", " << container->at(1)->evaluate() << ", " << container->at(2)->evaluate() << ", " << std::endl;
    
    container->set_sort_function(new SelectionSort());
    container->sort();
    
    std::cout << container->at(0)->evaluate() << ", " << container->at(1)->evaluate() << ", " << container->at(2)->evaluate() << ", " << std::endl;
    
  */  
    return 0;
}
