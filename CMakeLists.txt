CMAKE_MINIMUM_REQUIRED(VERSION 3.0.2)
set(WORKSPACE_DIR ${CMAKE_SOURCE_DIR}/../.. CACHE PATH "root of the packages workspace directory")
list(APPEND CMAKE_MODULE_PATH ${WORKSPACE_DIR}/share/cmake/system) # using generic scripts/modules of the workspace
include(Package_Definition NO_POLICY_SCOPE)

PROJECT(ellipsoid-fit)

declare_PID_Package(
			AUTHOR      idhuser
			YEAR        2018
			LICENSE     CeCILL
			DESCRIPTION TODO: input a short description of package ellipsoid-fit utility here
		)

set_PID_Package_Version(0 1 0)

#now finding packages

build_PID_Package()
