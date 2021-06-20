#ifndef TEST
#define TEST

class test
{
private:

	int	num1;
	int num2;
	int num3;
	int num4;
	int num5;
public:
	test(int,int,int,int,int);
	void setNum1(int);
	void setNum2(int);
	void setNum3(int);
	void setNum4(int);
	void setNum5(int);

	int getNum1() const;
	int getNum2() const;
	int getNum3() const;
	int getNum4() const;
	int getNum5() const;
	bool compareTwo(test);
	bool compareThree(test);

};
#endif 


