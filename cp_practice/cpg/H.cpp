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
    ull a = 1, b = pow(2,60)-1; 
    cin >> t;
  
    while(t--){
        
        int n,k;
        
        cin >> n >> k;
        string z,for_max,for_min;

        cin >> z;
        for_max = z;
        for_min = z;

        deque<bool> max_bool(n,false);
        deque<bool> min_bool(n,false);

        int x = 0;
        for(int i = 0; i < n && x < k;i++){
            if(for_max[i]=='G' && max_bool[i]==false){
                for_max[i] = 'L';
                max_bool[i] = true;
                x++;
            }
        }

        for(int i = n-1; i >= 0 && x < k; i--){
            if(for_max[i]=='L' && max_bool[i]==false){
                for_max[i] = 'G';
                x++;
                max_bool[i]= true;
            }
        }

        x = 0;
        for(int i = 0; i<n && x<k;i++){
            if(for_min[i]=='L' && min_bool[i]==false){
                for_min[i] = 'G';
                min_bool[i]=true;
                x++;
            }
        }
        for(int i = n-1; i>=0 && x<k;i--){
            if(for_min[i]=='G' && min_bool[i]==false){
                for_min[i] = 'L';
                min_bool[i]=true;
                x++;
            }
        }

        // cout << for_max<<"\n" << for_min<<"\n";

        ull ans_min = 1,ans_max = 1;

        ull low = a, high = b;

        for(int i = 0; i<n;i++){
            ull mid = (low+high)/2;
            if(for_max[i]=='G'){
                high = mid-1;
            }
            else if(for_max[i]=='L'){
                low = mid+1;
            }
            else if(for_max[i]=='E'){
                ans_max = mid;
            }
        }

        low = a , high = b;
        for(int i = 0; i<n;i++){
            ull mid = (low+high)/2;
            if(for_min[i]=='G'){
                high = mid-1;
            }
            else if(for_min[i]=='L'){
                low = mid+1;
            }
            else if(for_min[i]=='E'){
                ans_min = mid;
            }
        }
        cout << ans_min << " " << ans_max << "\n";
    }

    return 0;}