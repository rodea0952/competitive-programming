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

    int n; cin>>n;
    ll k; cin>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i], a[i]--;

    vector<int> idx2idx(n);
    for(int i=0; i<n; i++) idx2idx[i] = a[i];

    vector<bool> visited(n, false);
    int cur = 0, cnt = 0;
    while(!visited[cur]){
        visited[cur] = true;
        cur = idx2idx[cur];
        cnt++;

        if(cnt == k){
            cout << cur + 1 << endl;
            return 0;
        }
    }

    k -= cnt;

    for(int i=0; i<n; i++) visited[i] = false;

    int turn = 0;
    while(!visited[cur]){
        visited[cur] = true;
        cur = idx2idx[cur];
        turn++;
    }

    k %= turn;

    for(int i=0; i<k; i++){
        cur = idx2idx[cur];
    }

    cout << cur + 1 << endl;

    return 0;
}