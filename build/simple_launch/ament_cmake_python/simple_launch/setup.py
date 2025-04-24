from setuptools import find_packages
from setuptools import setup

setup(
    name='simple_launch',
    version='1.11.0',
    packages=find_packages(
        include=('simple_launch', 'simple_launch.*')),
)
