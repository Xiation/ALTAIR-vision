cmake_minimum_required(VERSION 3.8)
project(ball_detect)

# Debugging: Print current working directory
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

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
include_directories(${OpenCV_INCLUDE_DIRS})
target_include_directories(ball_det PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

ament_target_dependencies(ball_det 
  "rclcpp"
  "sensor_msgs"
  "cv_bridge"
  "image_transport"
  "OpenCV"    
  )

# Link libraries
target_link_libraries(ball_det ${OpenCV_LIBS} rclcpp::rclcpp 
cv_bridge::cv_bridge
)

# Install the executable
install(TARGETS ball_det
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
