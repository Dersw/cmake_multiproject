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

arr_files[0]="run_bubble_sort.sh"
arr_files[1]="run_multilevel_menu.sh"

arr_folders[0]="bubble_sort"
arr_folders[1]="multilevel_menu"

for i in {0,1}; do
    cp "../$SOURCE_FOLDER/${arr_folders[i]}/${arr_files[i]}" "./${arr_folders[i]}"
done

cp "../run_tests.sh" .
