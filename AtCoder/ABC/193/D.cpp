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

    int k; cin>>k;
    string s, t; cin>>s>>t;

    vector<int> rest(10, k);
    vector<int> tak(10, 0), aok(10, 0);
    for(int i=0; i<4; i++){
        rest[s[i] - '0']--, rest[t[i] - '0']--;
        tak[s[i] - '0']++, aok[t[i] - '0']++;
    }

    double ans = 0;
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            if(i == j && rest[i] < 2) continue;
            if(rest[i] < 1 || rest[j] < 1) continue;

            int tsum = 0;
            for(int l=1; l<=9; l++){
                int cur = l;
                for(int m=0; m<tak[l]; m++) cur *= 10;
                if(l == i) cur *= 10;
                tsum += cur;
            }

            int asum = 0;
            for(int l=1; l<=9; l++){
                int cur = l;
                for(int m=0; m<aok[l]; m++) cur *= 10;
                if(l == j) cur *= 10;
                asum += cur;
            }

            if(tsum > asum){
                ans += 1. * rest[i] * (rest[j] - (i == j)) / (9 * k - 8) / (9 * k - 9);
            }
        }
    }

    printf("%.10f\n", ans);

    return 0;
}