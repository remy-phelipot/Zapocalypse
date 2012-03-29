#include "thread_world.h"
#include "Controller.h"
#include "vector"

Thread_World::Thread_World(Controller * _ctrl,World * _w,gui::Main_Window * _win) :
    QThread()
{
    ctrl = _ctrl;
    world = _w;
    window = _win;
    playTurn = false;

    QObject::connect(this, SIGNAL(refreshMap(std::vector<Element*> *)), _win, SLOT(printAtPosition(std::vector<Element*> *)));
   }


void Thread_World::run(){
    playTurn = true;

    while(playTurn){
            cout<<"top";
            sleep(1);
            window->mutex.lock();
            world -> PlayTurn();
            window->mutex.unlock();
            emit refreshMap (world);


    }
}

void Thread_World::setPlay(bool _b){
    playTurn = _b;
}
