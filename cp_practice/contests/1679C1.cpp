#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);cout.tie(0);
#define HARPREET cout << fixed << setprecision(20);
int M = 1000000007;
using namespace std;

signed main(){
    CODE BY HARPREET

    int n,q;

    cin >> n >> q;
    set<int> freeRows,freeCols;
    map<int,int> filledRows,filledCols;

    for(int i = 1; i <= n; i++){
        freeRows.insert(i);
        freeCols.insert(i);
    }

    while(q--){
        int t;
        cin >> t;
        if(t==1){
            ll x,y;
            cin >> x >> y;
            filledRows[x]++;
            filledCols[y]++;
            freeRows.erase(x);
            freeCols.erase(y);
        }
        if(t==2){
            ll x,y;
            cin >> x >> y;
            filledRows[x]--;
            filledCols[y]--;
            if(filledRows[x]==0)freeRows.insert(x);
            if(filledCols[y]==0)freeCols.insert(y);
        }
        if(t==3){
            int x1,x2,y1,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            bool ansx = true,ansy = true;
            auto itrx1 = lower_bound(all(freeRows),x1);
            auto itrx2 = lower_bound(all(freeRows),x2);
            if(itrx1!=itrx2 || (*itrx1)==x1 || (*itrx2)==x2)ansx = false;
            
            auto itry1 = lower_bound(all(freeCols),y1);
            auto itry2 = lower_bound(all(freeCols),y2);
            if(itry1!=itry2 || (*itry1)==y1 || (*itry2)==y2)ansy = false;

            ansx || ansy ? cout << "Yes\n": cout << "No\n";
        }
    }

    return 0;}