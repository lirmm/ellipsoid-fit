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
 * @param[in]   data 3xN matrix with the cartesian coordinates to fit the ellipsoid
 * on
 * @return      ellipsoid's parameters
 */
Parameters fit(const Eigen::Matrix<double, Eigen::Dynamic, 3>& data,
               EllipsoidType type = EllipsoidType::Arbitrary);

/**
 * Fit an ellipsoid on the given data
 * @param[in]   data 3xN matrix with the cartesian coordinates to fit the ellipsoid
 * on
 * @param[out]  coefficients_p pointer storing the 10 coefficents of the fitted ellipsoid 
 * in algebraic form, \f$c=\f$ coefficients, \f{equation}{
 * c_0x^2 + c_1y^2 + c_2z^2 
 * + 2c_3xy + 2c_4xz + 2c_5yz 
 * + 2c_6x + 2c_7y + 2c_8z + c_9 = 0
 * \f}
 * @return      ellipsoid's parameters
 */
Parameters fit(const Eigen::Matrix<double, Eigen::Dynamic, 3>& data,
    Eigen::Matrix<double, 10, 1>* coefficients_p, 
    EllipsoidType type = EllipsoidType::Arbitrary);

/**
 * Fit an ellipsoid on the given data
 * @param[in]   data 3xN matrix with the cartesian coordinates to fit the ellipsoid
 * on
 * @param[out]  eval_p pointer storing the eigenvalues, solved from the fitted ellipsoid 
 * after its centre translated to the origin of ref. frame.
 * @param[out]  evec_column_p pointer storing the eigenvectors in columns, solved from the 
 * fitted ellipsoid after its centre translated to the origin of ref. frame.
 * @return      ellipsoid's parameters
 * 
 * @note The order of eigenvectors (column) in `evec_column_p` matches the eigenvalues 
 * in `eval_p`.
 */
Parameters fit(const Eigen::Matrix<double, Eigen::Dynamic, 3>& data,
    Eigen::Vector3d* eval_p, Eigen::Matrix3d* evec_column_p,
    EllipsoidType type = EllipsoidType::Arbitrary);

/**
 * Fit an ellipsoid on the given data
 * @param[in]   data 3xN matrix with the cartesian coordinates to fit the ellipsoid
 * on
 * @param[out]  coefficients_p pointer storing the 10 coefficents of the fitted ellipsoid 
 * in algebraic form, \f$c=\f$ coefficients, \f{equation}{
 * c_0x^2 + c_1y^2 + c_2z^2 
 * + 2c_3xy + 2c_4xz + 2c_5yz 
 * + 2c_6x + 2c_7y + 2c_8z + c_9 = 0
 * \f}
 * @param[out]  eval_p pointer storing the eigenvalues, solved from the fitted ellipsoid 
 * after its centre translated to the origin of ref. frame.
 * @param[out]  evec_column_p pointer storing the eigenvectors in columns, solved from the 
 * fitted ellipsoid after its centre translated to the origin of ref. frame.
 * @return      ellipsoid's parameters
 * 
 * @note The order of eigenvectors (column) in `evec_column_p` matches the eigenvalues 
 * in `eval_p`.
 */
Parameters fit(const Eigen::Matrix<double, Eigen::Dynamic, 3>& data,
    Eigen::Matrix<double, 10, 1>* coefficients_p, 
    Eigen::Vector3d* eval_p, Eigen::Matrix3d* evec_column_p,
    EllipsoidType type = EllipsoidType::Arbitrary);

} // namespace ellipsoid

