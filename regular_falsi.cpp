#include<iostream>
#include<cmath>

using namespace std;

float f(float x)		//change this function as per requirement
{
	return (x*exp(x)-cos(x));
}

int main()
{
	float a,b;
	float abserr = 0.0001f;		//absolute error
	int steps=0;
	printf("Enter interval points:\n");
	scanf("%f %f",&a,&b);	//enter a s.t. func(a)<0 && func(b)>0
	if(f(a)*f(b)>0)
		printf("invalid interval -_-\n");
	else
	{
		float prevx= a-(((b-a)/(f(b)-f(a)))*f(a));
		float curx;
		int i=0;
		bool res=false;
		while(i++<100)	//no of iterations must not exceed 100
		{
			steps++;
			if(f(prevx)<0)
			a=prevx;
			else
			b=prevx;
			
			curx= a-(((b-a)/(f(b)-f(a)))*f(a));
			if(fabs(prevx-curx)<abserr)
			{
				printf("answer found in %d iterations and ans is %.4f\n",steps,curx);
//				cout << f(prevx)<<" " <<f(curx);
				res=true;
				break;
			}
			prevx=curx;
		}
		if(!res)
		cout<<"Unable to find answer after 100 iterations hence terminating\n";
	}
}
