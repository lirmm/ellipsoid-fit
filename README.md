
ellipsoid-fit
==============

Ellipsoid fitting in C++ using Eigen. Widely inspired by https://www.mathworks.com/matlabcentral/fileexchange/24693-ellipsoid-fit



# Disclaimer

This library has the same problem as the original Matlab code: radii might not be in the correct order.

This is due to the algorithm relying on eigen values to compute them. These values are not guaranteed to be in any particular order by the algorithms computing them.

A new algorithm or a fix to this one needs to be found.

Package Overview
================

The **ellipsoid-fit** package contains the following:

 * Libraries:

   * ellipsoid-fit (shared)

 * Examples:

   * fitting-example

 * Tests:

   * test-ellipsoid-fit


Installation and Usage
======================

The **ellipsoid-fit** project is packaged using [PID](http://pid.lirmm.net), a build and deployment system based on CMake.

If you wish to adopt PID for your develoment please first follow the installation procedure [here](http://pid.lirmm.net/pid-framework/pages/install.html).

If you already are a PID user or wish to integrate **ellipsoid-fit** in your current build system, please read the appropriate section below.


## Using an existing PID workspace

This method is for developers who want to install and access **ellipsoid-fit** from their PID workspace.

You can use the `deploy` command to manually install **ellipsoid-fit** in the workspace:
```
cd <path to pid workspace>
pid deploy package=ellipsoid-fit # latest version
# OR
pid deploy package=ellipsoid-fit version=x.y.z # specific version
```
Alternatively you can simply declare a dependency to **ellipsoid-fit** in your package's `CMakeLists.txt` and let PID handle everything:
```
PID_Dependency(ellipsoid-fit) # any version
# OR
PID_Dependency(ellipsoid-fit VERSION x.y.z) # any version compatible with x.y.z
```

If you need more control over your dependency declaration, please look at [PID_Dependency](https://pid.lirmm.net/pid-framework/assets/apidoc/html/pages/Package_API.html#pid-dependency) documentation.

Once the package dependency has been added, you can use `ellipsoid-fit/ellipsoid-fit` as a component dependency.

You can read [PID_Component](https://pid.lirmm.net/pid-framework/assets/apidoc/html/pages/Package_API.html#pid-component) and [PID_Component_Dependency](https://pid.lirmm.net/pid-framework/assets/apidoc/html/pages/Package_API.html#pid-component-dependency) documentations for more details.
## Standalone installation

This method allows to build the package without having to create a PID workspace manually. This method is UNIX only.

All you need to do is to first clone the package locally and then run the installation script:
 ```
git clone https://gite.lirmm.fr/rpc/math/ellipsoid-fit.git
cd ellipsoid-fit
./share/install/standalone_install.sh
```
The package as well as its dependencies will be deployed under `binaries/pid-workspace`.

You can pass `--help` to the script to list the available options.

### Using **ellipsoid-fit** in a CMake project
There are two ways to integrate **ellipsoid-fit** in CMake project: the external API or a system install.

The first one doesn't require the installation of files outside of the package itself and so is well suited when used as a Git submodule for example.
Please read [this page](https://pid.lirmm.net/pid-framework/pages/external_API_tutorial.html#using-cmake) for more information.

The second option is more traditional as it installs the package and its dependencies in a given system folder which can then be retrived using `find_package(ellipsoid-fit)`.
You can pass the `--install <path>` option to the installation script to perform the installation and then follow [these steps](https://pid.lirmm.net/pid-framework/pages/external_API_tutorial.html#third-step--extra-system-configuration-required) to configure your environment, find PID packages and link with their components.
### Using **ellipsoid-fit** with pkg-config
You can pass `--pkg-config on` to the installation script to generate the necessary pkg-config files.
Upon completion, the script will tell you how to set the `PKG_CONFIG_PATH` environment variable for **ellipsoid-fit** to be discoverable.

Then, to get the necessary compilation flags run:

```
pkg-config --static --cflags ellipsoid-fit_ellipsoid-fit
```

```
pkg-config --variable=c_standard ellipsoid-fit_ellipsoid-fit
```

```
pkg-config --variable=cxx_standard ellipsoid-fit_ellipsoid-fit
```

To get linker flags run:

```
pkg-config --static --libs ellipsoid-fit_ellipsoid-fit
```




Offline API Documentation
=========================

With [Doxygen](https://www.doxygen.nl) installed, the API documentation can be built locally by turning the `BUILD_API_DOC` CMake option `ON` and running the `doc` target, e.g
```
pid cd ellipsoid-fit
pid -DBUILD_API_DOC=ON doc
```
The resulting documentation can be accessed by opening `<path to ellipsoid-fit>/build/release/share/doc/html/index.html` in a web browser.

License
=======

The license that applies to the whole package content is **GNULGPL**. Please look at the [license.txt](./license.txt) file at the root of this repository for more details.

Authors
=======

**ellipsoid-fit** has been developed by the following authors: 
+ Benjamin Navarro (LIRMM)

Please contact Benjamin Navarro (navarro@lirmm.fr) - LIRMM for more information or questions.
