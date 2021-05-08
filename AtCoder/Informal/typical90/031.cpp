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

vector<vector<int>> grundy(60, vector<int>(1600));

void init(){
    for(int i=0; i<=50; i++){
        for(int j=0; j<=1500; j++){
            vector<bool> mex(1555, false);
            // 1 手で行ける全ての状態を見る
            if(1 <= i){
                mex[grundy[i - 1][j + i]] = true;
            }
            if(2 <= j){
                for(int k=1; k<=j/2; k++){
                    mex[grundy[i][j - k]] = true;
                }
            }

            for(int k=0; k<1555; k++){
                if(mex[k] == false){
                    grundy[i][j] = k;
                    break;
                }
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    init();

    int sum_xor = 0;
    for(int i=0; i<n; i++){
        sum_xor ^= grundy[a[i]][b[i]];
    }

    cout << (sum_xor == 0 ? "Second" : "First") << endl;

    return 0;
}