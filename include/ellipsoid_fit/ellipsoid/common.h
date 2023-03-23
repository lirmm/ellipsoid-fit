#pragma once

#include <Eigen/Dense>

namespace ellipsoid {

struct Parameters {
    Eigen::Vector3d center;
    Eigen::Vector3d radii;
    Eigen::Matrix<double, 10, 1> v;

    void print();
};

} // namespace ellipsoid
