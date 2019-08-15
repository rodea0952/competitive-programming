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
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    int need=0;

    bool ldp[n+1][k+1];
    memset(ldp, 0, sizeof(ldp));
    ldp[0][0] = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<=k; j++){
            if(j - a[i] >= 0) ldp[i+1][j] |= ldp[i][j-a[i]];
            ldp[i+1][j] |= ldp[i][j];
        }
    }

    bool rdp[n+1][k+1];
    memset(rdp, 0, sizeof(rdp));
    rdp[0][0] = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<=k; j++){
            if(j - a[(n-1)-i] >= 0) rdp[i+1][j] |= rdp[i][j-a[(n-1)-i]];
            rdp[i+1][j] |= rdp[i][j];
        }
    }

    for(int i=0; i<n; i++){

        vector<int> l, r;
        for(int j=0; j<=k; j++){
            if(ldp[i][j]) l.eb(j);
            if(rdp[n-1-i][j]) r.eb(j);
        }

        for(int j=0; j<l.size(); j++){
            if(lower_bound(r.begin(), r.end(), k-l[j]) - lower_bound(r.begin(), r.end(), k-a[i]-l[j])){
                need++;
                break;
            }
        }
    }

    cout << n - need << endl;
}