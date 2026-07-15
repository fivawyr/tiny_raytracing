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

i32 backgroundColor = 0xff0000;
i32 imageHeight = 300;
i32 imageWidth = 500; 

i32 pixels[imageWidth][imageHeight] = {

}

struct Color {
    i32 r, g, b, a; 
};

struct Object {
    i32 x, y, z;
    bool isGlass;
    f32  indexOfRefraction;

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
};

struct Distance {

};

struct Light {
    i32 brightness;
};

i32 Fresnel(){

}

i32 Normalize(){

}

Color Trace(const Ray &ray, int depth, Color &backgroundColor, f32 &computeRefractionRay) {
    Object *object = NULL;
    f32 minDistance = INFINITY;
    Point pointHit; 
    Normal normalHit;
    for (i32 k = 0; k < object.size(); k++) {
        if (Intersect(object[k], ray, &pointHit, &normalHit)) {
            f32 distance = Distance(ray.origin, pointHit);
            if (distance < minDistance) {
                object = object[k];
                minDistance = distance; 

            }
        }
    }
    if (object == NULL) return backgroundColor;
    // if the object material is glass and the depth is less than MAX_RAY_DEPTH, split the ray
    if (object->isGlass && depth < MAX_RAY_DEPTH) {
        Ray reflectionRay, refractionRay;
        Color reflectionColor, refractionColor;
        f32 Kr, Kt;
        reflectionRay = computeRefractionRay(object->indexOfRefraction, ray.direction, normalHit, ray.origin, pointHit);
        reflectionColor = Trace(reflectionRay, depth + 1); // recursive call 
        refractionRay = computeRefractionRay(object->indexOfRefraction, ray.direction, normalHit, ray.origin, pointHit);
        refractionColor = Trace(refractionRay, depth + 1);
        Fresnel(object->indexOfRefraction, normalHit, ray.direction, &Kr, &Kt);
        return reflectionColor * Kr + refractionColor * (1 - Kr);
    else if (!object->isGlass) {
        Ray shadowRay;
        shadowRay.origin = pointHit + normalHit * bias // bias to avoid self-intersection 
        shadowRay.direction = Normalize(lightPosition - pointHit);
        bool isInShadow = false;
        for (i32 k = 0; k < object.size(); ++k) {
            if (Intersect(object[k], shadowRay)) {
                isInShadow = true;
                break;
                }
            }
            if (!isInShadow) return object->color * light.brightness; 
        }
    }
    return backgroundColor;
}



f64 computeRefractionRay{0};

int main() {
    cout << "Hello Raycasting" << "\n";

    // render loop
    for (i32 j = 0; j < imageHeight; j++) {
        for (int i = 0; i < imageWidth; i++) {
            Ray primRay;
            computePrimRay(i, j, &primRay);
            pixels[i][j] = Tracce(primRay, 0);
        }
    }    
}
