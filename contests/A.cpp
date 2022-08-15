#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n,H,M;
        cin >> n >> H >>M;
        deque<pii> diff;
        int arr[n][2];
        for(int i=0;i<n;i++){
            cin >> arr[i][0] >> arr[i][1];
            if(arr[i][1]>=M && arr[i][0]>=H){
                diff.push_back({arr[i][0]-H,arr[i][1]-M});}
            
            else if(arr[i][1]<M && arr[i][0]>H){
                diff.push_back({arr[i][0]-H-1,arr[i][1]-M+60});}
            else if(arr[i][1]<M && arr[i][0]==H){
                diff.push_back({arr[i][0]-H-1 + 24,arr[i][1]-M+60});}
            
            else if(arr[i][1]>=M && arr[i][0]<H){
                diff.push_back({arr[i][0]-H+24,arr[i][1]-M});}
            
            else if(arr[i][1]<M && arr[i][0]<H){
                diff.push_back({arr[i][0]-H-1+24,arr[i][1]-M+60});}
            }
            sort(diff.begin(),diff.end());
            cout<<diff[0].first<<" "<<diff[0].second <<"\n";
            
        }
    

    return 0;}