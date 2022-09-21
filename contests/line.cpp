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
        int n;
        cin>>n;
        string a;
        cin >>  a;

        ll ans = 0;

        deq left,right;

        for(int i = 0; i < n; i++){
            if(a[i]=='L'){ans+=i;left.push_back(i);}
            else if(a[i]=='R'){ans += (n-i-1);right.push_back(i);}
        }

        for(int i = 0; i < n; i++){
            int z = ans;
            if(!left.empty() && !right.empty()){
                ll l = left[0];
                ll r = right[right.size()-1];

                ll al = ans + n - l -1 - l;
                ll ar = ans + r - n + r + 1;

                if(al >= ar && al > ans){
                    ans = al;
                    left.pop_front();
                }
                else if(ar > al && ar > ans){
                    ans = ar;
                    right.pop_back();
                }
            }
            else if(!left.empty() && right.empty()){
                ll l = left[0];

                ll al = ans + n - l -1 - l;

                if(al > ans){
                    ans = al;
                    left.pop_front();
                }
            }
            else if(!right.empty() && left.empty()){
                ll r = right[right.size()-1];

                ll ar = ans + r - n + r + 1;
                if(ar > ans){
                    ans = ar;
                    right.pop_back();
                }
            }
            cout << ans << " ";
        }
        cout << "\n";
    }

    return 0;}