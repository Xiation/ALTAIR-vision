# launch/ball_detect.launch.py
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='usb_cam',
            executable='usb_cam_node_exe',
            name='camera',
            output='screen',
            parameters=[{
                'video_device': '/dev/video0',
                'image_width': 640,
                'image_height': 480,
                'framerate': 30.0,
                'pixel_format': 'yuyv',
                'camera_name': 'usb_cam',
                'camera_info_url': 'file:///home/abyan/Documents/FOR_ALTAIR/ALTAIR-vision/camera_calibration.yaml',
            }],
        ),
        Node(
            package='ball_detect',
            executable='ball_det',
            name='ball_detector',
            output='screen'
            # remappings=[
            #     ('image_raw', '/usb_cam/image_raw'),
            #     ('camera_info', '/usb_cam/camera_info')
            #     ]  # Remap if needed
        )
    ])
