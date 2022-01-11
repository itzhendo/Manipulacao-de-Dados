#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabela->setStyleSheet("QTableView {selection-background-color:steelblue}");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::printLista()
{
    for (int i = listaProfessores->getTam(); i >= 0; i--)
        ui->tabela->removeRow(i);

    int linha = 0;

    for (int i = 0; i < listaProfessores->getTam(); i++, linha++)
    {
        ui->tabela->insertRow(linha);
        Professor n = listaProfessores->getDados()[i];
        ui->tabela->setItem(linha,0,new QTableWidgetItem(QString::number(i+1)));
        ui->tabela->setItem(linha,1,new QTableWidgetItem(n.getMatricula()));
        ui->tabela->setItem(linha,2,new QTableWidgetItem(n.getNome()));
        ui->tabela->setItem(linha,3,new QTableWidgetItem(n.getDepartamento()));
        ui->tabela->setItem(linha,4,new QTableWidgetItem(n.getTitulacao()));
        ui->tabela->setItem(linha,5,new QTableWidgetItem(n.getTipoDeContrato()));
   }
}

void MainWindow::on_pushButtonAbrir_clicked()
{
    try
    {
            nomeDoArquivo = QFileDialog::getOpenFileName(this,"Abrir Arquivo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)");
            if(nomeDoArquivo.isEmpty()) throw QString("Arquivo nao foi selecionado");

            ui->tabela->setColumnCount(6);
            //definir o cabecalho da tabela
            QStringList cabecalhos = {"","Matricula", "Nome", "Departamento", "Titulacao", "TipoDeContrato"};
            ui->tabela->setHorizontalHeaderLabels(cabecalhos);
            //nao poder editar os itens da tabela
            ui->tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
            //selecionar a linha toda
            ui->tabela->setSelectionBehavior(QAbstractItemView::SelectRows);
            //sumir com a linha ao lado
            ui->tabela->verticalHeader()->setVisible(false);

          //definir tamanho das colunas
            ui->tabela->setColumnWidth(0,50);//Pos
            ui->tabela->setColumnWidth(1,100);//Matricula
            ui->tabela->setColumnWidth(2,363);//Nome
            ui->tabela->setColumnWidth(3,100);//Departamento
            ui->tabela->setColumnWidth(4,100);//Titulacao
            ui->tabela->setColumnWidth(5,100);//TIpodeContrato

            listaProfessores =new  BuscaPorMatricula(nomeDoArquivo);
            printLista();
            ui->lineEditResult->setText(nomeDoArquivo);
            ui->lineEditResult->setEnabled(false);

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }

}

void MainWindow::sequencialMatricula()
{
    try
    {       
        QString matricula = ui->lineEditDados->text();
        Professor procurado;
        procurado.setMatricula(matricula);

        listaProfessores= new BuscaPorMatricula(listaProfessores);

        int n = listaProfessores->buscaSequencial(procurado);
        if(n==-1)throw QString("Não encontrado");
        else ui->tabela->selectRow(n);
    }  catch (QString &e) {
        QMessageBox::information(this,"Posicao do Professor",e);
    }
}

void MainWindow::sequencialNome()
{
    try
    {
        QString nome = ui->lineEditDados->text();
        Professor procurado;
        procurado.setNome(nome);

        listaProfessores= new BuscaPorNome(listaProfessores);

        int n = listaProfessores->buscaSequencial(procurado);
        if(n==-1)throw QString("Não encontrado");
        else ui->tabela->selectRow(n);

    }  catch (QString &e) {
        QMessageBox::information(this,"Posicao do Professor",e);
    }
}

void  MainWindow::binariaNome()
{
    try
    {
        QString nome = ui->lineEditDados->text();
        Professor procurado;
        procurado.setNome(nome);

        listaProfessores= new BuscaPorNome(listaProfessores);
        on_pushButtonAttOK_clicked();

        int n = listaProfessores->buscaBinaria(procurado,0,listaProfessores->getTam()-1);
        if(n==-1)throw QString("Não encontrado");
        else ui->tabela->selectRow(n);

    }  catch (QString &e) {
        QMessageBox::information(this,"Posicao do Professor",e);
    }
}
void  MainWindow::binariaMatricula()
{  
    try
    {
        QString matricula = ui->lineEditDados->text();
        Professor procurado;
        procurado.setMatricula(matricula);

        listaProfessores= new BuscaPorMatricula(listaProfessores);
        on_pushButtonAttOK_clicked();

        int n = listaProfessores->buscaBinaria(procurado,0,listaProfessores->getTam()-1);
        if(n==-1)throw QString("Não encontrado");
        else ui->tabela->selectRow(n);
    }  catch (QString &e) {
        QMessageBox::information(this,"Posicao do Professor",e);
    }
}

void MainWindow::orderName()
{
    listaProfessores = new BuscaPorNome(listaProfessores);

    listaProfessores->ordenar();
    printLista();
}

void MainWindow::orderMatricula()
{
    listaProfessores = new BuscaPorMatricula(listaProfessores);

    listaProfessores->ordenar();
    printLista();
}
void MainWindow::ordernarDepartamentoNome()
{
    listaProfessores = new orderDeptoName(listaProfessores);

    listaProfessores->ordenar();
    printLista();

}
void MainWindow::ordernarTitulacaoNome()
{

    listaProfessores = new OrderTitulacaoNome(listaProfessores);

    listaProfessores->ordenar();
    printLista();
}
void MainWindow::ordernarTipoContratoNome()
{
    listaProfessores = new OrderTipoContratoNome(listaProfessores);

    listaProfessores->ordenar();
    printLista();
}
void MainWindow::OrdernarDepartamentoTitulacaoNome()
{
    listaProfessores = new OrderDepartamentoTitulacaoNome(listaProfessores);

    listaProfessores->ordenar();
    printLista();
}
void MainWindow::OrdernarnarDeptTipoContratoNome()
{
    listaProfessores = new OrderDeptTipoContratoNome(listaProfessores);

    listaProfessores->ordenar();
    printLista();
}

void MainWindow::on_pushButtonAtt_clicked()
{
    try
    {
        if(ui->comboBox->currentIndex()==0)
        {
            sequencialNome();
        }
        else if(ui->comboBox->currentIndex()==1)
        {
            sequencialMatricula();
        }
        else if(ui->comboBox->currentIndex()==2)
        {
            binariaNome();
        }
        else
        {
            binariaMatricula();
        }
    }  catch (QString &e) {
        QMessageBox::information(this,"Erro",e);
    }
}

void MainWindow::on_pushButtonAttOK_clicked()
{
    try
    {
        if(ui->comboBoxOrdenacao->currentIndex()==1)
        {
            orderName();
        }
        else if(ui->comboBoxOrdenacao->currentIndex()==2)
        {
            orderMatricula();
        }
        else if(ui->comboBoxOrdenacao->currentIndex()==3)
        {
            ordernarDepartamentoNome();
        }
        else if(ui->comboBoxOrdenacao->currentIndex()==4)
        {
            ordernarTitulacaoNome();
        }
        else if(ui->comboBoxOrdenacao->currentIndex()==5)
        {
            ordernarTipoContratoNome();
        }
        else if(ui->comboBoxOrdenacao->currentIndex()==6)
        {
            OrdernarDepartamentoTitulacaoNome();
        }
        else if(ui->comboBoxOrdenacao->currentIndex()==7)
        {
            OrdernarnarDeptTipoContratoNome();
        }

    }catch (QString &e)
    {
        QMessageBox::information(this,"Erro",e);
    }
}
