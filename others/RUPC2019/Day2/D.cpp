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

int dx[]={1, -1, 0, 0, 1, 1, -1, -1};
int dy[]={0, 0, 1, -1, 1, -1, -1, 1};

double calc(int lh, int rh, int h){
    double LH=abs(h-lh), RH=abs(h-rh);
    double S;
    
    // tow triangles
    if((h-lh>0 && h-rh<0) || (h-lh<0 && h-rh>0)){
        S=(LH/(LH+RH))*LH/2+(RH/(LH+RH))*RH/2;
    }
    else{
        S=(LH+RH)/2;
    }

    return S;
}

int main(){
    int n; cin>>n;
    vector<int> h(n);
    for(int i=0; i<n; i++) cin>>h[i];

    vector<vector<double>> dp(n+10, vector<double>(310, INF));
    for(int i=0; i<=300; i++){
        dp[1][i]=calc(1, i, h[0]);
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<300; j++){ // left height
            for(int k=1; k<300; k++){ // right height
                dp[i+1][k]=min(dp[i+1][k], dp[i][j]+calc(j, k, h[i]));
            }
        }
    }

    double ans=INF;
    for(int i=1; i<300; i++){
        chmin(ans, dp[n][i]);
    }

    cout << fixed << setprecision(10) << ans << endl;
}