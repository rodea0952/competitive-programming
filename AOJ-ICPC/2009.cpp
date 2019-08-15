#include <iostream>
#include <complex>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;

#define X real()
#define Y imag()
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

double dot(Vector a, Vector b){
    return a.X * b.X + a.Y * b.Y;
}

double cross(Vector a, Vector b){
    return a.X * b.Y - a.Y * b.X;
}

double norm(Vector a){
    return a.X * a.X + a.Y * a.Y;
}

double abs(Vector a){
    return sqrt(norm(a));
}

int ccw(Point p0, Point p1, Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a, b) > EPS) return 1;
    if(cross(a, b) < -EPS) return -1;
    if(dot(a, b) < -EPS) return 2;
    if(norm(a) < norm(b)) return -2;

    return 0;
}

bool intersect(Point p1, Point p2, Point p3, Point p4){
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(Segment s1, Segment s2){
    return intersect(s1.first, s1.second, s2.first, s2.second);
}

Point getCrossPointSS(Segment s1, Segment s2){
    Vector base = s2.second - s2.first;
    double d1 = abs(cross(base, s1.first - s2.first));
    double d2 = abs(cross(base, s1.second - s2.first));
    double t = d1 / (d1 + d2);
    return s1.first + (s1.second - s1.first) * t;
}

int n;

int solve(vector<Segment> &sg){
    int ans = 1;
    for(int i=0; i<n; i++){
        vector<Point> ps;
        for(int j=0; j<i; j++){
            // 線分が正方形内で交わらない
            if(!intersect(sg[i], sg[j])) continue;

            Point cross = getCrossPointSS(sg[i], sg[j]);

            // 交点が正方形の辺上にある
            if(equals(cross, sg[i].first) || equals(cross, sg[i].second)) continue;
            if(equals(cross, sg[j].first) || equals(cross, sg[j].second)) continue;

            bool same = false;
            for(int k=0; k<ps.size(); k++){
                if(equals(ps[k], cross)) same = true;
            }

            if(!same){
                ps.emplace_back(cross);
            }
        }

        ans += ps.size() + 1;
    }

    return ans;
}

int main(){
    while(1){
        cin>>n;
        if(n == 0) return 0;

        vector<Segment> sg;
        for(int i=0; i<n; i++){
            double x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
            sg.emplace_back(Point(x1, y1), Point(x2, y2));
        }

        cout << solve(sg) << endl;
    }
}