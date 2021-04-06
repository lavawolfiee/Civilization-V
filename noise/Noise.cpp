#include "Noise.h"

#include <utility>

Noise Noise::noiseGenerator(anl::EFractalTypes type, anl::EBasisTypes basisType, anl::EInterpTypes interpType,
                            long long int numOctaves, double frequency, unsigned int seed) {

    srand(time(nullptr));

    Noise result(new anl::CImplicitFractal(type, basisType, interpType));
    result.noise->setNumOctaves(numOctaves);
    result.noise->setFrequency(frequency);
    result.noise->setSeed(seed);
    return result;
}

Noise::Noise(anl::CImplicitFractal* noise) : noise(noise) {}

double Noise::get(double x, double y) {
    return noise->get(x, y);
}

std::vector<std::vector<double> > Noise::generateNoise(long long int width, long long int height, long long int step) {

    /*anl::CImplicitFractal noise(anl::EFractalTypes::MULTI, anl::EBasisTypes::SIMPLEX, anl::EInterpTypes::QUINTIC);
    noise.setNumOctaves(6);
    noise.setFrequency(1.25);
    noise.setSeed(rand());*/

    std::vector< std::vector< double > > mapPixels(height, std::vector< double >(width, 0.0));
    double min = std::numeric_limits<double>::max(), max = std::numeric_limits<double>::min();
    for(long long y = 0; y < height; ++y) {
        for (long long x = 0; x < width; ++x) {
            //std::cout << x << " " << y << std::endl;
            mapPixels[y][x] = get(static_cast<double>(x) / step, static_cast<double>(y) / step);
            min = fmin(min, mapPixels[y][x]);
            max = fmax(max, mapPixels[y][x]);
        }
    }
    for(long long y = 0; y < height; ++y) {
        for(long long x = 0; x < width; ++x) {
            mapPixels[y][x] = (mapPixels[y][x] - min) / (max - min);
        }
    }
    return mapPixels;
}

Noise::~Noise() {
    delete noise;
}
