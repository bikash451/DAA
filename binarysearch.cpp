#include<iostream>
using namespace std;

int binarysearch(int arr[],int size,int target) {
    int start=0;
    int end=size-1;

    while(start<=end){
        int mid=start+(end-start)/2;

        if(arr[mid]==target)
        {
            return mid; 
        }else if(arr[mid]<target)
        {
            start=mid+1;
        } else
        {
            end=mid-1; 
        }
    }

    return -1;
}

int main() {
    int arr[]={1,3,5,7,9,11};
    int size=sizeof(arr);
    int target=11;
    int result=binarysearch(arr,size,target);

    if (result!=-1) {
        cout<<"Element"<<target<<"found at index"<<result<<endl;
    } else{
        cout<<"Element"<<target<<"not found in the array"<<endl;
    }

    return 0;
}
