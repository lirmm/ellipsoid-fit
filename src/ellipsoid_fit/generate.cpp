/*      File: generate.cpp
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
#include <ellipsoid/generate.h>

namespace ellipsoid {

Eigen::Matrix<double, Eigen::Dynamic, 3> generate(const Parameters& parameters,
                                                  size_t samples) {
    Eigen::Matrix<double, Eigen::Dynamic, 3> points;
    points.resize(samples, 3);

    for (size_t i = 0; i < samples; ++i) {
        Eigen::Vector3d point;

        // Generate two pseudo-random angular coordinates
        double theta = ((std::rand() - RAND_MAX / 2) / double(RAND_MAX)) *
                       M_PI; // -pi/2 < theta < pi/2
        double phi = ((std::rand() - RAND_MAX / 2) / double(RAND_MAX)) * 2. *
                     M_PI; // -pi < phi < pi

        point.x() = parameters.center.x() +
                    parameters.radii.x() * std::cos(theta) * std::cos(phi);
        point.y() = parameters.center.y() +
                    parameters.radii.y() * std::cos(theta) * std::sin(phi);
        point.z() =
            parameters.center.z() + parameters.radii.z() * std::sin(theta);

        points.row(i) = point.transpose();
    }

    return points;
}

} // namespace ellipsoid
