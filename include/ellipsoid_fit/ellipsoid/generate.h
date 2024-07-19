/*      File: generate.h
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
#include <Eigen/Dense>

namespace ellipsoid {

/**
 * Generate 3D cartesian points laying on an ellipsoid.
 * @param parameters ellipsoid's parameters (center and radii)
 * @param samples    number of points to generate
 * @return           3xN Matrix containing the generated points
 */
Eigen::Matrix<double, Eigen::Dynamic, 3> generate(const Parameters& parameters,
                                                  size_t samples = 1000);

} // namespace ellipsoid
