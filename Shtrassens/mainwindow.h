#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>
#include "matrix.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    int x1;          //sizeOf arrays
    int y1;
    int x2;
    int y2;

    int **A;
    int **B;
    int **Result;
    unsigned sharedSize;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Generate_clicked();

    void on_Shtrass_Meth_clicked();

    void on_Vinogr_Shtrass_Meth_clicked();

    void on_Tradicional_Meth_clicked();

    void on_outputBtn_clicked();

    void on_writeFileBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
