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

        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        map<int,pii> cnt;
        for(int i = 0; i < n; i++){
            int x = i+1,y=a[i];
            while(i<n && a[i]==y){
                ++i;
            }
            cnt[y] = {x,i};
            --i;
        }

        bool check = true;

        for(auto i : cnt){
            if(i.second.first == i.second.second){
                check = false;
                break;
            }
        }

        if(!check){
            cout<<"-1\n";
            continue;
        }

        for(auto i : cnt){
            int x = i.second.second;
            cout << x << " ";
            for(int j = i.second.first; j < x; ++j){
                cout << j <<" ";
            }
        }
        cout << "\n";
    }

    return 0;}