/*
You are given an array of n integers. Your task is to calculate the median of each window of k elements, from left to right.
The median is the middle element when the elements are sorted. If the number of elements is even, there are two possible medians and we assume that the median is the smaller of them.

Input
The first input line contains two integers n and k : the number of elements and the size of the window.
Then there are n integers x1,x2,…,xn the contents of the array.

Output
Print n−k+1 values: the medians.

Constraints
1 ≤ k ≤ n≤ 2⋅105
1 ≤ xi ≤ 109

Example
Input:
8 3
2 4 3 5 8 1 2 1

Output:
3 4 5 5 2 1
*/

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define int long long
#define deq vector<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),b)
const ll M = 1000000007;
using namespace std;
 
pii aage(map<int,set<int>>& store, set<int>& uniq, int& x, int& y){
    auto itr = store[x].upper_bound(y);
    if(itr!=store[x].end()){
        return make_pair(x,*itr);
    }
    itr = uniq.upper_bound(x);
    int z = *itr;
    return make_pair(z,*(store[z].begin()));
}
pii peeche(map<int,set<int>>& store, set<int>& uniq, int& x, int& y){
    auto itr = store[x].upper_bound(-y);
    if(itr!=store[x].end()){
        return make_pair(x,-(*itr));
    }
    itr = uniq.upper_bound((-x));
    int z = -(*itr);
    return make_pair(z,-(*(store[z].begin())));
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);
 
    int n,k;
    cin >> n >> k;
 
    int arr[n];
    rp(i,0,n)cin >> arr[i];
 
    if(k==1){
        rp(i,0,n)cout << arr[i] << " ";
        return 0;
    }
 
    if(k==2){
        rp(i,0,n-1)cout << min(arr[i],arr[i+1]) << " ";
        return 0;
    }
 
    vector<pii> num;
    map<int,set<int>> store[2];
    set<int> uniq1,uniq2;
 
    rp(i,0,k){
        num.pb({arr[i],i});
        store[0][arr[i]].insert(i);
        store[1][arr[i]].insert(-i);
        uniq1.insert(arr[i]);
        uniq2.insert(-arr[i]);
    }
 
    sort(all(num));
    int x = (k&1) ? k/2 : (k/2-1);
    auto ans = num[x];
    cout << ans.f << " ";
 
    rp(i,k,n){
        int z1 = arr[i], z2 = arr[i-k];
        store[0][z1].insert(i);
        store[1][z1].insert(-i);
        store[0][z2].erase(i-k);
        store[1][z2].erase(-(i-k));
        if(sz(store[0][z2])==0){
            uniq1.erase(z2);
            uniq2.erase(-z2);
        }
        if(sz(store[0][z1])==1){
            uniq1.insert(z1);
            uniq2.insert(-z1);
        }
        if(z2==ans.f){
            if(z1>=ans.f){
                ans = aage(store[0],uniq1,ans.f,ans.s);
            }
            else if((z1<ans.f && ans.s==(i-k))){
                ans = peeche(store[1],uniq2,ans.f,ans.s);
            }
        }
        else if(z1>=ans.f && z2<ans.f){
            ans = aage(store[0],uniq1,ans.f,ans.s);
        }
        else if(z1<ans.f && z2>ans.f){
            ans = peeche(store[1],uniq2,ans.f,ans.s);
        }
        cout << ans.f << " ";
    }
    
    return 0;}