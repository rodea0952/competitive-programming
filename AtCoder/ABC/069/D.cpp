#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int h, w, n; cin>>h>>w>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int num=0;
    int c[110][110];
    for(int i=0; i<w; i++){
        if(i % 2 == 0){
            for(int j=0; j<h; j++){
                c[j][i]=num+1;
                a[num]--;

                if(a[num] == 0){
                    num++;
                }
            }
        }
        else{
            for(int j=h-1; j>=0; j--){
                c[j][i]=num+1;
                a[num]--;

                if(a[num] == 0){
                    num++;
                }
            }
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(j == w-1){
                cout << c[i][j];
            }
            else{
                cout << c[i][j] << " ";
            }
        }
        cout << endl;
    }
}