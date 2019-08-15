#include <bits/stdc++.h>
using namespace std;
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
const double pi = acos(-1);

struct Point{
    double x, y;
    
    Point(double x = 0, double y = 0): x(x), y(y) {}

    Point operator + (Point p) { return Point(x + p.x, y + p.y); }
    Point operator - (Point p) { return Point(x - p.x, y - p.y); }
    Point operator * (double a) { return Point(a * x, a * y); }
    Point operator / (double a) { return Point(x / a, y / a); }

    double norm() {return x * x + y * y; }
    double abs() {return sqrt(norm()); }

    bool operator < (const Point &p) const{
        return (x != p.x ? x < p.x : y < p.y);
    }

    bool operator == (const Point &p) const{
        return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
    }
};

typedef Point Vector;

double norm(Vector a){
    return a.x * a.x + a.y * a.y;
}

double abs(Vector a){
    return sqrt(norm(a));
}

double arg(Vector p){
    return atan2(p.y, p.x);
}

Vector polar(double a, double r){
    return Point(cos(r) * a, sin(r) * a);
}

int main(){
    while(1){
        int n; cin>>n;
        if(n == 0) return 0;
        vector<Point> p;
        for(int i=0; i<n; i++){
            double x, y; cin>>x>>y;
            p.emplace_back(x, y);
        }

        int ans = 1;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                Point p1 = p[i];
                Point p2 = p[j];

                double dist = abs(p1 - p2);

                if(2.0 < dist) continue;

                Point mp = {(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};

                double rad = arg(p2 - p1);
                
                double rad1 = rad + pi / 2;
                double rad2 = rad - pi / 2;

                double sideLength = sqrt(1.0 * 1.0 - abs(mp - p1) * abs(mp - p1));
                
                Point c1 = mp + polar(sideLength, rad1);
                int sum = 0;
                for(int k=0; k<n; k++){
                    dist = abs(c1 - p[k]);
                    if(1.0 + EPS < dist) continue;
                    sum++;
                }

                ans = max(ans, sum);

                Point c2 = mp + polar(sideLength, rad2);
                sum = 0;
                for(int k=0; k<n; k++){
                    dist = abs(c2 - p[k]);
                    if(1.0 + EPS < dist) continue;
                    sum++;
                }

                ans = max(ans, sum);
            }
        }

        cout << ans << endl;
    }
}