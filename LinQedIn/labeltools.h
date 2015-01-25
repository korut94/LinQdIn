#ifndef LABELTOOLS_H
#define LABELTOOLS_H

#include <QHBoxLayout>
#include <QPushButton>

class LabelTools : public QWidget
{
    Q_OBJECT

    signals:
        void search();
        void add();

    public:
        LabelTools( QWidget * = NULL );
        ~LabelTools();
};

#endif // LABELTOOLS_H
