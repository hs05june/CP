#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
int M = 1000000007;
using namespace std;

int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x;
    return 0;
}



int main(){

    int p[4] = {34,33,31,29};
    int x[5];

    int a[4];
    for(int i = 0; i < 4; i++) {
        cout<<"? "<<p[i]<<endl;
        cin>>a[i];
    }

    int r[4][4];
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            r[i][j] = modInverse(p[i],p[j]);
        }
    }
    

    for (int i = 0; i < 4; ++i) {
        x[i] = a[i];
        for (int j = 0; j < i; ++j) {
            x[i] = r[j][i] * (x[i] - x[j]);

            x[i] = x[i] % p[i];
            if (x[i] < 0)
                x[i] += p[i];
        }
    }

    int ans = x[0]+x[1]*p[0]+x[2]*p[1]*p[0]+x[3]*p[0]*p[1]*p[2];

    cout <<"! " << ans << endl;

    return 0;}