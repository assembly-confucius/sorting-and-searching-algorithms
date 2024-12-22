# Добавляем тесты для сортировок
add_executable(tests_sortings
        sortings/bubble.test.cpp
        sortings/shaker.test.cpp
        sortings/comb.test.cpp
        sortings/insertion.test.cpp
        sortings/merge.test.cpp
        sortings/selection.test.cpp
        sortings/counting.test.cpp
        sortings/quick.test.cpp
        sortings/heap.test.cpp
        sortings/binary_insertion.test.cpp
)

# Добавляем тесты для графов
add_executable(tests_graphs
        graphs/bfs.test.cpp
        graphs/dfs.test.cpp
)

# Линкуем тесты с библиотекой и Google Test
target_link_libraries(tests_sortings PRIVATE gtest_main lab4_lib)
target_link_libraries(tests_graphs PRIVATE gtest_main lab4_lib)

# Регистрируем тесты для CTest
add_test(NAME TestsSortings COMMAND tests_sortings)
add_test(NAME TestsGraphs COMMAND tests_graphs)
