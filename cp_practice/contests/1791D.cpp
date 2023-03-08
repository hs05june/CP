#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
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

        string a;
        cin >> a;

        set<char> start;

        int cnt[26] = {0};

        rp(i,0,26)cnt[i] = 0;

        for(auto i : a){
            start.insert(i);
            cnt[(int)(i-'a')]++;
        }

        set<char> end;
        
        int ans = 0;
        ans = start.size();

        for(int i = n-1;i>=0;i--){
            end.insert(a[i]);
            cnt[a[i]-'a']--;
            if(cnt[a[i]-'a']==0)start.erase(a[i]);
            ans = max(ans,int(start.size()+end.size()));
        }

        cout << ans << "\n";

    }

    return 0;}