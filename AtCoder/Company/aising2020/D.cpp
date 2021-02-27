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

ll modpow(ll a, ll b, int m){
    if(b == 0) return 1;
    else if(b % 2 == 0){
        ll d = modpow(a, b / 2, m);
        return d * d % m;
    }
    else{
        return a * modpow(a, b - 1, m) % m;
    }
}

ll f(ll x){
    ll cur = x;
    int cnt = 0;
    while(x > 0){
        cnt += x % 2;
        x /= 2;
    }
    return cur % cnt;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    string x; cin>>x;

    int cnt = count(all(x), '1');

    if(cnt == 0){
        for(int i=0; i<n; i++) cout << 1 << endl;
        return 0;
    }
    
    if(cnt == 1){
        if(x.back() == '1'){
            for(int i=0; i+1<n; i++) cout << 2 << endl;
            cout << 0 << endl;
        }
        else{
            for(int i=0; i+1<n; i++){
                if(x[i] == '1') cout << 0 << endl;
                else cout << 1 << endl;
            }
            cout << 2 << endl;
        }
        return 0;
    }


    ll sum01 = 0, sum10 = 0;
    for(auto i : x){
        sum01 *= 2;
        sum01 %= (cnt + 1);
        sum01 += i - '0';

        sum10 *= 2;
        sum10 %= (cnt - 1);
        sum10 += i - '0';
    }

    for(int i=0; i<n; i++){
        int ans = 1;
        ll csum01 = sum01, csum10 = sum10;
        if(x[i] == '0'){
            csum01 += modpow(2, n - 1 - i, cnt + 1);
            csum01 %= (cnt + 1);
            while(csum01 > 0){
                ans++;
                csum01 = f(csum01);
            }
        }
        else{
            csum10 -= modpow(2, n - 1 - i, cnt - 1);
            csum10 += (cnt - 1);
            csum10 %= (cnt - 1);
            while(csum10 > 0){
                ans++;
                csum10 = f(csum10);
            }
        }

        cout << ans << endl;
    }

    return 0;
}