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

pii points[3];

pair<int,vector<pair<pii,pii>>> solve(int x, int y){
    int ans = abs(points[x].f - points[y].f) + abs(points[x].s - points[y].s);
    vector<pair<pii,pii>> ans1;
    ans1.pb({{points[x].f,points[x].s},{points[y].f,points[x].s}}); 
    ans1.pb({{points[y].f,points[x].s},{points[y].f,points[y].s}});
    return make_pair(ans,ans1); 
}

int arr[][3] = {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    // cin >> t;

    while(t--){

        rp(i,0,3){
            cin >> points[i].f >> points[i].s;
        }
        // int ans = LLONG_MAX;
        // int index = -1;
        // rp(i,0,6){
        //     int ans1 = 0;
        //     auto itr1 = solve(arr[i][0],arr[i][1]);
        //     auto itr2 = solve(arr[i][1],arr[i][2]);
        //     ans1 = itr1.f + itr2.f;
        //     if(ans>ans1){
        //         ans = ans1;
        //         index = i;
        //     }
        // }

        // cout << 4 << "\n";
        
        // auto itr1 = solve(arr[index][0],arr[index][1]);
        // auto itr2 = solve(arr[index][1],arr[index][2]);
        
        // for(auto i : itr1.s){
        //     cout << i.f.f << " " << i.f.s << " " << i.s.f << " " << i.s.s << "\n";
        // }
        // for(auto i : itr2.s){
        //     cout << i.f.f << " " << i.f.s << " " << i.s.f << " " << i.s.s << "\n";
        // }

        sort(points,points+3);
        vector<pair<pii,pii>> ans;
        if(points[0].s<=points[1].s && points[1].s<=points[2].s){
            ans.pb({{points[0].f,points[0].s},{points[0].f,points[1].s}});
            ans.pb({{points[0].f,points[1].s},{points[2].f,points[1].s}});
            // ans.pb({{points[1].f,points[1].s},{points[1].f,points[2].s}});
            ans.pb({{points[2].f,points[1].s},{points[2].f,points[2].s}});
        }
        else if(points[0].s<=points[2].s && points[2].s<=points[1].s){
            ans.pb({{points[0].f,points[0].s},{points[0].f,points[2].s}});
            ans.pb({{points[0].f,points[2].s},{points[2].f,points[2].s}});
            ans.pb({{points[1].f,points[1].s},{points[1].f,points[2].s}});
        }
        else if(points[1].s<=points[0].s && points[0].s<=points[2].s){
            ans.pb({{points[0].f,points[0].s},{points[2].f,points[0].s}});
            ans.pb({{points[2].f,points[0].s},{points[2].f,points[2].s}});
            ans.pb({{points[1].f,points[1].s},{points[1].f,points[0].s}});
    }
        else if(points[1].s<=points[2].s && points[2].s<=points[0].s){
            ans.pb({{points[0].f,points[0].s},{points[0].f,points[2].s}});
            ans.pb({{points[0].f,points[2].s},{points[2].f,points[2].s}});
            ans.pb({{points[1].f,points[1].s},{points[1].f,points[2].s}});
    }
        else if(points[2].s<=points[1].s && points[1].s<=points[0].s){
            ans.pb({{points[0].f,points[0].s},{points[0].f,points[1].s}});
            ans.pb({{points[0].f,points[1].s},{points[2].f,points[1].s}});
            ans.pb({{points[2].f,points[1].s},{points[2].f,points[2].s}});
    }
        else if(points[2].s<=points[0].s && points[0].s<=points[1].s){
            ans.pb({{points[0].f,points[0].s},{points[2].f,points[0].s}});
            ans.pb({{points[2].f,points[0].s},{points[2].f,points[2].s}});
            ans.pb({{points[1].f,points[1].s},{points[1].f,points[0].s}});
    }
    cout << sz(ans) << "\n";
    for(auto i : ans){
        cout << i.f.f << " " << i.f.s << " " << i.s.f << " " << i.s.s << "\n";
    }
    }
    return 0;}