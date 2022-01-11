#ifndef DADOSDOARQUIVO_H
#define DADOSDOARQUIVO_H

#include<QString>
#include<fstream>
#include<professor.h>
#include<QStringList>
#include <QFileDialog>
#include<QWidget>
#include<iostream>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>



class DadosDoArquivo
{
private:
    QString nomeDoArquivoNoDisco;
    int tamanhoDoArquivo;
    int tamErro;
public:
    DadosDoArquivo(QString nomeDoArquivoNoDisco);

    int getTamanhoDoArquivo()const {return tamanhoDoArquivo;}
    int getTamDoErro()const{return tamErro;}
    Professor* obterDadosDoArquivo();
};


#endif // DADOSDOARQUIVO_H
