#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Generate_clicked()
{
    srand(time(NULL));

    x1 = ui->x1Size->value();
    y1 = ui->y1Size->value();
    x2 = ui->x2Size->value();
    y2 = ui->y2Size->value();

    sharedSize = findSize(max(max(x1,y1),max(x2,y2)));

    A = fillMatrix(sharedSize,x1,y1);
    B = fillMatrix(sharedSize,x2,y2);
    Result = makeMatrix(sharedSize);

    ui->isGenerated->setText("Ok");
    ui->isShtr->setText("");
    ui->isVinShtras->setText("");
    ui->isTradicional->setText("");
}

void MainWindow::on_Shtrass_Meth_clicked()
{
    unsigned int time =  clock();

    Result = multiplication1(A,B,sharedSize);

    time = clock() - time;
    ui->time1->setText(QString::number(time) + " (мс)");

    ui->isGenerated->setText("");
    ui->isShtr->setText("Ok");
    ui->isVinShtras->setText("");
    ui->isTradicional->setText("");
}

void MainWindow::on_Vinogr_Shtrass_Meth_clicked()
{
    unsigned int time =  clock();

    Result = multiplication2(A,B,sharedSize);

    time = clock() - time;
    ui->time2->setText(QString::number(time) + " (мс)");

    ui->isGenerated->setText("");
    ui->isShtr->setText("");
    ui->isVinShtras->setText("Ok");
    ui->isTradicional->setText("");
}

void MainWindow::on_Tradicional_Meth_clicked()
{
    unsigned int time =  clock();

    Result = multiplication3(A,B,sharedSize);

    time = clock() - time;
    ui->time3->setText(QString::number(time) + " (мс)");

    ui->isGenerated->setText("");
    ui->isShtr->setText("");
    ui->isVinShtras->setText("");
    ui->isTradicional->setText("Ok");
}

void MainWindow::on_outputBtn_clicked()
{
    int size = ui->outputSize->value();

    QString output = "";
    if (size > sharedSize)
        size = sharedSize;

    QString matrA = "";
    QString matrB = "";

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            output += QString::number(Result[i][j]) + " ";
            matrA += QString::number(A[i][j]) + " ";
            matrB += QString::number(B[i][j]) + " ";
        }
        output += "\n";
        matrA += "\n";
        matrB += "\n";
    }

    ui->outputMatrix->setText(output);
    ui->matrixA->setText(matrA);
    ui->matrixB->setText(matrB);

    if (ui->isShtr->text() == "Ok"){
        ui->MethodType->setText("Результат(Метод Штрассена):");
    }
    if (ui->isTradicional->text() == "Ok"){
        ui->MethodType->setText("Результат(Традиційний):");
    }
    if (ui->isVinShtras->text() == "Ok"){
        ui->MethodType->setText("Результат(Метод Вин.-Штрассена):");
    }
}

void MainWindow::on_writeFileBtn_clicked()
{
    QString output = "";
    QString matrA = "";
    QString matrB = "";

    for (int i = 0; i < sharedSize; i++){
        for (int j = 0; j < sharedSize; j++){
            output += QString::number(Result[i][j]) + " ";
            matrA += QString::number(A[i][j]) + " ";
            matrB += QString::number(B[i][j]) + " ";
        }
        output += "\n";
        matrA += "\n";
        matrB += "\n";
    }

    QFile fileA("matrA.txt");
    if (fileA.open(QIODevice::WriteOnly)){
        fileA.write(matrA.toUtf8());
        fileA.close();
    }

    QFile fileB("matrB.txt");
    if (fileB.open(QIODevice::WriteOnly)){
        fileB.write(matrB.toUtf8());
        fileB.close();
    }

    if (ui->isShtr->text() == "Ok"){
        QFile file1("shtrass_output.txt");
        if (file1.open(QIODevice::WriteOnly)){
            file1.write(output.toUtf8());
            file1.close();
        }
    }
    if (ui->isTradicional->text() == "Ok"){
        QFile file1("tradicional_output.txt");
        if (file1.open(QIODevice::WriteOnly)){
            file1.write(output.toUtf8());
            file1.close();
        }
    }
    if (ui->isVinShtras->text() == "Ok"){
        QFile file1("vinogradaShtrass_output.txt");
        if (file1.open(QIODevice::WriteOnly)){
            file1.write(output.toUtf8());
            file1.close();
        }
    }
}
