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

int negative[200007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        rp(i,0,n+2){
            negative[i] = 0;
        }

        int arr[n];
        deq zeroes;

        zeroes.pb(0);

        rp(i,0,n){
            cin >> arr[i];
            if(arr[i]==0){
                zeroes.pb(i+1);
            }
            negative[i+1] = negative[i] + (arr[i] < 0);
        }
        negative[n+1] = negative[n];
        zeroes.pb(n+1);

        int left = 0,right = 1,maxi = 0;

        for(int i = 1; i<zeroes.size(); i++){
            if((negative[zeroes[i]]-negative[zeroes[i-1]])%2==0){
                int two = 0;
                for(int j = zeroes[i-1]+1; j<=zeroes[i]-1;j++){
                    two+=(abs(arr[j-1])==2);
                }
                if(two>maxi){
                    left = zeroes[i-1];
                    right = zeroes[i];
                    maxi = two;
                }
            }
            else{
                int l,r;
                rp(j,zeroes[i-1]+1,zeroes[i]){
                    if(arr[j-1]<0){
                        l = j;break;
                    }
                }
                for(int j = zeroes[i]-1; j>=zeroes[i-1]+1;j--){
                    if(arr[j-1]<0){
                        r = j; break;16
                    }
                }
                int x = 0;
                rp(j,l+1,zeroes[i]){
                    x += (abs(arr[j-1])==2);
                }
                if(x>maxi){
                    maxi = x;
                    left = l;
                    right = zeroes[i];
                }
                x = 0;
                rp(j,zeroes[i-1]+1,r){
                    x += (abs(arr[j-1])==2);
                }
                if(x>maxi){
                    maxi = x;
                    left = zeroes[i-1];
                    right = r;
                }
            }
        }
        cout << left << " " << n-right+1 << "\n";
    }

    return 0;}