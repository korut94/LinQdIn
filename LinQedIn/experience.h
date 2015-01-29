#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include <QString>

class Experience
{
    private:
        QString work;
        QString company;
        QString period;
        QString description;

    public:
        Experience( const QString & = QString(),
                    const QString & = QString(),
                    const QString & = QString(),
                    const QString & = QString() );

        QString getCompany() const;
        QString getDescription() const;
        QString getPeriod() const;
        QString getWork() const;

        void setCompany( const QString & );
        void setDescroption( const QString & );
        void setPeriod( const QString & );
        void setWork( const QString & );
};

#endif // EXPERIENCE_H
