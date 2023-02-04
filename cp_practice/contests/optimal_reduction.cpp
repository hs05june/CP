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

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        bool asc = true,ans = true;

        for(int i = 0; i < n-1; i++){
            if(a[i]<=a[i+1] && asc){
                continue;
            }
            else if(a[i]>a[i+1] && asc){
                asc = false;
            }
            else if(a[i]<a[i+1] && !asc){
                ans = false;
                break;
            }
        }

        ans ? cout << "YES\n": cout << "NO\n";
    }
    
    return 0;}