#pragma once

#include <vector>

#pragma once

double combine (std::vector<double> const & vec, double (*mult)(double, double), double (*plus)(double, double));
