//Trapezoidal rule
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
	double h = (b-a)/(double)n;
	std::vector<double> y(n+1);
	for(int i = 0; i <= n; i++)
	{
		y[i] = f(a+h*i);
		// cout << "y["<<i<<"] = " << y[i] << ' ';
	}
	// cout << '\n';
	double res = y[0]+y[n];
	for(int i = 1; i < n; i++)
		res += 2*y[i];
	res*= h/2.0;
	cout << res;

}