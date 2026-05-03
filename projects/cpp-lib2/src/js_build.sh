#!/usr/bin/env bash
set -euo pipefail

BUILD_OPTION=$1
if [[ "$BUILD_OPTION" == "debug" ]]; then
  BUILD_TYPE="Debug"
  BUILD_DIR="debug"
elif [[ "$BUILD_OPTION" == "release" ]]; then
  BUILD_TYPE="Release"
  BUILD_DIR="release"
fi

emcmake cmake \
  -S ../../ \
  -B ../../build/emscripten/$BUILD_DIR \
  -G Ninja \
  -D CMAKE_BUILD_TYPE=$BUILD_TYPE \
  -D THESIS_BUILD_CPP_LIB2=true

cmake \
  --build ../../build/emscripten/$BUILD_DIR

rm -rf dist
mkdir dist
ln \
  ../../build/emscripten/$BUILD_DIR/projects/cpp-lib2/cpp-lib2-emscripten.* \
  ./dist/ \
