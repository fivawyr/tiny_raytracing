#include <array>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <cstdint>
#include <vector>

typedef int8_t i8;
typedef int32_t i32;
typedef float f32;
typedef double f64;

using namespace std;
typedef vector<i32> vi;

#define MAX_RAY_DEPTH 3 
#define COLOR_WHITE 0xffffffff
#define COLOR_YELLOW 0xffff00
#define COLOR_RED 0xff0000
#define COLOR_BLUE 0x0000ff
#define COLOR_GREEN 0x008000

struct Color {
    i32 r, g, b, a; 
};

struct Object {

};

struct Point {
    i32 x, y, z;
};

struct Vector {
    i32 x, y, z;
};

struct Normal {

};

struct Intersect {

};

struct Ray {
    
    Point origin;
    Vector direction;
}

Color Trace(const Ray &ray, int depth) {
    Object *object = NULL;
    f32 minDistance = INFINITY;
    Point pointHit; 
    Normal normalHit;
    for (i32 k = 0; k < object.size(); k++) {
        if (Intersect(object[k], ray, &pointHit, &normalHit)) {

        }
    }
}

int main() {
    cout << "Hello Raycasting" << "\n";
}
