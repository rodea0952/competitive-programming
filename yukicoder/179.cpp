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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w; cin>>h>>w;
    vector<string> s(h);
    for(int i=0; i<h; i++) cin>>s[i];

    int cnt = 0;
    for(int i=0; i<h; i++){
        cnt += count(all(s[i]), '#');
    }

    if(cnt == 0){
        cout << "NO" << endl;
        return 0;
    }

    for(int dy=-h; dy<=h; dy++){
        for(int dx=-w; dx<=w; dx++){
            if(dy == 0 && dx == 0) continue;
            vector<vector<int>> color(h, vector<int>(w, 0));
            bool painted = true;
            for(int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                    if(s[i][j] == '#' && color[i][j] == 0){
                        bool valid = false;
                        int ny = i + dy, nx = j + dx;
                        if(0 <= ny && ny < h && 0 <= nx && nx < w && s[ny][nx] == '#' && color[ny][nx] == 0){
                            color[i][j] = 1;
                            color[ny][nx] = 2;
                            valid = true;
                        }

                        if(!valid) painted = false;
                    }
                }
            }

            if(painted){
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}