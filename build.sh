#!/bin/bash
if [ "$#" -eq 1 ]; then
    tool=$1
else
    read -rp "Choose build tools qmake[q] or cmake[c] ? " tool
fi
case $tool in 
    q*) 
        tool=qmake
    ;;
    c*)
        tool=cmake
esac
version=$(ls ~/Qt/ | grep "[0-9]")
if [[ "${tool}" == "cmake" ]]; then
    buildtool="cmake .. -DQT_VERSION=${version}"
elif [[ "${tool}" == "qmake" ]]; then
    buildtool="$HOME/Qt/6.2.7/gcc_64/bin/qmake6 ${PWD}/AM.pro"
fi


if [ -n "${buildtool}" ]; then
    rm -rf build || exit
    mkdir -p build || exit 
    cd build || exit
    eval "${buildtool}" 
    make -j8
fi
