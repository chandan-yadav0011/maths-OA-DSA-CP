#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100000;
const int MOD = 1e9 +7;

// function for binary exponentiation
ll power(ll base, ll exp)
{   
    ll result =1;

    while(exp>0)
    {
        if(exp%2==1) result= (result*base)% MOD;
        
        base = (base*base)% MOD;
        exp = exp/2;
    }

    return result;
}

// Precompute Factorial and Inverse Factorial
ll fact[MAXN + 1], ifact[MAXN + 1];

void precompute()
{
    fact[0] =1;
    ifact[0] = 1; 

    for(int i=1; i<=MAXN ; i++)
    {
        fact[i]= (fact[i-1]*i)% MOD;
    }

    ifact[MAXN] = power(fact[MAXN], MOD -2);

    for(int i=MAXN-1; i>=1; i--)
    {
        ifact[i]= (ifact[i+1]*(i+1))% MOD;
    }

}

// Compute nCr
ll nCr(ll n, ll r)
{
    if(r>n ||r<0) return 0;
    return (fact[n]*ifact[r]% MOD) *ifact[n-r]% MOD;
}

int main()
{
    precompute();
    
    int t, n,r;
    cin>>t;

    while(t--)
    {
        cin>>n>>r;
        cout<<nCr(n,r)<<endl;
    }
}

