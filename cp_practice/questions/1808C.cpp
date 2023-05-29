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

pair<int,string> solve9(string a, int index, char mini, char maxi, string ans){
    string ans1 = ans;
    mini = min(mini,a[index]);
    maxi = max(maxi,a[index]);
    ans1.pb(a[index]);
    int i = index+1;
    for(;i<sz(a);i++){
        if(a[i]<=maxi){
            ans1.pb(maxi);
        }
        else if(i!=index+1 && ans1.back()!='9'){
            ans1[sz(ans1)-1] = char(ans1[sz(ans1)-1]+1);
            ans1.pb(ans1.back());
            maxi = max(maxi,ans1.back());
            break;
        }
        else{
            ans1.pb(a[i]);
            maxi = a[i];
        }
        if(ans1.back()>a[i])break;
    }
    rp(j,i+1,sz(a))ans1.pb(mini);
    // cout << maxi << " " << mini << " " << ans1 << "\n";
    return {abs((int)(maxi-mini)),ans1};
}

pair<int,string> solve0(string a, int index, char mini, char maxi, string ans){
    string ans1 = ans;
    mini = min(mini,a[index]);
    maxi = max(maxi,a[index]);
    ans1.pb(a[index]);
    int i = index+1;
    for(;i<sz(a);i++){
        if(a[i]>=mini){
            ans1.pb(mini);
        }
        else if(i!=index+1 && ans1.back()!='0'){
            ans1[sz(ans1)-1] = char(ans1[sz(ans1)-1]-1);
            ans1.pb(ans1.back());
            mini = min(mini,ans1.back());
            break;
        }
        else{
            ans1.pb(a[i]);
            mini = a[i];
        }
        if(ans1.back()<a[i])break;
    }
    rp(j,i+1,sz(a))ans1.pb(mini);
    // cout << maxi << " " << mini << " " << ans1 << "\n";
    return {abs((int)(maxi-mini)),ans1};
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        string a,b;
        cin >> a >> b;

        if(a==b){
            cout << a << "\n";
            continue;
        }

        if(sz(a)!=sz(b)){
            string ans = "";
            rp(i,0,max(sz(a),sz(b))-1)ans.pb('9');
            cout << ans << "\n";
            continue;
        }
        int one = -1, two = -1;
        rp(i,0,sz(a)){
            if((int)(b[i]-a[i])==1){
                one = i;
                break;
            }
            if((int)(b[i]-a[i])>1){
                two = i;
                break;
            }
        }

        if(two!=-1){
            string ans = "";
            char mini = '9', maxi = '0';
            if(two==0){
                char x = char(1+a[0]);
                rp(i,0,sz(a)){
                    ans.pb(x);
                }
                cout << ans << "\n";
                continue;
            }
            rp(i,0,two){
                ans.pb(a[i]);
                mini = min(mini,a[i]);
                maxi = max(maxi,a[i]);
            }
            char to = a[two];
            rp(i,two,sz(a))ans.pb(to);
            set<pair<int,char>> ty;
            for(char i = a[two]; i <= b[two]; i++){
                ty.insert({max(abs((int)(i-mini)),abs((int)(i-maxi))),i});
            }
            for(auto i : ty){
                rp(j,two,sz(a))ans[j] = i.s;
                if(ans>=a && ans<=b)break;
            }
            cout << ans << "\n";
            continue;
        }

        if(one!=-1){
            string ans = "";
            char mini = '9', maxi = '0';
            rp(i,0,one){
                mini = min(mini,a[i]);
                maxi = max(maxi,a[i]);
                ans.pb(a[i]);
            }
            set<pair<int,string>> possible;
            if(one==0){
                string ans1 = ans;
                possible.insert(solve9(a,one,a[0],a[0],ans1));
                ans1 = ans;
                possible.insert(solve0(b,one,b[0],b[0],ans1));
            }
            else{
                possible.insert(solve9(a,one,mini,maxi,ans));
                possible.insert(solve0(b,one,mini,maxi,ans));
            }
            cout << (*possible.begin()).s << "\n";
        }
        
    }

    return 0;}