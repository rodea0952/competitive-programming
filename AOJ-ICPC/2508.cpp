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
    string pat = "";
    for(int i=0; i<26; i++){
        pat += ('a' + i);
    }
    for(int i=0; i<26; i++){
        pat += ('A' + i);
    }

    while(1){
        int n; cin>>n;
        if(n == 0) return 0;
        vector<int> k(n);
        for(int i=0; i<n; i++) cin>>k[i];
        string s; cin>>s;

        int cnt = 0;
        string ans = "";
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<52; j++){
                if(s[i] == pat[j]){
                    ans += pat[(j - k[(cnt++) % n] + 52) % 52];
                    break;
                }
            }
        }

        cout << ans << endl;
    }
}