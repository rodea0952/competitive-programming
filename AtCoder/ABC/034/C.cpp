#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

ll MOD = 1e9 + 7;
ll INF = 1e18;

ll mod(ll a, ll b){
    if(b == 0) return 1;
    else if(b % 2 == 0){
        ll d = mod(a, b/2) % MOD;
        return (d * d) % MOD;
    }
    else{
        return (a * mod(a, b-1)) % MOD;
    }
}

int main() {
    ll w, h; cin>>w>>h;
    ll MIN = min(w, h);

    ll child=1, mother=1;
    for(ll i=0; i<MIN-1; i++){
        child *= (w+h-2-i);
        mother *= (MIN-1-i);
        child %= MOD;
        mother %= MOD;
    }
    cout << child * mod(mother, MOD-2) % MOD << endl;
}