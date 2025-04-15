from setuptools import find_packages
from setuptools import setup

setup(
    name='offboard_control_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('offboard_control_interfaces', 'offboard_control_interfaces.*')),
)
