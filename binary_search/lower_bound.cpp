#include<bits/stdc++.h>
#define ll long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

int lower_bound(deq d, int ele){
    int low = 0, high = d.size()-1;
    int x = 0;
    while(low<high){
        int mid = (low + high)/2;
        if(ele>d[mid])low=mid+1;
        else high = mid;
    }

    if(d[low]>=ele) return low;
    if(d[high]>=ele) return high;
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    deq d(n);

    for(int i=0; i<n; i++){
        cin>>d[i];
    }

    int ele;
    cin>>ele;

    sort(d.begin(),d.end());

    int index = lower_bound(d,ele);

    cout<<index<<"\n";

    return 0;}