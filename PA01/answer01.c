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
    int test;
    int small = array[0];
    
    if(len==0 || len==1)
    {
        answer = 1;
    }
    else
    {
        do
        {
            for(ind=0;ind<len;ind++)
            {
                if(array[ind]>=small)
                {
                    test = ind;
                    small = array[ind];
                }
            }
        while(array[ind]>=small)    
        if(test != len-1)
        {
            answer = 0;
        }
        else
        {
            answer = 1;
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
    int answer=len-1;
    int small = array[len-1];
    
    if(len==0)
    {    
        answer=0;
    }
    else
    {
        for(ind= len - 1;ind>=0;ind--)
        {
            if(array[ind]<= small)
            {
                small = array[ind];
                answer = ind;
            }
        }
    }
    return answer;
    //return 0;
}
