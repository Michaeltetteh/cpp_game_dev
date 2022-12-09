if [ -d build ]; then
    rm -rf build
fi

mkdir -p build

cmake -DRAPIDJSON_BUILD_DOC=OFF -DRAPIDJSON_BUILD_TESTS=OFF -DRAPIDJSON_BUILD_EXAMPLES=OFF -S . -B build
make -C build


# cd build/bin
# ./OpenGLAsteroid
# cd ../..
