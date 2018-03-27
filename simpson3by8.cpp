//simpson 3/8
#include<iostream>
#include<vector>
using std::cin;
using std::cout;
double f(double x)
{
	return 1.0/(1+x*x);
}
int main()
{
	double a,b;
	cout << "Enter Lower and Upper Limit: ";
	cin >> a >> b;
	cout << "Enter Number of subintervals: ";
	int n;
	cin >> n;
	if(n%3)
	{
		cout << "Subinterval Length is not multiple of 3!!!!";
		return 0;
	}
	double h = (b-a)/(double)n;
	std::vector<double> y(n+1);
	for(int i = 0; i <= n; i++)
	{
		y[i] = f(a+h*i);
	}
	double res = y[0]+y[n];
	for(int i = 1; i < n; i++)
	{
		if(i%3)
			res += 3*y[i];
		else
			res += 2*y[i];
	}
	res *= 3.0*h/8.0;
	cout << res;
}