 
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

#endif //_EvaluateDecoratorTest_
