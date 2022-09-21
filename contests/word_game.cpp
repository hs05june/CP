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
        int n;
        cin >> n;
        multiset<string> s[3];
        for(int i = 0; i<n;i++){
            string a;
            cin >>  a;
            s[0].insert(a);
        }
        for(int i = 0; i<n;i++){
            string a;
            cin >>  a;
            s[1].insert(a);
        }
        for(int i = 0; i<n;i++){
            string a;
            cin >>  a;
            s[2].insert(a);
        }

        int ans[3] = {0};

        for(int i = 0; i<3;i++){
            for(auto j : s[i]){
                bool x = s[(i+1)%3].count(j);
                bool y = s[(i+2)%3].count(j);
                if(!x && !y){
                    ans[i] += 3;
                }
                else if(x && y){
                    ans[i] += 0;
                }
                else if(x || y){
                    ans[i] += 1;
                }
            }
        }

        for(int i = 0; i<3;i++){
            cout<< ans[i] << " ";
        }
        cout<<"\n";
    }

    return 0;}