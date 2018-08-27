
#!/bin/bash
if [ "$PACKAGE_HAS_SITE" = true ] ; then
  # managing publication of developpers info
  if [ "$PACKAGE_DEV_INFO_PUBLISHED" = true ]; then
    site_publish_static_checks=ON
    if [ "$PACKAGE_HAS_TESTS" = true ] ; then
      site_publish_coverage=ON
    else
      site_publish_coverage=OFF
    fi
  else
    site_publish_static_checks=OFF
    site_publish_coverage=OFF
  fi

  # publishing API doc as soon as there are libraries
  if [ "$PACKAGE_HAS_LIBRARIES" = true ]; then
      site_publish_api=ON
  else
      site_publish_api=OFF
  fi

  cd build
  # first step generating the binary archives (if necessary),this stepis separate from following to avoid including in binary archive unecesary developper infos
  if [ "$PACKAGE_BINARIES_PUBLISHED" = true ]; then
    echo "[PID] CI : generating the binary archive..."
    cmake -DREQUIRED_PACKAGES_AUTOMATIC_DOWNLOAD=ON -DADDITIONNAL_DEBUG_INFO=OFF -DBUILD_AND_RUN_TESTS=OFF -DENABLE_PARALLEL_BUILD=ON -DBUILD_EXAMPLES=OFF -DBUILD_API_DOC=OFF -DBUILD_STATIC_CODE_CHECKING_REPORT=OFF -DGENERATE_INSTALLER=ON -DWORKSPACE_DIR="../binaries/pid-workspace" ..
    #reconfiguring again to avoid troubles with cache variables that have been generated
    cmake -DREQUIRED_PACKAGES_AUTOMATIC_DOWNLOAD=ON -DADDITIONNAL_DEBUG_INFO=OFF -DBUILD_AND_RUN_TESTS=OFF -DENABLE_PARALLEL_BUILD=ON -DBUILD_EXAMPLES=OFF -DBUILD_API_DOC=OFF -DBUILD_STATIC_CODE_CHECKING_REPORT=OFF -DGENERATE_INSTALLER=ON -DWORKSPACE_DIR="../binaries/pid-workspace" ..
    #build the package to get clean binary archives
    cmake --build . --target build -- force=true
  fi

  # second step configuring the package adequately to make it generate other artefacts included in the static site (API doc for instance)
  echo "[PID] CI : generating the static site..."
  cmake -DREQUIRED_PACKAGES_AUTOMATIC_DOWNLOAD=ON -DADDITIONNAL_DEBUG_INFO=OFF -DBUILD_AND_RUN_TESTS=$site_publish_coverage -DBUILD_TESTS_IN_DEBUG=$site_publish_coverage -DBUILD_COVERAGE_REPORT=$site_publish_coverage -DENABLE_PARALLEL_BUILD=ON -DBUILD_EXAMPLES=OFF -DBUILD_API_DOC=$site_publish_api -DBUILD_STATIC_CODE_CHECKING_REPORT=$site_publish_static_checks -DGENERATE_INSTALLER=OFF -DWORKSPACE_DIR="../binaries/pid-workspace" ..
  #reconfiguring again to avoid troubles with cache variables that have been generated
  cmake -DREQUIRED_PACKAGES_AUTOMATIC_DOWNLOAD=ON -DADDITIONNAL_DEBUG_INFO=OFF -DBUILD_AND_RUN_TESTS=$site_publish_coverage -DBUILD_TESTS_IN_DEBUG=$site_publish_coverage -DBUILD_COVERAGE_REPORT=$site_publish_coverage -DENABLE_PARALLEL_BUILD=ON -DBUILD_EXAMPLES=OFF -DBUILD_API_DOC=$site_publish_api -DBUILD_STATIC_CODE_CHECKING_REPORT=$site_publish_static_checks -DGENERATE_INSTALLER=OFF -DWORKSPACE_DIR="../binaries/pid-workspace" ..
  #build the package again to get all dev infos
  cmake --build . --target build -- force=true
  #build the static site
  cmake --build . --target site

  cd ..
fi
#if no site to publish then nothing to do
