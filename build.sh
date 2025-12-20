#!/bin/sh

# "Ninja" / "ninja"

BUILD_TYPE="Ninja"
BUILD_SUFFIX="ninja"

BUILD_FOLDER="build_${BUILD_SUFFIX}"
SOURCE_FOLDER="projects"

mkdir -p "${BUILD_FOLDER}"
cd "${BUILD_FOLDER}" || exit 1

cmake -G "${BUILD_TYPE}" "../${SOURCE_FOLDER}"
cmake --build .

mkdir -p bubble_sort
cp "../${SOURCE_FOLDER}/bubble_sort/run_bubble_sort.sh" ./bubble_sort
