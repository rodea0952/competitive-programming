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
    vector<vector<int>> v(m);
    for(int i=0; i<m; i++){
        int k; cin>>k;
        for(int j=0; j<k; j++){
            int s; cin>>s;
            s--;
            v[i].eb(s);
        }
    }

    vector<int> p(m);
    for(int i=0; i<m; i++) cin>>p[i];

    int sum = 0;
    for(int bit=0; bit<(1<<n); bit++){
        vector<int> num;
        for(int i=0; i<n; i++){
            if((1 << i) & bit){
                num.eb(i);
            }
        }

        int ans = 0;
        for(int i=0; i<m; i++){
            int cnt = 0;
            for(int j=0; j<num.size(); j++){
                for(int k=0; k<v[i].size(); k++){
                    if(num[j] == v[i][k]){
                        cnt++;
                        break;
                    }
                }
            }

            if(cnt % 2 == p[i]){
                ans++;
            }
        }

        if(ans == m){
            sum++;
        }
    }

    cout << sum << endl;
}
