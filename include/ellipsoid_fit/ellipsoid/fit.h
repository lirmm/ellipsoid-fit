/*      File: fit.h
*       This file is part of the program ellipsoid-fit
*       Program description : Ellipsoid fitting in C++ using Eigen. Widely inspired by https://www.mathworks.com/matlabcentral/fileexchange/24693-ellipsoid-fit
*       Copyright (C) 2018-2021 -  Benjamin Navarro (LIRMM) CK-Explorer (). All Right reserved.
*
*       This software is free software: you can redistribute it and/or modify
*       it under the terms of the LGPL license as published by
*       the Free Software Foundation, either version 3
*       of the License, or (at your option) any later version.
*       This software is distributed in the hope that it will be useful,
*       but WITHOUT ANY WARRANTY without even the implied warranty of
*       MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*       LGPL License for more details.
*
*       You should have received a copy of the GNU Lesser General Public License version 3 and the
*       General Public License version 3 along with this program.
*       If not, see <http://www.gnu.org/licenses/>.
*/
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

