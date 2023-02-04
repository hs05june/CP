#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int arr[n];

        bool ans = true;
        int cnt = 0,one = -1;

        rp(i,0,n){
            cin >> arr[i];
            if(arr[i]==1){cnt++;one = i;}
        }

        if(cnt!=1){
            cout << "NO\n";
            continue;
        }

        int h = (one+1)%n;
        int increase = 0;

        while(arr[h]!=1){
            int x = (h-1+n)%n;
            if((arr[h]-arr[x])>1){
                ans = false;
                break;
            }
            ++h;h%=n;
        }

        if(!ans){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

    }

    return 0;}  