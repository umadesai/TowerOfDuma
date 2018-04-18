# Exit if any lines fail
set -e

echo Running cpplint...
cpplint --recursive src/
echo
echo Running cppcheck...

cppcheck --enable=all src/
echo
echo Passed linters
