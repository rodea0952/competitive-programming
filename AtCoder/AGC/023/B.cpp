#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    char s[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>s[i][j];
        }
    }

    int ans=0;
    // a=0
    for(int b=0; b<n; b++){
        char t[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                t[i][j]=s[i%n][(j+b)%n];

                if(j<i && t[i][j]!=t[j][i]) goto END;
            }
        }
        ans++;
        END:;
    }
    cout << ans*n << endl;
}