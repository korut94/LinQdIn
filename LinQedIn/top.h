#ifndef TOP_H
#define TOP_H

#include <iostream>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "levelaccess.h"

class Top : public QWidget
{
    Q_OBJECT

    public:
        Top( const LevelAccess::Type &, QWidget * = nullptr );
        ~Top();
};

#endif // TOP_H
