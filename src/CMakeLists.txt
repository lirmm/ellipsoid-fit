declare_PID_Component(
    SHARED_LIB
    NAME ellipsoid-fit
    DIRECTORY ellipsoid_fit
    CXX_STANDARD 11
)

declare_PID_Component_Dependency(
    COMPONENT ellipsoid-fit
    EXPORT EXTERNAL eigen
    PACKAGE eigen
)
