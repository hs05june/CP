#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define int long long
#define deq vector<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),b)
const ll M = 1000000007;
using namespace std;

int arr[200007], tree1[800007],tree2[800007];

void build1(int node, int start, int end)
{
    if (start == end)
    {
        tree1[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    build1(2 * node, start, mid);
    build1(2 * node + 1, mid + 1, end);
    tree1[node] = max(tree1[2 * node], tree1[2 * node + 1]);
}

int query1(int node, int start, int end,int left, int right)
{
    if(start>right || end<left)return 0;
    if(start>=left && end<=right)return tree1[node];
    
    int mid = (start+end)/2;
    int q1 = query1(2*node,start,mid,left,right);
    int q2 = query1(2*node+1,mid+1,end,left,right);
    return max(q1,q2);
}

void build2(int node, int start, int end)
{
    if (start == end)
    {
        tree2[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    build2(2 * node, start, mid);
    build2(2 * node + 1, mid + 1, end);
    tree2[node] = min(tree2[2 * node], tree2[2 * node + 1]);
}

int query2(int node, int start, int end, int left, int right)
{
    if(start>right || end<left)return LLONG_MAX;
    if(start>=left && end<=right)return tree2[node];
    
    int mid = (start+end)/2;
    int q1 = query2(2*node,start,mid,left,right);
    int q2 = query2(2*node+1,mid+1,end,left,right);
    return min(q1,q2);
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        for(int i = 0; i <n ;i++){
            cin >> arr[i];
        }
        
        build1(1,0,n-1);
        build2(1,0,n-1);

        int i = 0, j = n-1;
        bool ans = false;
        while(i<j){
            int maxi = query1(1,0,n-1,i,j);
            int mini = query2(1,0,n-1,i,j);
            if(maxi==arr[i] || mini==arr[i]){
                ++i;
            }
            else if(maxi==arr[j] || mini==arr[j]){
                --j;
            }   
            else{
                ans = true;
                break;
            }
        }

        ans ? cout << i+1 << " " << j+1 << "\n" : cout << "-1\n";

    }

    return 0;}