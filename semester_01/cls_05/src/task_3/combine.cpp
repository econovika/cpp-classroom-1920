//
// Created by ksenia on 20.10.2020.
//

#include "combine.hpp"


double combine (std::vector<double> const & vec, double (*mult)(double, double), double (*plus)(double, double))
{
    if (vec.empty())
        return 0;

    if (vec.size() == 1)
        return vec[0];

    double res = mult(vec[0], vec[1]);

    for (size_t i = 2; i < vec.size() - 2; i += 2)
        res = plus(res, mult(vec[i], vec[i + 1]));
    if (vec.size() % 2 == 0)
        res = plus(res, mult(vec[vec.size() - 2], vec[vec.size() - 1]));
    else
        res = plus(res, vec[vec.size() - 1]);
    return res;
}