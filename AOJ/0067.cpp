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
    vector<string> s(12);
    while(cin>>s[0]){
        for(int i=1; i<12; i++) cin>>s[i];

        int ans=0;
        for(int i=0; i<12; i++){
            for(int j=0; j<12; j++){
                if(s[i][j] == '1'){
                    ans++;
                    s[i][j] = '0';
                    queue<P> que;
                    que.push(P(i, j));
                    while(que.size()){
                        int cy = que.front().fs;
                        int cx = que.front().sc;
                        que.pop();

                        for(int k=0; k<4; k++){
                            int ny = cy + dy[k];
                            int nx = cx + dx[k];

                            if(0 <= ny && ny < 12 && 0 <= nx && nx < 12){
                                if(s[ny][nx] == '1'){
                                    que.push(P(ny, nx));
                                    s[ny][nx] = '0';
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}