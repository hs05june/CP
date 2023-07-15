#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define ld long double
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

bool check(int mid, vector<int>& arr, int& k){
    mii cnt;
    set<int> uniq;
    int total = LLONG_MAX;
    for(auto i : arr){
        cnt[i]++;
        uniq.insert(i);
        // uniq.insert(i-mid);
        // uniq.insert(i+mid);
    }

    deq array;
    for(auto i : uniq){
        if(i >= arr[0] && i <= arr.back())array.pb(i);
    }

    
    int n = sz(array);
    ll uppar[n+1], neeche[n+1];

    uppar[n] = 0;
    neeche[0] = cnt[array[0]]*array[0];

    rep(i,n-1,0){
        uppar[i] = uppar[i+1] + (array[i]*cnt[array[i]]);
    }

    rp(i,1,n){
        
    }

    // int neeche[n], uppar[n];
    // neeche[0] = 0, uppar[n-1] = 0;

    // int num = cnt[array[0]];

    // rp(i,1,n){
    //     neeche[i] = neeche[i-1] + num*abs(array[i]-array[i-1]);
    //     num += cnt[array[i]];
    // }

    // num = cnt[array[n-1]];

    // rep(i,n-2,0){
    //     uppar[i] = uppar[i+1] + num*abs(array[i+1]-array[i]);
    //     num += cnt[array[i]];
    // }

    // rp(i,0,sz(array)){
    //     int x = array[i] + mid;
    //     auto itr = lower_bound(all(array),x);
    //     if(itr == array.end())break;
    //     int z = itr - array.begin();
    //     total = min(total,neeche[i]+uppar[z]);
    // }
    // for(auto i : array)cout << i << " ";
    // cout << "\n";
    // rp(i,0,n)cout << neeche[i] << " ";
    // cout << "\n"; 
    // rp(i,0,n)cout << uppar[i] << " ";
    // cout << "\n"; 
    // cout << total << " " << mid << "\n";
    return total < k;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n, k;
    cin >> n >> k;

    deq arr;
    rp(i,0,n){
        int a;
        cin >> a;
        arr.pb(a);
    }

    sort(all(arr));

    int low = 0, high = arr.back() - arr[0];

    while(high - low > 1){
        int mid = (low + high)/2;
        if(check(mid,arr,k)){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }

    if(check(low,arr,k))cout << low << "\n";
    else cout << high << "\n";

    check(3,arr,k);

    return 0;}