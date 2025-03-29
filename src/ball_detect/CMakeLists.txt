cmake_minimum_required(VERSION 3.8)
project(ball_detect)

# Debugging
message(STATUS "rclcpp_INCLUDE_DIRS: ${rclcpp_INCLUDE_DIRS}")
message(STATUS "type_description_interfaces_INCLUDE_DIRS: ${type_description_interfaces_INCLUDE_DIRS}")
message(STATUS "AMENT_PREFIX_PATH: $ENV{AMENT_PREFIX_PATH}")

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(OpenCV REQUIRED)

# Add executable
add_executable(ball_det src/ball_detect.cpp src/ball_detector_node.cpp)

# Include directories
target_include_directories(ball_det PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${rclcpp_INCLUDE_DIRS}
  ${sensor_msgs_INCLUDE_DIRS}
  ${cv_bridge_INCLUDE_DIRS}
  ${image_transport_INCLUDE_DIRS}
  /opt/ros/jazzy/include  # Add this line
)

# Link libraries
target_link_libraries(ball_det
  ${OpenCV_LIBS}
  rclcpp
  sensor_msgs
  cv_bridge
  image_transport
)

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
