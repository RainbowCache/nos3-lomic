project(cannon_sim)

find_package(ITC_Common REQUIRED QUIET COMPONENTS itc_logger)
find_package(NOSENGINE REQUIRED QUIET COMPONENTS common transport client uart)

include_directories(inc
                    ${sim_common_SOURCE_DIR}/inc
                    ${ITC_Common_INCLUDE_DIRS}
                    ${NOSENGINE_INCLUDE_DIRS})

set(cannon_sim_src
    src/cannon_hardware_model.cpp
    src/cannon_42_data_provider.cpp
    src/cannon_data_provider.cpp
    src/cannon_data_point.cpp
)

# For Code::Blocks and other IDEs
file(GLOB cannon_sim_inc inc/*.hpp)

set(cannon_sim_libs
    sim_common
    ${ITC_Common_LIBRARIES}
    ${NOSENGINE_LIBRARIES}
)

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_RPATH}:$ORIGIN/../lib") # Pick up .so in install directory

add_library(cannon_sim SHARED ${cannon_sim_src} ${cannon_sim_inc})
target_link_libraries(cannon_sim ${cannon_sim_libs})
install(TARGETS cannon_sim LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
