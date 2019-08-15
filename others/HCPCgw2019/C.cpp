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

namespace patch{
    template <typename T> string to_string(const T& n){
        ostringstream stm;
        stm << n;
        return stm.str();
    }
}

int main(){
    while(1){
        string s; cin>>s;
        if(s == "#") return 0;
        int a, b, c, d; cin>>a>>b>>c>>d;
        a--, b--, c--, d--;

        vector<vector<int>> board(10, vector<int>(10));

        int H=0, W=0;
        int h=0, w=0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'b'){
                board[h][w] = 1;
                w++;
            }
            else if(s[i] == '/'){
                h++;
                w = 0;
            }
            else{
                int num = (s[i] - '0');
                for(int j=w; j<w+num; j++){
                    board[h][j] = 0;
                }
                w += num;
            }

            chmax(H, h);
            chmax(W, w - 1);
        }

        swap(board[a][b], board[c][d]);

        string ans="";
        for(int i=0; i<=H; i++){
            for(int j=0; j<=W; j++){
                if(board[i][j] == 1){
                    ans += "b";
                }
                else{
                    int num=0;
                    while(j <= W && board[i][j] == 0){
                        num++;
                        j++;
                    }

                    j--;
                    ans += patch::to_string(num);
                }
            }

            if(i != H) ans += "/";
        }

        cout << ans << endl;
    }
}