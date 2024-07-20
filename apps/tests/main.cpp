/*      File: main.cpp
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
#include <ellipsoid/fit.h>

#include <iostream>

int main() {
    // An example of incomplete coverage of the surface points in the input data.
    Eigen::Matrix<double, 100, 3> points;
    double a = 3, b = 1, c = 2;
    auto s = Eigen::Matrix<double, 100, 1>::LinSpaced(0, M_PI);

    auto x = points.col(0);
    auto y = points.col(1);
    auto z = points.col(2);

    const auto ang = M_PI / 6.;

    for (size_t i = 0; i < points.rows(); i++) {
        x(i) = a * std::cos(s(i)) * std::cos(s(i));
        y(i) = b * std::cos(s(i)) * std::sin(s(i));
        z(i) = c * std::sin(s(i));

        auto xt = x(i) * std::cos(ang) - y(i) * std::sin(ang);
        auto yt = x(i) * std::sin(ang) + y(i) * std::cos(ang);

        double shiftx = 4, shifty = 5, shiftz = 6;
        x(i) = xt + shiftx;
        y(i) = yt + shifty;
        z(i) += shiftz;
    }

    auto identified_parameters =
        ellipsoid::fit(points, ellipsoid::EllipsoidType::Arbitrary);

    std::cout << "Identified parameters:\n";
    identified_parameters.print();

    return 0;
}
