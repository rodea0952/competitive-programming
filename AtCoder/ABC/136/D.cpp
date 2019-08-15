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

    string s; cin>>s;
    int n = s.size();

    vector<int> ans(n, 0);
    for(int i=0; i<n-1; i++){
        int cntR = 0, cntL = 0;
        int idR;
        while(1){
            if((s[i] == 'L' && s[i+1] == 'R') || i == n - 1){
                cntL++;
                break;
            }
            if(s[i] == 'R' && s[i+1] == 'L'){
                idR = i;
            }

            cntR += (s[i] == 'R');
            cntL += (s[i] == 'L');
            i++;
        }

        int miR = cntR / 2;
        int maR = cntR - miR;
        int miL = cntL / 2;
        int maL = cntL - miL;

        ans[idR] = maR + miL;
        ans[idR+1] = miR + maL;
    }

    for(int i=0; i<n; i++){
        cout << ans[i] << " \n"[i==n-1];
    }
}