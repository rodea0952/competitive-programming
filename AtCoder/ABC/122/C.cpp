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
    int n, q; cin>>n>>q;
    string s; cin>>s;

    vector<int> sum(n+10, 0);
    for(int i=0; i<n; i++){
        if(i+1 < n && s[i] == 'A' && s[i+1] == 'C'){
            sum[i+1] = sum[i];
            sum[i+2] = sum[i+1] + 1;
            i++;
        }
        else sum[i+1] = sum[i];
    }

    while(q--){
        int a, b; cin>>a>>b;
        cout << sum[b] - sum[a] << endl;
    }
}