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

    int l; cin>>l;

    int N = 0;
    while(pow(2, N) <= l) N++;

    vector<T> edge;
    for(int i=1; i<N; i++){
        int u = i, v = i + 1;
        edge.emplace_back(u, v, pow(2, i - 1));
        edge.emplace_back(u, v, 0);
    }

    int base = pow(2, N - 1);
    for(int i=N-1; i>=1; i--){
        if(l - pow(2, i - 1) >= base){
            edge.emplace_back(i, N, l - pow(2, i - 1));
            l -= pow(2, i - 1);
        }
    }

    int M = edge.size();

    cout << N << " " << M << endl;
    for(auto i : edge){
        cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << endl;
    }

    return 0;
}