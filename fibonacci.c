#include <stdio.h>

int main()
{
    int a, b, result, n, i;
    printf("Enter The Number Of terms:");
    scanf("%d" , &n);
    a=-1;
    b=1;
    for(i=1; i<=n; i++)
    {
        result = a+b;
        printf("%d ", result);
        a=b;
        b=result;
    }

    return 0;
}
