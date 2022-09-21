#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int, int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);
#define HARPREET cout.tie(0);
int M = 1000000007;
using namespace std;

int main()
{
    CODE BY HARPREET

        int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
       
        map<char,ll> s,t;
        for (int i = 0; i < n; i++)
        {
            // letters[i][a[i] - 'a'] = i;
            s[a[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            t[b[i]]++;
        }

        bool ans = true;
        for(int i = 0 ; i < 3; i++){
            // cout << s[char(i+'a')] << " " << t[char(i+'a')] << "\n";
            if(s[char(i+'a')]!=t[char(i+'a')]){
                ans = false;
            }
        }

        if(!ans){
            cout << "NO\n";
            continue;
        }

       
        int j = 0;

        for(int i = 0; i < n && j<n; i++){
            if(a[i]=='b')continue;
            while(b[j]=='b')j++;

            if(a[i]!=b[j] || (a[i]=='a' && i > j) || (a[i]=='c' && i < j)){
                ans = false;
                break;
            }
            ++j;
        }
        ans ? cout << "YES\n": cout << "NO\n";
    }

    return 0;
}