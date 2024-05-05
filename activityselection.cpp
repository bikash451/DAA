#include<iostream>
using namespace std;
struct Activity{
    int start;
    int finish;

};
bool compare(Activity a,Activity b)
{
    return a.finish<b.finish;
}

void sort(Activity arr[], int n)
{
    for (int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            if(compare(arr[j],arr[i]))
            {
                int tempStart = arr[i].start;
                int tempFinish = arr[i].finish;
                arr[i].start = arr[j].start;
                arr[i].finish = arr[j].finish;
                arr[j].start = tempStart;
                arr[j].finish = tempFinish;
            }
        }
    }
}

void printMaxactivities(Activity arr[], int n)
{
    int i,j;
    i=0;
    cout<<"("<<arr[i].start<<","<<arr[i].finish<<")";
    int count=1;
    for(j=1;j<n;j++)
    {
        if(arr[j].start>=arr[i].finish)
        {
            cout<<"("<<arr[j].start<<","<<arr[j].finish<<")";;
            i=j; //points to newly last selected activity
            count++;
        }
    }
    cout<<"\n"<<count<<" is the max amount of activities";
}
int  main()
{
    Activity arr[]={{12, 25}, {10, 20}, {20, 30}};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,n);
    printMaxactivities(arr,n);
    return 0;

     
}