#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int, int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);
#define HARPREET cout.tie(0);
int M = 1000000007;
using namespace std;

int parent[30];
int sizes[30];

void make(int v)
{
    parent[v] = v;
}

int find(int v)
{
    if (parent[v] == v)
        return v;
    else
        return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
    int x = find(a), y = find(b);
    if (sizes[x] > sizes[y])
        swap(x, y);
    parent[x] = y;
    sizes[y] += sizes[x];
}

signed main()
{
    CODE BY HARPREET

        int t;
    cin >> t;

    while (t--)
    {

        map<char, char> convert;
        int used[26] = {0};

        for (char i = 'a'; i <= 'z'; i++)
        {
            convert[i] = '1';
            parent[int(i - 'a')] = int(i - 'a');
            sizes[int(i - 'a')] = 1;
        }
        ll n;
        cin >> n;
        string a;
        cin >> a;

        for (int i = 0; i < n; i++)
        {
            if (convert[a[i]] == '1')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (used[j] == 0 && find(j) != find(int(a[i] - 'a')))
                    {
                            used[j] = 1;
                            convert[a[i]] = char(j + 'a');
                            Union(j, int(a[i] - 'a'));
                            break;
                    }
                }
            }
        }

        char closer = 'z';

        for(int i = 0; i < 26; i++){
            if(used[i]==0){closer = char(i+'a');break;}
        }

        string ans = "";

        for(int i = 0; i < n; i++){
            if(convert[a[i]]=='1')convert[a[i]] = closer;
            ans.push_back(convert[a[i]]);
        }
    cout << ans << "\n";
    }


    return 0;
}