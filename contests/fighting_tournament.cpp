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

    int n,q;
    cin >> n >> q;
  
    deq candi;
    int arr[n];
    
    int a,maxi = 0,k = 0;

    for(int i = 0; i < n; i++){
        cin >> a;
        if(maxi<a){
            maxi = a;
            k = i;
        }
        arr[i] = a;
        candi.push_back(i);
    }

    // int to_calculate = (k!=0) ? k : 1;
    int to_calculate = n-1;

    map<int,deque<pii>> ans;

    for(int i = 0; i < n; i++){
        ans[i].push_back({0,0});
    }

    for(int i = 1; i < to_calculate; i++){
        int x = candi[0];
        candi.pop_front();
        int y = candi[0];
        candi.pop_front();
        if(arr[x]<arr[y])swap(x,y);
        int z = ans[x][ans[x].size()-1].second;
        ans[x].push_back({i,z+1});
        candi.push_front(x); 
        candi.push_back(y);
    }

    while(q--){
        int x,y;
        cin >> x >> y;

        if(y>=to_calculate){
            if(x==(k+1)){
                cout<<(ans[k][ans[k].size()-1].second+y-to_calculate+1)<<"\n";
            }
            else{
                cout << ans[x-1][ans[x-1].size()-1].second<<"\n";
            }
        }
        else{
            pii f = {y,0};
            auto ans1 = *(lower_bound(ans[x-1].begin(),ans[x-1].end(),f));
                cout << ans1.second << "\n";
        }
    }
}
    return 0;}