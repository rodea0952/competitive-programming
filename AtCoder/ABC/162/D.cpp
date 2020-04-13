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

    int n; cin>>n;
    string s; cin>>s;

    vector<int> rsum(n+1, 0), gsum(n+1, 0), bsum(n+1, 0);
    for(int i=0; i<n; i++){
        rsum[i+1] = rsum[i];
        gsum[i+1] = gsum[i];
        bsum[i+1] = bsum[i];
        if(s[i] == 'R') rsum[i+1]++;
        if(s[i] == 'G') gsum[i+1]++;
        if(s[i] == 'B') bsum[i+1]++;
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+2; j<n; j++){
            if((s[i] == 'G' && s[j] == 'B') || (s[i] == 'B' && s[j] == 'G')){
                ll rcur = rsum[j+1] - rsum[i];
                if((j - i) % 2 == 0){
                    if(s[(j+i)/2] == 'R') rcur--;
                }
                ans += rcur;
            }

            if((s[i] == 'R' && s[j] == 'B') || (s[i] == 'B' && s[j] == 'R')){
                ll gcur = gsum[j+1] - gsum[i];
                if((j - i) % 2 == 0){
                    if(s[(j+i)/2] == 'G') gcur--;
                }
                ans += gcur;
            }

            if((s[i] == 'R' && s[j] == 'G') || (s[i] == 'G' && s[j] == 'R')){
                ll bcur = bsum[j+1] - bsum[i];
                if((j - i) % 2 == 0){
                    if(s[(j+i)/2] == 'B') bcur--;
                }
                ans += bcur;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
