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
typedef tuple<int, int, int, vector<vector<int>>> T;
typedef tuple<int, int, int> T2;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int main(){
    int t; cin>>t;
    for(int a=1; a<=t; a++){
        int r, c; cin>>r>>c;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                vector<vector<int>> num(r, vector<int>(c, 0));
                num[i][j] = 1;

                queue<T> que;
                que.push(T(i, j, 1, num));
                while(que.size()){
                    int cy, cx, cnt;
                    vector<vector<int>> cnum(r, vector<int>(c));
                    tie(cy, cx, cnt, cnum) = que.front();
                    que.pop();

                    if(cnt == r * c){
                        cout << "Case #" << a << ": " << "POSSIBLE" << endl;
                        vector<T2> ans;
                        for(int k=0; k<r; k++){
                            for(int l=0; l<c; l++){
                                ans.eb(T2(cnum[k][l], k + 1, l + 1));
                            }
                        }

                        sort(ans.begin(), ans.end());

                        for(auto k : ans){
                            cout << get<1>(k) << " " << get<2>(k) << endl;
                        }
                        goto END;
                    }

                    for(int ny=0; ny<r; ny++){
                        for(int nx=0; nx<c; nx++){
                            if(cnum[ny][nx] != 0) continue;
                            if(cy == ny) continue;
                            if(cx == nx) continue;
                            if(cy - cx == ny - nx) continue;
                            if(cy + cx == ny + nx) continue;

                            cnum[ny][nx] = cnt + 1;
                            que.push(T(ny, nx, cnt + 1, cnum));
                            cnum[ny][nx] = 0;
                        }
                    }
                }
            }
        }

        cout << "Case #" << a << ": " << "IMPOSSIBLE" << endl;

        END:;
    }
}