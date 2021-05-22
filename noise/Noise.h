#ifndef CIVILIZATION_V_NOISE_H
#define CIVILIZATION_V_NOISE_H

#include "anl.h"
#include <ctime>
#include <cmath>
#include <vector>

#include <iostream>

class Noise {
private:
    anl::CImplicitFractal *noise;
public:

    Noise(anl::CImplicitFractal *noise);

    ~Noise();

    static Noise noiseGenerator(anl::EFractalTypes type, anl::EBasisTypes basisType, anl::EInterpTypes interpType,
                                long long numOctaves, double frequency, unsigned int seed = rand());

    double get(double x, double y);

    std::vector<std::vector<double> > generateNoise(long long width, long long height, long long step);
};


#endif //CIVILIZATION_V_NOISE_H
