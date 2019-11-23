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

int dx[] = {1, 0, 1};
int dy[] = {0, 1, 1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w; cin>>h>>w;
    vector<string> s(h);
    for(int i=0; i<h; i++) cin>>s[i];

    for(int i=h-1; i>=0; i--){
        for(int j=w-1; j>=0; j--){
            if(s[i][j] == '#') continue;

            bool existL = false;
            for(int k=0; k<3; k++){
                int ny = i + dy[k], nx = j + dx[k];
                if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
                if(s[ny][nx] == 'L') existL = true;
            }

            if(existL) s[i][j] = 'W';
            else s[i][j] = 'L';
        }
    }

    cout << (s[0][0] == 'W' ? "First" : "Second") << endl;

    return 0;
}