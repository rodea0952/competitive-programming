#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    ll h, w; int n; cin>>h>>w>>n;
    map<P, int> mp;
    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        for(int x=-2; x<=0; x++){
            for(int y=-2; y<=0; y++){
                if(0 <= x+b && x+b < w && 0 <= y+a && y+a < h){
                    if(x+b+2 < w && y+a+2 < h){
                        mp[P(y+a, x+b)]++;
                    }
                } 
            }
        }
    }

    vector<int> ans(10, 0);
    set<P> st;
    for(auto itr=mp.begin(); itr!=mp.end(); itr++){
        ans[itr->second]++;
        st.insert(P(itr->first.first, itr->first.second));
    }
    cout << (h-2)*(w-2) - st.size() << endl;
    for(int i=1; i<=9; i++){
        cout << ans[i] << endl;
    }
}