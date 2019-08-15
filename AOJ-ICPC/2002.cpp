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
typedef tuple<int, int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int main(){
    int n; cin>>n;
    while(n--){
        int h, w; cin>>h>>w;
        vector<string> s(h);
        
        set<char> st;
        for(int i=0; i<h; i++){
            cin>>s[i];
            for(int j=0; j<w; j++){
                if(s[i][j] != '.') st.insert(s[i][j]);
            }
        }

        if(st.size() == 0){
            cout << "SAFE" << endl;
            continue;
        }

        vector<char> v;
        for(auto i:st){
            v.eb(i);
        }

        sort(v.begin(), v.end());

        map<char, T> mp;
        for(auto i:v){
            get<0>(mp[i]) = 1e9;
            get<1>(mp[i]) = 1e9;
            get<2>(mp[i]) = 0;
            get<3>(mp[i]) = 0;
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                for(int k=0; k<v.size(); k++){
                    if(s[i][j] == v[k]){
                        chmin(get<0>(mp[v[k]]), j);
                        chmin(get<1>(mp[v[k]]), i);
                        chmax(get<2>(mp[v[k]]), j);
                        chmax(get<3>(mp[v[k]]), i);
                        break;
                    }
                }
            }
        }

        bool valid = false;
        do{
            auto cs = s;
            for(int k=0; k<v.size(); k++){
                int xmin=1e9, ymin=1e9, xmax=0, ymax=0;
                int cnt=0;
                for(int i=0; i<h; i++){
                    for(int j=0; j<w; j++){
                        if(cs[i][j] == v[k]){
                            chmin(xmin, j);
                            chmin(ymin, i);
                            chmax(xmax, j);
                            chmax(ymax, i);
                            cnt++;

                            for(int l=k+1; l<v.size(); l++){
                                if(get<0>(mp[v[l]]) <= j && get<1>(mp[v[l]]) <= i && j <= get<2>(mp[v[l]]) && i <= get<3>(mp[v[l]])){
                                    cs[i][j] = v[l];
                                    break;
                                }
                            }
                        }
                    }
                }

                if((ymax - ymin + 1) * (xmax - xmin + 1) != cnt){
                    break;
                }

                if(k == v.size() - 1){
                    cout << "SAFE" << endl;
                    valid = true;
                }
            }

            if(valid) break;

        }while(next_permutation(v.begin(), v.end()));

        if(!valid) cout << "SUSPICIOUS" << endl;
    }
}