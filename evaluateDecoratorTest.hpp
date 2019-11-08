#ifndef _EvaluateDecoratorTest_
#define _EvaluateDecoratorTest_

#include "gtest/gtest.h"
 
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

TEST(DecoratorEvaluate, AddCeilPosTest) {
    Base* op1 = new Op(7.5);
    Base* op2 = new Op(1.4);
    
    Base* test = new Add(op1, op2);
    Decorator* test1 = new Ceiling();
    
    EXPECT_EQ(test1->evaluate(), 9);
}

TEST(DecoratorEvaluate, AddCeilNegTest) {
	Base* op1 = new Op(-7.5);
	Base* op2 = new Op(-1.4);

	Base* test = new Add(op1, op2);
	Decorator* test1 = new Ceiling();
	EXPECT_EQ(test->evaluate(), -9);
}

TEST(DecoratorEvaluate, AddCeilZeroTest) {
        Base* op1 = new Op(0.5);
        Base* op2 = new Op(-0.0);

        Base* test = new Add(op1, op2);
        Decorator* test1 = new Ceiling();
        EXPECT_EQ(test->evaluate(), 0.5);
}

TEST(DecoratorEvaluate, SubCeilPosTest) {
        Base* op1 = new Op(7.5);
        Base* op2 = new Op(1.4);

        Base* test = new Sub(op1, op2);
        Decorator* test1 = new Ceiling();
        EXPECT_EQ(test->evaluate(), 6);
}

TEST(DecoratorEvaluate, MultCeilNegTest) {
        Base* op1 = new Op(0.5);
        Base* op2 = new Op(-6);

        Base* test = new Mult(op1, op2);
        Decorator* test1 = new Ceiling();
        EXPECT_EQ(test->evaluate(), -3);
}

TEST(DecoratorEvaluate, DivCeilNegTest) {
        Base* op1 = new Op(-6);
        Base* op2 = new Op(0.5);

		Base* test = new Mult(op1, op2);
        Decorator* test1 = new Ceiling();
        EXPECT_EQ(test->evaluate(), -12);
}

TEST(DecoratorEvaluate, AddFloorPosTest){
        Base* op1 = new Op(3.6);
        Base* op2 = new Op(7.5);

        Base* test = new Mult(op1, op2);
        Decorator* test1 = new Ceiling();
        EXPECT_EQ(test->evaluate(),11);
}

TEST(DecoratorEvaluate, SubFloorPosTest){
        Base* op1 = new Op(3.6);
        Base* op2 = new Op(7.5);

        Base* test = new Mult(op1, op2);
        Decorator* test1 = new Ceiling();
        EXPECT_EQ(test->evaluate(), -4);
}

TEST(DecoratorEvaluate, MultFloorPosTest) {
        Base* op1 = new Op(0.5);
        Base* op2 = new Op(6.6);

        Base* test = new Mult(op1, op2);
        Decorator* test1 = new Ceiling();
        EXPECT_EQ(test->evaluate(),0);
}

TEST(DecoratorEvaluate, DivFloorPosTest) {
        Base* op1 = new Op(6.6);
        Base* op2 = new Op(0.5);

                Base* test = new Mult(op1, op2);
        Decorator* test1 = new Ceiling();
        EXPECT_EQ(test->evaluate(), 13);
}

TEST(DecoratorEvaluate, AddAbsNegTest) {
        Base* op1 = new Op(-10.3);
        Base* op2 = new Op(5.6);

        Base* test = new Mult(op1, op2);
        Decorator* test1 = new Ceiling();
        EXPECT_EQ(test->evaluate(), 4.7);
}


TEST(DecoratorEvaluate, SubAbsPosTest) {
        Base* op1 = new Op(0.5);
        Base* op2 = new Op(6.6);

        Base* test = new Mult(op1, op2);
        Decorator* test1 = new Ceiling();
        EXPECT_EQ(test->evaluate(), 6.1);
}

TEST(DecoratorEvaluate, MultAbsNegTest) {
        Base* op1 = new Op(6.6);
        Base* op2 = new Op(-0.5);

                Base* test = new Mult(op1, op2);
        Decorator* test1 = new Ceiling();
        EXPECT_EQ(test->evaluate(), 3.3);
}

TEST(DecoratorEvaluate, DivAbsPosTest) {
        Base* op1 = new Op(6.6);
        Base* op2 = new Op(0.5);

                Base* test = new Mult(op1, op2);
        Decorator* test1 = new Ceiling();
        EXPECT_EQ(test->evaluate(), 13.2);
}

#endif
