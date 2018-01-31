/*
100 10.63
150 13.03
200 15.04
250 16.81
300 18.42
350 19.90
400 21.27

ans = 21.5352
*/
#include<iostream>
#include<cmath>
#include<iomanip>
using std::cin;
using std::cout;
using std::endl;
double abserr = 0.0001;
int main()
{
	cout << "Enter no of data items: ";
	int n;
	cin >> n;
	cout << "Enter x and f(x): \n";
	double v[n];
	double func[n];
	for(int i=0;i<n;i++)
	{
		cin >> v[i] >> func[i];
	}
	
	cout << "Enter point at which value is required: ";
	double x;
	cin >> x;
	double mat[n-1][n-1];
	for(int i=0;i<n-1;i++)
	{
		mat[i][0] = func[i+1] - func[i];
	}
	for(int i=1;i<n-1;i++)
	{
		for(int j = 1; j<=i ; j++)
			mat[i][j] = mat[i][j-1] - mat[i-1][j-1];
	}
	
	double u = (x - v[n-1])/(v[1] - v[0]);
	double res = func[n-1];
	double num = u,denom = 1;
	for(int i = 1;i <= n-1;i++)
	{
		res += (num/denom)*mat[n-2][i-1];
		num *= (u+i);
		denom *= (i+1);
	}
	cout << "Result is "<<res;
}

