#include <ellipsoid/eigenOrder.h>

void eigenOrder::leastRotationAngle(Eigen::Vector3d& eval, Eigen::Matrix3d& evec_column)
{
    // Store all possible configurations
    std::vector<Eigen::Vector3d> eval_set;	// for eigenvalues
    std::vector<Eigen::Matrix3d> evec_column_set; //for eigenvectors stored in column

    // All possible placements of eigenvalues and eigenvectors
    const std::array<const std::array<const int, 3>, 6> order_set = { {
        {0, 1, 2}, {0, 2, 1},
        {1, 0, 2}, {1, 2, 0},
        {2, 0, 1}, {2, 1, 0}
    } };
    // All possible signs assigned to eigenvectors
    const std::array<const std::array<const int, 3>, 4> sign_set = { {
        {0, 0, 0}, {0, 1, 0},
        {1, 0, 0}, {1, 1, 0}
    } };

    Eigen::Vector3d temp_vector;
    Eigen::Matrix3d temp_matrix;

    // Find all possible configurations of eigenvectors with their respective eigenvalues
    for (const auto& order : order_set) {
        for (const auto& sign : sign_set) {            
            for (int i = 0; i < 3; i++) {
                temp_matrix.col(i) = std::pow(-1, sign[i]) * evec_column.col(order[i]);
                temp_vector(i) = eval(order[i]);
            }
            // Ensure the determinant always positive to preserve orientation
            if (temp_matrix.determinant() < 0) {
                temp_matrix.col(2) = -temp_matrix.col(2);
            }

            evec_column_set.push_back(temp_matrix);
            eval_set.push_back(temp_vector);
        }
    }

    std::vector<double> rot_angle;
    Eigen::AngleAxisd angleAxis;

    // Find the rotation angles based on Rodrigues' rotation formula
    for (const auto& element : evec_column_set) {
        angleAxis = element;
        rot_angle.push_back(angleAxis.angle());
    }

    // Find the least rotation angle
    auto min_It = std::min_element(rot_angle.begin(), rot_angle.end());
    auto idx = std::distance(rot_angle.begin(), min_It);

    // Overwrites the inputs
    eval = eval_set[idx];
    evec_column = evec_column_set[idx];
}