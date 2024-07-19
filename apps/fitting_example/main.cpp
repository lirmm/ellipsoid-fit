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
#include <ellipsoid/generate.h>

#include <iostream>
#include <time.h>

int main(int argc, char const* argv[]) {

    std::srand(time(nullptr));

    ellipsoid::Parameters parameters;
    parameters.center = Eigen::Vector3d::Random();
    parameters.radii = Eigen::Vector3d::Random().cwiseAbs();

    auto points = ellipsoid::generate(parameters, 10000);

    auto identified_parameters =
        ellipsoid::fit(points, ellipsoid::EllipsoidType::Arbitrary);

    std::cout << "Parameters used for generation:\n";
    parameters.print();
    std::cout << "Identified parameters:\n";
    identified_parameters.print();

    return 0;
}
