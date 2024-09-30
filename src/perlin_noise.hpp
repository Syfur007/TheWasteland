#pragma once
#include <vector>

struct vector2 {
    double x, y;
};

typedef enum  {
    SMALL = 40,
    MEDIUM = 20,
    LARGE = 10,
    VERY_LARGE = 5
} MapSize;

class PerlinNoise {

public:
    int mapHeight = 1080;
    int mapWidth = 1920;
    vector2 randomUnitVector(int ix, int iy);
    PerlinNoise(unsigned int seed = 0);
    std::vector<float> finalNoise; // Declare the member variable p
private:
    unsigned int seed;
    float dotGridGradient(int ix, int iy, float x, float y);
    float interpolate(float a0, float a1, float w);
    float noise(float x, float y);
};