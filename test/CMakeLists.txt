PID_Component(
    TEST
    NAME test-ellipsoid-fit
    DIRECTORY fit
    DEPEND ellipsoid-fit/ellipsoid-fit
)

run_PID_Test(NAME checking-aligned-fit COMPONENT test-ellipsoid-fit ARGUMENTS "aligned")
run_PID_Test(NAME checking-aligned-xy-equal-fit COMPONENT test-ellipsoid-fit ARGUMENTS "aligned-xy-equal")
run_PID_Test(NAME checking-aligned-xz-equal-fit COMPONENT test-ellipsoid-fit ARGUMENTS "aligned-xz-equal")
run_PID_Test(NAME checking-sphere-fit COMPONENT test-ellipsoid-fit ARGUMENTS "sphere")
run_PID_Test(NAME checking-arbitary-fit COMPONENT test-ellipsoid-fit ARGUMENTS "arbitary")
