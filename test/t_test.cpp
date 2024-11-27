#include "t_test.h"

void t_test::test1() {
    int result = t.ejecutar(5, 3);  // Suma de dos números positivos
    QCOMPARE(result, 8);  // La respuesta esperada es 8 (5 + 3)
}

void t_test::test2() {
    int result = t.ejecutar(-5, -3);  // Resta de dos números negativos
    QCOMPARE(result, -2);  // La respuesta esperada es -2 (-5 - (-3))
}

void t_test::test3() {
    int result = t.ejecutar(0, 3);  // Producto de cero positivo
    QCOMPARE(result, 0);  // El producto de cualquier número por cero es 0
}

void t_test::test4() {
    int result = t.ejecutar(5, -3);  // Caso positivo y negativo
    QCOMPARE(result, -1);  // La respuesta esperada es -1
}

void t_test::test5() {
    int result = t.ejecutar(0, 5);  // Producto de cero positivo
    QCOMPARE(result, 0);  // El producto de cualquier número por cero es 0
}

void t_test::test6() {
    int result = t.ejecutar(0, -5);  // Producto de cero negativo
    QCOMPARE(result, 0);  // El producto de cualquier número por cero es 0
}

void t_test::test7() {
    int result = t.ejecutar(0, 0);  // Producto de dos ceros
    QCOMPARE(result, 0);  // El producto de dos ceros es 0
}

void t_test::test8() {
    int result = t.ejecutar(-5, 3);  // Combinación de negativo y positivo
    QCOMPARE(result, -1);  // La respuesta esperada es -1
}
