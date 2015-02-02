#ifndef TOP_H
#define TOP_H

#include <iostream>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "levelaccess.h"
#include "smartptr_utente.h"

class Top : public QWidget
{
    Q_OBJECT

    public:
        Top( const smartptr_utente &, QWidget * = nullptr );
        ~Top();
};

#endif // TOP_H
