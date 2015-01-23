#ifndef ADMININTERFACE_VIEW_H
#define ADMININTERFACE_VIEW_H

#include <iostream>
#include <QPushButton>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QWidget>

#include "labeltools.h"
#include "tableusers.h"
#include "utilityframe.h"

class AdminInterface_View : public QWidget
{
    Q_OBJECT

    private:
        QScrollArea * utility;

    signals:
        void requestToSearchUsers() const;

    public slots:
        void setFrameUtility( QWidget * );

    public:
        AdminInterface_View( QWidget * = nullptr );
        ~AdminInterface_View();
};

#endif // ADMININTERFACE_VIEW_H
