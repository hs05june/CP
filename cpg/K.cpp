#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
int M = 1000000007;
using namespace std;

deq primes;

void seive_algorithm(ll n){
    int is_prime[n+1] = {0};

    for(int i = 2; i <= n; i++){
        if(is_prime[i] == 0){
            primes.push_back(i);
            for(int j = 2*i; j <= n; j+=i){
                is_prime[j] = 1;
            }
        }
    }
}

set<int> x_prime;set<int> y_prime;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll x,y,k;
    cin >> x >> y >> k;

    seive_algorithm(k);

    ll ans = 1;
    ans = __gcd(x,y);
    ans = ans%M;

    for(int i = 0; i<primes.size(); i++){
        if(primes[i] > x && primes[i] > y)break;
        if((x%primes[i])==0)x_prime.insert(primes[i]);
        if((y%primes[i])==0)y_prime.insert(primes[i]); 
    }

    for(int i = 0; i<primes.size(); i++){
        if(!x_prime.count(primes[i]) || !y_prime.count(primes[i])){
            ans  = ((ans % M) * (primes[i]%M))%M;
        }
    }

    cout << (ans%M);

    return 0;}