# Exit if any lines fail
set -e

echo Running cpplint...
cpplint --recursive src/ include/
echo
echo Running cppcheck...

cppcheck --enable=all --suppress=missingIncludeSystem src/
echo
echo Passed linters
