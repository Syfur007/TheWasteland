#include "perlin_noise.hpp"
#include <cmath>
#include <random>
#include <algorithm>
#include <numeric>
#include <SDL.h>


PerlinNoise::PerlinNoise(unsigned int seed) : seed(seed) {
    
    // Initialize finalNoise with the size of the window
    finalNoise.resize(mapHeight * mapWidth);

    const int GRID_SIZE = SMALL;

    // Generate noise values (example logic, replace with actual noise generation)
    for (int y = 0; y < mapHeight; ++y) {
        for (int x = 0; x < mapWidth; ++x) {
            finalNoise[y * mapWidth + x] = noise(static_cast<float>(x) / GRID_SIZE, static_cast<float>(y) / GRID_SIZE); // Example noise value
        }
    }
}


vector2 PerlinNoise::randomUnitVector(int ix, int iy)
{
    const unsigned w = 8 * sizeof(unsigned);
    const unsigned s = w / 2; 
    unsigned a = ix, b = iy;
    a *= 3284157443;
 
    b ^= a << s | a >> w - s;
    b *= 1911520717;
 
    a ^= b << s | b >> w - s;
    a *= 2048419325;

    a ^= seed;
    b ^= seed;

    float random = a * (3.14159265 / ~(~0u >> 1));
    
    return {cos(random), sin(random)};
}


float PerlinNoise::dotGridGradient(int ix, int iy, float x, float y) {
    // Get gradient from integer coordinates
    vector2 gradient = randomUnitVector(ix, iy);
 
    // Compute the distance vector
    float dx = x - (float)ix;
    float dy = y - (float)iy;
 
    // Compute the dot-product
    return (dx * gradient.x + dy * gradient.y);
}

 
float PerlinNoise::interpolate(float a0, float a1, float w)
{
    return (a1 - a0) * (3.0 - w * 2.0) * w * w + a0;
}


float PerlinNoise::noise(float x, float y)
{
    int x0 = (int)x;
    int y0 = (int)y;
    int x1 = x0 + 1;
    int y1 = y0 + 1;

    // Interpolation weights
    float sx = x - (float)x0;
    float sy = y - (float)y0;

    // Compute and interpolate top two corners
    float n0 = dotGridGradient(x0, y0, x, y);
    float n1 = dotGridGradient(x1, y0, x, y);
    float ix0 = interpolate(n0, n1, sx);

    // Compute and interpolate bottom two corners
    n0 = dotGridGradient(x0, y1, x, y);
    n1 = dotGridGradient(x1, y1, x, y);
    float ix1 = interpolate(n0, n1, sx);

    // Interpolate the two results
    return interpolate(ix0, ix1, sy);
}


// PerlinNoise::PerlinNoise(unsigned int seed): seed(seed) {

//     const int GRID_SIZE = 400;

//     for (int x = 0; x < windowWidth; x++)
//     {
//         for (int y = 0; y < windowHeight; y++)
//         {
//             int index = (y * windowWidth + x) * 4;
            
//             float val = 0;
//             float freq = 1;
//             float amp = 1;
 
//             for (int i = 0; i < 4; i++)
//             {
//                 val += noise(x * freq / GRID_SIZE, y * freq / GRID_SIZE) * amp;
 
//                 freq *= 2;
//                 amp /= 2;
 
//             }
 
//             // Contrast
//             val *= 1.2;
            
//             // Clipping
//             if (val > 1.0f)
//                 val = 1.0f;
//             else if (val < -1.0f)
//                 val = -1.0f;
 
//             // Convert 1 to -1 into 255 to 0
//             int color = (int)(((val + 1.0f) * 0.5f) * 255);
 
//             finalNoise.push_back(color);
//         }
//     }
// }