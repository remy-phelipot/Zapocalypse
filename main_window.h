#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QApplication>
#include <QMessageBox>
#include <QTextEdit>

#include "world_map_area.h"
#include "preference_window.h"

class Controller;

namespace gui{



class Main_Window : public QMainWindow
{
    Q_OBJECT
public:
    Main_Window(Controller * _ctrl);
    ~Main_Window();



private:

    Controller * ctrl;

    QAction *quitAction;
    QAction *preferenceAction;
    QAction *helpAction;
    QAction *aboutAction ;
    QAction *aboutQtAction;
    World_map_area * area;

    QWidget *centralWidget;

    QTextEdit *textarea;
    QPushButton *start;
    QPushButton *stop;

    void buildMenu();
signals:

public slots:
    void preference();
    void help();
    void about();
    void aboutQt();
    void startSimulation();
    void stopSimulation();
    void printAtPosition(int,int,char);

};

}

#endif // MAIN_WINDOW_H
