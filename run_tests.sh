BUILD_SUFFIX="ninja"
BUILD_FOLDER="build_${BUILD_SUFFIX}"

TEST_FILE="run_tests.sh"

cd "${BUILD_FOLDER}" || exit 1
./"${TEST_FILE}"
