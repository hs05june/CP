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

struct TrieNode
{
    struct TrieNode * child[26];
    bool isEnd;
    int endhere;
    int cnt;
    TrieNode(){
        isEnd = false;
        endhere = 0;
        cnt = 0;
        for(ll i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
};

void insertString(struct TrieNode *root, string a){
    struct TrieNode* curr = root;
    int n = a.size();
    for(int i = 0; i < n; i++){
        int ind = a[i] - 'a';
        if(curr->child[ind] == NULL){
            curr->child[ind] = new TrieNode();
        }
        curr = curr->child[ind];
        curr->cnt++;
    }
    curr->endhere++;
    curr->isEnd = true;
}

bool searchString(struct TrieNode *root, string a){
    struct TrieNode* curr = root;
    int n = a.size();
    for(int i = 0; i < n; i++){
        int ind = a[i] - 'a';
        if(curr->child[ind] == NULL)return false;
        curr = curr->child[ind];
    }
    return curr->isEnd;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    struct TrieNode root = new TrieNode();

    return 0;}