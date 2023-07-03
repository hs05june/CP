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

        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int cnt[2] = {0,0};
        string str;
        cin >> str;

        int n = sz(str);

        for(auto i : str){
            cnt[(int)(i-'A')]++;
        }
        if(cnt[0]!=(a+d+c) || cnt[1]!=(b+c+d)){
            cout << "NO\n";
            continue;
        }

        deq change[2];

        rp(i,0,n){
            int start = i;
            while(i+1<n && str[i+1]!=str[i]){
                ++i;
            }
            if(i==start)continue;
            if(str[start]=='A'){change[0].pb((i-start+1)/2);change[1].pb((i-start)/2);}
            else if(str[start]=='B'){change[1].pb((i-start+1)/2);change[0].pb((i-start)/2);}
        }
        
        set<pii> ab,ba,equals;

        rp(i,0,sz(change[0])){
            if(change[0][i]==change[1][i]){
                equals.insert({change[0][i],i});
            }
            else if(change[0][i] != change[1][i]){
                if(change[0][i]>change[1][i])ab.insert({change[0][i],i});
                else ba.insert({change[1][i],i});
            }
        }

        for(auto i : ab){
            if(i.f<=c)c-=i.f;
            else{
                i.f -= min(i.f,c);
                c = 0;
                if(i.f-1>0)equals.insert({i.f-1,i.s});
            }
        }

        for(auto i : ba){
            if(i.f<=d)d-=i.f;
            else{
                i.f -= min(i.f,d);
                d = 0;
                if(i.f-1>0)equals.insert({i.f-1,i.s});
            }
        }

        for(auto i : equals){
            if(c > 0){
                int x = min(i.f,c);
                i.f-=x;
                c-=x;
            }
            if(d > 0){
                int x = min(i.f,d);
                i.f-=x;
                d-=x;
            }
        }
        c<=0 && d<=0 ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;}