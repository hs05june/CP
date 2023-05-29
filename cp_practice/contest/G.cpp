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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int peeche[n] = {0}, aage[n] = {0};

        int arr[n];
        rp(i,0,n)cin >> arr[i];
        int total = 0;

        rp(i,0,n){
            rp(j,i+1,n){
                if(arr[j]<arr[i]){
                    total++;
                    peeche[j]++;
                    aage[i]++;
                }
            }
        }

        rp(i,0,n){
            int x = total - peeche[i] - aage[i] + i;
            int y = total - peeche[i] - aage[i] + n - i - 1;
            cout << max(x,y) << " ";
        }
        cout << "\n";


    }

    return 0;}