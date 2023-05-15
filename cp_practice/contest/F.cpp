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
        
        // int total = 0;
        sort(array,array+n);

        int calc[n];
        int mini[n];
        // int total[n];
        // total[0] = 0;
        rp(i,0,n){
            calc[i] = (array[i] - array[0] - i);
        }

        mini[0] = calc[0];

        rp(i,1,n){
            mini[i] = min(mini[i-1],calc[i]);
        }

        int total = 0;

        rp(i,0,n){
            total+=2*abs(calc[i]-mini[n-1]);
        }

        // rp(i,0,n){
        //     cout << calc[i] << " " << mini[i] << "\n"; 
        // }

        while(query--){
            int k;
            cin >> k;
            int answer = LLONG_MAX;
            if(k<=n){
                answer = (array[0] + k + mini[k-1]);
                if(k!=n)answer = min(answer,array[k]);
            }
            else{
                int left = k - n;
                int z = n-1;
                if(left%2==0){
                    z=n-1;
                }
                else{
                    z = n-2;
                    left++;}
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