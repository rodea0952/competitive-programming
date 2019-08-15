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
int dx2[]={1, 1, 0, -1, -1, -1, 0, 1};
int dy2[]={0, -1, -1, -1, 0, 1, 1, 1};

int main(){
    int n; cin>>n;
    vector<int> c(n);
    for(int i=0; i<n; i++) cin>>c[i];

    vector<int> v;
    for(int i=0; i<n; i++){
        v.push_back(c[i]);
        while(i+1<n && c[i]==c[i+1]){
            i++;
        }
    }

    // dp[i] := i 番目まで操作したときの数列の場合の数
    vector<ll> dp(n+10, 0);
    vector<ll> dpsum(200010, 0);
    dp[0]=1;
    for(int i=0; i<v.size(); i++){
        dp[i+1]=dp[i]+dpsum[v[i]];
        dpsum[v[i]]+=dp[i];
        dp[i+1]%=MOD;
        dpsum[v[i]]%=MOD;
    }

    cout << dp[v.size()] << endl;
}
