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
    vector<bool> exist(n, false);
    bool zero = false;
    for(int i=0; i<k; i++){
        int a; cin>>a;
        if(a == 0) zero = true;
        else exist[--a] = true;
    }

    int ans = 0;
    if(!zero){
        for(int i=0; i<n; i++){
            int cnt = 0;
            while(i < n && exist[i]){
                cnt++;
                i++;
            }
            chmax(ans, cnt);
        }
    }
    else{
        for(int i=0; i<n; i++){
            if(exist[i]) continue;

            int cnt = 1;
            for(int j=i+1; j<n; j++){
                if(!exist[j]) break;
                cnt++;
            }
            for(int j=i-1; j>=0; j--){
                if(!exist[j]) break;
                cnt++;
            }
            chmax(ans, cnt);
        }
    }

    cout << ans << endl;

    return 0;
}