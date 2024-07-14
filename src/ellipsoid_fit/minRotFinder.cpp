#include <ellipsoid/minRotFinder.h>

void minRotFinder::find_min_rotation(Eigen::Vector3d& eval, Eigen::Matrix3d& evec_column)
{
    // Store all possible configurations
    std::vector<Eigen::Vector3d> eval_set;	// for eigenvalues
    std::vector<Eigen::Matrix3d> evec_column_set; //for eigenvectors stored in column

    // All possible placements of eigenvalues and eigenvectors
    std::array<std::array<int, 3>, 6> order = { {
        {0, 1, 2}, {0, 2, 1},
        {1, 0, 2}, {1, 2, 0},
        {2, 0, 1}, {2, 1, 0}
    } };
    // All possible signs assigned to eigenvectors
    std::array<std::array<int, 2>, 4> sign = { {
        {0, 0}, {0, 1},
        {1, 0}, {1, 1}
    } };

    Eigen::Vector3d temp_vector;
    Eigen::Matrix3d temp_matrix;

    const unsigned int dim = 3;
    const unsigned int dim_minus_1 = dim - 1;

    // Find all possible configurations of eigenvectors with their respective eigenvalues
    for (int i = 0; i < order.size(); i++) {
        for (int j = 0; j < sign.size(); j++) {
            for (int k = 0; k < dim_minus_1; k++) {
                temp_matrix.col(k) = std::pow(-1, sign[j][k]) * evec_column.col(order[i][k]);
                temp_vector[k] = eval[order[i][k]];
            }
            temp_matrix.col(dim_minus_1) = evec_column.col(order[i][dim_minus_1]);
            // Ensure the determinant always positive to preserve orientation
            if (temp_matrix.determinant() < 0) {
                temp_matrix.col(dim_minus_1) = -temp_matrix.col(dim_minus_1);
            }
            temp_vector[dim_minus_1] = eval[order[i][dim - 1]];

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