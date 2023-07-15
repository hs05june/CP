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

int n,arr[200007];
pii tree1[800007],tree2[800007];
int pref[200007];
int next_greater[200007],prev_greater[200007];

void build1(int node, int start, int end){
    if(start==end){
        tree1[node] = pref[start];
        return ;
    }
    int mid = (start+end)/2;
    build1(2*node,start,mid);
    build1(2*node+1,mid+1,end);
    tree1[node] = min(tree1[2*node],tree1[2*node+1]);
}

void build2(int node, int start, int end){
    if(start==end){
        tree2[node] = pref[start];
        return ;
    }
    int mid = (start+end)/2;
    if(mid>=start)build2(2*node,start,mid);
    if(mid+1<=end)build2(2*node+1,mid+1,end);
    tree2[node] = max(tree2[2*node],tree2[2*node+1]);
}

pii query1(int node, int start, int end, int left, int right){
    if(start>right || end < left){
        return LLONG_MAX;
    }
    if(start>=left && end<=right){
        return tree1[node];
    }
    int mid = (start+end)/2;
    auto q1 = query1(2*node,start,mid,left,right);
    auto q2 = query1(2*node+1,mid+1,end,left,right);
    return min(q1,q2);
}

pii query2(int node, int start, int end, int left, int right){
    if(start>right || end < left){
        return LLONG_MIN;
    }
    if(start>=left && end<=right){
        return tree2[node];
    }
    int mid = (start+end)/2;
    auto q1 = query2(2*node,start,mid,left,right);
    auto q2 = query2(2*node+1,mid+1,end,left,right);
    return max(q1,q2);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        cin >> n;
        rp(i,0,n+5){
            arr[i] = 0;
            pref[i] = 0;
        }
        rp(i,1,n+1)cin >> arr[i];
        rp(i,0,n+4){pref[i] = 0;next_greater[i] = 0; prev_greater[i] = 0;}
        rp(i,0,4*n){
            tree1[i] = 0;
            tree2[i] = 0;
        }

        rp(i,1,n+2){
            pref[i] = pref[i-1] + arr[i];
        }   

        stack<pii> st;
        rp(i,1,n+1){
            if(st.empty()){
                st.push({arr[i],i});
                continue;
            }
            // auto k = st.top();
            while(!st.empty() && st.top().f<arr[i]){
                next_greater[st.top().s] = i;
                // if(!st.empty())k = st.top();
                st.pop();
            }
            st.push({arr[i],i});
        }
        while(!st.empty()){
            // auto k = st.top();
            next_greater[st.top().s] = n+1;
            st.pop();
        }
        // st.clear();
        rep(i,n,1){
            if(st.empty()){
                st.push({arr[i],i});
                continue;
            }
            // auto k = st.top();
            while(!st.empty() && st.top().f<arr[i]){
                prev_greater[st.top().s] = i;
                st.pop();
                // if(!st.empty())k = st.top();
            }
            st.push({arr[i],i});
        }

        while(!st.empty()){
            // auto k = st.top();
            prev_greater[st.top().s] = 0;
            st.pop();
        }

        build1(1,1,n);
        build2(1,1,n);
        bool ans = true;
        rp(i,1,n+1){
            auto q1 = query1(1,1,n,prev_greater[i]+1,i);
            auto q2 = query2(1,1,n,i,next_greater[i]-1);
            if(pref[i] - )
        }
        ans ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;}