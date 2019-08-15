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
    while(1){
        int N, M; cin>>N>>M;
        if(N == 0) return 0;

        vector<vector<bool>> use(M+10, vector<bool>(1300, false));
        vector<int> cnt(M+10, 0);
        vector<int> startTime(M+10, -1);
        int r; cin>>r;
        while(r--){
            int t, n, m, s; cin>>t>>n>>m>>s;
            if(s == 1){
                cnt[m]++;
                if(cnt[m] == 1){
                    startTime[m] = t;
                }
            }
            else{
                cnt[m]--;
            }

            if(cnt[m] == 0){
                int endTime = t;
                for(int i=startTime[m]; i<endTime; i++){
                    use[m][i] = true;
                }
            }
        }

        int q; cin>>q;
        while(q--){
            int s, t, m; cin>>s>>t>>m;
            int ans=0;
            for(int i=s; i<t; i++){
                if(use[m][i]) ans++;
            }

            cout << ans << endl;
        }
    }
}