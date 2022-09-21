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

    pii palindromes[16] = {{0,0},{1,10},{2,20},{3,30},{4,40},{5,50},{10,1},{11,11},{12,21},{13,31},{14,41},{15,51},{20,2},{21,12},{22,22},{23,32}};

    int t;
    cin >> t;
    while(t--){
    string time;
    cin >> time;

    int to_add;
    cin >> to_add;

    int h = (time[0]-'0')*10 + (time[1]-'0'),m = (time[3]-'0')*10 + (time[4]-'0');
    int covered_h = h,covered_m = m;
    int ans = 0;

    bool z = true;

    while(z==true || covered_h!=h || covered_m!=m){
        z = false;
        for(int i = 0; i<16; i++){
            if(palindromes[i].first==h && palindromes[i].second==m){
                ans++;
                break;
            }
        }
        m+=to_add;
        if(m>=60){
            h += m/60;
            m = m%60;
        }
        if(h>=24){
            h = h%24;
        }
    }
    cout << ans << "\n";
}
    return 0;}