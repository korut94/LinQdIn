#ifndef LINK_H
#define LINK_H

#include <iostream>
#include <QHBoxLayout>
#include <QLabel>
#include <QString>
#include <QWidget>

class Link : public QWidget
{
    public:
        Link( const QString &,
              const QString & = "",
              QWidget * = NULL );
        ~Link();
};

#endif // LINK_H
