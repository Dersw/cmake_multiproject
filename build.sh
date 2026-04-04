# "Ninja" / "ninja"

BUILD_TYPE="Ninja"
BUILD_SUFFIX="ninja"

BUILD_FOLDER="build_${BUILD_SUFFIX}"
SOURCE_FOLDER="projects"

mkdir -p "${BUILD_FOLDER}"
cd "${BUILD_FOLDER}" || exit 1

cmake -G "${BUILD_TYPE}" "../${SOURCE_FOLDER}"
cmake --build .

arr_files[0]="run_bubble_sort.sh"
arr_files[1]="run_bubble_sort_test.sh"
arr_files[2]="run_multilevel_menu.sh"
arr_files[3]="run_long_numbers_test.sh"
arr_files[4]="run_double_linked_list_test.sh"
arr_files[5]="run_vector_test.sh"

arr_folders[0]="bubble_sort"
arr_folders[1]="bubble_sort_test/test"
arr_folders[2]="multilevel_menu"
arr_folders[3]="long_numbers/test"
arr_folders[4]="double_linked_list/test"
arr_folders[5]="vector/test"

for i in {0..5}; do
    cp "../$SOURCE_FOLDER/${arr_folders[i]}/${arr_files[i]}" "./${arr_folders[i]}"
done

cp "../run_tests.sh" .
