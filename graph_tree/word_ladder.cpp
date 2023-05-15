/*
Word Ladder II

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 
Constraints:
1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 500
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
The sum of all shortest transformation sequences does not exceed 10^5.
*/

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
#define lb(a,b) lower_bound((a).begin(),(a).end(),b)
const ll M = 1000000007;
using namespace std;

vector<vector<string>> ans;
    vector<string> ans1;
    void solve(string x, map<string, int>& levels, string& beginWord){
        if(x==beginWord){
            ans.push_back(ans1);
            return;
        }

        int n = x.size();
        int y = levels[x];
        string h = x;
        for(int i = 0; i < n; i ++){
            for(char j =  'a'; j <= 'z'; j++){
                h[i] = j;
                if(levels.count(h) && levels[h] == y - 1){
                    ans1.push_back(h);
                    solve(h,levels,beginWord);
                    ans1.pop_back();
                }
                h[i] = x[i];
            }
        }
    }
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    string beginWord,endWord;

    cin >> beginWord >> endWord;

    int n;
    cin >> n;
    vector<string> wordList;

    rp(i,0,n){
        string x;
        cin >> x;
        wordList.pb(x);
    }

    map<string, int> levels;
        levels[beginWord] = 0;

        queue<string> bfs;
        set<string> all;
        for(auto i : wordList){
            all.insert(i);
        }

        bfs.push(beginWord);

        while(!bfs.empty()){
            string x = bfs.front();
            int y = levels[x];
            string h = x;
            bfs.pop();
            for(int i = 0; i < x.size(); i++){
                for(int j = 0;  j < 26; j++){
                    h[i] = char(j+'a');
                    // cout << h << "\n";
                    if(all.count(h) && (!levels.count(h) || levels[h] > 1 + y)){
                        levels[h] = 1 + y;
                        bfs.push(h);
                    }
                    h[i] = x[i];
                }
            }
        }

        ans1.push_back(endWord);
        solve(endWord,levels,beginWord);
        ans1.pop_back();

        for(auto &i : ans){
            reverse(i.begin(),i.end());
        }

        for(auto i : ans){
            for(auto j : i){
                cout << j << " ";
            }
            cout << "\n";
        }

    return 0;}