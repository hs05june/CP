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
    // bool zero = true;
    int arr[n];

    map<int, int> cnt;
    cnt[0] = 0;
    bool zero = false;
    bool all_zero = true;
    int maxi = -1;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
        if(arr[i]==0)zero=true;
        if(arr[i]!=0)all_zero=false;
        cnt[arr[i]]++;
        if(arr[i]>maxi)maxi=arr[i];
    }

    if((n==1) || all_zero || (!zero)){
        cout << "1\n";
        continue;
    }

    int z = 0;
    while(true){
        if(cnt[z]==0)break;
        ++z;}

        int ans = 0;

        for(int i = 1; i <= z; i++){
            bool check = true;
            for(int j = 0; j <i; j++){
                if(cnt[j]==0){check = false;break;}
                else cnt[j]--;
            }
            if(!check)break;
            else ans++;
        }

        for(auto i : cnt){
            if(i.first==0)continue;
            if(i.second!=0){
                ans++;
                break;
            }
        }

        cout << ans << "\n";
}
    return 0;}
