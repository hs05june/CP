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

int can(char x){
    return (x == '0') ? 2 : 1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string a;
        cin >> a;

        int visited[n] = {0};
        rp(i,0,n)visited[i] = 0;

        set<pii> ans;

        int cnt = 0;
        rp(i,0,n){
            cnt += can(a[i]);
        }

        if((cnt & 1) || ((cnt/2) >= n)){
            cout <<  "NO\n";
            continue;
        }

        multiset<int> left;

        rp(i,0,n){
            if(a[i]=='0'){
                int start = i;
                while((i+1) < n && a[i+1]=='0'){
                    ans.insert({i+1,i+2});
                    ++i;
                }
                left.insert(start+1);
                if(i+1<n){
                    ans.insert({i+1,i+2});
                    ++i;
                }
            }
            else left.insert(i+1);
        }

        if(a[n-1] == '0'){
            left.erase(left.find(1));
            ans.insert({1,n});
        }

        int ind = *(left.begin());
        for(auto i : left){
            if(ind!=i){
                ans.insert({ind,i});
            }
        }
        cout << "YES\n";
        for(auto i : ans){
            cout << i.f << " " << i.s << "\n";
        }

    }

    return 0;}