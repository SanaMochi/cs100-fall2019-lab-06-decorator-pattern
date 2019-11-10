#ifndef _EvaluateDecoratorTest_
#define _EvaluateDecoratorTest_

#include "gtest/gtest.h"
 
#include "base.hpp"
#include "op.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "paren.hpp"
#include "trunc.hpp"
#include "decorator.hpp"
#include "floor.hpp"
#include "ceiling.hpp"
#include "abs.hpp"

TEST(DecoratorTests, BasicParenTest){
    Op* six = new Op(6);
    Decorator* dec = new Decorator(six);
    Paren* p = new Paren(dec);
    EXPECT_EQ(p->stringify(), "(6.000000)");
}

TEST(DecoratorTests, BasicTruncTest){
	Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* Tree = new Sub(ten, six);
    Decorator* dec = new Decorator(Tree);
    Trunc * t = new Trunc(dec);
    EXPECT_EQ(t->stringify(), "4.000000");
}

TEST(DecoratorTests, TruncTestAdd){
	Op* ten = new Op(10);
    Op* six = new Op(6);
    Op* two = new Op(2);
    Sub* Tree = new Sub(ten, six);
    Decorator* dec = new Decorator(Tree);
    Trunc * t = new Trunc(dec);
    Add* a = new Add(two, t);
    EXPECT_EQ(a->stringify(), "2.000000 + 4.000000");
}

TEST(DecoratorTests, TruncTestSub){
	Op* ten = new Op(10);
    Op* six = new Op(6);
    Op* two = new Op(2);
    Sub* Tree = new Sub(ten, six);
    Decorator* dec = new Decorator(Tree);
    Trunc * t = new Trunc(dec);
    Sub* s = new Sub(two, t);
    EXPECT_EQ(s->stringify(), "2.000000 - 4.000000");
}

TEST(DecoratorTests, ParenTestAdd){
    Op* six = new Op(6);
    Op* four = new Op(4);
    Add* a = new Add(six, four);
    Decorator* dec = new Decorator(a);
    Paren* p = new Paren(dec);
    EXPECT_EQ(p->stringify(), "(6.000000 + 4.000000)");
}

TEST(DecoratorTests, ParenTestSub){
    Op* six = new Op(6);
    Op* four = new Op(4);
    Sub* s = new Sub(six, four);
    Decorator* dec = new Decorator(s);
    Paren* p = new Paren(dec);
    EXPECT_EQ(p->stringify(), "(6.000000 - 4.000000)");
}

TEST(DecoratorTests, ParenAndTrunc){
    Op* ten = new Op(10);
    Op* six = new Op(6);
    Op* two = new Op(2);
    Sub* Tree = new Sub(ten, six);
    Decorator* dec = new Decorator(Tree);
    Trunc * t = new Trunc(dec);
    Sub* s = new Sub(two, t);
    Decorator* d2 = new Decorator(s);
    Paren* p = new Paren(d2);
    EXPECT_EQ(p->stringify(), "(2.000000 - 4.000000)");
}

///---------------------------------------------------fix these---------------------------------
TEST(DecoratorTests, AddCeilPosTest) {
    Base* op1 = new Op(7.5);
    Base* op2 = new Op(1.4);
    
    Base* test = new Add(op1, op2);
    Decorator* test1 = new Ceiling(test);
    
    EXPECT_EQ(test1->evaluate(), 9);
}

TEST(DecoratorTests, AddCeilNegTest) {
	Base* op1 = new Op(-7.5);
	Base* op2 = new Op(-1.4);

	Base* test = new Add(op1, op2);
	Decorator* test1 = new Ceiling(test);
	EXPECT_EQ(test1->evaluate(), -8);
}

TEST(DecoratorTests, AddCeilZeroTest) {
        Base* op1 = new Op(0.5);
        Base* op2 = new Op(-0.0);

        Base* test = new Add(op1, op2);
        Decorator* test1 = new Ceiling(test);
        EXPECT_EQ(test1->evaluate(), 1);
}

TEST(DecoratorTests, SubCeilPosTest) {
        Base* op1 = new Op(7.5);
        Base* op2 = new Op(1.4);

        Base* test = new Sub(op1, op2);
        Decorator* test1 = new Ceiling(test);
        EXPECT_EQ(test1->evaluate(), 7);
}

TEST(DecoratorTests, MultCeilNegTest) {
        Base* op1 = new Op(0.5);
        Base* op2 = new Op(-6);

        Base* test = new Mult(op1, op2);
        Decorator* test1 = new Ceiling(test);
        EXPECT_EQ(test1->evaluate(), -3);
}

TEST(DecoratorTests, DivCeilNegTest) {
        Base* op1 = new Op(-6);
        Base* op2 = new Op(0.45);

		Base* test = new Div(op1, op2);
        Decorator* test1 = new Ceiling(test);
        EXPECT_EQ(test1->evaluate(), -13);
}

TEST(DecoratorTests, AddFloorPosTest){
        Base* op1 = new Op(3);
        Base* op2 = new Op(7.5);

        Base* test = new Mult(op1, op2);
        Decorator* test1 = new Floor(test);
        EXPECT_EQ(test1->evaluate(),22);
}

TEST(DecoratorTests, SubFloorPosTest){
        Base* op1 = new Op(3.6);
        Base* op2 = new Op(7.5);

        Base* test = new Sub(op1, op2);
        Decorator* test1 = new Floor(test);
        EXPECT_EQ(test1->evaluate(), -4);
}

TEST(DecoratorTests, MultFloorPosTest) {
        Base* op1 = new Op(0.5);
        Base* op2 = new Op(6.6);

        Base* test = new Mult(op1, op2);
        Decorator* test1 = new Floor(test);
        EXPECT_EQ(test1->evaluate(),3);
}

TEST(DecoratorTests, DivFloorPosTest) {
        Base* op1 = new Op(6.6);
        Base* op2 = new Op(0.5);

        Base* test = new Div(op1, op2);
        Decorator* test1 = new Floor(test);
        EXPECT_EQ(test1->evaluate(), 13);
}

TEST(DecoratorTests, SubAbsPosTest) {
        Base* op1 = new Op(0.5);
        Base* op2 = new Op(6.6);

        Base* test = new Sub(op1, op2);
        Decorator* test1 = new Abs(test);
        EXPECT_EQ(test1->evaluate(), 6.1);
}

TEST(DecoratorTests, MultAbsNegTest) {
        Base* op1 = new Op(6.6);
        Base* op2 = new Op(-0.5);

        Base* test = new Mult(op1, op2);
        Decorator* test1 = new Abs(test);
        EXPECT_EQ(test1->evaluate(), 3.3);
}

TEST(DecoratorTests, DivAbsPosTest) {
        Base* op1 = new Op(6.6);
        Base* op2 = new Op(0.5);

        Base* test = new Div(op1, op2);
        Decorator* test1 = new Abs(test);
        EXPECT_EQ(test1->evaluate(), 13.2);
}

#endif
