#ifndef FRANKENSTEIN_H
#define FRANKENSTEIN_H

#include "utente.h"

class Frankenstein : public Entity
{
    private:
        bool matchExperiences( const QVector<Experience> &,
                               const QVector<Experience> & ) const;
        bool matchSkills( const QVector<Skill> &,
                          const QVector<Skill> & ) const;
        bool partialMatch( const Experience &, const Experience & ) const;
        bool partialMatch( const Personal &, const Personal & ) const;
        bool partialMatch( const Skill &, const Skill & ) const;

    public:
        Utente::Rete contatti;

        Frankenstein();
        Frankenstein( const QString &, const Info & );
        Frankenstein( const Utente & );

        bool operator==( const Frankenstein & ) const;
        bool operator!=( const Frankenstein & ) const;
};

#endif // FRANKENSTEIN_H
