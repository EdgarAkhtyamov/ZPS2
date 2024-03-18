#include <iostream>
#include <cmath>
#include <algorithm>

struct point {
    double x, y;
};

double square(point a, point b, point c) {
    return 0.5 * std::abs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)));
}

double find_min(double a, double b, double c) {
    return std::min(std::min(a, b), c);
}

double find_max(double a, double b, double c) {
    return std::max(std::max(a, b), c);
}

double crossing_square(point a1, point b1, point c1, point a2, point b2, point c2) {
    double sq1 = square(a1, b1, c1);
    double sq2 = square(a2, b2, c2);

    double minx1 = find_min(a1.x, b1.x, c1.x); 
    double maxx1 = find_max(a1.x, b1.x, c1.x);
    double miny1 = find_min(a1.y, b1.y, c1.y);
    double maxy1 = find_max(a1.y, b1.y, c1.y);

    double minx2 = find_min(a2.x, b2.x, c2.x);
    double maxx2 = find_max(a2.x, b2.x, c2.x);
    double miny2 = find_min(a2.y, b2.y, c2.y);
    double maxy2 = find_max(a2.y, b2.y, c2.y);

    double crossminx = std::max(minx1, minx2);
    double crossmaxx = std::min(maxx1, maxx2);
    double crossminy = std::max(miny1, miny2);
    double crossmaxy = std::min(maxy1, maxy2);

    double intersectsquare = square({ crossminx, crossminy }, { crossmaxx, crossminy }, { crossminx, crossmaxy });

    return intersectsquare;
}

int main() {
    point a1, b1, c1, a2, b2, c2;
    std::cin >> a1.x >> a1.y >> b1.x >> b1.y >> c1.x >> c1.y >> a2.x >> a2.y >> b2.x >> b2.y >> c2.x >> c2.y;

    double res = crossing_square(a1, b1, c1, a2, b2, c2);
    std::cout << res << std::endl;

    return 0;
}