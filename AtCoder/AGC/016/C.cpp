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

    int H, W, h, w; cin>>H>>W>>h>>w;

    vector<vector<int>> a(H, vector<int>(W, -1000));
    if(H % h != 0){
        cout << "Yes" << endl;
        for(int i=0; i<H; i+=h){
            for(int j=0; j<W; j++){
                a[i][j] = 1000 * h - 1001;
            }
        }

        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cout << a[i][j] << " \n"[j == W-1];
            }
        }
    }
    else if(W % w != 0){
        cout << "Yes" << endl;
        for(int i=0; i<W; i+=w){
            for(int j=0; j<H; j++){
                a[j][i] = 1000 * w - 1001;
            }
        }

        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cout << a[i][j] << " \n"[j == W-1];
            }
        }
    }
    else{
        cout << "No" << endl;
    }
}