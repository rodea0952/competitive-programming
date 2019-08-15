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
    int t; cin>>t;
    for(int i=1; i<=t; i++){
        int n; cin>>n;
        vector<string> s(n);
        for(int i=0; i<n; i++) cin>>s[i];

        vector<int> v(n);
        iota(v.begin(), v.end(), 0);

        int ans=0;
        do{
            set<string> st;
            for(int j=0; j<n; j+=2){
                if(n % 2 == 1 && j == n - 1) break;

                int fid = v[j];
                int sid = v[j+1];
                int l1 = s[v[j]].size();
                int l2 = s[v[j+1]].size();

                for(int k=0; k<l1; k++){
                    for(int l=0; l<l2; l++){
                        string t = s[v[j]].substr(k, l1-k);
                        string t2 = s[v[j+1]].substr(l, l2-l);

                        if(t == t2){
                            st.insert(t);
                            goto END;
                        }
                    }
                }

                END:;
            }


            chmax(ans, (int)st.size() * 2);

        }while(next_permutation(v.begin(), v.end()));

        cout << "Case #" << i << ": " << ans << endl;
    }
}