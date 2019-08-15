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
    int n, m; cin>>n>>m;
    int a[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            a[i][j]--;
        }
    }

    int ans=1000;
    vector<bool> used(m, false);

    for(int k=0; k<m; k++){
        vector<int> cnt(m, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!used[a[i][j]]){
                    cnt[a[i][j]]++;
                    break;
                }
            }
        }

        int maxid = max_element(cnt.begin(), cnt.end()) - cnt.begin();

        used[maxid] = true;
        chmin(ans, cnt[maxid]);
    }

    cout << ans << endl;
}