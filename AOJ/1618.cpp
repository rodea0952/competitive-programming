#include <bits/stdc++.h>
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

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int d, w;
    while(cin>>d>>w, d){
        int e[d][w];
        for(int i=0; i<d; i++){
            for(int j=0; j<w; j++){
                cin>>e[i][j];
            }
        }

        int ans=0;
        for(int i=0; i<d; i++){
            for(int j=i+2; j<d; j++){
                for(int k=0; k<w; k++){
                    for(int l=k+2; l<w; l++){

                        int nmin=10, nmax=0;
                        for(int y=i; y<=j; y++){
                            for(int x=k; x<=l; x++){
                                if(y==i || y==j || x==k || x==l){
                                    chmin(nmin, e[y][x]);
                                }
                                else{
                                    chmax(nmax, e[y][x]);
                                }
                            }
                        }

                        int sum=0;
                        if(nmax<nmin){
                            for(int y=i; y<=j; y++){
                                for(int x=k; x<=l; x++){
                                    if(y==i || y==j || x==k || x==l){
                                        continue;
                                    }
                                    sum+=nmin-e[y][x];
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