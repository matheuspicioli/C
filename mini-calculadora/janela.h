#ifndef JANELA_H
#define JANELA_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class Janela;
}

class Janela : public QMainWindow
{
    Q_OBJECT

public:
    explicit Janela(QWidget *parent = 0);
    ~Janela();

private slots:
    void on_btnSoma_clicked();

    void on_btnSub_clicked();

    void on_btnMult_clicked();

    void on_btnDiv_clicked();

private:
    Ui::Janela *ui;
};

#endif // JANELA_H
