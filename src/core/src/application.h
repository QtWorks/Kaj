#ifndef APPLICATION_H
#define APPLICATION_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>

class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application(QObject *parent = nullptr);

    enum ApplicationState {
        ApplicationSuspended    = 0x00000000,
        ApplicationHidden       = 0x00000001,
        ApplicationInactive     = 0x00000002,
        ApplicationActive       = 0x00000004
    };

    Q_DECLARE_FLAGS(ApplicationStates, ApplicationState)
    Q_ENUM(ApplicationState)

private slots:
    void qApp_applicationStateChanged(Qt::ApplicationState state);

signals:
    void applicationStateChanged(ApplicationState state);

};

#endif // APPLICATION_H