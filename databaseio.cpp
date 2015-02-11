#include "databaseio.h"

DatabaseIO::DatabaseIO() : loaded( false )
{}


DatabaseIO::~DatabaseIO()
{}


bool DatabaseIO::isLoaded() const
{
	return loaded;
}


void DatabaseIO::setFlagLoad( bool state )
{
	loaded = state;
}
