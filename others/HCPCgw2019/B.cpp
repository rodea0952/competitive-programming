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
typedef pair<double, string> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int main(){
    while(1){
        int n; cin>>n;
        if(n == 0) return 0;

        vector<P> ans(n);
        for(int i=0; i<n; i++){
            string l;
            double p, a, b, c, d, e, f, s, m;
            cin>>l>>p>>a>>b>>c>>d>>e>>f>>s>>m;
            double num = ((f * s * m) - p) / (a + b + c + (d + e) * m);
            ans[i] = P(num, l);
        }

        sort(ans.begin(), ans.end(), greater<P>());

        for(int i=0; i<n; i++){
            vector<string> v;
            v.eb(ans[i].sc);

            while(i + 1 < n && ans[i].fs == ans[i+1].fs){
                i++;
                v.eb(ans[i].sc);
            }

            sort(v.begin(), v.end());
            for(auto j:v){
                cout << j << endl;
            }
        }
        cout << "#" << endl;
    }
}