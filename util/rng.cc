#include "rng.h"
using namespace std;

RNGGenerator::RNGGenerator(uint32_t seed) : gen_(seed) {}

float RNGGenerator::uniform(float a, float b) {
    uniform_real_distribution<double> dis(a, b);
    return dis(gen_);
}