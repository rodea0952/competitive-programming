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
    int a[n][n-1];
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            cin>>a[i][j];
            a[i][j]--;
        }
    }

    vector<int> index(n, 0);
    int ans = 0;
    queue<int> que;
    for(int i=0; i<n; i++){
        que.emplace(i);
    }

    map<P, int> match;
    bool end = false;
    while(!end){
        ans++;
        vector<P> candi;
        while(que.size()){
            int h = que.front(); que.pop();
            P fight = make_pair(min(h, a[h][index[h]]), max(h, a[h][index[h]]));
            match[fight]++;
            if(match[fight] == 2){
                candi.emplace_back(fight);
            }
        }

        bool is_exist = false;
        for(int i=0; i<(int)candi.size(); i++){
            is_exist = true;
            index[candi[i].first]++;
            index[candi[i].second]++;
            match.erase(P(candi[i].first, candi[i].second));
            if(index[candi[i].first] != n - 1) que.emplace(candi[i].first);
            if(index[candi[i].second] != n - 1) que.emplace(candi[i].second);
        }

        if(!is_exist){
            cout << -1 << endl;
            return 0;
        }

        bool valid = true;
        for(int i=0; i<n; i++){
            if(index[i] != n - 1) valid = false;
        }

        if(valid) end = true;

        if(end) break;
    }

    cout << ans << endl;
}
