# ALTAIR-vision

This repository provides modules for ALTAIR humanoid vision software to be then used for ALTAIR vision packages enabling humanoid robot perceptions

---

## Prerequisites
Before using this repository, ensure to meet the following requirements:
- ROS2, specifically ROS jazzy
- Opencv libray
- Ubuntu 24.04 (since jazzy only supports for ubuntu 24.04)

---

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