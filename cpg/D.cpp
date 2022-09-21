#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
const int M = 1000000007;
using namespace std;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

   while (t--)
    {
        ll x,y,l,r,sum=0;
        cin>>x>>y>>l>>r;
        int r1 = x|y;
        int r2 = y^r1;
        ll a[]={x,y,r1,r2},b[]={r1,y,r1,r2};

        if (l<4)
        {
            for (int i=l;i<4&&i<=r;i++)
                sum+=a[i];
            l=4;
        }
        
        if (l<=r)
        {
            sum+=(r-l+1)/4*(2*(x|y)+(x&y)+(x^y));
            for (int i=0;i<(r-l+1)%4;i++)
                sum+=b[(l+i)%4];
        }
        cout<<sum<<endl;
    }

    return 0;}