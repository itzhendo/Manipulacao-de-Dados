#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <professor.h>
#include <metododeordenacao.h>
#include <buscapormatricula.h>
#include <buscapornome.h>
#include <orderdeptoname.h>
#include <ordertitulacaonome.h>
#include <ordertipocontratonome.h>
#include <orderdepartamentotitulacaonome.h>
#include <orderdepttipocontratonome.h>
#include <QFileDialog>
#include <QString>
#include <dadosdoarquivo.h>
#include <QMessageBox>
#include <fstream>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonAbrir_clicked();
    void sequencialNome();
    void sequencialMatricula();
    void binariaNome();
    void binariaMatricula();
    void orderMatricula();
    void orderName();
    void ordernarDepartamentoNome();
    void ordernarTitulacaoNome();
    void ordernarTipoContratoNome();
    void OrdernarDepartamentoTitulacaoNome();
    void OrdernarnarDeptTipoContratoNome();
    void printLista();
    void on_pushButtonAtt_clicked();
    void on_pushButtonAttOK_clicked();

private:
    Ui::MainWindow *ui;
    QString nomeDoArquivo;
    MetodoDeOrdenacao* listaProfessores;
    DadosDoArquivo *Vetor;
};
#endif // MAINWINDOW_H
