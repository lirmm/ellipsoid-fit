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

    // Resulted surface is a hyperboloid, since one of the radii is NaN
    std::cout << "Identified parameters:\n";
    identified_parameters.print();

    return 0;
}
