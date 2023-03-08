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

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL * a%mod) % mod;
        b >>= 1;}
    return ans%mod;}

ll modInverse(ll n,ll mod){
    return power(n,mod-2,mod)%mod;}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n,p;
        cin >> n >> p;

        set<int> present;
        int arr[n];

        rp(i,0,n){
            cin >> arr[i];
            present.insert(arr[i]);
        }

        // if(t==2000-64){
        //     cout << n << "k" << p << "m";
        //     rp(i,0,n){
        //         cout << arr[i] << "k";
        //     }
        // }

        int largest = *(--present.end());
        int neeche = arr[n-1];
        int uppar;
        while(neeche>=0){
            if(present.count(neeche))neeche--;
            else break;
        }

        if(largest < (p-1)){
            uppar = p-1;
        }
        else{
            while (largest > arr[n-1])
            {
                // cout << largest << "\n";
                if(present.count(largest))largest--;
                else break;
            }
            uppar = largest;
        }
        
        // int num = n==1 ? 0 :  arr[n-2];
        int num = 0;
        int gh = 2;
        while(n>=gh){
            if(arr[n-gh]==(p-1))gh++;
            else{
                num = arr[n-gh];
                break;
            }
        }

        if(neeche == -1){
            cout << uppar - arr[n-1] << "\n";
        }
        else if(neeche == (num +1)%p){
            neeche--;
            while(neeche>=0){
                if(present.count(neeche))neeche--;
                else break;
            }
            if(neeche == -1){
                cout << p - arr[n-1] << "\n";
            }
            else{
                cout << p - arr[n-1] + neeche << "\n";
            }
        }
        else{
            cout << p - arr[n-1] + neeche << "\n";
        }
        // cout << num << " " << uppar << " " << neeche << "\n";
        // cout << arr[n-1] 
    }

    return 0;}