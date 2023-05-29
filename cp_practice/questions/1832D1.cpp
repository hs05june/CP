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

        int n,query;
        cin >> n >> query;

        int array[n];

        rp(i,0,n)cin >> array[i];
        
        int total = 0;
        sort(array,array+n);

        while(query--){
            int k;
            cin >> k;
            int final[n];
            int answer = LLONG_MAX;
            rp(i,0,n)final[i] = array[i];
            if(k<=n){
                int x = k;
                rp(i,0,n){
                    answer = min(answer,final[i]+max(x,0LL));
                    --x;
                }
            }
            else{
                int left = k - n;
                if(left%2==0){
                    int x = k;
                    rp(i,0,n){
                        final[i]+=x;
                        x--;
                    }
                }
                else{
                    int x = k;
                    rp(i,0,n-1){
                        final[i]+=x;
                        --x;
                    }
                    left++;}
                    sort(final,final+n);
                    int total = 0;
                    rp(i,0,n)total+=(2*abs(final[i]-final[0]));
                    if(left<=total){
                        answer = final[0];
                    }
                    else{
                        left-=total;
                        left/=2;
                        int y = ceil(((long double)left)/n);
                        answer = final[0]-y;
                    }
                
            }
            cout << answer << " ";
            
        }

        cout << "\n";

    

    return 0;}