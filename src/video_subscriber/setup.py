from setuptools import find_packages, setup

package_name = 'video_subscriber'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='altair',
    maintainer_email='abyanraditya.rakapasha@gmail.com',
    description='GUI subscriber for displaying video and detection results',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        'gui_subscriber = video_subscriber.vid_subscriber:main'
        ],
    },
)
