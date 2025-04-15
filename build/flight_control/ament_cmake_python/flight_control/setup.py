from setuptools import find_packages
from setuptools import setup

setup(
    name='flight_control',
    version='0.0.0',
    packages=find_packages(
        include=('flight_control', 'flight_control.*')),
)
