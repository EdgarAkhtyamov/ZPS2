#include <iostream>
#include <algorithm>


//Structure of a point on a plane
struct Point {
    double x;
    double y;
};

//Function to check if point C is to the left/right of AB
bool onSegment(Point a, Point b, Point c) {
    if (c.x <= std::max(a.x, b.x) && c.x >= std::min(a.x, b.x) && c.y <= std::max(a.y, b.y) && c.y >= std::min(a.y, b.y)) {
        return true;
    }
    return false;
}
//Direction of the vector (segment)
int direction(Point a, Point b, Point c) {
    double val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (val == 0) 
        return 0; 
    
    else if (val > 0) return 1;

    else return 2;
}

//Function to calculate the intersection of two triangles
double CommonPartArea(Point p1_tr1, Point p2_tr1, Point p3_tr1, Point p1_tr2, Point p2_tr2, Point p3_tr2) {
    Point p1 = { std::max(p1_tr1.x, p1_tr2.x), std::max(p1_tr1.y, p1_tr2.y) };
    Point p2 = { std::min(p2_tr1.x, p2_tr2.x), std::min(p2_tr1.y, p2_tr2.y) };

    if (p1.x >= p2.x || p1.y >= p2.y) {
        return 0.0; 
        // no intersection
    }

    return (p2.x - p1.x) * (p2.y - p1.y);
}

int main() {
    Point p1_tr1, p2_tr1, p3_tr1, p1_tr2, p2_tr2, p3_tr2;
    std::cin >> p1_tr1.x >> p1_tr1.y >> p2_tr1.x >> p2_tr1.y >> p3_tr1.x >> p3_tr1.y >> p1_tr2.x >> p1_tr2.y >> p2_tr2.x >> p2_tr2.y >> p3_tr2.x >> p3_tr2.y;

    double square= CommonPartArea(p1_tr1, p2_tr1, p3_tr1, p1_tr2, p2_tr2, p3_tr2);

    std::cout << "Result for the Task: " << square << std::endl;

    return 0;
}

