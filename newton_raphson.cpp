#include<iostream>
#include<cmath>
#include<iomanip>
using std::cin;
using std::cout;
using std::endl;
double abserr = 0.0001;

double f(double x)
{
	double res = 3*x - cos(x) - 1;
	return res;
}

double df(double x)
{
	return (3 + sin(x));
}

int main()
{
	double a;
	cin >> a;
	int itrns = 0;
	while(1)
	{
		itrns++;
		double x = a - f(a)/df(a);
		if(fabs(a-x) < abserr)
		{
			cout << "ans found in " << itrns << "iterations and answer is";
			cout << std::fixed << std::setprecision(5) << x << endl;
			cout << "f(x) is " << f(x);
			break;
		}
		a = x;
	}
}

