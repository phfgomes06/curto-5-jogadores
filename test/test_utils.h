#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <stdio.h>

// Função para imprimir resultados dos testes com cores
static inline void print_test_result(const char *test_name, int passed) {
    if (passed) {
        printf("\033[0;32m[PASS] %s\033[0m\n", test_name); // Verde
    } else {
        printf("\033[0;31m\033[9m[FAIL] %s\033[0m\n", test_name); // Vermelho com tachado
    }
}

// Macro para verificar expressões e imprimir resultados
#define ASSERT_TEST(expr, test_name) \
    do { \
        if (expr) { \
            print_test_result(test_name, 1); \
        } else { \
            print_test_result(test_name, 0); \
        } \
    } while (0)

#endif // TEST_UTILS_H
