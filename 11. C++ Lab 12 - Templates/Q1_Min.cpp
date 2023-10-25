#include<iostream>
using namespace std;

template<class T>

T minimum(T arr[5], int n)
{
    int i, j;
    T min = arr[0];
 
    for(i=0;i<n;i++)
    {
        if(min>arr[i])
        {
            min = arr[i];
        }
    }
    
    return min;
}
 
int main()
{
    int a[5] = {3,2,4,1,5};
    float b[5] = {1.2,1.9,2.3,1.4,1.5};
    
    cout<<"\nSmallest integer: "<<minimum(a,5);
    cout<<"\nSmallest float no.: "<<minimum(b,5);
    
}