#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
int M = 1000000007;
using namespace std;

ll findPermutations(int a[], int b[],int c[], int tt[] , int ff[] int n)
{

ll ans = LLONG_MAX;

sort(a, a + n);
sort(b ,b + n);
sort(c , c + n);
reverse(c,c+n);



pair<ll,ll> arr[n] = {{0,0}};

do {
    ll z = 0;
    for(int i = 0; i < n; i++) {
        z += ((a[i]+b[i])*(a[i]+b[i]));
    }
   
    for(int i = 0; i < n; i++) {
        tt[i] = (a[i]+b[i]);
        ff[i] = c[i];
    }
    sort(ff,ff+n);
    sort(tt, tt+n);
    reverse(ff,ff+n);

    for(int i = 0; i < n; i++){
        z+=ff[i]*(tt[i]);
    }

} while (next_permutation(a, a + n));

    ll sol = 0;

    sort(arr,arr+n);

    for(int i = 0; i < n; i++) {
        sol += (arr[i].first*c[i]);
        sol += arr[i].second;
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int a[n],b[n],c[n],tt[n],ff[n];
    int k;

    for(int i = 0; i < n; i++){cin >> a[i];}
    for(int i = 0; i < n; i++){cin >> b[i];}
    for(int i = 0; i < n; i++){cin >> c[i];}

    for(int i = 0; i < n; i++) k+=a[i]

    ll ans = findPermutations(a,b,c,tt,ff,n);

    cout << ans;

    return 0;}