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
        string a;
        
        cin >> a;
        int n;cin >> n;
        int ans = 0;
        
        map<char,deq> cnt;
        
        for(int i = 0;i < a.size();i++){
            cnt[a[i]].push_back(i);
            ans += (a[i]-'a'+1);
        }

        // for(auto it : cnt){
        //     cout<<it.first<<" = ";
        //     for(auto j : it.second){
        //         cout << j << " ";
        //     }
        //     cout<<"\n";
        // }
        // cout << ans<<"\n";
        set<int> to_remove;
        auto itr = cnt.end();
        while(ans>n){
            --itr;
            auto z = *itr;
            while(ans>n && !((z.second).empty())){
                ans-=(z.first - 'a' + 1);
                to_remove.insert(z.second[0]);
                (z.second).pop_front();
            }
        }
        // for(auto j : to_remove){cout<<j<<"\n";}
        for(int i=0; i<a.size(); i++){
            if(!to_remove.count(i))cout<<a[i];
        }
        cout << "\n";
    }

    return 0;}