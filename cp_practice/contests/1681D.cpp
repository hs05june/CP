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

int num_of_digits(int n){
    int ans = 0;
    if(n==0)return 1;
    while(n>0){
        ans++;
        n/=10;
    }
    return ans;
}

int largest_digit(int n){
    if(n==0)return 0;
    int ans = 0;

    while(n>0){
        ans = max(ans,n%10);
        n/=10;
    }

    return ans;
}

int solve(int n, int x){
    int num = num_of_digits(x);
    // cout << x << "\n";
    if(num>=n)return 0;
    
    bool done[10];
    
    rp(i,0,10)done[i] = false;
    done[0] = true;
    done[1] = true;

    int z = x;
    int ans = INT_MAX;
    while(z>0){
        int large = z%10;
        // x*=large;
        if(done[large]==false && large!=0 && large!=1){
            ans = min(ans,1+solve(n,x*large));
            done[large] = true;
        }
        z/=10;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    // cin >> t;

    while(t--){

        int n,x;
        cin >> n >> x;

        int num = num_of_digits(x);

        if(n==num){
            cout << "0\n";
            continue;
        }

        int digit = largest_digit(x);

        if(n<num || digit==0 || digit==1){
            cout << "-1\n";
            continue;
        }

        // cout << solve(n,x) << "\n";

        mii dp;
        queue<int> bfs;
        bfs.push(x);
        dp[x] = 0;

        while (!bfs.empty())
        {
            int y = bfs.front();

            if(num_of_digits(y)==n){
                cout << dp[y] << "\n";
                return 0;
            }

            int z = y;

            while(z>0){
                int dig = z%10;
                if(!dp.count(dig*y)){
                    dp[dig*y] = 1 + dp[y];
                    if(num_of_digits(dig*y)==n){
                        cout << dp[dig*y] << "\n";
                        return 0;
                    }
                    bfs.push(dig*y);
                }
                z/=10;
            }
            
            bfs.pop();
        }
        
    }

    return 0;}