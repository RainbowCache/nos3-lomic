project(lomic_thruster_sim)

find_package(ITC_Common REQUIRED QUIET COMPONENTS itc_logger)
find_package(NOSENGINE REQUIRED QUIET COMPONENTS common transport client uart)

include_directories(inc
                    ${sim_common_SOURCE_DIR}/inc
                    ${ITC_Common_INCLUDE_DIRS}
                    ${NOSENGINE_INCLUDE_DIRS})

set(lomic_thruster_sim_src
    src/lomic_thruster_hardware_model.cpp
    src/lomic_thruster_42_data_provider.cpp
    src/lomic_thruster_data_point.cpp
)

# For Code::Blocks and other IDEs
file(GLOB lomic_thruster_sim_inc inc/*.hpp)

set(lomic_thruster_sim_libs
    sim_common
    ${ITC_Common_LIBRARIES}
    ${NOSENGINE_LIBRARIES}
)

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_RPATH}:$ORIGIN/../lib") # Pick up .so in install directory

add_library(lomic_thruster_sim SHARED ${lomic_thruster_sim_src} ${lomic_thruster_sim_inc})
target_link_libraries(lomic_thruster_sim ${lomic_thruster_sim_libs})
install(TARGETS lomic_thruster_sim LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
