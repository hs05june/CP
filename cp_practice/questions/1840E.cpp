#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define ld long double
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

    int test = 1;
    cin >> test;

    while(test--){

        string a[2];
        cin >> a[0] >> a[1];

        int n = a[0].size();

        int t,q;
        cin >> t >> q;

        int change[q];
        rp(i,0,q)change[i] = -1;

        set<int> diff;
        int m = 0;
        rp(i,0,n){
            if(a[0][i] != a[1][i]){diff.insert(i+1);}
        }

        rp(i,0,q){
            int x;
            cin >> x;

            if(change[i] != -1)m--;

            if(x==3){
                sz(diff) == m ? cout << "YES\n" : cout << "NO\n";
            }
            else if(x==1){
                int y;
                cin >> y;
                if(diff.count(y)){
                    m++;
                    if((i+t) < q)change[i+t] = y;
                }
            }
            else if(x==2){
                int y1, y2, z1, z2;
                cin >> y1 >> y2 >> z1 >> z2;
                y1--; z1--;
                swap(a[y1][y2-1],a[z1][z2-1]);
                if(a[0][y2-1] == a[1][y2-1])diff.erase(y2);
                if(a[0][z2-1] == a[1][z2-1])diff.erase(z2);
                if(a[0][y2-1] != a[1][y2-1])diff.insert(y2);
                if(a[0][z2-1] != a[1][z2-1])diff.insert(z2);
            }
        }

    }

    return 0;}