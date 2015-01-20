#ifndef SMARTCLASS_H
#define SMARTCLASS_H

#include <iostream>

class SmartClass
{   
    private:
        int refCounter;

    protected:
        SmartClass();

    public:
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

                SmartClass & operator*() const;
                SmartClass * operator->() const;

                smartptr & operator=( const smartptr & );
        };
};

#endif // SMARTCLASS_H
