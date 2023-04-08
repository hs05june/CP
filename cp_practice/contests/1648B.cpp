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

int cnt[1000007],preffix[1000007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n,c;
        cin >> n >> c;
        deq arr;

        rp(i,0,c+1){
            cnt[i] = 0;
            preffix[i] = 0;
        }

        set<int> uniq;

        rp(i,0,n){
            int x;
            cin >> x;
            cnt[x]++;
            uniq.insert(x);
            // arr[i] = x;
        }

        // sort(arr,arr+n);
        for(auto i : uniq){
            arr.pb(i);
        }
        n = sz(arr);
        rp(i,1,c+1){
            preffix[i] = preffix[i-1] + cnt[i];
        }

        bool check = true;
        for(int i = 1; i <=c; i++){
            if(!check)break;
            if(cnt[i]==0){
                rp(j,0,n){
                    if(arr[j]*i>c)break;
                    int maxi = min(c,(i+1)*arr[j]-1);
                    int mini = i*arr[j];
                    if((preffix[maxi]-preffix[mini-1])!=0){
                        check = false;
                        // cout << i << " " << j << "\n";
                        break;
                    }
                }
            }
        }

        check ? cout << "YES\n": cout << "NO\n";

    }

    return 0;}