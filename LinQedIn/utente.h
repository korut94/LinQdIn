#ifndef UTENTE_H
#define UTENTE_H

#include <iostream>
#include <QList>
#include <QStringList>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "info.h"
#include "entity.h"
#include "levelaccess.h"
#include "smartptr_utente.h"

class smartptr_utente;

class Utente : public Entity
{
    public:
        class Rete : private QList<smartptr_utente>
        {
            public:
                class const_iterator
                    : public QList<smartptr_utente>::const_iterator
                {
                    public:
                        const_iterator();
                        const_iterator(
                            const QList<smartptr_utente>::const_iterator & );
                };

            public:
                Rete();

                bool isPresent( const smartptr_utente & t ) const;

                const_iterator begin() const;
                const_iterator end() const;

                QVector<smartptr_utente> toVector() const;

                void add( const smartptr_utente & t );
                void remove( const smartptr_utente & t );
        };

    private:
        bool activate;

        Rete contacts;

    protected:
		void readXmlUserData( QXmlStreamReader & );
        void writeXmlUserData( QXmlStreamWriter & ) const;

    public:
        Utente();
        Utente( const QString &, const Info & );
        virtual ~Utente();

        bool isActivate() const;
        bool isFriendOf( const smartptr_utente & ) const;

		virtual LevelAccess::Type typeAccount() const = 0;

        const Rete & getContatti() const;

        void addContact( const smartptr_utente & );
		virtual void readXmlFormat( QXmlStreamReader & ) = 0;
        void removeContact( const smartptr_utente & );
        void setActivate( bool );
        virtual void writeXmlFormat( QXmlStreamWriter & ) const = 0;
};

#endif // UTENTE_H
