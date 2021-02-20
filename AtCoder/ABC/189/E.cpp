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

vector<vector<ll>> mul(vector<vector<ll>> &A, vector<vector<ll>> &B){
    vector<vector<ll>> C(A.size(), vector<ll>(B.size(), 0LL));

    for(int i=0; i<A.size(); i++){
        for(int k=0; k<B.size(); k++){
            for(int j=0; j<B[0].size(); j++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    return C;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> x(n), y(n);
    for(int i=0; i<n; i++) cin>>x[i]>>y[i];

    int m; cin>>m;
    vector<vector<vector<ll>>> mat(m + 1);
    mat[0] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    for(int i=0; i<m; i++){
        int op; cin>>op;
        if(op == 1){
            mat[i + 1] = {
                {0, 1, 0},
                {-1, 0, 0},
                {0, 0, 1}
            };
        }
        else if(op == 2){
            mat[i + 1] = {
                {0, -1, 0},
                {1, 0, 0},
                {0, 0, 1}
            };
        }
        else if(op == 3){
            ll p; cin>>p;
            mat[i + 1] = {
                {-1, 0, 2 * p},
                {0, 1, 0},
                {0, 0, 1}
            };
        }
        else{
            ll p; cin>>p;
            mat[i + 1] = {
                {1, 0, 0},
                {0, -1, 2 * p},
                {0, 0, 1}
            };
        }
    }

    for(int i=0; i<m; i++){
        mat[i + 1] = mul(mat[i + 1], mat[i]);
    }

    int q; cin>>q;
    while(q--){
        int a, b; cin>>a>>b; b--;
        vector<vector<ll>> cur = {
            {x[b]},
            {y[b]},
            {1}
        };
        cur = mul(mat[a], cur);
        cout << cur[0][0] << " " << cur[1][0] << endl;
    }

    return 0;
}