#ifndef CHECKGROUPINPUT_H
#define CHECKGROUPINPUT_H

namespace CheckGroupInput
{
    class CheckInput
    {
        public:
            virtual bool check( const QString & ) const = 0;
    };

    class CheckName : public CheckInput
    {
        public:
            bool check( const QString & ) const;
    };
}

#endif // CHECKGROUPINPUT_H
