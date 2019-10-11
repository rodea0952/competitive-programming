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

int dx[] = {1, -1};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, l; cin>>n>>l;
    vector<string> s(l+1);
    cin.ignore();
    for(int i=0; i<l+1; i++){
        getline(cin, s[i]);
    }

    for(int i=0; i<n; i++){
        int cx = i * 2;
        for(int j=0; j<l+1; j++){
            if(j == l){
                if(s[j][cx] == 'o'){
                    cout << i + 1 << endl;
                    return 0;
                }
                else break;
            }

            for(int k=0; k<2; k++){
                int nx = cx + dx[k];

                if(0 <= nx && nx < 2*n-1){
                    if(s[j][nx] == '-'){
                        cx += dx[k] * 2;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
