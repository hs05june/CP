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

int n;
int arr[107];
deq fibo;

int dp[60][107];

int solve(int ind, int k){
    if(ind >= sz(fibo))return 1;
    if(dp[ind][k]!=-1)return dp[ind][k];
    int ans = 0;
    rp(i,1,n+1){
        if(k==i)continue;
        if(arr[i]>=fibo[ind]){
            arr[i]-=fibo[ind];
            ans |= solve(ind+1,i);
            arr[i]+=fibo[ind];
        }
    }
    return dp[ind][k] = ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        cin >> n;
        fibo.clear();
        int sum = 0;
        rp(i,0,60){
            rp(j,0,n+1)dp[i][j] = -1;
        }
        set<pii> as;
        rp(i,1,n+1){
            cin >> arr[i];
            sum += arr[i];
            as.insert({-arr[i],i});
        }

        int newsum = 0;
        if(sum == 1){
            cout << "YES\n";
            continue;
        }
        if(sum == 2){
            if(n==2)cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        fibo.pb(1);fibo.pb(1);
        newsum = 2;
        while(newsum < sum){
            fibo.pb(fibo.back()+fibo[sz(fibo)-2]);
            newsum += fibo.back();
        }
        if(newsum != sum){
            cout << "NO\n";
            continue;
        }
        // for(auto i : fibo)cout << i << " ";
        // cout << "\n";
        int x = 0;
        bool ans = true;
        rep(i, sz(fibo)-1, 0){
            auto itr = (as.begin());
            int y = -(*itr).f, z = (*itr).s;
            // cout << fibo[i] << " " << y << " " << x << ' ' << z << "\n";
            if(y < fibo[i]){
                ans = false;
                break;
            }
            if(z==x){
                ++itr;
                // cout << -(*itr).f << " " << (*itr).s << "\n";
                if(itr == as.end() || -(*itr).f < fibo[i]){
                    ans = false;
                    break;
                }
                as.erase(itr);
                as.insert({-(-(*itr).f - fibo[i]),(*itr).s});
                x = (*itr).s;
                continue;
            }
            as.erase(as.begin());
            x = z;
            as.insert({-(y-fibo[i]),z});
        }
        ans ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;}