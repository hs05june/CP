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

        int n;
        cin >> n;

        deq contest;
        rp(i,1,((1<<n)+1)){
            contest.pb(i);
        }

        while(sz(contest)>1){
            deq test;
            if(sz(contest)==2){
                int h = contest[0], k = contest[1];
                int x;
                cout << "? " << h << " " << k << endl;
                contest.clear();
                cin >> x;
                if(x==1){
                    contest.pb(h);
                }
                else{
                    contest.pb(k);
                }
                break;
            }

            else if(sz(contest)>=4){
                for(int i = 0; i < sz(contest); i+=4){
                    int x,h,k;
                    
                    int a[4];
                    rp(j,0,4){
                        a[j] = contest[i+j];
                    }
                    
                    h = a[0]; k = a[2];

                    cout << "? " << h << " " << k << endl;
                    cin >> x;
                    if(x==1){
                        h = a[0];
                        k = a[3];
                    }
                    else if(x==2){
                        h = a[1];
                        k = a[2];
                    }
                    else if(x==0){
                        h = a[1];
                        k = a[3];
                    }

                    cout << "? " << h << " " << k << endl;
                    cin >> x;
                    if(x==1){
                        test.pb(h);
                    }
                    else if(x==2){
                        test.pb(k);
                    }
                }
            }
            contest.clear();
            for(auto j : test){
                contest.pb(j);
            }
            test.clear();
        }

        cout << "! " << contest[0] << endl;
        contest.clear();
    }

    return 0;}