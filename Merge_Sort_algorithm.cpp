#include<iostream>
using namespace std;
void merge(int x[],int low,int mid,int high){
    int b[100001];
    int i=low;
    int j=mid + 1;
    int k=0;
    if(i<j){
        while(i<=mid && j<=high){
            if(x[i] < x[j]){
            b[k++]=x[i++];
            }
            else {
                b[k++]=x[j++];
            }
        }
    }
    if(i > mid) {
        while(j <= high){
            b[k++]=x[j++];
        }
    }
    else {
        while(i <= mid){
            b[k++]=x[i++];
        }
    }
    for(k=low;k<=high;k++){
        x[k]=b[k-low];
    }
}
void mergesort(int x[],int low,int high) {
    if(low >= high) return;
    int mid=(low+high)/2;
    mergesort(x,low,mid);
    mergesort(x,mid + 1,high);
    merge(x,low,mid,high);
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int x[n];
    for(i=0;i<n;i++)
    scanf("%d",&x[i]);
    mergesort(x,0,n-1);
    for(i=0;i<n;i++)
    printf("%d ",x[i]);
}
