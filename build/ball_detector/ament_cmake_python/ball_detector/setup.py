from setuptools import find_packages
from setuptools import setup

setup(
    name='ball_detector',
    version='0.0.0',
    packages=find_packages(
        include=('ball_detector', 'ball_detector.*')),
)
