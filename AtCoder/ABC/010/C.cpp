#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int txa, tya, txb, tyb, T, V;
    cin>>txa>>tya>>txb>>tyb>>T>>V;
    int n; cin>>n;
    bool girl=false;
    for(int i=0; i<n; i++){
        int x, y; cin>>x>>y;
        double first_dist = sqrt((x-txa)*(x-txa) + (y-tya)*(y-tya));
        double second_dist = sqrt((x-txb)*(x-txb) + (y-tyb)*(y-tyb));

        if(first_dist + second_dist <= (double)(T*V)){
            girl=true;
        }
    }

    if(girl){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}