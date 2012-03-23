#include "thread_world.h"
#include "Controller.h"

Thread_World::Thread_World(Controller * _ctrl,World * _w,gui::Main_Window * _win) :
    QThread()
{
    ctrl = _ctrl;
    world = _w;
    window = _win;
    playTurn = false;

    QObject::connect(this, SIGNAL(refreshMap(int,int,char)), _win, SLOT(printAtPosition(int,int,char)));
   }


void Thread_World::run(){
    unsigned int i;
    int valX, valY;
    playTurn = true;


    while(playTurn){
        sleep(1);
        for ( i = 0 ; i <= ( world -> size() - 1 ) ; i++ ) {
            valX = world -> at( i ) -> getMyPosition().GetposX();
            valY = world -> at( i ) -> getMyPosition().GetposY();
            //window -> printAtPosition( valX, valY, world -> at( i ) -> getImage() );
            //window -> printAtPosition();
            emit refreshMap (valX,valY,'c');
        }
// Play a turn
        world -> PlayTurn();
    }
}

void Thread_World::setPlay(bool _b){
    playTurn = _b;
}
