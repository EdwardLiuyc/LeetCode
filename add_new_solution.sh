#!/bin/bash

NEW_SOLUTION_NAME=$1

mkdir -p $NEW_SOLUTION_NAME
cd $NEW_SOLUTION_NAME
echo 'add_executable('$NEW_SOLUTION_NAME' test_main.cc)' >> CMakeLists.txt
echo '#pragma once' >> solution.hpp
echo '#include <iostream>' >> test_main.cc
echo '#include "solution.hpp"' >> test_main.cc
echo '' >> test_main.cc
echo 'int main(int, char**) { return 0; }' >> test_main.cc

cd ..
echo 'add_subdirectory('$NEW_SOLUTION_NAME')' >> CMakeLists.txt


