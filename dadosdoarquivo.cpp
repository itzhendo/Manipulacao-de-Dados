#include "dadosdoarquivo.h"

//namespace  ED2{// Inicio

    DadosDoArquivo::DadosDoArquivo(QString nomeDoArquivoNoDisco):
    nomeDoArquivoNoDisco(nomeDoArquivoNoDisco)
{
        std::ifstream arquivo;
        arquivo.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivo.is_open()) throw QString("Erro na Abertura do Arquivo");
        std::string linha;
        std::getline(arquivo,linha);
        for(tamanhoDoArquivo = 0; !arquivo.eof(); tamanhoDoArquivo++){std::getline(arquivo,linha);}
        arquivo.close();
}

Professor* DadosDoArquivo::obterDadosDoArquivo()
{
    int i =1 ;
    tamErro = 0;
    try
    {
        int pos = 0;

        std::ifstream arquivo;

        std::ofstream arquivoComErros;
        QString erroDeArquivo;

        arquivo.open(nomeDoArquivoNoDisco.toStdString().c_str());
        arquivoComErros.open("ErrosDoArquivo.txt");

        if(!arquivo.is_open() ) throw QString("Erro na Abertura do Arquivo");
        std::string linha;
        Professor* vetor =  new Professor[tamanhoDoArquivo];
        std::getline(arquivo,linha);
        while(!arquivo.eof())
        {

            QString linhaAux=QString::fromStdString(linha);
            i++;
            QStringList lista = linhaAux.split(';');
            if(lista.length()!=5)
            {

                erroDeArquivo ="Linha "+ QString::number(i)+" dados: "+ linhaAux;
                arquivoComErros<<erroDeArquivo.toStdString().c_str()<<endl;
                std::getline(arquivo,linha);
                tamErro++;
             }
            else
            {

                Professor Professor;
                vetor[pos].setMatricula(lista[0]);
                vetor[pos].setNome(lista[1]);
                vetor[pos].setDepartamento(lista[2]);
                vetor[pos].setTitulacao(lista[3]);
                vetor[pos].setTipoDeContrato(lista[4]);
                std::getline(arquivo,linha);
                pos++;
            }
        }
        arquivo.close();
        return vetor;
    }
    catch (QString &erro)
    {
    throw erro;
    }
    catch(std::bad_alloc&)
    {
    throw QString("Estrutura de dados vector nao criada");
    }
 }

