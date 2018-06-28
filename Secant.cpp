# include <stdio.h>
# include <math.h>
#define esp 10e-6
 
double f(double x){
     return (x*x-3*x+2);
}
 
 
double  solve_secant(double x0,double x1){
     double x;
    
     int i=0;
     while(fabs(x1-x0)>esp)
     {
            x=x1-f(x1)*(x1-x0)/(f(x1)-f(x0));
            x0=x1;
            x1=x;
            i++;
     }
     //printf("the number of operations: i=%d\n",i);
    
     return (x1);
}
int main ()
{
     double m,n,result;
    
     printf("please input m n: \n");
     scanf("%lf%lf",&m,&n);
    
     result=solve_secant(m,n);
    
    printf("result=% 6.3f\n",result);
}
