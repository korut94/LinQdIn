#ifndef ID_H
#define ID_H

#include <iostream>
#include <QFormLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

#include "personal.h"
#include "levelaccess.h"

class ID : public QWidget
{
    Q_OBJECT

    public:
        ID( const Personal &, QWidget * = nullptr );
        ~ID();
};

#endif // ID_H
