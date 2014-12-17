#ifndef SMARTCLASS_H
#define SMARTCLASS_H

class SmartClass
{   
    friend class smartptr;

    private:
        int refCounter;

    public:
        SmartClass();

        class smartptr
        {
            private:
                SmartClass * ptr;

            public:
                smartptr( SmartClass * = NULL );
        };

};

#endif // SMARTCLASS_H
