# copy resource files
macro(copy_files files destination)
    foreach(file ${files})
        message(STATUS "Copying resource ${file}")
        file(COPY ${file} DESTINATION ${CMAKE_BINARY_DIR}/bin/${destination})
    endforeach()
endmacro()