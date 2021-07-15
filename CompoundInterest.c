#include <stdio.h>

int main()
{
    float A,T,R,P;
    printf("enter the principal amount");
    scanf("%f",&P);
    printf("enter the rate of interst");
    scanf("%f",&R);
    printf("enter time");
    scanf("%f",&T);
    A=P*(pow((1 + R /100),T));
    printf("compound interest is = %f", A);
    return 0;
}
