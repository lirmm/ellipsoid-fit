CMAKE_MINIMUM_REQUIRED(VERSION 3.0.2)
set(WORKSPACE_DIR ${CMAKE_SOURCE_DIR}/../.. CACHE PATH "root of the packages workspace directory")
list(APPEND CMAKE_MODULE_PATH ${WORKSPACE_DIR}/share/cmake/system) # using generic scripts/modules of the workspace
include(Package_Definition NO_POLICY_SCOPE)

PROJECT(ellipsoid-fit)

PID_Package(
			AUTHOR 			Benjamin Navarro
			INSTITUTION		LIRMM
			MAIL			navarro@lirmm.fr
			ADDRESS			git@github.com:BenjaminNavarro/ellipsoid-fit.git
			PUBLIC_ADDRESS	https://github.com/BenjaminNavarro/ellipsoid-fit.git
			YEAR 			2018-2020
			LICENSE 		GNULGPL
			README			README.md
			DESCRIPTION 	"Ellipsoid fitting in C++ using Eigen. Widely inspired by https://www.mathworks.com/matlabcentral/fileexchange/24693-ellipsoid-fit"
			README			instructions.md
			CODE_STYLE		pid11
			VERSION 		1 0 1
		)

PID_Dependency(eigen)

build_PID_Package()
