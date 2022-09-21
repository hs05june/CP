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

    int n;
    cin >> n;

    deque<pii> tree,solve;
    set<int> ele;

    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        ele.insert(a);
        solve.push_back({a,i+1});
    }

    int mini = *(ele.begin());
    int maxi = *(--ele.end());

    sort(solve.begin(),solve.end());

    int root = mini;
    int check = abs(root-mini)+abs(maxi-root);

    for(auto i : ele){
        int check1 = abs(i-mini)+abs(i-maxi);
        if(check>check1){
            root = i;
            check = check1;
        }
    }
    int z = 1;

    if(n==1){
        cout << 1 << "\n";
        return 0;
    }

    for(int i = 0; i < n-1 ;i++){
        if(solve[i].first==root){
            z = i;
            while((i+1)<n && solve[i].first==root && solve[i+1].first==root){
                tree.push_back({solve[i].second,solve[i+1].second});
                ++i;
            }
            if((i+1)<n){tree.push_back({solve[z].second,solve[i+1].second});}
            continue;
        }
        tree.push_back({solve[i].second,solve[i+1].second});
    }

    cout << solve[z].second << "\n" ;

    for(int i = 0; i < tree.size() ; i++){
        cout << tree[i].first <<" " << tree[i].second << "\n";
    }

    return 0;}