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

int arr[600050], operations[600057];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,k;
    cin >> n >> k;

    int brr[n+2];
    rp(i,0,n+2)brr[i] = 0;
    rp(i,1,n+1){cin >> arr[i];}

    int ans = 0, opr = 0, added = 0;
    for(int i = n; i >= k; i--){
        brr[i] = brr[i+1] - opr;
        opr -= operations[i+k];
        if(brr[i] >= arr[i]){
            operations[i] = 0;
        }
        else{
            int news = ceil((long double)(arr[i] - brr[i])/(long double)k);
            opr+=news;
            operations[i] = news;
            brr[i] += k*news;
            ans+=news;
        }
    }

    for(int i = k-1; i>=1; i--){
        brr[i] = brr[i+1] - opr;
        opr -= operations[i+k];
    }

    int maxi = 0;
    rp(i,1,k){
        if(brr[i]>=arr[i])continue;
        int diff = arr[i] - brr[i];
        int news = ceil((long double)diff / (long double)i);
        maxi = max(maxi,news);
    }

    cout << ans + maxi << "\n";

    return 0;}