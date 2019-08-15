#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int r, c, k; cin>>r>>c>>k;
    string s[510];
    for(int i=0; i<r; i++) cin>>s[i];

    vector<vector<int>> downsum(510, vector<int>(510, 0));
    for(int i=0; i<c; i++){
        for(int j=0; j<r; j++){
            if(j == 0){
                if(s[j][i] == 'o') downsum[j][i] = 1;
                else downsum[j][i] = 0;
            }
            else{
                if(s[j][i] == 'o') downsum[j][i] = downsum[j-1][i] + 1;
                else downsum[j][i] = 0;
            }
        }
    }

    vector<vector<int>> upsum(510, vector<int>(510, 0));
    for(int i=0; i<c; i++){
        for(int j=r-1; j>=0; j--){
            if(j == r-1){
                if(s[j][i] == 'o') upsum[j][i] = 1;
                else upsum[j][i] = 0;
            }
            else{
                if(s[j][i] == 'o') upsum[j][i] = upsum[j+1][i] + 1;
                else upsum[j][i] = 0;
            }
        }
    }
    
    int ans=0;
    for(int i=k-1; i<=r-k; i++){
        for(int j=k-1; j<=c-k; j++){
            int cnt=0;
            for(int l=j-(k-1); l<=j+(k-1); l++){
                if(l <= j) cnt++;
                else cnt--;

                if(!(downsum[i][l] >= cnt && upsum[i][l] >= cnt)) goto END;
            }
            ans++;
            END:;
        }
    }
    cout << ans << endl;
}