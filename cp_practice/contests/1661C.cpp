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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int arr[n];

        int maxi[2],z=-1;

        maxi[0] = LLONG_MIN;

        int ans[2] = {0,1};

        rp(i,0,n){
            cin >> arr[i];
            if(maxi[0]<arr[i]){
                z = i;
                maxi[0] = arr[i];
            }
        } 

        maxi[1] = maxi[0] + 1;

        rp(j,0,2){
            deq remain;
            int sum = 0,two = 0;
            rp(i,0,n){
                int x = maxi[j] - arr[i];
                if(x>0){
                    remain.pb(x);
                    two+=(x/2);
                    sum+=x;
                }
            }
            int y = min(sum/3,two);
            two-=y;
            ans[j]+=2*y;
            int left = sum - (3*y);
            if(left==1){
                if(j==0){ans[j]++;}
                else{
                    if(two>0){
                        ans[j]++;
                    }
                    else ans[j]+=2;
                }
            }
            else if(left==2){
                if(two>0){
                    if(j==0)ans[j]+=2;
                    else ans[j]+=1;
                }
                else{
                    if(j==0)ans[j]+=3;
                    else ans[j]+=4;
                }
            }
            else if(left>=3){
                if(j==0)ans[j]+=(2*left-1);
                else ans[j]+=(2*left);
            }
            arr[z]++;
        }

        cout << min(ans[0],ans[1]) <<"\n";

    }

    return 0;}