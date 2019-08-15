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
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

vector<vector<ll>> mul(vector<vector<ll>> &A, vector<vector<ll>> &B){
    vector<vector<ll>> C(A.size(), vector<ll>(B.size()));

    for(int i=0; i<A.size(); i++){
        for(int k=0; k<B.size(); k++){
            for(int j=0; j<B[0].size(); j++){
                C[i][j] += (A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    
    return C;
}

vector<vector<ll>> pow(vector<vector<ll>> A, ll n){
    vector<vector<ll>> B(A.size(), vector<ll>(A.size()));

    for(int i=0; i<A.size(); i++){
        B[i][i] = 1;
    }

    while(n > 0){
        if(n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }

    return B;
}

int main(){
    ll n; cin>>n;
    vector<vector<ll>> A(3, vector<ll>(3));
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 2; A[1][1] = 1; A[1][2] = 3;
    A[2][0] = 1; A[2][1] = 1; A[2][2] = 2;
    A = pow(A, n);

    cout << (A[0][0] + A[1][0] + A[2][0]) * 2LL % MOD << endl;
}
