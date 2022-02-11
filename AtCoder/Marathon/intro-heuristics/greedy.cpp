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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int d; cin >> d;
    vector<ll> c(26);
    vector<vector<ll>> s(d, vector<ll>(26));
    for(int i=0; i<26; i++) cin >> c[i];
    for(int i=0; i<d; i++){
        for(int j=0; j<26; j++) cin >> s[i][j];
    }

    ll score = 0;
    vector<ll> lst(26, -1);
    for(int i=0; i<d; i++){
        int ma = -inf, contest = -1;
        for(int j=0; j<26; j++){
            ll cscore = 0, plst = lst[j];
            cscore += s[i][j];
            lst[j] = i;
            for(int k=0; k<26; k++){
                cscore -= c[k] * (i - lst[k]);
            }
            if(ma < cscore){
                ma = cscore;
                contest = j;
            }
            lst[j] = plst;
        }

        score += s[i][contest];
        lst[contest] = i;
        for(int j=0; j<26; j++){
            score -= c[j] * (i - lst[j]);
        }
        cout << contest + 1 << endl;
    }

    return 0;
}