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
