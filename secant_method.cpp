//secant method
#include<iostream>
#include<cmath>
#include<iomanip>
using std::cin;
using std::cout;
using std::endl;
double abserr = 0.0001;
double f(double x)
{
	double res = 3*x + sin(x) - exp(x);
	return res;
}
int main()
{
	cout << "Enter a and b";
	double a,b;
	cin >> a >> b;
	int itrns = 0;
	while(1)
	{
		itrns++;
		double x = b - ((b-a)/(f(b)-f(a)))*f(b);
		if(fabs(x-b) < abserr)
		{
			cout << "ans found in " << itrns << "iterations and answer is";
			cout << std::fixed << std::setprecision(5) << x << endl;
			break;
		}
		a = b;
		b = x;
	}
}
