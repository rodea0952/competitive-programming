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
    string s, t; cin>>s>>t;
    int n = s.size(), m = t.size();
    vector<int> ssum(n+10, 0), tsum(m+10, 0);

    for(int i=0; i<n; i++){
        if(s[i] == 'A') ssum[i+1] = ssum[i] + 1;
        else ssum[i+1] = ssum[i] + 2;
    }
    
    for(int i=0; i<m; i++){
        if(t[i] == 'A') tsum[i+1] = tsum[i] + 1;
        else tsum[i+1] = tsum[i] + 2;
    }

    int q; cin>>q;
    while(q--){
        int a, b, c, d; cin>>a>>b>>c>>d;
        int snum = ssum[b] - ssum[a-1];
        int tnum = tsum[d] - tsum[c-1];

        if(snum % 3 == tnum % 3){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}