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

int arr[200007],visited[200007],first[200007],to_delete[200007],chance[200007];
stack<int> st;
set<int> cycle, one_pr;
int tim;

void saaf(){
    while(!st.empty())st.pop();
}

void cycle_bhar(){
    while(!st.empty()){
            cycle.insert(st.top());
            st.pop();
        }
}

void one_pr_bhar(){
    while(!st.empty()){
            one_pr.insert(st.top());
            st.pop();
        }
}

bool dfs(int i, int n){
    st.push(i);
    int x = i + arr[i];
    if(x<=0 || x>n)return false;
    if(visited[x]==1)return true;
    visited[x] = 1;
    first[x] = ++tim;
    
    return dfs(x,n);
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

        cycle.clear();
        one_pr.clear();
        saaf();
        tim = 0;
        visited[0] = arr[0] = 0;
        to_delete[0] = 0;first[0] = 0;chance[0] = 0;
        rp(i,1,n+1){cin >> arr[i];visited[i] = 0;to_delete[i] = 0;first[i] = 0;chance[i]=0;}
        one_pr.insert(1);
    
        saaf();
        visited[1] = 1;
        bool check = dfs(1,n);

        if(check){
            cycle_bhar();
        }
        saaf();
        int z = 2;
        rp(i,2,n+1){
            if(visited[i]==0){
                saaf();
                int x = i;
                visited[x] = z;
                st.push(x);
                while(true){
                    int y = x;
                    x = x + arr[x];
                    if(x<=0 || x>n){saaf();break;}
                    if(!check && one_pr.count(x)){
                        st.push(x);
                        one_pr_bhar();
                        saaf();
                        break;
                    }
                    if(cycle.count(x) || visited[x]==z){
                        st.push(x);
                        cycle_bhar();
                        saaf();
                        break;
                    }
                    if(visited[x]!=0){
                        if(visited[x]==1){
                            to_delete[first[x]]+=st.size();
                            chance[y] = first[x];
                        }
                        else if(chance[x]!=0){
                            to_delete[chance[x]]+=st.size();
                            chance[y] = chance[x];
                        }
                        while(!st.empty()){
                            chance[st.top()] = chance[y];
                            st.pop();
                        }
                        saaf();
                        break;
                    }
                    visited[x] = z;
                    st.push(x);
                }
                ++z;
            }
        }

        int ans = 0;

        if(!check){
            rp(i,1,n+1){
                to_delete[i] += to_delete[i-1];
            }
            rp(i,1,n+1){
                if(i==1){
                    ans+=((2*n)+1 - sz(one_pr) - sz(cycle));
                }
                else if(visited[i]==1){
                    ans += ((2*n) - sz(one_pr) - sz(cycle) - first[i] + 1 - to_delete[first[i]]);
                }
                else{
                    ans+= ((2*n)+1);
                }
            }
            cout << ans << "\n";
        }
        else{
            rp(i,1,n+1){
                if(visited[i]==1){
                    ans+=((2*n)+1 - sz(cycle));
                }
            }
            cout << ans << "\n";
        }

    }

    return 0;}