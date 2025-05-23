cmake_minimum_required(VERSION 3.8)
project(altair_calibration)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)

if(OpenCV_FOUND)
  message(STATUS "OpenCV library status:")
  message(STATUS "  version: ${OpenCV_VERSION}")
  message(STATUS "  libraries: ${OpenCV_LIBS}")
  message(STATUS "  include path: ${OpenCV_INCLUDE_DIRS}")
endif()

include_directories(
  include
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(cam_calibration src/cam_calibration.cpp)

target_include_directories(cam_calibration PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)

ament_target_dependencies(cam_calibration
  "rclcpp"
  "sensor_msgs"
  "cv_bridge"
  "OpenCV"    
  )

target_compile_features(cam_calibration PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

install(TARGETS cam_calibration
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
