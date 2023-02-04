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
    cin >> t;

    while(t--){

    int n,k;
    cin  >> n >> k;

    mii cnt;

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        cnt[a]++;
    }

    deq s;

    for(auto i : cnt){
        if(i.second>=k){
            s.push_back(i.first);
        }
    }   

    if(s.empty()){
        cout<<"-1\n";
        continue;
    }

    sort(s.begin(), s.end());

    int x=s[0],ans = 0;

    for(int i=0; i<s.size()-1; i++){
        int k = s[i];
        int z = 0;

        while((i+1)<s.size() && s[i+1]-s[i]==1){
            ++z;
            ++i;
        }

        if(z>ans){
            ans = z;
            x = k;
        }
    }

    cout << x << " " << x+ans<<"\n";
}
    return 0;}