#include <iostream>

using namespace std;

class Fraction
{
	int up_Num;
	int down_Num;
public:
	Fraction(int arg1, int arg2) : up_Num(arg1), down_Num(arg2) {};
	int get_Up_Num();
	int get_Down_Num();
	void set_Up_Num(int);
	void set_Down_Num(int);
	void Print();
	void Multiply(Fraction);
	void Devide(Fraction);
	void Plus(Fraction);
	void Minus(Fraction frac);
	void Reduce();
private:
	int GetNOD();
	int GetNOK();
	
};


int main()
{
	Fraction test{3,15};
	test.Print();
	//test.Multiply({ -53,-52 });
	//test.Devide({ -53,-52 });
	//test.Plus({ 4,18 });
	//test.Minus({ 4,18 });
	test.Print();
	return 0;
}




int Fraction::get_Up_Num()
{
	return up_Num;
}
int Fraction::get_Down_Num()
{
	return down_Num;
}
void Fraction::set_Up_Num(int arg)
{
	up_Num = arg;
}
void Fraction::set_Down_Num(int arg)
{
	down_Num == arg;
}

void Fraction::Print()
{
	cout << up_Num << "/" << down_Num << endl;
}

void Fraction::Multiply(Fraction frac)
{
	up_Num *= frac.up_Num;
	down_Num *= frac.down_Num;
	Reduce();
}

int Fraction::GetNOD()
{
	int a = up_Num;
	int b = down_Num;
	if (a < b)
		swap(a, b);

	while (a % b != 0) 
	{
		a %= b;
		swap(a, b);
	}
	return b;
}

int Fraction::GetNOK()
{
	return (up_Num * down_Num) / GetNOD();
}

void Fraction::Reduce()
{
	int NOD = GetNOD();
	up_Num /= NOD;
	down_Num /= NOD;
}

void Fraction::Devide(Fraction frac)
{
	swap(frac.up_Num, frac.down_Num);
	Multiply(frac);
}

int GetNODMain(int a, int b)
{
	if (a < b)
		swap(a, b);

	while (a % b != 0)
	{
		a %= b;
		swap(a, b);
	}
	return b;
}

int GetNOKMain(int a, int b)
{
	return (a * b) / GetNODMain(a, b);
}

void Fraction::Plus(Fraction frac)
{
	int NOK = GetNOKMain(frac.down_Num, down_Num);
	int dop_mult1 = NOK / down_Num;
	int dop_mult2 = NOK / frac.down_Num;
	up_Num *= dop_mult1;
	frac.up_Num *= dop_mult2;
	up_Num += frac.up_Num;
	down_Num = NOK;
	Reduce();
}

void Fraction::Minus(Fraction frac)
{
	frac.up_Num = ~frac.up_Num + 1;
	Plus(frac);
}