#include "utente.h"

Utente::Rete::Rete()
{
}


bool Utente::Rete::isPresent( const smartptr_utente & t ) const
{
    bool found = false;

    QList<smartptr_utente>::const_iterator itr =
                                           QList<smartptr_utente>::begin();

    while( itr != QList<smartptr_utente>::end() && !found )
    {
        found = ( **itr == *t );
        itr++;
    }

    return found;
}


QVector<smartptr_utente> Utente::Rete::toVector() const
{
    return QList<smartptr_utente>::toVector();
}


void Utente::Rete::add( const smartptr_utente & t )
{
    if( !isPresent( t ) ) QList<smartptr_utente>::push_front( t );
}


void Utente::Rete::remove( const smartptr_utente & t )
{
    bool found = false;

    QList<smartptr_utente>::iterator itr = QList<smartptr_utente>::begin();

    while( itr != QList<smartptr_utente>::end() && !found )
    {
        if( **itr == *t )
        {
            QList<smartptr_utente>::erase( itr );
            found = true;
        }
        else itr++;
    }
}


Utente::Utente()
{
}


Utente::Utente( const QString & user,
                const Info & info )
                : online( false ), activate( false ), Entity( user, info )
{
}


Utente::~Utente()
{
}


bool Utente::isActivate() const
{
    return activate;
}


bool Utente::isFriendOf( const smartptr_utente & user ) const
{
    return contacts.isPresent( user );
}


bool Utente::isOnline() const
{
    return online;
}


const Utente::Rete & Utente::getContatti() const
{
    return contacts;
}


void Utente::addContact( const smartptr_utente & user )
{
    if( user != nullptr ) contacts.add( user );
}


void Utente::readXmlUserData( QXmlStreamReader & reader )
{
    Info & myInfo = getInfo();

    Personal & myPersonal = myInfo.getPersonal();

	QXmlStreamReader::TokenType token = reader.readNext();

	while( !( token == QXmlStreamReader::EndElement && 
			  reader.name() == "Info" ) )
	{
		if( token == QXmlStreamReader::StartElement )
		{
			if( reader.name() == "Personal" )
			{
				while( !( token == QXmlStreamReader::EndElement &&
						  reader.name() == "Personal" ) )
				{	
					if( reader.name() == "nome" )
					{
						token = reader.readNext();
			
						if( token == QXmlStreamReader::Characters )
                            myPersonal.setNome( reader.text().toString() );
	
						token = reader.readNext();
					}
	
					if( reader.name() == "cognome" )
					{
						token = reader.readNext();
	
						if( token == QXmlStreamReader::Characters )
                            myPersonal.setCognome( reader.text().toString() );
	
						token = reader.readNext();
					}
	
					if( reader.name() == "birthday" )
					{
						token = reader.readNext();
	
						if( token == QXmlStreamReader::Characters )
						{
							QString date = reader.text().toString();
							QStringList partsDate = date.split( '.' ); 

							int day = partsDate.at( 0 ).toInt();
							int month = partsDate.at( 1 ).toInt();
							int year = partsDate.at( 2 ).toInt();
	
                            myPersonal.setDate( QDate( year, month, day ) );
						}
				
						token = reader.readNext();
					}	
	
					if( reader.name() == "number" )
					{
						token = reader.readNext();
				
						if( token == QXmlStreamReader::Characters )
                            myPersonal.setNumTelefono(
                                        reader.text().toString() );
	
						token = reader.readNext();
					}

                    if( reader.name() == "actualwork" )
					{	
						token = reader.readNext();
	
						if( token == QXmlStreamReader::Characters )
                            myPersonal.setActualWork(
                                        reader.text().toString() );
	
						token = reader.readNext();
					}	

					token = reader.readNext();			
				} //while personal
			
				token = reader.readNext();	
			}

            if( reader.name() == "Experiences" )
			{
                while( !( token == QXmlStreamReader::EndElement &&
                          reader.name() == "Experiences" ) )
                {
                    if( reader.name() == "Experience" )
                    {
                        Experience exp;

                        while( !( token == QXmlStreamReader::EndElement &&
                                  reader.name() == "Experience" ) )
                        {
                            if(  reader.name() == "work" )
                            {
                                token = reader.readNext();

                                if( token == QXmlStreamReader::Characters )
                                    exp.setWork( reader.text().toString() );

                                token = reader.readNext();
                            }

                            if( reader.name() == "company" )
                            {
                                token = reader.readNext();

                                if( token == QXmlStreamReader::Characters )
                                    exp.setCompany( reader.text().toString() );

                                token = reader.readNext();
                            }

                            if( reader.name() == "period" )
                            {
                                token = reader.readNext();

                                if( token == QXmlStreamReader::Characters )
                                    exp.setPeriod( reader.text().toString() );

                                token = reader.readNext();
                            }

                            if( reader.name() == "description" )
                            {
                                token = reader.readNext();

                                if( token == QXmlStreamReader::Characters )
                                exp.setDescription( reader.text().toString() );

                                token = reader.readNext();
                            }

                            token = reader.readNext();
                        }

                        myInfo.addWorkExperience( exp );
                    }

                    token = reader.readNext();
                }
			}

            if( reader.name() == "Skills" )
            {
                while( !( token == QXmlStreamReader::EndElement &&
                          reader.name() == "Skills" ) )
                {
                    if( reader.name() == "skill" )
                    {
                        token = reader.readNext();

                        if( token == QXmlStreamReader::Characters )
                            myInfo.addSkill( reader.text().toString() );

                        token = reader.readNext();
                    }

                    token = reader.readNext();
                }
            }

            if( reader.name() == "Educations" )
            {
                while( !( token == QXmlStreamReader::EndElement &&
                          reader.name() == "Educations" ) )
                {
                    if( reader.name() == "Education" )
                    {
                        Experience sch;

                        while( !( token == QXmlStreamReader::EndElement &&
                                  reader.name() == "Education" ) )
                        {
                            if( reader.name() == "school" )
                            {
                                token = reader.readNext();

                                if( token == QXmlStreamReader::Characters )
                                    sch.setWork( reader.text().toString() );

                                token = reader.readNext();
                            }

                            if( reader.name() == "title" )
                            {
                                token = reader.readNext();

                                if( token == QXmlStreamReader::Characters )
                                    sch.setCompany( reader.text().toString() );

                                token = reader.readNext();
                            }

                            if( reader.name() == "time_period" )
                            {
                                token = reader.readNext();

                                if( token == QXmlStreamReader::Characters )
                                    sch.setPeriod( reader.text().toString() );

                                token = reader.readNext();
                            }

                            if( reader.name() == "description" )
                            {
                                token = reader.readNext();

                                if( token == QXmlStreamReader::Characters )
                                sch.setDescription( reader.text().toString() );

                                token = reader.readNext();
                            }

                            token = reader.readNext();
                        }

                        myInfo.addSchoolExperience( sch );
                    }

                    token = reader.readNext();
                }
            }
		}
		
		token = reader.readNext();
	}
}


