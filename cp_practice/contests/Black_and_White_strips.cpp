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
        int n,k;
        cin >> n >> k;

        string a;
        cin >> a;

        int white[n];
        for(int i = 0; i < n; i++){
            white[i] = INT_MAX;
        }
        int x = 0;
        for(int i = 0; i < k; i++){
            if(a[i] == 'W'){
                x++;
            }
        }
        white[0] = x;

        int j = k;

        for(int i = 1; i < n && j<n; i++){
            if(a[i-1] == a[j]){
                white[i] = white[i-1];
            }
            else if(a[i-1]=='W' && a[j]=='B')white[i]=white[i-1]-1;
            else if(a[i-1]=='B' && a[j]=='W')white[i]=white[i-1]+1;
            j++;
        }

        // for(int i = 0; i < n; i++){
        //     cout << white[i] << " ";
        // }

        int ans = *min_element(white, white+n);
        cout<<ans<<"\n";
    }

    return 0;}