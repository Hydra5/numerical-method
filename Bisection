# include <stdio.h>
# include <math.h>
 
double quest(double x)
{
     return (2*x*x*x-4*x*x+3*x-6);
}
 
 
double solve_bisection(double m,double n)
{
     double r;int i=0;
    
     if (quest(m)*quest(n)>0)
            printf ("There are no roots in this area\n");
    
   
     while (fabs(n-m)>0.001)
     {
            r=(m+n)/2;
            if (quest(r)*quest(n)<=0)
                   m=r;
            else
                   n=r;
            i=i++;
     }
     printf("the number of operations: i=%d\n",i);
     return r;
}
