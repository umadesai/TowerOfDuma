# Exit if any lines fail
set -e

echo Running cpplint...
cpplint --recursive src/ include/
echo
echo Running cppcheck...

cppcheck --enable=all src/ include/
echo
echo Passed linters
