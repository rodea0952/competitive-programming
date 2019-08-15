#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int h, w; cin>>h>>w;
    vector<string> s(h);
    for(int i=0; i<h; i++) cin>>s[i];

    char t[h][w];
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            t[i][j]='.';
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(s[i][j]=='#'){
                bool f=false;
                for(int dy=i-1; dy<=i+1; dy++){
                    for(int dx=j-1; dx<=j+1; dx++){
                        if(0<=dy && dy<h && 0<=dx && dx<w){
                            if(s[dy][dx]=='.') f=true;
                        }
                    }
                }
                if(!f) t[i][j]='#';
            }
        }
    }

    char c[h][w];
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            c[i][j]='.';
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(t[i][j]=='#'){
                for(int dy=i-1; dy<=i+1; dy++){
                    for(int dx=j-1; dx<=j+1; dx++){
                        if(0<=dy && dy<h && 0<=dx && dx<w){
                            c[dy][dx]='#';
                        }
                    }
                }
            }
        }
    }

    bool judge=true;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(s[i][j] != c[i][j]) judge=false;
        }
    }

    if(judge){
        cout << "possible" << endl;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cout << t[i][j];
            }
            cout << endl;
        }
    }
    else{
        cout << "impossible" << endl;
    }
}