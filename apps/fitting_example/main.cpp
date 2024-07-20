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

    Eigen::Matrix<double, 10, 1> coefficients; // 10 coefficients
    Eigen::Vector3d eval;   // eigenvalues
    Eigen::Matrix3d evec_column;    // eigenvectors in column

    // There are 4 function overloadings can be used, please refer to ellipsoid/fit.h
    auto identified_parameters =
        ellipsoid::fit(points, &coefficients, &eval, &evec_column, 
            ellipsoid::EllipsoidType::Arbitrary);

    std::cout << "Parameters used for generation:\n";
    parameters.print();
    std::cout << "Identified parameters:\n";
    identified_parameters.print();

    std::cout << "\n\tEigenvalue: ";
    std::cout << eval.transpose() << "\n";

    std::cout << "\tEigenvectors:\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "\t\t(" << i + 1 << ")-> " << evec_column.col(i).transpose() << "\n";
    }

    std::cout << "\n\tEllipsoid algebraic eqn.:\n"
        << "\t\t  Ax^2 + By^2 + Cz^2 \n"
        << "\t\t+ 2Dxy + 2Exz + 2Fyz \n"
        << "\t\t+ 2Gx  + 2Hy  + 2Iz  + J = 0 \n\n";

    for (int i = 0; i < coefficients.size(); ++i) {
        std::cout << "\t\t" << static_cast<char>('A' + i) << " = " << coefficients(i) << '\n';
    }

    return 0;
}
