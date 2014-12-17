#ifndef SMARTCLASS_H
#define SMARTCLASS_H

#include <iostream>

class SmartClass
{   
    private:
        int refCounter;

    public:
        SmartClass();
        virtual ~SmartClass();

        class smartptr
        {
            private:
                SmartClass * ptr;

            public:
                smartptr( SmartClass * = NULL );
                smartptr( const smartptr & );
                ~smartptr();

                bool operator==( const smartptr & ) const;
                bool operator!=( const smartptr & ) const;

                virtual SmartClass & operator*() const;
                virtual SmartClass * operator->() const;

                smartptr & operator=( const smartptr & );
        };
};

#endif // SMARTCLASS_H
