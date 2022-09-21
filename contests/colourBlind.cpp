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

        string a,b;
        cin >> a >> b;
        bool check = true;

        for(int i = 0; i < n; i++){
            if(a[i]==b[i] || (a[i]=='G' && b[i]=='B') || (a[i]=='B' && b[i]=='G'))
            {
                continue;
            }
            else{
                check = false;
                break;
            }
        }

        check ? cout << "YES\n": cout<<"NO\n";

    }

    return 0;}