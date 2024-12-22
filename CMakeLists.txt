cmake_minimum_required(VERSION 3.30)
project(sorts_and_graphs)

set(CMAKE_CXX_STANDARD 20)

# Подключаем FetchContent для Google Test
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

FetchContent_MakeAvailable(googletest)

# Указываем поддержку тестирования
enable_testing()

# Создаём статическую библиотеку с общей логикой
add_library(lab4_lib STATIC
        src/bfs.cpp
        src/binary_insertion.cpp
        src/bubble.cpp
        src/comb.cpp
        src/counting.cpp
        src/dfs.cpp
        src/heap.cpp
        src/insertion.cpp
        src/merge.cpp
        src/quick.cpp
        src/selection.cpp
        src/shaker.cpp
        include/toInclude.h
)

target_include_directories(lab4_lib PUBLIC include)

# Создаём исполняемый файл для основного приложения
add_executable(lab4 main.cpp)
target_link_libraries(lab4 PRIVATE lab4_lib)

# Подключаем папку с тестами
add_subdirectory(tests)
