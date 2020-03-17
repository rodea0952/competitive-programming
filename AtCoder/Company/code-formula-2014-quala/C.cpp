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

    int n, k; cin>>n>>k;
    vector<vector<int>> a(n, vector<int>(k));
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++) cin>>a[i][j];
    }

    int rest = k;
    vector<int> rank(n*k, 0);
    vector<bool> passed(1000000, false);
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            rank[j * n + i] = a[i][j];
        }

        vector<int> ans;
        int cnt = 0;
        for(int j=0; j<n*k; j++){
            if(passed[rank[j]]) continue;
            if(++cnt > rest) break;
            if(rank[j] > 0){
                passed[rank[j]] = true;
                ans.emplace_back(rank[j]);
            }
        }

        sort(all(ans));
        for(int j=0; j<ans.size(); j++){
            if(j != ans.size() - 1) cout << ans[j] << " ";
            else cout << ans[j];
        }
        cout << endl;

        rest -= ans.size();
    }

    return 0;
}