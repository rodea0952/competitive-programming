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
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, k; cin>>n>>k;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<ll> m, p;
    for(int i=0; i<n; i++){
        if(a[i] < 0) m.emplace_back(a[i]);
        else if(a[i] > 0) p.emplace_back(a[i]);
    }

    sort(m.begin(), m.end());
    sort(p.begin(), p.end());

    ll msz = m.size(), psz = p.size();
    ll zero = n - msz - psz;

    ll mcnt = msz * psz;

    if(k <= mcnt){
        // k 番目の数がマイナス
        // (ng, ok]
        ll ng = -INF - 1, ok = -1;
        while(ok - ng > 1){
            ll mid = (ng + ok) / 2;
            ll sum = 0;
            int l = 0;
            for(int r=0; r<psz; r++){
                while(l < msz && m[l] * p[r] <= mid) l++;
                sum += l;
            }

            if(sum < k) ng = mid;
            else ok = mid;
        }

        cout << ok << endl;
        return 0;
    }

    k -= mcnt;
    ll zerocnt = 0;
    for(int i=0; i<zero; i++){
        zerocnt += (n - (i + 1));
    }

    if(k <= zerocnt){
        // k 番目の数が 0
        cout << 0 << endl;
        return 0;
    }

    k -= zerocnt;

    for(int i=0; i<msz; i++) m[i] = -m[i];
    sort(m.begin(), m.end());

    // k 番目の数がプラス
    // (ng, ok]
    ll ng = 0, ok = INF;
    while(ok - ng > 1){
        ll mid = (ng + ok) / 2;
        ll sum = 0;
        for(int i=0; i<psz; i++){
            ll target = mid / p[i];
            ll cnt = (upper_bound(p.begin(), p.end(), target) - p.begin()) - (i + 1);
            sum += max(0LL, cnt);
        }

        for(int i=0; i<msz; i++){
            ll target = mid / m[i];
            ll cnt = (upper_bound(m.begin(), m.end(), target) - m.begin()) - (i + 1);
            sum += max(0LL, cnt);
        }

        if(sum < k) ng = mid;
        else ok = mid;
    }

    cout << ok << endl;

    return 0;
}