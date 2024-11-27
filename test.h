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
