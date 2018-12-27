import sys

from pkg_resources import require, VersionConflict
from setuptools import setup, Extension

VERSION = '0.1'


def ext_modules():
    import numpy
    dspy = Extension('desmumepy',
                     include_dirs=[numpy.get_include()],
                     # libraries=['tcl83'],
                     # library_dirs=['/usr/local/lib'],
                     sources=['src/desmumepy/main.cpp'])
    return [dspy]


setup(
    name='desmumepy',
    version=VERSION,
    description='Python bindings for the DeSmuME emulator.',
    url='https://github.com/Signaltonsalat/DeSmuMEpy',
    author='Signaltonsalat',
    license='gpl2',
    packages=['src/desmumepy'],
    install_requires=['numpy'],
    ext_modules=ext_modules(),
)
