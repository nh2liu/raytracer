#ifndef MATH_H_
#define MATH_H_
#include <random>

// Thread safe rng generator to use in OMP.
// rand() has a global lock - need seperate rng generator
// objects per thread for OMP.
class RNGGenerator {
    std::mt19937 gen_;

  public:
    RNGGenerator(uint32_t seed);
    float uniform(float a = 0., float b = 1.);
};

#endif