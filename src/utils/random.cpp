#include "random.hpp"


int utils::Random::randomi(int minInclusive, int maxInclusive) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distr(minInclusive, maxInclusive);
    return distr(generator);
 
}

float utils::Random::randomf(float minInclusive, float maxInclusive) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<> distr(minInclusive, maxInclusive);
    return distr(generator);
}
