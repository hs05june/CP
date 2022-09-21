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
        map<char,int> cnt;
        cnt['T']=1;
        cnt['i']=1;
        cnt['m']=1;
        cnt['u']=1;
        cnt['r']=1;

        bool check = true;

    int n;
    cin >> n;
        string a;
        cin >> a;

        for(int i=0;i<n;i++){
            if(cnt[a[i]]<=0){
                check = false;
                break;
            }
            cnt[a[i]]--;
        }

        if(check){
        for(auto i : cnt){
            if(i.second!=0){
                check = false;
                break;
            }
        }
}
        check ? cout<< "YES\n": cout<<"NO\n";
    }

    return 0;}