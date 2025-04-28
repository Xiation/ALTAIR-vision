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
            package='ball_detect',
            executable='ball_det',
            name='ball_detector',
            output='screen',
            remappings=[('image_raw', '/camera/image_raw')]  # Remap if needed
        )
    ])
