project(KMeans)
cmake_minimum_required(VERSION 2.8)

find_package( Boost 1.40 COMPONENTS program_options REQUIRED)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIRS})

add_definitions(-std=c++11 -lboost_system)


aux_source_directory(app MAIN)
aux_source_directory(src SRC_LIST)
INCLUDE_DIRECTORIES(include)

add_executable(${PROJECT_NAME} ${SRC_LIST} ${SRC_FILTERS} ${MAIN})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
                      ${Boost_PROGRAM_OPTIONS_LIBRARIES}
                      ${Boost_FILESYSTEM_LIBRARIES}
                      ${Boost_SYSTEM_LIBRARIES})

