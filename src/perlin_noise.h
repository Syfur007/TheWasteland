#pragma once
#include <vector>

class PerlinNoise {

public:
    static unsigned int generateSeed();
    PerlinNoise(unsigned int seed);
    double noise(double x, double y, double z);

private:
    double fade(double t);
    double lerp(double t, double a, double b);
    double grad(int hash, double x, double y, double z);

    std::vector<int> p; // Declare the member variable p

};