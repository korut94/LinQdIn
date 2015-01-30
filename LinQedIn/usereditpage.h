#ifndef USEREDITPAGE_H
#define USEREDITPAGE_H

#include <iostream>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "info.h"
#include "levelaccess.h"
#include "line.h"
#include "moduleaccout.h"
#include "moduleeducation.h"
#include "moduleexperience.h"
#include "moduleid.h"
#include "moduleskills.h"

class UserEditPage : public QWidget
{
    Q_OBJECT

    private:
        ModuleAccout * account;
        ModuleExperience * experience;
        ModuleID * id;
        ModuleSkills * skills;
        ModuleEducation * education;

        QLabel * msgError;

        QVBoxLayout * layoutArea;

    signals:
        void requestAddEducation();
        void requestAddExperience();
        void requestAddSkill();

    public slots:
        bool checkErrorForm() const;

        Info recapInfo() const;

        void addEducation();
        void addExperience();
        void addSkill();
        void error( const QString & );
        void reset();

    public:
        UserEditPage( QWidget * = nullptr );
        ~UserEditPage();

        void loadModuleAccount();
        void loadModuleEducation();
        void loadModuleExperience();
        void loadModuleId();
        void loadModuleSkill();
};

#endif // USEREDITPAGE_H
