/*      File: eigenOrder.h
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

#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <Eigen/Dense>
#include <Eigen/Geometry>

namespace eigenOrder {

/**
 * @brief Rearrange the eigenvectors with their respective eigenvalues for the smallest 
 * angle deviated from the ref. frame.
 * 
 * This function first permutates the eigenvalues with their respective eigenvalues (3! = 
 * 6 arrangements), then assigns all possible signs to each permutated eigenvectors set 
 * (4 possibilites) while maintaining the determinant of eigenvector matrix to be +1.
 * 
 * Subsequently, using Rodrigues' rotation formula, the function computes the rotational 
 * angles based on the rotational matrices formed from each configuration of eigenvectors.
 * 
 * Lastly, the two input parameters are overwrote with the configuration which possesses 
 * the smallest rotational angle deviated from the ref. frame.
 * 
 * @param  eval 3D vector containing eigenvalues
 * @param  evec_column 3x3 Matrix containing eigenvectors arranged in column vectors
 * 
 * @note The order of eigenvectors (column) in `evec_column` is the same as the eigenvalues 
 * in `eval`.
 * 
 */
void leastRotationAngle(Eigen::Vector3d& eval, Eigen::Matrix3d& evec_column);

} // namespace minRotFinder
