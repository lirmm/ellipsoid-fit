#pragma once

#include <ellipsoid/common.h>
#include <Eigen/Dense>
#include <functional>

namespace ellipsoid {

enum class EllipsoidType {
    Arbitrary,
    XYEqual,
    XZEqual,
    Sphere,
    Aligned,
    AlignedXYEqual,
    AlignedXZEqual,
};

/**
 * Fit an ellipsoid on the given data
 * @param  data 3xN matrix with the cartesian coordinates to fit the ellipsoid
 * on
 * @return      ellipsoid's parameters
 */
Parameters fit(const Eigen::Matrix<double, Eigen::Dynamic, 3>& data,
               EllipsoidType type = EllipsoidType::Arbitrary);

Parameters fit(const Eigen::Matrix<double, Eigen::Dynamic, 3>& data,
    std::function<void(const Eigen::Matrix<double, 10, 1>&)> getAlgebraicForm,
    EllipsoidType type = EllipsoidType::Arbitrary);

} // namespace ellipsoid
