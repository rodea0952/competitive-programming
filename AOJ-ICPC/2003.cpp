#include <bits/stdc++.h>
using namespace std;

struct Point{
    double x, y;
    
    Point(double x = 0, double y = 0): x(x), y(y) {}

    Point operator + (Point p) { return Point(x + p.x, y + p.y); }
    Point operator - (Point p) { return Point(x - p.x, y - p.y); }
    Point operator * (double a) { return Point(a * x, a * y); }
    Point operator / (double a) { return Point(x / a, y / a); }

    double norm() {return x * x + y * y; }
    double abs() {return sqrt(norm()); }
};

typedef Point Vector;

struct Segment{
    Point p1, p2;
    Segment(Point p1, Point p2): p1(p1), p2(p2) {}
};

typedef Segment Line;

double cross(Vector a, Vector b){
    return a.x * b.y - a.y * b.x;
}

bool intersection(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy){
    double ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
    double tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
    double tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
    double td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);

    return (ta * tb < 0 && tc * td < 0);
}

Point getCrossPoint(Segment s1, Segment s2){
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1 / (d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
}

int main(){
    int q; cin>>q;
    while(q--){
        double xa, ya, xb, yb; cin>>xa>>ya>>xb>>yb;
        Segment s1 = {Point(xa, ya), Point(xb, yb)};
        int n; cin>>n;
        vector<tuple<double, double, bool>> point;
        for(int i=0; i<n; i++){
            double xs, ys, xt, yt; 
            int o, l;
            cin>>xs>>ys>>xt>>yt>>o>>l;
            Segment s2 = {Point(xs, ys), Point(xt, yt)};

            if(intersection(xa, ya, xb, yb, xs, ys, xt, yt)){
                Point p1 = getCrossPoint(s1, s2);
                double px = p1.x;
                double py = p1.y;

                if((o == 1 && l == 1) || (o == 0 && l == 0)){
                    point.emplace_back(px, py, true);
                }
                else{
                    point.emplace_back(px, py, false);
                }
            }
        }

        sort(point.begin(), point.end());

        cout << point.size() - 1 << endl;

        int ans = 0;
        for(int i=0; i<point.size()-1; i++){
            if(get<2>(point[i]) != get<2>(point[i+1])){
                ans++;
            }
        }

        cout << ans << endl;
    }
}