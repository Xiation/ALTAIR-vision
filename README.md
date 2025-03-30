# ALTAIR-vision

This repository provides modules for ALTAIR humanoid vision software to be then used for ALTAIR vision packages enabling humanoid robot perceptions

---

## Prerequisites
Before using this repository, ensure to meet the following requirements:
- ROS2, specifically ROS jazzy
- cv_bridge
- C++ Opencv libray
- Ubuntu 24.04 (since jazzy only supports for ubuntu 24.04)

---

## Installing Prerequisites

### Opencv (Build with opencv_contrib)

#### 1. Install minimal prerequisites
``` bash
sudo apt update && sudo apt install -y cmake g++ wget unzip
```

#### 2. Download and unpack sources
```bash
wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.x.zip
unzip opencv.zip
unzip opencv_contrib.zip
```

#### 3. Create a build directory and switch into it
``` bash
mkdir -p build && cd build
```

#### 4. Configure (inside of the build directory)
``` bash
cmake -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib-4.x/modules ../opencv-4.x
```

#### 5. Build
``` bash
cmake --build .
```

## Cloning the Repository

### Option 1: Clone with Submodules (Recommended)
```bash
git clone --recurse-submodules https://github.com/Xiation/ALTAIR-vision.git
```
### Option 2: Clone and Initialize Submodules Manually
```bash
git clone https://github.com/Xiation/ALTAIR-vision.git

cd ALTAIR-vision

git submodule update --init --recursive
```

## Setting up Submodules
ALTAIR-VISION currently utilizes following open-source submodules:
- soccer_field_map_generator : A tool for generating soccer field maps.
- usb_cam : A ROS driver for USB cameras.

These submodules are located in the src directory. After cloning, ensure they are properly initialized by running:
``` bash
git submodule update --init --recursive
```

For more details, refer to the original repositories:
- [`soccer_field_map_generator`](https://github.com/ros-sports/soccer_field_map_generator "soccer_field_map_generator Repository")

- [`usb_cam`](https://github.com/ros-drivers/usb_cam "usb_cam Repository")

## usage
1. Build the project
```bash
cd ALTAIR-vision

colcon build
```
2. Launch the modules

currently the vision modules are still under development and may not run accordingly