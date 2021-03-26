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
    vector<int> p(n);
    for(int i=0; i<n; i++) cin>>p[i], p[i]--;

    vector<bool> visited(n, false);
    int cv = 0, cnt = 0, turn = 0;
    while(!visited[cv]){
        cnt++;
        visited[cv] = true;
        if(cv > p[cv] && cv == n - 1) turn++;
        cv = p[cv];
    }

    if(cnt != n || turn != 1){
        cout << -1 << endl;
        return 0;
    }

    queue<int> que;
    for(int i=0; i+1<n; i++){
        if(p[i] > p[i + 1]) que.emplace(i);
    }

    while(que.size()){
        int idx = que.front(); que.pop();
        cout << idx + 1 << endl;
        swap(p[idx], p[idx + 1]);
        if(0 <= idx - 1 && p[idx - 1] > p[idx]) que.emplace(idx - 1);
        if(idx + 2 < n && p[idx + 1] > p[idx + 2]) que.emplace(idx + 1);
    }

    return 0;
}