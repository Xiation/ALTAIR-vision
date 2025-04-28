# launch/ball_detect.launch.py
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='usb_cam',
            executable='usb_cam_node_exe',
            name='camera',
            output='screen'
        ),
        Node(
            package='altair_calibration',
            executable='cam_calibration',
            name='camera_calibration',
            output='screen'
            # remappings=[('image_raw', '/camera/image_raw')]  # Remap if needed
        )
    ])
