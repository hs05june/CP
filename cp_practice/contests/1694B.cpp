#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
int M = 1000000007;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        ull n;string a;
        cin >> n >> a;

        ull ans = n;

        for(ull i = 1;i < n;i++){
            if(a[i]!=a[i-1])ans+=i;
        }

        cout << ans << "\n";
    }

    return 0;}