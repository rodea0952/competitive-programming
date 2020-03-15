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

    vector<string> s(3);
    vector<vector<int>> alp(3, vector<int>(26, 0));
    for(int i=0; i<3; i++){
        cin>>s[i];
        for(auto j:s[i]){
            alp[i][j - 'A']++;
        }
    }

    for(int i=0; i<26; i++){
        for(int j=0; j<2; j++){
            chmin(alp[j][i], alp[2][i]);
        }
    }

    int sum1 = 0, sum2 = 0;
    for(int i=0; i<26; i++){
        sum1 += alp[0][i];
        sum2 += alp[1][i];
    }

    int n = s[0].size() / 2;
    if(n <= sum1 && n <= sum2) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}