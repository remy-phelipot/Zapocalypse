#ifndef THREAD_WORLD_H
#define THREAD_WORLD_H

#include <QThread>
#include "World.h"
#include "main_window.h"
class Controller;

class Thread_World : public QThread
{
    Q_OBJECT
    Controller * ctrl;
    World * world;
    gui::Main_Window * window;

    // Variable used to stop the thread/play turn loop
            bool playTurn;
public:
    Thread_World(Controller *,World *,gui::Main_Window *);
    void run();

    void setPlay(bool);
signals:
    void refreshMap (int,int,char);
public slots:
    
};

#endif // THREAD_WORLD_H
