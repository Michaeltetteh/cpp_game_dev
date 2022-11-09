if [ -d build ]; then
    rm -rf build
fi

mkdir -p build
cd build
cmake ..

make
./bin/state_machine
cd ../
