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
