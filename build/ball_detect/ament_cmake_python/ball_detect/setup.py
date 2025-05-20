from setuptools import find_packages
from setuptools import setup

setup(
    name='ball_detect',
    version='0.0.0',
    packages=find_packages(
        include=('ball_detect', 'ball_detect.*')),
)
