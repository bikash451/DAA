#include<iostream>
using namespace std;
 int maxsum(int arr[],int n)
 {
    int sum=0,max=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum=sum+arr[i];
        if(sum>max)
        {
            max=sum;
        }
        if (sum<0)
        {
            sum=0;
        }
    }
    return max;
    
 }
 int main()
 {
    int arr[]={-2,-3,4,-1,-2,1,5,-3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max_sum =maxsum(arr,n); 
    cout <<"Maximum sum is " << max_sum; 
    return 0;
 }