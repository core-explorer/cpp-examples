cmake_minimum_required(VERSION 3.14)
project(CPlusPlusExamples)

# Enable extra warnings and turn warnings into errors for high quality code
add_compile_options(-pedantic -Werror)
# Always enable debug information
add_compile_options(-g3)

add_executable(PointerExample PointerExample.cpp)
add_executable(VirtualExample VirtualExample.cpp)
add_executable(VectorExample VectorExample.cpp)
add_executable(ArrayExample ArrayExample.cpp ArrayExample2.cpp)
add_executable(FunctionExample FunctionExample.cpp)
add_executable(NewExample NewExample.cpp)
add_executable(MallocExample MallocExample.cpp)
add_executable(DeleteExample DeleteExample.cpp)
add_executable(UniquePtrExample UniquePtrExample.cpp)
add_executable(LongJmpExample LongJmpExample.cpp)
add_executable(SharedPtrExample SharedPtrExample.cpp)


add_library(Auditor SHARED Auditor.c)
add_library(Weather SHARED Weather.c)
target_link_options(Weather PRIVATE -Wl,-z,lazy )
add_executable(LibraryExample LibraryExample.cpp)
target_link_libraries(LibraryExample PRIVATE Weather)

add_library(NoRtti SHARED NoRtti.cpp)
target_compile_options(NoRtti PRIVATE -fno-rtti )
add_executable(RttiExample RttiExample.cpp)
target_link_libraries(RttiExample PRIVATE NoRtti)

add_library(Static STATIC Static.cpp)
add_library(Shared SHARED Shared.cpp)
target_link_libraries(Shared PRIVATE Static)

add_executable(LinkingExample LinkingExample.cpp)
target_link_libraries(LinkingExample PRIVATE Static Shared)
