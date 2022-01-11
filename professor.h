#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <QString>
#include <iostream>

using namespace std;
class Professor
{
private:
    QString matricula;
    QString nome;
    QString departamento;
    QString titulacao;
    QString tipoDeContrato;
public:
    Professor();
    QString getMatricula() const;
    void setMatricula(QString value);
    QString getNome() const;
    void setNome(const QString &value);
    QString getDepartamento() const;
    void setDepartamento(const QString &value);
    QString getTitulacao() const;
    void setTitulacao(const QString &value);
    QString getTipoDeContrato() const;
    void setTipoDeContrato(const QString &value);
};
#endif // PROFESSOR_H
