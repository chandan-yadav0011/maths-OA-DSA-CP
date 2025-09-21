#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100000;
const int MOD = 1e9 +7;


ll fact[MAXN+1], ifact[MAXN+1];

// Function to compute (base^exp) % MOD using Binary Exponentiation
ll power(ll base, ll exp)
{
    ll result =1;

    while(exp>0)
    {
        if(exp%2==1) result = (result*base)% MOD;

        base = (base*base)% MOD;
        exp = exp/2;
    }

    return result;
}


int main()
{
    ll a = 5, b=3;
    ll ans = power(a,b);
    cout<<ans<<endl;

}