#include<bits/stdc++.h>
using namespace std;
long long n,f,p,arr[5000000],j;

bool cmp(long long i,long long j){
    return j < i;
}

int main(){
    cin>>n>>f>>p;
    
    if(n==0){
        cout<<1;
        return 0;
    }
    
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n, cmp);
    
    for(int i=0;i<p;i++){
        if(arr[i]<=f){
            while(1){
                j=i;
                if(j>=p-1){
                    cout<<"-1";
                    return 0;
                }
                if(arr[j]!=arr[f]) break;
                if(j>500) return 0;
                j++;
            }
            j=0;
            cout<<i+1;
            return 0;
        }
    }
    cout<<"-1";
}