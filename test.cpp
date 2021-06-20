#include "test.h"
#include<cstdlib>
#include<iomanip>
#include<iostream>
using namespace std;


test::test(int num1, int num2, int num3, int num4, int num5)
{
	setNum1(num1);
	setNum2(num2);
	setNum3(num3);
	setNum4(num4);
	setNum5(num5);

}
void test::setNum1(int num1)
{
	this->num1 = num1;
}
void test::setNum2(int num2)
{
	this->num2 = num2;
}
void test::setNum3(int num3)
{
	this->num3 = num3;
}
void test::setNum4(int num4)
{
	this->num4 = num4;
}
void test::setNum5(int num5)
{
	this->num5 = num5;
}

int test::getNum1() const
{
	return num1;
}
int test::getNum2() const
{
	return num2;
}
int test::getNum3() const
{
	return num3;
}
int test::getNum4() const
{
	return num4;
}
int test::getNum5() const
{
	return num5;
}bool test::compareTwo(test com)
{
	int player = com.getNum4() + com.getNum5();
	if (player % 10 == 0)
		return 1;
	else 
		return 0;
}
bool test::compareThree(test play) 
{
	int player = play.getNum1() + play.getNum2() + play.getNum3();
	if (player % 10 == 0)
		return 1;
	else
		return 0;
}


