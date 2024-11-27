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
/*
Queremos escribir una función llamada ejecutar que reciba dos números enteros y devuelva su suma si ambos números son positivos, su resta si ambos son negativos, o el producto si uno de los dos números es cero.

Requisitos del problema:

Si ambos números son positivos, la función debe devolver su suma.
Si ambos números son negativos, la función debe devolver su resta (el primero menos el segundo).
Si uno de los números es cero, debe devolver el producto de ambos (siendo el producto de cualquier número por cero igual a cero).
En cualquier otro caso (combinación de positivo/negativo), debe devolver -1.
*/
int test::ejecutar(int a, int b)
{
    if(a>0 && b>0){
        return a+b;
    }else if(a<0 && b<0){
        return a-b;
    }else if(a==0 || b==0){
        return 0;
    }else{
        return -1;
    }
}


