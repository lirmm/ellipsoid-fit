Here are the basic steps to have OpenPHRI up and running:
 * Clone the PID workspace: `git clone https://github.com/lirmm/pid-workspace.git` or `git clone git@github.com:lirmm/pid-workspace.git` to use SSH instead of HTTPS
 * Go to the `pid` directory: `cd pid-workspace/pid`
 * Configure the workspace: `cmake ..`
 * Deploy ellipsoid-fit and its dependencies: `make deploy package=ellipsoid-fit`
 * Now the library is compiled and available under `pid-workspace/instal/your-architecture/ellipsoid-fit/current-version/`. The dynamic library files are under `lib` while the headers are in the `include` folder.
 * If you want to try out the example applications, go to the package build directory: `cd pid-workspace/packages/ellipsoid-fit/build` then turn the CMake option `BUILD_EXAMPLES` to `ON` with the help of: `ccmake ..`
 * Rebuild the package: `make build`
 * Find and run the applications under the `bin` folder of the install path `pid-workspace/instal/your-architecture/ellipsoid-fit/current-version/`
