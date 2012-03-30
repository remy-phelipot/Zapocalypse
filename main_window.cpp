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
    QMainWindow()

{
    ctrl = _ctrl;

    buildMenu();
    QVBoxLayout *layout = new QVBoxLayout();
    QHBoxLayout *hlayout = new QHBoxLayout();
    QVBoxLayout *boutons= new QVBoxLayout();

    textarea = new QTextEdit();
    centralWidget = new QWidget;
    start = new QPushButton("Start");
    stop = new QPushButton("Stop");
    area = new gui::World_map_area(centralWidget,800,450);

    area->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    textarea->setEnabled(false);

    layout->addWidget(area,0,Qt::AlignTop);
    layout->addLayout(hlayout);

    hlayout->addWidget(textarea);
    hlayout->addLayout(boutons,0);

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

    ctrl->Play();
}

void Main_Window::stopSimulation(){
    start->setEnabled(true);
    stop->setEnabled(false);
    preferenceAction->setEnabled(true);

    ctrl->setPlayTurn(false);
}

void Main_Window::printAtPosition(vector<Element*> * _v){
    int valX,valY;

    area->clearAll();
    mutex.lock();
    for ( vector<Element*>::iterator it =  _v -> begin() ; it !=  _v -> end() ; ++it ) {
        valX = (*it) -> getMyPosition().GetposX();
        valY = (*it) -> getMyPosition().GetposY();
        cout<<valX<<valY;
        area->addItem( valX, valY,(*it)->getType());
    }
    mutex.unlock();
}

}


