#ifndef ONESIGNAL_H
#define ONESIGNAL_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>
#include <kajpluginbase.h>

class QQmlApplicationEngine;
class OneSignal : public KajPluginBase
{
    Q_OBJECT
    KAJ_SINGLETON_UNIT(OneSignal)

    Q_PROPERTY(QString applicationId READ applicationId WRITE setApplicationId NOTIFY applicationIdChanged)
    Q_PROPERTY(QString userId READ userId WRITE setUserId NOTIFY userIdChanged)
    Q_PROPERTY(QString registrationId READ registrationId WRITE setRegistrationId NOTIFY registrationIdChanged)
    Q_PROPERTY(QString additionalData READ additionalData WRITE setAdditionalData NOTIFY additionalDataChanged)

    QString m_applicationId;
    bool isRegistered;

public:
    explicit OneSignal(QObject *parent = nullptr);
    static bool init();
    static bool init(const QQmlApplicationEngine *engine);

    QString applicationId() const;
    QString userId();
    QString registrationId();
    QString additionalData();

signals:
    void signalRecived(QString title, QString body, QString extra);
    void signalOpened(QString title, QString body, QString extra);
    void applicationIdChanged(QString applicationId);
    void userIdChanged(QString userId);
    void registrationIdChanged(QString registrationId);
    void additionalDataChanged(QString additionalData);

public slots:
    void initOneSignal();
    void setApplicationId(QString applicationId);
    void setUserId(QString userId);
    void setRegistrationId(QString registrationId);
    void setAdditionalData(QString additionalData);

private:
    QString m_userId;
    QString m_registrationId;
    QString m_additionalData;
};

KAJ_DECLARE_QML_PLUGIN(OneSignal)

#endif // ONESIGNAL_H
