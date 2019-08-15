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
    int n; cin>>n;
    string s; cin>>s;

    bool valid = true;
    if(s[0] != 'R' || s[1] == 'B' || s[n-1] != 'B' || s[n-2] == 'R'){
        valid = false;
    }

    for(int i=0; i<n-1; i++){
        if(s[i] == 'R' && s[i+1] == 'B') valid = false;
        if(s[i] == 'G' && s[i+1] == 'G') valid = false;
    }

    if(valid) cout << "Yes" << endl;
    else cout << "No" << endl;
}