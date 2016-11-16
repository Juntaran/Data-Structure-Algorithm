#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>

using namespace std;

int main()
{
    long i,in,N=1000000;
    double x,y,pi;
	srand(time(NULL));
    for(i=0,in=0; i<N; i++)
    {
        x=2.0*rand()/RAND_MAX-1;
        y=2.0*rand()/RAND_MAX-1;
        if((x*x+y*y)<=1)
		{
			in++;
		}
    }
    pi=4.0*in/N;
    cout<<pi<<endl;
    getch();
    return 1;
}