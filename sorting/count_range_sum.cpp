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

vector<int> numbers;
int pref_sum[100007],hash_arrlower[100007],hash_arrupper[100007],hash_arrpref[100007];
int fenwick[100007],largest;

int sum(int n){
    int sum = 0;
    for(int i = n; i>0;i -= (i&(-i))){
        sum+=fenwick[i];
    }
    return sum;
}

void update(int n, int value){
    for(int i = n; i<=largest; i += (i&(-i))){
        fenwick[i] += value;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;

    while(t--){

        int n;
        cin >> n;

        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            numbers.push_back(x);
        }

        int lower[n+1],upper[n+1];
        cin >> lower[1] >> upper[1];

        pref_sum[0] = 0;

        for(int i = 1; i <= n; i++){
            if(i>=2){
                lower[i] = lower[i-1] + numbers[i-2];
                upper[i] = upper[i-1] + numbers[i-2];
            }
            pref_sum[i] = numbers[i-1]+pref_sum[i-1];
        }

        for(int i = 1; i<=n; i++){
            cout << pref_sum[i] << " " << lower[i] << " " << upper[i] << "\n";
        }

        vector<int> to_create_hash;

        for(int i = 1; i <= n; i++){
            to_create_hash.pb(pref_sum[i]);
            to_create_hash.pb(lower[i]);
            to_create_hash.pb(upper[i]);
        }

        sort(all(to_create_hash));


        for(auto i : to_create_hash){
            cout << i << " ";
        }
        cout << "\n";
        for(int i = 1; i <= n; i++){
            auto itr1 = lower_bound(all(to_create_hash),pref_sum[i]);
            hash_arrpref[i] = itr1 - to_create_hash.begin() + 1;
            auto itr2 = lower_bound(all(to_create_hash),lower[i]);
            hash_arrlower[i] = itr2 - to_create_hash.begin() + 1;
            auto itr3 = lower_bound(all(to_create_hash),upper[i]);
            hash_arrupper[i] = itr3 - to_create_hash.begin() + 1;
        }

        for(int i = 1; i<=n;i++){
            cout << hash_arrpref[i] << " " << hash_arrlower[i] << " " << hash_arrupper[i] << "\n";
        }

        largest = to_create_hash.size();

        for(int i = 1; i<=n; i++){
            update(hash_arrpref[i],1);
        }

        int ans = 0;

        for(int i = 1; i<=n; i++){
            int x = (sum(hash_arrupper[i]) - sum(hash_arrlower[i]-1));
            cout << x << "\n";
            ans+=x;
            update(hash_arrpref[i],-1);
        }

        cout << ans << "\n";

    }

    return 0;}