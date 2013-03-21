/*    Copyright (c) 2010-2013, Delft University of Technology
 *    All rights reserved.
 *
 *    Redistribution and use in source and binary forms, with or without modification, are
 *    permitted provided that the following conditions are met:
 *      - Redistributions of source code must retain the above copyright notice, this list of
 *        conditions and the following disclaimer.
 *      - Redistributions in binary form must reproduce the above copyright notice, this list of
 *        conditions and the following disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *      - Neither the name of the Delft University of Technology nor the names of its contributors
 *        may be used to endorse or promote products derived from this software without specific
 *        prior written permission.
 *
 *    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
 *    OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *    COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 *    GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *    AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 *    OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *    Changelog
 *      YYMMDD    Author            Comment
 *      120529    K. Kumar          File created.
 *      130212    K. Kumar          Migrated to GeneralTools project; renamed file.
 *
 *    References
 *      SQLite3++, http://code.google.com/p/sqlite3pp/, last accessed: 12th Feb, 2013.
 *
 *    Notes
 *      To use this wrapper, you must have the SQLite3 C-interface configured to be accessible
 *      within your project.
 *
 *      Unit tests have to still be written for the wrapper class.
 *
 */

#ifndef ASSIST_SQLITE3_DATABASE_CONNECTOR_H
#define ASSIST_SQLITE3_DATABASE_CONNECTOR_H

#include <iostream>
#include <string>
#include <stdexcept>

#include <boost/exception/all.hpp>
#include <boost/shared_ptr.hpp>

#include <sqlite3.h>

namespace assist
{
namespace database
{

//! Sqlite3 database connector class.
/*!
 * This class is a simple C++ wrapper for the C-interface for sqlite3. Inspiration is drawn from
 * the SQLite3++ interface (SQLite++, 2013).
 */
class Sqlite3DatabaseConnector
{
public:

    //! Constructor that takes absolute path to database file.
    /*!
     * Constructor that takes the absolute path to the SQLite3 database file. The constructor
     * attempts to open the database. If the file doesn't exist, a runtime error is thrown.
     * \param absolutePathToDatabase
     */
    Sqlite3DatabaseConnector( const std::string& absolutePathToDatabase )
    {
        if ( sqlite3_open( absolutePathToDatabase.c_str( ), &database ) != SQLITE_OK )
        {
            closeDatabase( );
            boost::throw_exception(
                        boost::enable_error_info(
                            std::runtime_error( "Database could not be opened!" ) ) );
        }
    }

    //! Destructor that closes the database.
    ~Sqlite3DatabaseConnector( ) { closeDatabase( ); }

    //! Close database.
    void closeDatabase( ) { sqlite3_close( database ); }

    void execute( const std::string& sqlCommand )
    {
        // Check if sql statement exited with an error message and throw runtime error if necessary.
        if ( sqlite3_exec( database, sqlCommand.c_str( ), 0, 0, &databaseErrorMessage )
             != SQLITE_OK )
        {
            sqlite3_free( databaseErrorMessage );
            finalizeStatement( );
            closeDatabase( );
            boost::throw_exception( boost::enable_error_info(
                                        std::runtime_error( "Statement execution failed!" ) ) );
        }
    }

    void prepare_v2( const std::string& sqlCommand )
    {
        if ( sqlite3_prepare_v2( database, sqlCommand.c_str( ),
                                 sqlCommand.size( ), &sqlStatement, 0 ) != SQLITE_OK )
        {
            finalizeStatement( );
            closeDatabase( );
            boost::throw_exception(
                        boost::enable_error_info(
                            std::runtime_error( "SQL statement was not prepared correctly!" ) ) );
        }
    }

    void bind( const int value, const int index )
    {
        sqlite3_bind_int( sqlStatement, index, value );
    }

    void bind( const double value, const int index )
    {
        sqlite3_bind_double( sqlStatement, index, value );
    }

    void bind( const std::string& text, const int index )
    {
        sqlite3_bind_text( sqlStatement, index, text.c_str( ), text.size( ), NULL );
    }

    double fetchDouble( const int column )
    {
        return sqlite3_column_double( sqlStatement, column );
    }

    int fetchInteger( const int column )
    {
        return sqlite3_column_int( sqlStatement, column );
    }

    std::string fetchString( const int column )
    {
        return reinterpret_cast< const char* >( sqlite3_column_text( sqlStatement, column ) );
    }

    int step( )
    {
        int status = sqlite3_step( sqlStatement );

        if ( status == SQLITE_ERROR )
        {
            finalizeStatement( );
            closeDatabase( );
            boost::throw_exception(
                        boost::enable_error_info(
                            std::runtime_error( "Error in step function!" ) ) );
        }

        return status;
    }

    void clearBindings( )
    {
        sqlite3_clear_bindings( sqlStatement );
    }

    void finalizeStatement( )
    {
        sqlite3_finalize( sqlStatement );
    }

    void resetStatement( )
    {
        sqlite3_reset( sqlStatement );
    }

    //!
    void beginTransaction( )
    {
        execute( "BEGIN;" );
    }

    void endTransaction( )
    {
        execute( "END;" );
    }

protected:

private:

    //! SQLite database connection.
    sqlite3* database;

    //! Database error message.
    char* databaseErrorMessage;

    //! SQL statement.
    sqlite3_stmt* sqlStatement;
};

//! Typedef for shared-pointer to SQLite3 database connector.
typedef boost::shared_ptr< Sqlite3DatabaseConnector > Sqlite3DatabaseConnectorPointer;

} // namespace database
} // namespace assist

#endif // ASSIST_SQLITE3_DATABASE_CONNECTOR_H
