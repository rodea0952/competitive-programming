#include <iostream>
#include <complex>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;
typedef vector<Point> Polygon;

#define X real()
#define Y imag()
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

// 平面走査による線分交差
#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3

struct EndPoint{
    Point p;
    int seg, st; // 入力線分のID, 端点の種類
    EndPoint() {}
    EndPoint(Point p, int seg, int st): p(p), seg(seg), st(st) {}

    bool operator < (const EndPoint &ep) const{
        // y 座標が小さい順に整列
        if(p.Y == ep.p.Y){
            // y が同一の場合は、下端点、左端点、右端点、上端点の順に並べる
            return st < ep.st;
        }
        else{
            return p.Y < ep.p.Y;
        }
    }
};

// 端点のリスト
EndPoint EP[2 * 100000];

// 線分交差問題: マンハッタン幾何
int manhattanIntersection(vector<Segment> S){
    int n = S.size();

    for(int i=0, k=0; i<n; i++){
        // 端点 p1, p2 が左下を基準に並ぶように調整
        if(S[i].first.Y == S[i].second.Y){
            if(S[i].first.X > S[i].second.X){
                swap(S[i].first, S[i].second);
            }
        }
        else if(S[i].first.Y > S[i].second.Y){
            swap(S[i].first, S[i].second);
        }

        if(S[i].first.Y == S[i].second.Y){
            // 水平線分を端点リストに追加
            EP[k++] = EndPoint(S[i].first, i, LEFT);
            EP[k++] = EndPoint(S[i].second, i, RIGHT);
        }
        else{
            EP[k++] = EndPoint(S[i].first, i, BOTTOM);
            EP[k++] = EndPoint(S[i].second, i, TOP);
        }
    }

    // 端点の y 座標に関して昇順に整列
    sort(EP, EP + (2 * n));

    set<int> BT;
    BT.insert(1000000001);
    int cnt = 0;

    for(int i=0; i<2*n; i++){
        if(EP[i].st == TOP){
            // 上端点を削除
            BT.erase(EP[i].p.X);
        }
        else if(EP[i].st == BOTTOM){
            // 下端点を追加
            BT.insert(EP[i].p.X);
        }
        else if(EP[i].st == LEFT){
            set<int>::iterator b = BT.lower_bound(S[EP[i].seg].first.X);
            set<int>::iterator e = BT.upper_bound(S[EP[i].seg].second.X);
            cnt += distance(b, e);
        }
    }

    return cnt;
}

int main(){
    int n; cin>>n;
    vector<Segment> seg;
    while(n--){
        double x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        seg.emplace_back(Point(x1, y1), Point(x2, y2));
    }

    cout << manhattanIntersection(seg) << endl;
}