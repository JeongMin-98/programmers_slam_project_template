project(test)
# Test sources
set(ImageProjector_TEST_SRCS
        image_projector
        )

# Include
include_directories(
        ${ImageProjector_INCLUDE_PATH}
)

# Targets
add_executable(unit_tests
        main.cpp
        ${ImageProjector_TEST_SRCS}.cpp
        )

target_link_libraries(unit_tests
        ${GTEST_LIBS}
        ImageProjector
        stdc++fs
        )

add_test(NAME UnitTest COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/unit_tests)

set(matchString "/")
set(replaceWith "_")

foreach(test ${ImageProjector_TEST_SRCS})
    string(REPLACE ${matchString} ${replaceWith} test_name ${test})
    set(test_name ${test_name})

    add_executable(${test_name}
            main.cpp
            ${test}.cpp)
    target_link_libraries(${test_name}
            ${GTEST_LIBS}
            ImageProjector
            stdc++fs
            )
    add_test(${test_name}
            ${test_name}
            --gtest_color=yes
            )
endforeach()