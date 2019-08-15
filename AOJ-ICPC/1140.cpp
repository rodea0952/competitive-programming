#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
#include <queue>
using namespace std;

typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    while(1){
        int w, h;
        cin >> w >> h;
        if(w == 0){
            return 0;
        }

        vector<string> c(h);
        vector<P> s;
        map<int, P> mp;
        int sy, sx;
        int cnt = 1;
        for (int i = 0; i < h; i++){
            cin >> c[i];
            for (int j = 0; j < w; j++){
                if(c[i][j] == 'o'){
                    sy = i;
                    sx = j;
                    c[i][j] = '.';
                }
                if(c[i][j] == '*'){
                    mp[cnt++] = P(i, j);
                    s.emplace_back(i, j);
                }
            }
        }

        int dist[20][30][30];
        for (int i = 0; i < 20; i++){
            for (int j = 0; j < 30; j++){
                for (int k = 0; k < 30; k++){
                    dist[i][j][k] = 1e9;
                }
            }
        }

        int n = s.size();
        for (int i = 0; i <= n; i++){
            queue<T> que;
            if(i == 0){
                que.emplace(0, sy, sx);
                dist[0][sy][sx] = 0;
            }
            else{
                que.emplace(0, s[i - 1].first, s[i - 1].second);
                dist[i][s[i - 1].first][s[i - 1].second] = 0;
            }

            while(que.size()){
                int cost, cy, cx;
                tie(cost, cy, cx) = que.front();
                que.pop();

                for (int j = 0; j < 4; j++){
                    int ny = cy + dy[j];
                    int nx = cx + dx[j];

                    if(0 <= ny && ny < h && 0 <= nx && nx < w){
                        if(c[ny][nx] == 'x'){
                            continue;
                        }

                        if(dist[i][cy][cx] + 1 < dist[i][ny][nx]){
                            dist[i][ny][nx] = dist[i][cy][cx] + 1;
                            que.emplace(dist[i][ny][nx], ny, nx);
                        }
                    }
                }
            }
        }

        vector<int> v;
        for (int i = 1; i <= n; i++){
            v.emplace_back(i);
        }

        int ans = 1e9;
        do{
            int sum = 0;
            P nv = mp[v[0]];

            if(dist[0][nv.first][nv.second] == 1e9){
                cout << -1 << endl;
                goto END;
            }

            sum += dist[0][nv.first][nv.second];

            for (int i = 1; i < n; i++){
                nv = mp[v[i]];

                if(dist[v[i-1]][nv.first][nv.second] == 1e9){
                    cout << -1 << endl;
                    goto END;
                }

                sum += dist[v[i - 1]][nv.first][nv.second];
            }

            ans = min(ans, sum);

        } while (next_permutation(v.begin(), v.end()));

        cout << ans << endl;

        END:;
    }
}