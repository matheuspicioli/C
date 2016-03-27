#include "janela.h"
#include "ui_janela.h"

Janela::Janela(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Janela)
{
    ui->setupUi(this);
    setFixedSize(geometry().width(), geometry().height());
}

Janela::~Janela()
{
    delete ui;
}

void Janela::on_btnSoma_clicked()
{
    double resultado = ui->txt1->text().toDouble() + ui->txt2->text().toDouble();
    ui->txtResul->setText(QString("%1").arg(resultado));
}

void Janela::on_btnSub_clicked()
{
    double resultadoSub = ui->txt1->text().toDouble() - ui->txt2->text().toDouble();
    ui->txtResul->setText(QString("%1").arg(resultadoSub));
}

void Janela::on_btnMult_clicked()
{
    double resultadoSub = ui->txt1->text().toDouble() * ui->txt2->text().toDouble();
    ui->txtResul->setText(QString("%1").arg(resultadoSub));
}

void Janela::on_btnDiv_clicked()
{
    if(ui->txt2->text().toDouble() == 0)
    {
        QMessageBox::critical(this, "Erro", "<font color=red>Não pode dividir por 0</font>", QMessageBox::Cancel);
        return;
    }
    else
    {
        double resultadoSub = ui->txt1->text().toDouble() / ui->txt2->text().toDouble();
        ui->txtResul->setText(QString("%1").arg(resultadoSub));
    }

}
