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

int squares[1000007];
int upar[10000007][2];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;
    squares[0] = 0;

    upar[1][0] = upar[1][1] = 0;

    rp(i,2,10000){
        int x = 1 + (i*(i-1))/2,  y = (i*(i+1))/2;
        upar[y][0] = upar[y][1] = y - i;
        upar[x][0] = upar[x][1] = x - (i-1);
        if(x>1000000)break;
        rp(j,x+1,y){
            upar[j][0] = j - i;
            upar[j][1] = j - (i - 1);
        }
    }


    rp(i,1,1000005){
        squares[i] = i*i + squares[i-1];
    }

    while(t--){

        int n;
        cin >> n;

        int x = n, y = n, sum = 0;
        while(x!=0 || y!=0){
            sum += (squares[y] - squares[x-1]);
            x = upar[x][0];
            y = upar[y][1];
        }

        cout << sum << "\n";

    }

    return 0;}