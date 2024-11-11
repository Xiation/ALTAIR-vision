cmake_minimum_required(VERSION 3.8)
project(ball_detector)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
# find_package(opencv REQUIRED)

# new packages
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)

# add_executable(ball_detector src/ball_detector.cpp)
# target_include_directories(ball_detector PUBLIC
#   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#   $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
# target_compile_features(ball_detector PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
# ament_target_dependencies(
#   ball_detector
#   "rclpy"
#   "opencv"
#   "rosidl_default_generators"
#   "std_msgs"
# )

rosidl_generate_interfaces(
  ${PROJECT_NAME}
  "vision_msgs/BallDistance.msg"
  DEPENDENCIES
  std_msgs
)


# install(TARGETS ball_detector
#   DESTINATION lib/${PROJECT_NAME})

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
