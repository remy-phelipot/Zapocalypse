#include "preference_window.h"

#include <QLineEdit>
#include <QDesktopWidget>
#include <QApplication>
namespace gui{


preference_window::preference_window(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout* vl = new QVBoxLayout(this);
    QFormLayout* fl = new QFormLayout();

    QHBoxLayout* hl = new QHBoxLayout();

    vl->addLayout(fl);
    vl->addLayout(hl);

    QLabel *HumanNbH = new QLabel("Nombre d'humain (M)");
    QLabel *HumanNbF = new QLabel("Nombre d'humain (F)");
    QLabel *woodLimit = new QLabel("Limite de bois");
    QLabel *foodLimit = new QLabel("Limite de  nourriture");
    QLabel *incubationPeriod = new QLabel("Periode d'incubation");
    QLabel *nbHexagonX = new QLabel("Nombre d'hexagone en x");
    QLabel *nbHexagonY = new QLabel("Nombre d'hexagone en y");
    QLabel *lifeEsperancy = new QLabel("Esperance de vie max");
    QLabel *zombieFrequency = new QLabel("Frequence d'apparition des humains");

    QLineEdit *HumanNbHLE = new QLineEdit(this);
    QLineEdit *HumanNbFLE = new QLineEdit(this);
    QLineEdit *woodLimitLE = new QLineEdit(this);
    QLineEdit *foodLimitLE = new QLineEdit(this);
    QLineEdit *incubationPeriodLE = new QLineEdit(this);
    QLineEdit *nbHexagonXLE = new QLineEdit(this);
    QLineEdit *nbHexagonYLE = new QLineEdit(this);
    QLineEdit *lifeEsperancyLE = new QLineEdit(this);
    QLineEdit *zombieFrequencyLE = new QLineEdit(this);

    QPushButton* ok = new QPushButton("&Ok");
    QPushButton* cancel = new QPushButton("&Cancel");

    fl->addRow(HumanNbH,HumanNbHLE);
    fl->addRow(HumanNbF,HumanNbFLE);
    fl->addRow(woodLimit,woodLimitLE);
    fl->addRow(foodLimit,foodLimitLE);
    fl->addRow(incubationPeriod,incubationPeriodLE);
    fl->addRow(nbHexagonX,nbHexagonXLE);
    fl->addRow(nbHexagonY,nbHexagonYLE);
    fl->addRow(lifeEsperancy,lifeEsperancyLE);
    fl->addRow(zombieFrequency,zombieFrequencyLE);

    hl->addWidget(ok);
    hl->addWidget(cancel);


    connect(cancel,SIGNAL(clicked()),this, SLOT(cancelAction()));
    connect(ok,SIGNAL(clicked()),this, SLOT(okAction()));

    this->setLayout(vl);

    this->setWindowFlags(Qt::Window);
    this->setWindowModality(Qt::WindowModal);

    cancel->setDefault(true);

    CenterParent(parent,this);
}

void preference_window::cancelAction(){
    this->setVisible(false);
    delete(this);
}

void preference_window::okAction(){
    if (true){
        QMessageBox::warning(this,"Empty fields","One or many fields are empty, please check its",QMessageBox::Ok,QMessageBox::NoButton);
    }else{
        delete(this);
    }

}

void CenterParent(QWidget* parent, QWidget* child)
{
QPoint centerparent(
parent->x() + ((parent->frameGeometry().width() - child->frameGeometry().width()) /2),
parent->y() + ((parent->frameGeometry().height() - child->frameGeometry().height()) /2));

QDesktopWidget * pDesktop = QApplication::desktop();
QRect sgRect = pDesktop->screenGeometry(pDesktop->screenNumber(parent));
QRect childFrame = child->frameGeometry();

if(centerparent.x() < sgRect.left())
    centerparent.setX(sgRect.left());
else if((centerparent.x() + childFrame.width()) > sgRect.right())
    centerparent.setX(sgRect.right() - childFrame.width());

if(centerparent.y() < sgRect.top())
    centerparent.setY(sgRect.top());
else if((centerparent.y() + childFrame.height()) > sgRect.bottom())
    centerparent.setY(sgRect.bottom() - childFrame.height());

child->move(centerparent);
}


}
