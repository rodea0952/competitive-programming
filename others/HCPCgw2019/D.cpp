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
    while(1){
        int w, h; cin>>w>>h;
        if(w == 0) return 0;

        int lsy, lsx, rsy, rsx;
        int lgy, lgx, rgy, rgx;
        vector<string> s1(h), s2(h);
        for(int i=0; i<h; i++){
            cin>>s1[i]>>s2[i];
            reverse(s2[i].begin(), s2[i].end());

            for(int j=0; j<w; j++){
                if(s1[i][j] == '%'){
                    s1[i][j] = '.';
                    lgy = i;
                    lgx = j;
                }
                if(s2[i][j] == '%'){
                    s2[i][j] = '.';
                    rgy = i;
                    rgx = j;
                }
                if(s1[i][j] == 'L'){
                    s1[i][j] = '.';
                    lsy = i;
                    lsx = j;
                }
                if(s2[i][j] == 'R'){
                    s2[i][j] = '.';
                    rsy = i;
                    rsx = j;
                }
            }
        }

        bool valid=false;
        queue<T> que;
        que.push(T(lsy, lsx, rsy, rsx));
        map<ll, bool> visited;
        visited[lsy+lsx*10000+rsy*100000000+rsx*1000000000000] = true;
        while(que.size()){
            int lcy, lcx, rcy, rcx;
            tie(lcy, lcx, rcy, rcx) = que.front();
            que.pop();
            //cout << lcy << " " << lcx << " " << rcy << " " << rcx << endl;

            if(lcy == lgy && lcx == lgx && rcy == rgy && rcx == rgx){
                cout << "Yes" << endl;
                valid = true;
                break;
            }

            for(int i=0; i<4; i++){
                int lny = lcy + dy[i];
                int lnx = lcx + dx[i];
                int rny = rcy + dy[i];
                int rnx = rcx + dx[i];

                if((lny == lgy && lnx == lgx) && !(rny == rgy && rnx == rgx)) continue;
                if(!(lny == lgy && lnx == lgx) && (rny == rgy && rnx == rgx)) continue;

                if(0 <= lny && lny < h && 0 <= lnx && lnx < w){
                    if(s1[lny][lnx] == '.'){
                        if(rny < 0 || h <= rny || rnx < 0 || w <= rnx){
                            if(!visited[lny+lnx*10000+rcy*100000000+rcx*1000000000000]){
                                visited[lny+lnx*10000+rcy*100000000+rcx*1000000000000] = true;
                                que.push(T(lny, lnx, rcy, rcx));
                            }
                        }
                        else if(s2[rny][rnx] == '#'){
                            if(!visited[lny+lnx*10000+rcy*100000000+rcx*1000000000000]){
                                visited[lny+lnx*10000+rcy*100000000+rcx*1000000000000] = true;
                                que.push(T(lny, lnx, rcy, rcx));
                            }
                        }
                        else{
                            if(!visited[lny+lnx*10000+rny*100000000+rnx*1000000000000]){
                                visited[lny+lnx*10000+rny*100000000+rnx*1000000000000] = true;
                                que.push(T(lny, lnx, rny, rnx));
                            }
                        }
                    }
                }

                if(0 <= rny && rny < h && 0 <= rnx && rnx < w){
                    if(s2[rny][rnx] == '.'){
                        if(lny < 0 || h <= lny || lnx < 0 || w <= lnx){
                            if(!visited[lcy+lcx*10000+rny*100000000+rnx*1000000000000]){
                                visited[lcy+lcx*10000+rny*100000000+rnx*1000000000000] = true;
                                que.push(T(lcy, lcx, rny, rnx));
                            }
                        }
                        else if(s1[lny][lnx] == '#'){
                            if(!visited[lcy+lcx*10000+rny*100000000+rnx*1000000000000]){
                                visited[lcy+lcx*10000+rny*100000000+rnx*1000000000000] = true;
                                que.push(T(lcy, lcx, rny, rnx));
                            }
                        }
                        else{
                            if(!visited[lny+lnx*10000+rny*100000000+rnx*1000000000000]){
                                visited[lny+lnx*10000+rny*100000000+rnx*1000000000000] = true;
                                que.push(T(lny, lnx, rny, rnx));
                            }
                        }
                    }
                }
            }
        }

        if(!valid) cout << "No" << endl;
    }
}