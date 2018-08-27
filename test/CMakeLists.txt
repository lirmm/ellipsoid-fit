
#declare your tests here
declare_PID_Component(
    TEST_APPLICATION
    NAME test-ellipsoid-fit
    DIRECTORY fit)

declare_PID_Component_Dependency(
    COMPONENT test-ellipsoid-fit
    NATIVE ellipsoid-fit
)


run_PID_Test(NAME checking-aligned-fit COMPONENT test-ellipsoid-fit ARGUMENTS "aligned")
run_PID_Test(NAME checking-aligned-xy-equal-fit COMPONENT test-ellipsoid-fit ARGUMENTS "aligned-xy-equal")
run_PID_Test(NAME checking-aligned-xz-equal-fit COMPONENT test-ellipsoid-fit ARGUMENTS "aligned-xz-equal")
run_PID_Test(NAME checking-sphere-fit COMPONENT test-ellipsoid-fit ARGUMENTS "sphere")
