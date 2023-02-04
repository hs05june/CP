//							  ੴ  ਵਾਹਿਗੁਰੂ 

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq deque<ll>
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

int a[200007],tree[800007];
void build(int node, int start, int end){
    if(start==end){
        tree[node] = a[start];
        return;
    }
    
    int mid = (start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);

    tree[node] = max(tree[2*node],tree[2*node+1]);
}

int query(int node, int start, int end, int& left, int& right){
    if(end<left || start>right){
        return 0;
    }
    if(left<=start && right>=end){
        return tree[node];
    }

    int mid = (start+end)/2;
    int q1 = query(2*node,start,mid,left,right);
    int q2 = query(2*node+1,mid+1,end,left,right);
    return max(q1,q2);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);
    
    int n,m;
    cin >> n >> m;

    rp(i,0,m)cin >> a[i];

    build(1,0,m-1);

    int q;
    cin >> q;
    while(q--){
        int x1,y1,x2,y2,k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;

        if((abs(x2-x1)%k)!=0 || (abs(y2-y1)%k)!=0){
            cout << "No\n";
            continue;
        }
        int q1 = min(y1-1,y2-1);
        int q2 = max(y1-1,y2-1);
        int maxi = query(1,0,m-1,q1,q2);

        int x = (((n-x1)/k)*k) + x1;

        if(x>maxi){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
        // cout << x << " " << maxi << '\n';
    }    

    return 0;}