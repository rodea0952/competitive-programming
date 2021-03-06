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
        int h, w; cin>>h>>w;
        if(h == 0) return 0;

        int base = h*h + w*w;

        int ansh = 200;
        int answ = 200;
        for(int i=1; i<=200; i++){
            for(int j=i+1; j<=200; j++){
                int cl = i*i + j*j;
                int ansl = ansh*ansh + answ*answ;

                if(base < cl){
                    if(cl < ansl){
                        ansh = i;
                        answ = j;
                    }
                    else if(cl == ansl && i < ansh){
                        ansh = i;
                        answ = j;
                    }
                }
                else if(base == cl && h < i){
                    if(cl < ansl){
                        ansh = i;
                        answ = j;
                    }
                    else if(cl == ansl && i < ansh){
                        ansh = i;
                        answ = j;
                    }
                }
            }
        }

        cout << ansh << " " << answ << endl;
    }
}