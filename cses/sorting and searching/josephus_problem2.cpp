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
int fenwick[200007];

void update(int x){
    for(int i = x; i <= n; i += (i&(-i))){
        fenwick[i]++;
    }
}

int sum(int x){
    int ans = 0;
    for(int i = x; i > 0; i -= (i&(-i))){
        ans+=fenwick[i];
    }
    return ans;
}

int find_index(int x){
    int in = x;
    int z = sum(x+1);
    while(z!=0){
        in+=z;
        z = sum(in+1) - sum(x+1);
        x = in;
    }
    return in;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int k;
    cin >> n >> k;

    int x = -1;

    deq num;
    rp(i,1,n+1){num.pb(i);}

    if(k==0){
        for(auto i : num)cout << i << " ";
        return 0;
    }

    deq ans;
    int Size = n;
    while(sz(ans)<n){
        x-=sum(x+1);
        x = (x+1+k)%Size;
        int in = find_index(x);
        x = in;
        ans.pb(num[in]);
        Size--;
        update(in+1);
    }

    for(auto i : ans)cout << i << " ";
    cout << "\n";

    return 0;}