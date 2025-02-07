import subprocess
import os

def set_cam_setting(setting, value):
    cmd = f"v4l2-ctl -d /dev/video0 --set-ctrl {setting}={value}"
    subprocess.run(cmd, shell=True)

set_cam_setting("brightness", 180)
