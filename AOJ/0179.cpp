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
typedef pair<string, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

char judge(char a, char b){
    if((a == 'r' && b == 'b') || (a == 'b' && b == 'r')) return 'g';
    if((a == 'b' && b == 'g') || (a == 'g' && b == 'b')) return 'r';
    if((a == 'g' && b == 'r') || (a == 'r' && b == 'g')) return 'b';
}

int main(){
    while(1){
        string s; cin>>s;
        if(s == "0") return 0;

        queue<P> que;
        que.push(P(s, 0));
        map<string, bool> visited;
        visited[s] = true;
        bool isNA = true;
        while(que.size()){
            string t;
            int cnt;
            tie(t, cnt) = que.front();
            que.pop();

            bool valid = true;

            for(int i=0; i<t.size()-1; i++){
                if(t[i] != t[i+1]){
                    valid = false;
                    string nt = t;
                    nt[i] = nt[i+1] = judge(t[i], t[i+1]);

                    if(!visited[nt]){
                        visited[nt] = true;
                        que.push(P(nt, cnt+1));
                    }
                }
            }

            if(valid){
                isNA = false;
                cout << cnt << endl;
                break;
            }
        }

        if(isNA){
            cout << "NA" << endl;
        }
    }
}