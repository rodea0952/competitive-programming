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

double comb(int n, int r){
    double u = 1, d = 1;
    for(int i=0; i<r; i++) u *= (n - i);
    for(int i=1; i<=r; i++) d *= i;
    return u / d;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, l; cin>>n>>m>>l;
    vector<double> p(n), t(n), v(n);
    for(int i=0; i<n; i++) cin>>p[i]>>t[i]>>v[i];

    vector<vector<double>> proba(n, vector<double>(m+1));
    for(int i=0; i<n; i++){
        for(int j=0; j<=m; j++){
            proba[i][j] = pow(1. * p[i] / 100, j) * pow(1 - 1. * p[i] / 100, m - j) * comb(m, j);
        }
    }

    for(int i=0; i<n; i++){
        double ans = 0;
        for(int j=0; j<=m; j++){
            double ctime = 1. * l / v[i] + t[i] * j;
            double sum = 1;
            for(int ii=0; ii<n; ii++){
                if(i == ii) continue;
                double proba_sum = 0;
                for(int jj=0; jj<=m; jj++){
                    double ntime = 1. * l / v[ii] + t[ii] * jj;
                    if(ctime < ntime){
                        proba_sum += proba[ii][jj];
                    }
                }
                
                sum *= proba_sum;
            }

            ans += sum * proba[i][j];
        }

        printf("%.10f\n", ans);
    }

    return 0;
}