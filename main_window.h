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
#include "vector"
#include "Element.h"
#include <QMutex>
#include <QWaitCondition>
#include <QLineEdit>
class Controller;



namespace gui{

class Main_Window : public QMainWindow
{
    Q_OBJECT
public:
    Main_Window(Controller * _ctrl);
    ~Main_Window();

    QMutex mutex;
    QWaitCondition isNotReady;
    bool refreshing;

private:

    Controller * ctrl;

    QAction *quitAction;
    QAction *preferenceAction;
    QAction *helpAction;
    QAction *aboutAction ;
    QAction *aboutQtAction;
    World_map_area * area;

    QWidget *centralWidget;

    QLineEdit *days;
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
    void printAtPosition(std::vector<Element*> *);

};

}

#endif // MAIN_WINDOW_H
