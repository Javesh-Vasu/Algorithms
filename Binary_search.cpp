//So in Binary Search everytime our space is reduced to half, thus the time complexity id O(logn).
#include<iostream>
using namespace std;

int binary_search ( int array[] , int number , int size )
{
    int start = 0;
    int end = size-1;

    while ( start < end )
    {
        int mid = (start + end)/2;
        if ( array[mid] == number )
        {
            return mid;
        }

        else if( array[mid] > number )
        {
            end = mid-1 ;
        }

        else
        {
            start = mid+1;
        }
    }

    return -1;
}

int main( )
{
    int array[10] = { 1, 8, 13, 14, 15, 30, 44, 50 , 52 , 100};
    int size = sizeof(array)/sizeof(array[0]);
    int index = binary_search(array , 15 , size );
    cout << "Found the number : " << array[index] << " at index : " << index;
    return 0;
}