void Utente::removeContact( const smartptr_utente & user )
{
    contacts.remove( user );
}


void Utente::setActivate( bool set )
{
    activate = set;
}


void Utente::setOnline( bool set )
{
    online = set;
}


void Utente::writeXmlUserData( QXmlStreamWriter & writer ) const
{
    writer.writeTextElement( "username", getUsername() );

    const Info & info = getInfo();
    writer.writeStartElement( "Info" ); //Open Info

    const Personal & personal = info.getPersonal();
    writer.writeStartElement( "Personal" ); //Open Personal

    writer.writeTextElement( "nome", personal.getNome() );
    writer.writeTextElement( "cognome", personal.getCognome() );
    writer.writeTextElement( "birthday",
                             personal.getDate().toString( "dd.M.yyyy" ) );
    writer.writeTextElement( "number", personal.getNumTelefono() );
    writer.writeTextElement( "actualwork", personal.getActualWork() );

    writer.writeEndElement(); //Close Personal

    const QVector<Experience> & exp = info.getWorkExperiences();
    writer.writeStartElement( "Experiences" ); //Open Experiences

    for( QVector<Experience>::const_iterator itr = exp.begin();
         itr != exp.end();
         itr++ )
    {
        writer.writeStartElement( "Experience" ); //Open Experience

        writer.writeTextElement( "work", itr->getWork() );
        writer.writeTextElement( "company", itr->getCompany() );
        writer.writeTextElement( "period", itr->getPeriod() );
        writer.writeTextElement( "description", itr->getDescription() );

        writer.writeEndElement(); //Close Experience
    }

    writer.writeEndElement(); //Close Experiences

    const QVector<Skill> & sks = info.getSkills();
    writer.writeStartElement( "Skills" ); //Open Skills

    for( QVector<Skill>::const_iterator itr = sks.begin();
         itr != sks.end();
         itr++ )
    {
        writer.writeTextElement( "skill", itr->getSkill() );
    }

    writer.writeEndElement(); //Close Skills

    const QVector<Experience> & sch = info.getSchoolExperiences();
    writer.writeStartElement( "Educations" ); //Open Educations

    for( QVector<Experience>::const_iterator itr = sch.begin();
         itr != sch.end();
         itr++ )
    {
        writer.writeStartElement( "Education" ); //Open Education

        writer.writeTextElement( "school", itr->getWork() );
        writer.writeTextElement( "title", itr->getCompany() );
        writer.writeTextElement( "time_period", itr->getPeriod() );
        writer.writeTextElement( "description", itr->getDescription() );

        writer.writeEndElement(); //Close Education
    }

    writer.writeEndElement(); //Close Educations

    writer.writeEndElement(); //Close Info
}











