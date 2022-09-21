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
    int root = 1;

    int leaf[n+1] = {false},tree_parent[n+1]={0};
    bool visited[n+1] = {false};

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x==i)tree_parent[i] = 0;
        else{
            tree_parent[i] = x;
        }
        leaf[x] = true;
    }

    if(n==1){
        cout<<"1\n1\n1\n\n";
        continue;
    }


    int a = 0;

    for(int i = 1; i <= n; i++){
        if(leaf[i] == false)a++;
    }

    cout << a << "\n";

    for(int i = 1; i <= n; i++){
        if(leaf[i] == false){
            deq x;
            x.push_back(i);
            visited[i] = true;
            int k = tree_parent[i];
            while(!visited[k] && k!=0){
                x.push_back(k);
                visited[k] = true;
                k = tree_parent[k];
            }
            cout<<x.size()<<"\n";
            reverse(all(x));
            for(int j = 0; j < x.size(); j++){
                cout<<x[j]<<" ";
            }
            cout<<"\n";
        }
    }

    cout<<"\n";
    
    }
    return 0;}