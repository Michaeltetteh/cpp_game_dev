if [ -d build ]; then
    rm -rf build
fi

mkdir -p build

cmake -S . -B build
make -C build


cd build/bin
./OpenGLAsteroid
cd ../..
