#pragma once

#include <Eigen/Dense>

namespace ellipsoid {

struct Parameters {
	Eigen::Vector3d center;
	Eigen::Vector3d radii;

	void print();
};

}
