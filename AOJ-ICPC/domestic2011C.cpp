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
        int h, w, c; cin>>h>>w>>c;
        if(h == 0) return 0;

        vector<vector<int>> p(h, vector<int>(w));
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>p[i][j];
            }
        }

        int ans=0;
        for(int a1=1; a1<=6; a1++){
            for(int a2=1; a2<=6; a2++){
                for(int a3=1; a3<=6; a3++){
                    for(int a4=1; a4<=6; a4++){
                        int a5 = c;

                        vector<vector<int>> cp(h, vector<int>(w));
                        cp = p;

                        vector<int> color(5);
                        color[0] = a1;
                        color[1] = a2;
                        color[2] = a3;
                        color[3] = a4;
                        color[4] = a5;

                        for(int i=0; i<5; i++){
                            int start = cp[0][0];
                            cp[0][0] = color[i];
                            queue<P> que;
                            que.push(P(0, 0));
                            vector<vector<bool>> visited(h, vector<bool>(w, false));
                            visited[0][0] = true;

                            while(que.size()){
                                int cy, cx;
                                tie(cy, cx) = que.front();
                                que.pop();

                                for(int j=0; j<4; j++){
                                    int ny = cy + dy[j];
                                    int nx = cx + dx[j];

                                    if(0 <= ny && ny < h && 0 <= nx && nx < w){
                                        if(!visited[ny][nx] && cp[ny][nx] == start){
                                            cp[ny][nx] = color[i];
                                            visited[ny][nx] = true;
                                            que.push(P(ny, nx));
                                        }
                                    }
                                }
                            }
                        }

                        int sum=1;
                        queue<P> que2;
                        que2.push(P(0, 0));
                        cp[0][0] = -1;
                        while(que2.size()){
                            int cy, cx;
                            tie(cy, cx) = que2.front();
                            que2.pop();

                            for(int i=0; i<4; i++){
                                int ny = cy + dy[i];
                                int nx = cx + dx[i];

                                if(0 <= ny && ny < h && 0 <= nx && nx < w){
                                    if(cp[ny][nx] == c){
                                        que2.push(P(ny, nx));
                                        cp[ny][nx] = -1;
                                        sum++;
                                    }
                                }
                            }
                        }

                        chmax(ans, sum);
                    }
                }
            }
        }

        cout << ans << endl;
    }
}