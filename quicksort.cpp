#include<iostream>
using namespace std;

void swap(int &a,int &b)
 {
    int temp=a;
    a=b;
    b=temp;
 }

int Partition(int arr[], int l, int h)
{   
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}

void quicksort(int arr[],int l,int h)
{
    if(l<h)
    {
        int p=Partition(arr,l,h);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,h);
    }
}
 
int main() 
{
	int arr[]={5,9,7,6,3,8,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	quicksort(arr,0,n-1);
	
	for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}