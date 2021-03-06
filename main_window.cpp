#include "main_window.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QStyle>
#include <QDesktopWidget>
#include <iostream>
#include "Controller.h"

namespace gui{
Main_Window::Main_Window(Controller * _ctrl) :
    QMainWindow(),
    isNotReady()
{
    ctrl = _ctrl;
    refreshing = false;
    buildMenu();
    QVBoxLayout *layout = new QVBoxLayout();
    QHBoxLayout *hlayout = new QHBoxLayout();
    QVBoxLayout *boutons= new QVBoxLayout();

    days = new QLineEdit();
    textarea = new QTextEdit();
    centralWidget = new QWidget;
    start = new QPushButton("Start");
    stop = new QPushButton("Stop");
    area = new gui::World_map_area(centralWidget,800,450);

    area->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    days->setEnabled(false);
    textarea->setEnabled(false);

    days->setMaximumWidth(100);
    days->setAlignment(Qt::AlignRight);
    days->setText("0 days");


    layout->addWidget(area,0,Qt::AlignTop);
    layout->addLayout(hlayout);

    hlayout->addWidget(textarea);
    hlayout->addLayout(boutons,0);

    boutons->addWidget(days);
    boutons->addWidget(start);
    boutons->addWidget(stop);

    QObject::connect(start,SIGNAL(clicked()),this, SLOT(startSimulation()));
    QObject::connect(stop,SIGNAL(clicked()),this, SLOT(stopSimulation()));

    start->setEnabled(true);
    stop->setEnabled(false);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    setFixedSize(800,600);


    int x = QApplication::desktop()->availableGeometry(this).width() /2 - frameSize().width()/2;
    int y = QApplication::desktop()->availableGeometry(this).height() /2 - frameSize().height()/2;
    move(x,y);
}

Main_Window::~Main_Window(){
    setVisible(false);

    delete(quitAction);
    delete(preferenceAction);
    delete(helpAction);
    delete(aboutAction );
    delete(aboutQtAction);
    delete(area);
    delete(textarea);
    delete(start);
    delete(stop);
    delete(centralWidget);
}


void Main_Window::buildMenu(){
    QMenu *fileMenu;
    QMenu *editionMenu;
    QMenu *helpMenu;

    quitAction = new QAction("&Quit", this);
    preferenceAction = new QAction("&Preferences", this);
    helpAction = new QAction("&Help", this);
    aboutAction = new QAction("&About", this);
    aboutQtAction = new QAction("About &Qt", this);

    fileMenu = menuBar()->addMenu("&File");
    editionMenu = menuBar()->addMenu("&Edition");
    helpMenu = menuBar()->addMenu("&Help");


    fileMenu->addAction(quitAction);
    editionMenu->addAction(preferenceAction);
    helpMenu->addAction(helpAction);
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);


    connect(quitAction, SIGNAL(triggered()),qApp, SLOT(quit()));
    connect(preferenceAction, SIGNAL(triggered()),this, SLOT(preference()));
    connect(helpAction, SIGNAL(triggered()),this, SLOT(help()));
    connect(aboutAction, SIGNAL(triggered()),this, SLOT(about()));
    connect(aboutQtAction, SIGNAL(triggered()),this, SLOT(aboutQt()));
}

//slots

void Main_Window::preference(){
    preference_window *win = new preference_window(this,ctrl);
    win->setVisible(true);
    win->show();
}

void Main_Window::help(){

}

void Main_Window::about(){
    QMessageBox::about(this,"Zapocalipse","Made by 3 students of Blagnac IUT.");
}

void Main_Window::aboutQt(){
    QMessageBox::aboutQt(this,"Zapocalipse");
}
void Main_Window::startSimulation(){
    start->setEnabled(false);
    stop->setEnabled(true);
    preferenceAction->setEnabled(false);
    refreshing = false;

    ctrl->Play();
}

void Main_Window::stopSimulation(){
    start->setEnabled(true);
    stop->setEnabled(false);
    preferenceAction->setEnabled(true);

    refreshing = false;

    ctrl->setPlayTurn(false);
}

void Main_Window::printAtPosition(vector<Element*> * _v){
    int valX,valY;

    if (ctrl->getHumanNumber() > 0){
    mutex.lock();

    area->clearAll();

    for ( vector<Element*>::iterator it =  _v -> begin() ; it !=  _v -> end() ; ++it ) {
        valX = (*it) -> getMyPosition().GetposX();
        valY = (*it) -> getMyPosition().GetposY();
        area->addItem( valX, valY,(*it)->getType());
    }

    QString day =  QString::number(ctrl->getGameDate()) + " days";
    days->setText(day);



    refreshing = false;
    isNotReady.wakeAll();
    mutex.unlock();
    }else{
        QMessageBox::information(this,"End","All humans died. Number of days : "+QString::number(ctrl->getGameDate() -1));
        stopSimulation();

        mutex.lock();
        isNotReady.wakeAll();
        mutex.unlock();
        area->clearAll();
        area->repaint();
        ctrl->InitialiseWorld(20,20);

    }
}

}


