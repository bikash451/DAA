#include<iostream>
#include<algorithm>
using namespace std;
struct items{
    int profit;
    int weight;
    double ratio;
};
bool comp(items a,items b){
    return a.ratio>b.ratio;
    
}
int knapsack(items item[],int n,int w){
    sort(item,item+n,comp);
    int result=0;
    int currw=0;
    for(int i=0;i<n;i++){
        if(item[i].weight<=w){
            result=result+item[i].profit;
            w=w-item[i].weight;
        }
        else{
            
           result = result + item[i].profit * (static_cast<double>(w) / item[i].weight); 
            break;
            
        }
        
    }
    return result;
}
int main(){
     items item[3] = {{60,10,0},{100,20,0},{120,30,0}};
    for(int i=0;i<3;i++){
    item[i].ratio =(item[i].profit) / item[i].weight; 
    }
    int w=50;
    cout<<knapsack(item,3,w);
}