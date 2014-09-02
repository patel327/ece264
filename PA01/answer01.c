#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
    int ind;
    int sum=0;
    
    for(ind=0;ind<len;ind++)
        {
            sum += array[ind];
        }
    //return 0;
    return sum;
}

int arrayCountNegative(int * array, int len)
{
    int ind;
    int count=0;
    
    for(ind=0;ind<len;ind++)
        {
            if(array[ind]<0)
            {
                count = count + 1;
            }
        }
    return count;
    //return 0;
}

int arrayIsIncreasing(int * array, int len)
{    
    int ind;
    int test=0;
    
    if(len==0 || len==1)
    {
        test = 1;
    }
    else
    {
        for(ind=1;ind<=len;ind++)
        {
            if(array[ind]>=array[ind-1])
            {
                test=1;
            }
            else
            {
            test=0;
            }
        }
    }
    //return 0;
    return test;
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
    int ind;
    
    return 0;
}

int arrayFindSmallest(int * array, int len)
{
    return 0;
}
