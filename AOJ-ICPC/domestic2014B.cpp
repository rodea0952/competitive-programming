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
        int h; cin>>h;
        if(h == 0) return 0;

        vector<vector<int>> num(h+10, vector<int>(5, 0));
        for(int i=0; i<h; i++){
            for(int j=0; j<5; j++){
                cin>>num[i][j];
            }
        }

        int ans=0;
        while(1){
            int sum=0;
            for(int i=h-1; i>=0; i--){
                if(num[i][0] == num[i][1] && num[i][1] == num[i][2] && num[i][2] == num[i][3] && num[i][3] == num[i][4]){
                    sum += num[i][0] * 5;
                    num[i][0] = num[i][1] = num[i][2] = num[i][3] = num[i][4] = 0;
                }
                else if(num[i][0] == num[i][1] && num[i][1] == num[i][2] && num[i][2] == num[i][3]){
                    sum += num[i][0] * 4;
                    num[i][0] = num[i][1] = num[i][2] = num[i][3] = 0;
                }
                else if(num[i][1] == num[i][2] && num[i][2] == num[i][3] && num[i][3] == num[i][4]){
                    sum += num[i][1] * 4;
                    num[i][1] = num[i][2] = num[i][3] = num[i][4] = 0;
                }
                else if(num[i][0] == num[i][1] && num[i][1] == num[i][2]){
                    sum += num[i][0] * 3;
                    num[i][0] = num[i][1] = num[i][2] = 0;
                }
                else if(num[i][1] == num[i][2] && num[i][2] == num[i][3]){
                    sum += num[i][1] * 3;
                    num[i][1] = num[i][2] = num[i][3] = 0;
                }
                else if(num[i][2] == num[i][3] && num[i][3] == num[i][4]){
                    sum += num[i][2] * 3;
                    num[i][2] = num[i][3] = num[i][4] = 0;
                }
            }

            if(sum == 0) break;

            ans += sum;

            for(int i=0; i<5; i++){
                int height = h - 1;
                for(int j=h-1; j>=0; j--){
                    if(num[j][i] != 0){
                        num[height][i] = num[j][i];
                        if(height != j) num[j][i] = 0;
                        height--;
                    }
                }
            }
        }

        cout << ans << endl;
    }
}