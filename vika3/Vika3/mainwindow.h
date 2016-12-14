#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Person.h"
#include "Domain.h"
#include "Computer.h"
#include "PersonsAndComputers.h"
#include "persandcomp.h"
#include "addnewdialog.h"
#include "dialogedit.h"
#include "dialogeditcomputer.h"

#include <vector>
#include <QMainWindow>
#include <QTableWidgetItem>
#include <QDebug>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_btnNew_clicked();

    void on_btnDelete_clicked();

    void on_tblComputers_clicked(const QModelIndex &index);

    void on_tblPersons_clicked(const QModelIndex &index);

    void on_input_filter_person_textChanged(const QString &arg1);

    void on_comboBox_person_sort_currentIndexChanged(int index);

    void on_btnEdit_clicked();

    void on_radioButton_person_sort_asc_toggled(bool checked);

    void on_radioButton_person_sort_desc_toggled(bool checked);

    void on_actionNew_triggered();

    void on_radioButton_computer_sort_asc_toggled(bool checked);

    void on_radioButton_computer_sort_desc_toggled(bool checked);

    void on_comboBox_computer_sort_currentIndexChanged(int index);

    void on_input_filter_computer_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Domain domain;
    void displayAllPersons();
    void displayPersons(vector<Person> pers);
    void displayAllComputers();
    void displayComputers(vector<Computer> comp);
    void displayAllPersAndComp();
    //void displayPersAndComp(vector<PersonsAndComputers> pAc);

    void displayPersAndComp(vector<PersAndComp> pAc);
    string getPersonCurrentSortBy();
    string getComputerCurrentSortBy();
    vector<Person> currentlyDisplayedPersons;
    vector<Computer> currentlyDisplayedComputers;
    //vector<PersonsAndComputers> currentlyDisplayedPersAndComp;
    vector<PersAndComp> currentlyDisplayedPersAndComp;
};

#endif // MAINWINDOW_H
