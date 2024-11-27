#ifndef T_TEST_H
#define T_TEST_H

#include <QObject>
#include <QtTest>
#include "test.h"

class t_test : public QObject
{
    Q_OBJECT
private:
    test t;
private slots:
    void test1();  // Suma de dos números positivos
    void test2();  // Resta de dos números negativos
    void test3();  // Producto con cero positivo
    void test4();  // Producto con cero negativo
    void test5();  // Suma de positivo y negativo
    void test6();  // Combinación de positivo y cero
    void test7();  // Combinación de negativo y cero
    void test8();  // Dos ceros
};

#endif // T_TEST_H
