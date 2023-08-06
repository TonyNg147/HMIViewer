project(HOME)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt6 COMPONENTS AppManMainPrivate 
                 COMPONENTS Quick)
set(SOURCES main.cpp)
qt6_add_executable(HOME ${SOURCES})

# target_link_directories(AC PRIVATE ${PROJECT_BINARY_DIR}/../../apps/libraries)
target_link_libraries(HOME PRIVATE Qt6::AppManMainPrivate
                         PRIVATE Qt6::Quick)
                         #PRIVATE UICommon)

set_target_properties(HOME
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../../apps/HOME
)

