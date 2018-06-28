# include <stdio.h>
# include <math.h>
#define esp 10e-6
 
double  f(double x)
{
     return (2*x*x*x-4*x*x+3*x-6);
}
 
double  f1(double x)
{
     return (6*x*x-8*x+3);
}
 
 
 
double solve_newton(double x)
{ 
     int i=0;
     double x1=x;
     do{
            if (f1(x)<esp) break;
            x=x1;
            x1=x-f(x)/f1(x);
            i++;
     }
     while(fabs(f(x1)-f(x))>esp);
     printf("运算次数为 i=%d\n",i);
     return (x1);
}
