#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);
#define HARPREET cout.tie(0);
int M = 1000000007;
using namespace std;

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL *a%mod) % mod;
        b >>= 1;}
    return ans;}

signed main(){
    CODE BY HARPREET

    int t; cin >> t;

    while(t--){

        int n,k;
        cin >> n >> k;

        string a;
        cin >> a;

        map<char,ll> cnt;

        for(char i = 'a'; i < 'z'; i++){
            cnt.insert({i,0});
        }

        for(int i = 0; i < n ;i ++){
            cnt[a[i]]++;
        }

        string b= "";

        for(int i = 0; i < k; i++){
            int s = 0;
            bool done = false;
            for(char j = 'a'; j < 'z' && s < n/k; j++){
                if(cnt[j]==0 && !done){
                    b.push_back(j);
                    done = true;
                }
                else if(cnt[j]>0){
                    cnt[j]--;
                    s++;
                    if(s==n/k && !done){
                        b.push_back(char(j+1));
                        done = true;
                    }
                }
            }
        }

        cout << b << "\n";
    }

    return 0;}