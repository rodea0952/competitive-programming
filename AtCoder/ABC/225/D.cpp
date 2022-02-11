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

    int n, q; cin >> n >> q;
    vector<int> pre(n, -1), nxt(n, -1);
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int x, y; cin >> x >> y; x--, y--;
            nxt[x] = y, pre[y] = x;
        }
        else if(type == 2){
            int x, y; cin >> x >> y; x--, y--;
            nxt[x] = -1, pre[y] = -1;
        }
        else{
            int x; cin >> x; x--;
            while(pre[x] != -1){
                x = pre[x];
            }
            vector<int> ans;
            while(x != -1){
                ans.emplace_back(x);
                x = nxt[x];
            }
            cout << ans.size() << " ";
            for(int i=0; i<ans.size(); i++){
                cout << ans[i] + 1 << " \n"[i == ans.size()-1];
            }
        }
    }

    return 0;
}