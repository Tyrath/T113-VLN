#include "data.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
data::data()
{

}

void data::openDatabase() {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("vika2.sqlite");

    if (!m_db.open())
    {
       cout << "Error: connection with database fail" << endl;
    }
    else
    {
       cout << "Database: connection ok" << endl;
    }
}

void data::read(vector<Person>& pers)
{
    QSqlQuery query("SELECT ID, Name, Sex, Birth, Death, Status FROM persons");
    int idID = query.record().indexOf("ID");
    int idName = query.record().indexOf("Name");
    int idSex = query.record().indexOf("Sex");
    int idBirth = query.record().indexOf("Birth");
    int idDeath = query.record().indexOf("Death");
    int idStatus = query.record().indexOf("Status");
    while (query.next())
    {
        if (query.value(idStatus) == 0) {
            QString qid = query.value(idID).toString();
            string id = qid.toLocal8Bit().constData();
            QString qname = query.value(idName).toString();
            string name = qname.toLocal8Bit().constData();
            QString qsex = query.value(idSex).toString();
            string sex = qsex.toLocal8Bit().constData();
            QString qbirth = query.value(idBirth).toString();
            string birth = qbirth.toLocal8Bit().constData();
            QString qdeath = query.value(idDeath).toString();
            string death = qdeath.toLocal8Bit().constData();
            Person p(id, name, sex, birth, death);
            pers.push_back(p);
        }
    }
}

void data::readComputer(vector<Computer>& comp)
{
    QSqlQuery query("SELECT ID, Name, Year, Type, Built, Status FROM persons");
    int idID = query.record().indexOf("ID");
    int idName = query.record().indexOf("Name");
    int idYear = query.record().indexOf("Year");
    int idType = query.record().indexOf("Type");
    int idBuilt = query.record().indexOf("Built");
    int idStatus = query.record().indexOf("Status");
    while (query.next())
    {
        if (query.value(idStatus) == 0) {
            QString qid = query.value(idID).toString();
            string id = qid.toLocal8Bit().constData();
            QString qname = query.value(idName).toString();
            string name = qname.toLocal8Bit().constData();
            QString qyear = query.value(idYear).toString();
            string year = qyear.toLocal8Bit().constData();
            QString qtype = query.value(idType).toString();
            string type = qtype.toLocal8Bit().constData();
            QString qbuilt = query.value(idBuilt).toString();
            string built = qbuilt.toLocal8Bit().constData();
            Computer c(id, name, year, type, built);
            comp.push_back(c);
        }
    }
}

void data::write(string& firstname, string& sex, string& birth, string& death)
{
    QSqlQuery query;
    QString qfirstname = QString::fromStdString(firstname);
    QString qsex = QString::fromStdString(sex);
    QString qbirth = QString::fromStdString(birth);

    QString qdeath= QString::fromStdString(death);
    query.prepare("INSERT INTO persons (Name, Sex, Birth, Death,Status)"
                      "VALUES (:name, :sex, :birth, :death, :status)");

        query.bindValue(":name", qfirstname);
        query.bindValue(":sex", qsex);
        query.bindValue(":birth", qbirth);
        query.bindValue(":death", qdeath);
        query.bindValue(":status",0);
        query.exec();
}

void data::writeComputer(string& name, string& year, string& type, string& built)
{
    QSqlQuery query;
    QString qname = QString::fromStdString(name);
    QString qyear = QString::fromStdString(year);
    QString qtype = QString::fromStdString(type);
    QString qbuilt = QString::fromStdString(built);
    query.prepare("INSERT INTO computer (computer_name, computer_year, computer_type, computer_built)"
                      "VALUES (:name, :year, :type, :built)");
        query.bindValue(":name", qname);
        query.bindValue(":year", qyear);
        query.bindValue(":type", qtype);
        query.bindValue(":built", qbuilt);
        query.exec();
}

void data::remove(string& ID) {
    QSqlQuery query;
    QString qID = QString::fromStdString(ID);
    query.prepare("UPDATE persons SET status = 1 WHERE ID = :id");

    query.bindValue(":id", qID);
    query.exec();
}

void data::edit(string& ID, string& value, string& type) {
    QSqlQuery query;
    QString qID = QString::fromStdString(ID);
    QString qvalue = QString::fromStdString(value);
    if (type == "-firstname")
    {
        query.prepare("Update persons SET name = :value WHERE ID = :id");
        query.bindValue(":id", qID);
        query.bindValue(":value", qvalue);
    }
    else if (type == "-sex")
    {
        query.prepare("Update persons SET sex = :value WHERE ID = :id");
        query.bindValue(":id", qID);
        query.bindValue(":value", qvalue);
    }
    else if (type == "-birth")
    {
        query.prepare("Update persons SET birth = :value WHERE ID = :id");
        query.bindValue(":id", qID);
        query.bindValue(":value", qvalue);
    }
    else if (type == "-death")
    {
        query.prepare("Update persons SET death = :value WHERE ID = :id");
        query.bindValue(":id", qID);
        query.bindValue(":value", qvalue);
    }
    query.exec();
}
