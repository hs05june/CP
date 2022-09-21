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

    ll arr[n];
    set<ll> ele;
    deq res;
    int zero = 0, neg = 0, pos = 0;
    bool possible = true;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        ele.insert(arr[i]);
        if(arr[i] == 0){
            zero++;
            if(zero<=2)res.push_back(arr[i]);
        }
        else if(arr[i]>0 && pos < 2){
            pos++;
            res.push_back(arr[i]);
        }
        else if(arr[i]<0 && neg < 2){
            neg++;
            res.push_back(arr[i]);
        }
        else{
            possible = false;
        }
    }    

    if(!possible){
        cout<<"NO\n";
        // return 0;
        continue;
    }
    for(int i = 0; i < res.size(); i++){
        for(int j = i+1; j < res.size(); j++){
            for(int k = j+1; k < res.size(); k++){
                ll z = res[i]+res[j]+res[k];
                if(!ele.count(z)){
                    possible = false;
                }
            }
        }
    }
    possible ? cout<<"YES\n" : cout<<"NO\n";}
    return 0;}