#include<bits/stdc++.h>
#define ll long long
#define deq deque<int>
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

        deq x,y;
        int x1[n],y1[n];
        int xc = 0, yc = 0;
        for(int i=0;i<n;i++){
            cin >> x1[i] >> y1[i];
            if(y1[i]==0){x.push_back(x1[i]);xc++;}
            if(x1[i]==0){y.push_back(y1[i]);yc++;}
        }

        sort(x.begin(),x.end());
        sort(y.begin(),y.end());

        int sx = x[0];
        int ex = x[xc-1];
        int sy = y[0];
        int ey = y[yc-1];

        ll ans = 0;

        if(sx==0 || ex==0){
            ans += abs(2*(sx+ex));
        }
        else if(sx<0 && ex>0){
            ans += 2*(ex-sx);
        }
        else if(sx<0 && ex<0){
            ans-=2*sx;
        }
        else if(sx>0 && ex>0){
            ans += 2*ex; 
        }
        if(sy==0 || ey==0){
            ans += abs(2*(sy+ey));
        }
        else if(sy<0 && ey>0){
            ans += 2*(ey-sy);
        }
        else if(sy<0 && ey<0){
            ans-= 2*sy;
        }
        else if(sy>0 && ey>0){
            ans += 2*ey; 
        }

        cout << ans << "\n";
    }

    return 0;}