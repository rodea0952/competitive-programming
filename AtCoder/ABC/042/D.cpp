#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

ll factorial[300000];

ll mod_pow(ll a, ll b){
    if(b == 0) return 1;
    else if(b % 2 == 0){
        ll d = mod_pow(a, b/2) % MOD;
        return (d * d) % MOD;
    }
    else{
        return (a * mod_pow(a, b-1)) % MOD;
    }
}

void calc(){
    factorial[0]=1;
    for(int i=1; i<=250000; i++){
        factorial[i] = factorial[i-1]*i;
        factorial[i] %= MOD;
    }
}

int main(){
    int h, w; cin>>h>>w;
    int a, b; cin>>a>>b;

    calc();

    ll sum=0;
    for(int i=0; i<h-a; i++){
        ll ans=1;
        ans *= factorial[i+b-1];
        ans %= MOD;
        ans *= mod_pow(factorial[i], MOD-2);
        ans %= MOD;
        ans *= mod_pow(factorial[b-1], MOD-2);
        ans %= MOD;
        ans *= factorial[h-i+w-b-2];
        ans %= MOD;
        ans *= mod_pow(factorial[w-b-1], MOD-2);
        ans %= MOD;
        ans *= mod_pow(factorial[h-i-1], MOD-2);
        ans %= MOD;
        sum += ans;
        sum %= MOD;
    }
    cout << sum << endl;
}