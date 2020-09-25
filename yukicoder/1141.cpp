#pragma GCC optimize("O3")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

ll modpow(ll a, ll b){
    if(b == 0) return 1;
    else if(b % 2 == 0){
        ll d = modpow(a, b / 2) % MOD;
        return (d * d) % MOD;
    }
    else{
        return (a * modpow(a, b - 1)) % MOD;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w; cin>>h>>w;
    vector<vector<ll>> a(h, vector<ll>(w));
    int zcnt = 0;
    ll allsum = 1;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>a[i][j];
            if(a[i][j] == 0){
                zcnt++;
            }
            else{
                allsum *= a[i][j];
                allsum %= MOD;
            }
        }
    }

    if(zcnt == 0){
        vector<ll> hsum(h, 1), wsum(w, 1);
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                hsum[i] *= a[i][j];
                hsum[i] %= MOD;
            }
        }

        for(int i=0; i<w; i++){
            for(int j=0; j<h; j++){
                wsum[i] *= a[j][i];
                wsum[i] %= MOD;
            }
        }

        int q; cin>>q;
        while(q--){
            int r, c; cin>>r>>c;
            r--, c--;

            ll ans = allsum;
            ans *= modpow(hsum[r], MOD - 2);
            ans %= MOD;
            ans *= modpow(wsum[c], MOD - 2);
            ans %= MOD;
            ans *= a[r][c];

            cout << ans % MOD << endl;
        }
    }
    else{
        vector<ll> hsum(h, 1), wsum(w, 1);
        vector<int> hzcnt(h, 0), wzcnt(w, 0);
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(a[i][j] == 0){
                    hzcnt[i]++;
                }
                else{
                    hsum[i] *= a[i][j];
                    hsum[i] %= MOD;
                }
            }
        }

        for(int i=0; i<w; i++){
            for(int j=0; j<h; j++){
                if(a[j][i] == 0){
                    wzcnt[i]++;
                }
                else{
                    wsum[i] *= a[j][i];
                    wsum[i] %= MOD;
                }
            }
        }

        int q; cin>>q;
        while(q--){
            int r, c; cin>>r>>c;
            r--, c--;

            int czcnt = zcnt;
            czcnt -= hzcnt[r];
            czcnt -= wzcnt[c];
            if(a[r][c] == 0) czcnt++;

            if(czcnt == 0){
                ll ans = allsum;
                ans *= modpow(hsum[r], MOD - 2);
                ans %= MOD;
                ans *= modpow(wsum[c], MOD - 2);
                ans %= MOD;
                if(a[r][c] != 0){
                    ans *= a[r][c];
                }

                cout << ans % MOD << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }

    return 0;
}