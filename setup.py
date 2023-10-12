from distutils.core import setup, Extension


# python3 setup.py build

module = Extension("Module", sources=["module.c"])

setup(
	name="PackageName",
	version="0.01",
	description="This is the example module created in C",
	ext_modules=[module],
)
