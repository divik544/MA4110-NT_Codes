//simpson 1/3
#include<iostream>
#include<vector>
using std::cin;
using std::cout;
double f(double x)
{
	return 1.0/(1+x);
}
int main()
{
	double a,b;
	cout << "Enter Lower and Upper Limit: ";
	cin >> a >> b;
	cout << "Enter Number of subintervals: ";
	int n;
	cin >> n;
	if(n%2)
	{
		cout << "Subinterval Length is not even!!!!";
		return 0;
	}
	double h = (b-a)/(double)n;
	std::vector<double> y(n+1);
	for(int i = 0; i <= n; i++)
	{
		y[i] = f(a+h*i);
	}
	double res = y[0]+y[n]+4*y[1];
	for(int i = 2; i < n; i+=2)
	{
		res += 4*y[i+1];
		res += 2*y[i];
	}
	res *= h/3.0;
	cout << res;
}