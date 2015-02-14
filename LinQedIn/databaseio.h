#ifndef DATABASEIO_H
#define DATABASEIO_H

#include "database.h"
#include "utenteexecutive.h"

class DatabaseIO : public Database
{
	private:
		bool loaded;
	
	protected:
		void setFlagLoad( bool );

	public:
		DatabaseIO();
		virtual ~DatabaseIO();

		bool isLoaded() const;

		virtual bool load() = 0;
		virtual bool save() = 0;

		virtual QString error() const = 0;
};

#endif
