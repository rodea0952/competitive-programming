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
    vector<int> d(n);
    vector<int> cnt(13, 0);
    for(int i=0; i<n; i++){
        cin>>d[i];
        cnt[d[i]]++;
    }

    bool valid = true;
    vector<int> v2, v1;
    for(int i=0; i<13; i++){
        if(3 <= cnt[i]) valid = false;
        else if(cnt[i] == 2){
            v2.push_back(i);
            v2.push_back(24 - i);
        }
        else if(cnt[i] == 1){
            v1.push_back(i);
        }
    }

    if(!valid){
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    for(int bit=0; bit<(1<<v1.size()); bit++){
        set<int> st;
        for(auto i:v2){
            st.insert(i);
        }

        for(int i=0; i<v1.size(); i++){
            if(i & bit){
                st.insert(24 - v1[i]);
            }
            else{
                st.insert(v1[i]);
            }
        }

        int pre = 0;
        int maxgap = 100;
        for(auto i:st){
            maxgap = min(maxgap, i - pre);
            pre = i;
        }

        ans = max(ans, maxgap);
    }

    cout << ans << endl;
}