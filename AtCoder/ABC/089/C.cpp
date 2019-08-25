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

    int n; cin>>n;
    vector<ll> cnt(5, 0);
    for(int i=0; i<n; i++){
        string s; cin>>s;
        if(s[0] == 'M') cnt[0]++;
        if(s[0] == 'A') cnt[1]++;
        if(s[0] == 'R') cnt[2]++;
        if(s[0] == 'C') cnt[3]++;
        if(s[0] == 'H') cnt[4]++;
    }

    vector<int> v(5, 0);
    for(int i=2; i<5; i++) v[i] = 1;

    ll ans = 0;
    do{
        ll sum = 1;
        for(int i=0; i<5; i++){
            if(v[i]) sum *= cnt[i];
        }

        ans += sum;

    }while(next_permutation(v.begin(), v.end()));

    cout << ans << endl;
}