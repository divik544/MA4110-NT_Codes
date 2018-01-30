#include<iostream>
#include<cmath>

using namespace std;

float func(float x)		//change this function as per requirement
{
	return (x*log10(x)-1.2f);
}

int main()
{
	float a,b;
	float abserr = 0.001f;		//absolute error
	int steps = 0;
	printf("Enter interval points:\n");
	scanf("%f %f",&a,&b);	//enter a s.t. func(a)<0 && func(b)>0
	if(func(a)*func(b)>0)
		printf("invalid interval -_-\n");
	else
	{
		float prevx = (a+b)/(float)2;
		float curx;
		int i = 0;
		bool res = false;
		while(i++<100)	//no of iterations must not exceed 100
		{
			steps++;
			if(func(prevx)<0)
			a = prevx;
			else
			b = prevx;
			
			curx = (a+b)/(float)2;
			if( fabs(prevx-curx) < abserr ) 
			{
				printf("answer found in %d iterations and ans is %.4f\n", steps, curx);
				printf("%f %f", func(prevx), func(curx));
				res = true;
				break;
			}
			prevx = curx;
		}
		if(!res)
		printf("Unable to find answer in 100 iterations\n");
	}
}
