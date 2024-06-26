#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int h)
{
    
    int n1=m-l+1,n2=h-m;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++)
        left[i]=arr[i+l];
    for(int j=0;j<n2;j++)
        right[j]=arr[m+1+j];

    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
    while(i<n1)
        arr[k++]=left[i++];
    while(j<n2)
        arr[k++]=right[j++];    
}

void mergesort(int arr[],int l,int r)
{
    if(r>l)
    {
        int m=l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main() 
{
	
    int a[]={10,50,30,15,70};
	int l=0,r=4;
	mergesort(a,l,r);
	for(int i=0;i<=r;i++)
	    cout<<a[i]<<" ";
}