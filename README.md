
Overview
=========

Ellipsoid fitting in C++ using Eigen. Widely inspired by https://www.mathworks.com/matlabcentral/fileexchange/24693-ellipsoid-fit

# Disclaimer

This library has the same problem as the original Matlab code: radii might not be in the correct order.

This is due to the algorithm relying on eigen values to compute them. These values are not guaranteed to be in any particular order by the algorithms computing them.

A new algorithm or a fix to this one needs to be found.

The license that applies to the whole package content is **GNULGPL**. Please look at the license.txt file at the root of this repository.

Installation and Usage
=======================

The detailed procedures for installing the ellipsoid-fit package and for using its components is based on the [PID](http://pid.lirmm.net/pid-framework/pages/install.html) build and deployment system called PID. Just follow and read the links to understand how to install, use and call its API and/or applications.

For a quick installation:

## Installing the project into an existing PID workspace

To get last version :
 ```
cd <path to pid workspace>/pid
make deploy package=ellipsoid-fit
```

To get a specific version of the package :
 ```
cd <path to pid workspace>/pid
make deploy package=ellipsoid-fit version=<version number>
```

## Standalone install
 ```
git clone https://github.com/BenjaminNavarro/ellipsoid-fit.git
cd ellipsoid-fit
```

Then run the adequate install script depending on your system. For instance on linux:
```
sh share/install/standalone_install.sh
```

The pkg-config tool can be used to get all links and compilation flags for the libraries defined inthe project. To let pkg-config know these libraries, read the last output of the install_script and apply the given command. It consists in setting the PKG_CONFIG_PATH, for instance on linux do:
```
export PKG_CONFIG_PATH=<path to ellipsoid-fit>/binaries/pid-workspace/share/pkgconfig:$PKG_CONFIG_PATH
```

Then, to get compilation flags run:

```
pkg-config --static --cflags ellipsoid-fit_<name of library>
```

To get linker flags run:

```
pkg-config --static --libs ellipsoid-fit_<name of library>
```


About authors
=====================

ellipsoid-fit has been developped by following authors: 
+ Benjamin Navarro (LIRMM)

Please contact Benjamin Navarro (navarro@lirmm.fr) - LIRMM for more information or questions.



