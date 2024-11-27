# Ejercicio de Programación: Función `ejecutar`

## Planteamiento del Problema

Escribe una función llamada `ejecutar` que reciba dos números enteros y devuelva un resultado según las siguientes reglas:

1. Si ambos números son **positivos**, devuelve la suma de los dos.
2. Si ambos números son **negativos**, devuelve la resta del primero menos el segundo.
3. Si uno de los números es **cero**, devuelve el producto de ambos.
4. Si los números son de signos opuestos (uno positivo y otro negativo), devuelve `-1`.

---

## Estructura de los Tests

Vamos a implementar 8 pruebas unitarias para verificar el comportamiento de la función `ejecutar`:

1. **Test 1**: Comprobar que la suma de dos números positivos es correcta.
2. **Test 2**: Comprobar que la resta de dos números negativos es correcta.
3. **Test 3**: Comprobar que el producto de un número positivo y cero es correcto.
4. **Test 4**: Comprobar que el producto de un número negativo y cero es correcto.
5. **Test 5**: Comprobar que la función devuelve `-1` cuando uno de los números es positivo y el otro negativo.
6. **Test 6**: Comprobar el comportamiento cuando uno de los números es cero y el otro positivo.
7. **Test 7**: Comprobar el comportamiento cuando uno de los números es cero y el otro negativo.
8. **Test 8**: Comprobar el resultado cuando ambos números son cero.

---

## Estructura del proyecto

```
proyecto/
├── main.cpp
├── ejecutar.h
├── ejecutar.cpp
├── test/
│   ├── t_ejecutar.h
│   ├── t_ejecutar.cpp
├── proyecto.pro
```

---

## Implementación de la Función
### Archivo `main.cpp`
```cpp
#include "test.h"

#include <QApplication>
#include "test/t_test.h"
#include <QApplication>
#include <QtTest>
#include <QStringList>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    if (argc > 1 && QString(argv[1]) == "--test") {
        // Eliminar "--test" antes de pasar los argumentos a QTest
        QStringList testArgs;
        testArgs << argv[0]; // Nombre del ejecutable
        for (int i = 2; i < argc; ++i) {
            testArgs << argv[i];
        }
        t_test test;
        return QTest::qExec(&test, testArgs);
    } else {
        // Ejecución normal de la aplicación
        test window;
        window.show();
        return app.exec();
    }
}
```
### Archivo `ejecutar.h`

```cpp
#ifndef TEST_H
#define TEST_H

#include <QMainWindow>
#include <QtTest/QTest>

QT_BEGIN_NAMESPACE
namespace Ui {
class test;
}
QT_END_NAMESPACE

class test : public QMainWindow
{
    Q_OBJECT

public:
    test(QWidget *parent = nullptr);
    ~test();
    int ejecutar(int a, int b);

private:
    Ui::test *ui;
};
#endif // TEST_H

```

### Archivo `ejecutar.h`
```cpp
#include "test.h"
#include "ui_test.h"

test::test(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::test)
{
    ui->setupUi(this);
}

test::~test()
{
    delete ui;
}

int test::ejecutar(int a, int b)
{

}
```

## Implementación de los Tests
### Archivo t_ejecutar.h
```cpp
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

```

### Archivo t_ejecutar.cpp

```cpp
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

```

## Compilar el Proyecto: 
Configura tu proyecto en Qt Creator o usa qmake y make para compilarlo.

## Ejecutar el Programa:

### Modo normal:
```bash
./miaplicacion
```

### Modo pruebas:
```bash
./miaplicacion --test
```

Revisar Resultados: Si todas las pruebas son correctas, la salida mostrará que todos los tests pasaron exitosamente.