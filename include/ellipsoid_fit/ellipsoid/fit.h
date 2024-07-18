#pragma once

#include <ellipsoid/common.h>
#include <ellipsoid/eigenOrder.h>
#include <Eigen/Dense>

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

/**
 * Fit an ellipsoid on the given data
 * @param  data 3xN matrix with the cartesian coordinates to fit the ellipsoid
 * on
 * @param[out]  coefficients pointer storing the 10 coefficents of the fitted ellipsoid 
 * in algebraic form, \f$c=\f$ coefficients, \f{equation}{
 * c_0x^2 + c_1y^2 + c_2z^2 
 * + 2c_3xy + 2c_4xz + 2c_5yz 
 * + 2c_6x + 2c_7y + 2c_8z + c_9 = 0
 * \f}
 * @return      ellipsoid's parameters
 */
Parameters fit(const Eigen::Matrix<double, Eigen::Dynamic, 3>& data,
    Eigen::Matrix<double, 10, 1>* coefficients, 
    EllipsoidType type = EllipsoidType::Arbitrary);

} // namespace ellipsoid

