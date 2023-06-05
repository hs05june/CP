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

int arr[][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int diff(vector<string>& a, vector<string>& b,int n, int m){
    int ans = 0;
    rp(i,0,n){
        rp(j,0,m){
            if(a[i][j]!=b[i][j]){
                rp(k,0,4){
                    if(a[i+arr[k][0]][j+arr[k][1]] != b[i+arr[k][0]][j+arr[k][1]] || b[i][j]!=a[i+arr[k][0]][j+arr[k][1]])return LLONG_MAX;
                }
                ans++;
            }
        }
    }
    return ans;
}

void print_ans(vector<string>& a, vector<string>& b,int n, int m){
    rp(i,0,n){
        rp(j,0,m){
            if(a[i][j]!=b[i][j]){
                cout << 1 << " " << i+1 << " " << j+1 << "\n";
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

        int n,m,k;
        cin >> n >> m >> k;
        set<vector<string>> uniq;
        map<vector<string>,deq> cnt;

        rp(i,0,k+1){
            vector<string> a;
            rp(j,0,n){
                string str;
                cin >> str;
                a.pb(str);
            }
            cnt[a].pb(i+1);
            uniq.insert(a);
        }

    vector<vector<string>> str;
    for(auto i : uniq){
        str.pb(i);
    }
    int agla[sz(str)], pichhla[sz(str)];
    rp(i,0,sz(str))pichhla[i] = agla[i] = -1;
    rp(i,0,sz(str)){
        int maxi = LLONG_MAX, in = -1;
        rp(j,0,sz(str)){
            if(i==j)continue;
            int x = diff(str[i],str[j],n,m);
            if(x < maxi){
                maxi = x; in = j;
            }
        }
        agla[i] = in;
        maxi = LLONG_MAX; in = -1;
        rp(j,0,sz(str)){
            if(i==j)continue;
            int x = diff(str[j],str[i],n,m);
            if(x < maxi){
                maxi = x; in = j;
            }
        }
        pichhla[i] = in;
    }

    int start = -1;
    rp(i,0,sz(str))if(pichhla[i]==-1)start = i;
    cout << cnt[str[start]].back() << "\n";
    cnt[str[start]].pop_back();
    int ans = 0;
    int start1 = start;

    while(start1!=-1){
        if(agla[start1]!=-1)ans += diff(str[start1],str[agla[start1]],n,m);
        start1 = agla[start1];
    }
    cout << ans+k << "\n";

    while(start!=-1){
        while(sz(cnt[str[start]])!=0){cout << 2 << " " << cnt[str[start]].back() << "\n"; cnt[str[start]].pop_back();}
        if(agla[start]!=-1)print_ans(str[start],str[agla[start]],n,m);
        start = agla[start];
    }

    return 0;}