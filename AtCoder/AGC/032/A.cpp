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
    vector<int> b;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        b.eb(x);
    }

    vector<int> ans;
    for(int i=n-1; i>=0; i--){
        for(int j=b.size()-1; j>=0; j--){
            if(b[j] == j + 1){
                ans.eb(b[j]);
                b.erase(b.begin() + j);
                break;
            }
        }
    }

    if(ans.size() != n){
        cout << -1 << endl;
    }
    else{
        for(int i=n-1; i>=0; i--){
            cout << ans[i] << endl;
        }
    }
}