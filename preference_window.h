#ifndef PREFERENCE_WINDOW_H
#define PREFERENCE_WINDOW_H

#include <QWidget>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "preference_window.h"
#include <QMessageBox>
namespace gui{


class preference_window : public QWidget
{
    Q_OBJECT
public:
    explicit preference_window(QWidget *parent = 0);
    
signals:
    
public slots:
    void cancelAction();
    void okAction();
};


void CenterParent(QWidget* parent, QWidget* child);
}

#endif // PREFERENCE_WINDOW_H
