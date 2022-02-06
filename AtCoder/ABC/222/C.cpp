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

    int n, m; cin >> n >> m;
    vector<string> a(2*n);
    for(int i=0; i<2*n; i++) cin >> a[i];

    vector<int> win(2*n, 0);
    vector<int> rank(2*n);
    iota(all(rank), 0);

    auto judge = [](char f, char s){
        if(f == 'G') return s == 'C';
        if(f == 'C') return s == 'P';
        if(f == 'P') return s == 'G';
    };

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int f = rank[j*2], s = rank[j*2+1];
            win[f] += judge(a[f][i], a[s][i]);
            win[s] += judge(a[s][i], a[f][i]);
        }

        sort(all(rank), [&](int f, int s){
            if(win[f] != win[s]) return win[f] > win[s];
            else return f < s;
        });
    }

    for(int i=0; i<2*n; i++){
        cout << rank[i] + 1 << endl;
    }

    return 0;
}