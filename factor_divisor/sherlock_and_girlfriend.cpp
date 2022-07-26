/*
Sherlock and his girlfriend

Sherlock has a new girlfriend (so unlike him!). Valentine's day is coming and he wants to gift her some jewelry.

He bought n pieces of jewelry. The i-th piece has price equal to i + 1, that is, the prices of the jewelry are 2, 3, 4, ... n + 1.

Watson gave Sherlock a challenge to color these jewelry pieces such that two pieces don't have the same color if the price of one piece is a prime divisor of the price of the other piece. Also, Watson asked him to minimize the number of different colors used.

Help Sherlock complete this trivial task.

Input
The only line contains single integer n (1 ≤ n ≤ 100000) — the number of jewelry pieces.

Output
The first line of output should contain a single integer k, the minimum number of colors that can be used to color the pieces of jewelry with the given constraints.

The next line should consist of n space-separated integers (between 1 and k) that specify the color of each piece in the order of increasing price.

If there are multiple ways to color the pieces using k colors, you can output any of them.

Examples
inputCopy
3
outputCopy
2
1 1 2 
inputCopy
4
outputCopy
2
2 1 1 2
Note
In the first input, the colors for first, second and third pieces of jewelry having respective prices 2, 3 and 4 are 1, 1 and 2 respectively.

In this case, as 2 is a prime divisor of 4, colors of jewelry having prices 2 and 4 must be distinct.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 1000000007;
using namespace std;

deq prime;
deque<bool> d(100001,true);

void sieve_algorithm(int n){
    d[0] = false;
    d[1] = false;
    for(int i = 2; i<=n;i++){
        if(d[i]){
            prime.push_back(i);
            for(int j = 2*i; j<=n; j+=i){
                d[j] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    if(n==1){
        cout<<"1\n1\n";
    }
    else if(n==2){
        cout<<"1\n1 1\n";
    }
    else{
        sieve_algorithm(n+1);
        cout<<"2\n";
        for(int i = 2; i<=(n+1);i++){
            d[i] ? cout<<"2 ":cout<<"1 ";
        }
    }

    return 0;}