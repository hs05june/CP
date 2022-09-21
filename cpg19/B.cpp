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

    int n;
    cin >> n;
    string a;
    cin >> a;

    map<char,int> cnt;

    for(int i = 0; i < n; i++){
        cnt[a[i]]++;
    }

    int mini = (*(cnt.begin())).second;

    for(auto i : cnt){
        if(mini>(i.second)){
            mini = i.second;
        }
    }

    // for(auto i : cnt){
    //     cout << i.first << " " << i.second<<"\n";
    // }

    int k = __gcd(n,mini);
    int z = 1;

    for(int i = k; i>=1; i--){
        bool check = true;
        for(auto j : cnt){
            if(((j.second)%i) == 0){
                continue;
            }
            check = false;
        }
        if(check == true){
            z = i;
            break;
        }
    }

    cout << (n/z);

    return 0;}