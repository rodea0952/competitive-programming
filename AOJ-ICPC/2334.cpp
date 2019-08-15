#include <iostream>
#include <complex>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;
typedef pair<double, int> P;

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

double solve(vector<Point> &pa, vector<Point> &pb){

    Segment base = {pa[0], pa[1]};
    double ans = abs(pa[0] - pa[1]);

    vector<double> dist(1000, 1e9);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[0] = 0;
    que.emplace(0, 0);

    while(que.size()){
        double ccost; int cv;
        tie(ccost, cv) = que.top();
        que.pop();

        if(dist[cv] < ccost) continue;

        for(int i=0; i<pb.size(); i++){
            int nv = i;
            Segment sg = {pb[cv], pb[nv]};

            if(intersect(base, sg)) continue;

            double cdist = abs(pb[nv] - pb[cv]);

            if(dist[cv] + cdist < dist[nv]){
                dist[nv] = dist[cv] + cdist;
                que.emplace(dist[nv], nv);
            }
        }
    }

    return  (ans + dist[1]);
}

int main(){
    int na, nb; cin>>na>>nb;
    vector<Point> pa;
    for(int i=0; i<na; i++){
        double x, y; cin>>x>>y;
        pa.emplace_back(x, y);
    }

    vector<Point> pb;
    for(int i=0; i<nb; i++){
        double x, y; cin>>x>>y;
        pb.emplace_back(x, y);
    }

    double ansa = solve(pa, pb);
    double ansb = solve(pb, pa);

    if(1e9 <= ansa and 1e9 <= ansb){
        cout << -1 << endl;
    }
    else{
        double ans = min(ansa, ansb);
        printf("%.12f\n", ans);
    }
}