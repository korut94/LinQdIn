#ifndef INFO_H
#define INFO_H

#include <string>

class Info
{
    private:
        std::string cognome;
        std::string data; //class Data?
        std::string nome;
        std::string n_telefono; //class N_Telefono?

    public:
        Info();
        Info( const std::string &, //nome
              const std::string &, //cognome
              const std::string &, //n_telefono
              const std::string &  //data
            );

        std::string getCognome() const;
        std::string getData() const;
        std::string getNome() const;
        std::string getNumTelefono() const;

        void setCognome( const std::string & );
        void setNome( const std::string & );
        void setData( const std::string & );
        void setNumTelefono( const std::string & );
};

#endif // INFO_H
