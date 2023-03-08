#include <bits/stdc++.h>
using namespace std;

int fenwick[200007];

int num_of_digits(int n)
{
    int ans = 0;
    while (n > 0)
    {
        ans++;
        n /= 10;
    }
    return ans;
}

void update(int n, int x)
{
    for (int i = n; i <= 200005; i += (i & (-i)))
    {
        fenwick[i] += x;
    }
}

int sum(int n)
{
    int s = 0;
    for (int i = n; i > 0; i -= (i & (-i)))
    {
        s += fenwick[i];
    }
    return s;
}

int main()
{

    int t = 1;
    cin >> t;

    while (t--)
    {

        int n, q;
        cin >> n >> q;
        int aarray[n + 1];

        for (int i = 0; i <= n; i++)
        {
            fenwick[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            cin >> aarray[i];
        }

        while (q--)
        {

            int x;
            cin >> x;
            if (x == 1)
            {
                int l, r;
                cin >> l >> r;
                update(l, 1);
                update(r + 1, -1);
            }
            else if (x == 2)
            {
                int l;
                cin >> l;
                int r = sum(l);
                int num = aarray[l], x = 0;

                while (x < r && num_of_digits(num) > 1)
                {
                    int z = 0, y = num;
                    while (y > 0)
                    {
                        z += (y % 10);
                        y /= 10;
                    }
                    x++;
                    num = z;
                }

                cout << num << "\n";
            }
        }
    }

    return 0;
}