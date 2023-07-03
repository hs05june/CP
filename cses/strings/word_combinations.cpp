#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define ld long double
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

struct TrieNode{
    struct TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        rp(i,0,26)child[i] = NULL;
        isEnd = false;
    }
};

void Insert(struct TrieNode* root, string str){
    struct TrieNode* curr = root;
    int n = str.size();
    rp(i,0,n){
        int ind = str[i] - 'a';
        if(curr->child[ind]==NULL){
            curr->child[ind] = new TrieNode();
        }
        curr = curr->child[ind];
    }
    curr->isEnd = true;
}

bool Search(struct TrieNode* root, string str){
    struct TrieNode* curr = root;
    int n = str.size();
    rp(i,0,n){
        int ind = str[i] - 'a';
        if(curr->child[ind]==NULL)return false;
        curr = curr->child[ind];
    }
    return curr->isEnd;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    string a;
    cin >> a;
    int n = a.size();

    int q;
    cin >> q;

    struct TrieNode* root = new TrieNode();

    string str[q];
    set<string> uniq;
    rp(i,0,q){
        cin >> str[i];
        uniq.insert(str[i]);
        Insert(root,str[i]);
    }

    int dp[n+1];
    rp(i,0,n+1)dp[i] = 0;
    dp[n] = 1;

    rep(i,n-1,0){
        string x = "";
        int j = i;
        struct TrieNode * curr = root;
        while(j < n){
            int ind = a[j] - 'a';
            if(curr->child[ind]==NULL)break;
            curr = curr->child[ind];
            if(curr->isEnd)dp[i] = (dp[i]%M + dp[j+1]%M)%M;
            ++j;
        }
    }

    cout << dp[0]%M << "\n";

    return 0;}