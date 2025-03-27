from setuptools import find_packages
from setuptools import setup

setup(
    name='temp_ball_detector',
    version='0.0.0',
    packages=find_packages(
        include=('temp_ball_detector', 'temp_ball_detector.*')),
)
