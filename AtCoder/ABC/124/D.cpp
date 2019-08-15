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

int main(){
    int n, k; cin>>n>>k;
    string s; cin>>s;

    vector<int> cnt;
    for(int i=0; i<n; i++){
        int num=1;
        while(i + 1 < n && s[i] == s[i+1]){
            num++;
            i++;
        }

        cnt.eb(num);
    }

    int m=cnt.size();
    vector<int> sum(m+10, 0);
    for(int i=0; i<m; i++){
        sum[i+1] = sum[i] + cnt[i];
    }

    int ans=0;
    for(int i=(s[0]=='0'?1:0); i<=m; i+=2){
        int ub = sum[min(i+k*2-1, m)];
        int lb = sum[max(i-2, 0)];

        chmax(ans, ub - lb);
    }

    cout << ans << endl;
}