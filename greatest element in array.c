#include <stdio.h>
int maximum(int arr[], int n)
{

    int i;
    int max = arr[0];  
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
 

int main()
{
    int arr[5],i;
    printf("enter 5 numbers:");
    for (i=0;i<= sizeof(arr[5]);i++)
    {
    scanf("%d",&arr[i]);
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Largest in given array is %d", maximum(arr, n));
    return 0;
}
