#!/usr/bin/env python3

import os
import sys
import shutil
import subprocess

def get_cmake_path():
    return shutil.which("cmake")

def get_module_dir():
    return os.path.join(os.getcwd(), "malt_modules/")

def main():
    original_wd = os.getcwd()

    install_prefix = get_module_dir()
    cmake_dir = os.path.join(get_module_dir(), "modules/", sys.argv[1])
    if not os.path.exists(cmake_dir):
        os.makedirs(cmake_dir)
    os.chdir(cmake_dir)

    proc = subprocess.Popen([get_cmake_path(), "-DCMAKE_INSTALL_PREFIX=" + install_prefix, os.path.join(original_wd, sys.argv[1])])
    proc.wait()
    another = subprocess.Popen([get_cmake_path(), "--build", ".", "--", "-j16"])
    another = subprocess.Popen([get_cmake_path(), "--build", ".", "--", "install"])

if __name__ == '__main__':
    main()