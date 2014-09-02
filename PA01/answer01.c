#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
    int ind;
    int sum = 0;
    
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
    int count = 0;
    
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
    int answer = 0;
    
    if(len==0 || len==1)
    {
        answer = 1;
    }
    else
    {
        for(ind=1;ind<=len;ind++)
        {
            if(array[ind]>=array[ind-1])
            {
                answer = 1;
            }
            else
            {
            answer = 0;
            }
        }
    }
    //return 0;
    return answer;
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
    int ind;
    int answer = -1;
    
    for (ind=0;ind<len;ind++)
    {
        if(haystack[ind]==needle)
        {
            answer = ind;
        }
    }
    //return 0;
    return answer;
}

int arrayFindSmallest(int * array, int len)
{
    int ind;
    
    return 0;
}
