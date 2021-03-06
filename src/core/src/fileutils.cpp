#include "fileutils.h"

#include <QDir>
#include <QFile>
#include <QUrl>
#include <QtCore/QDebug>

KAJ_BEGIN_NAMESPACE

FileUtils::FileUtils(QObject *parent) : QObject(parent)
{

}

QString FileUtils::readFile(const QString &filePath)
{
    QFile f(filePath);

    if (!f.exists()) {
        qWarning("File %s does not exists", qPrintable(filePath));
        return "";
    }

    if (!f.open(QIODevice::ReadOnly))
        return "";

    auto buffer = f.readAll();
    f.close();
    return buffer;
}

void FileUtils::writeFile(const QString &filePath, const QString &content)
{
    QFile f(filePath);
    if (!f.open(QIODevice::WriteOnly))
        return;

    f.write(content.toLocal8Bit());
    f.close();
}

QStringList FileUtils::filesInDir(const QString &dirPath)
{
    QDir d(dirPath);
    if (!d.exists())
        return QStringList();
    return d.entryList();
}

QString FileUtils::readFile(const QUrl &fileUrl)
{
    return readFile(fileUrl.toString());
}

void FileUtils::writeFile(const QUrl &fileUrl, const QString &content)
{
    writeFile(fileUrl.toLocalFile(), content);
}

QStringList FileUtils::filesInDir(const QUrl &dirUrl)
{
    return filesInDir(dirUrl.toLocalFile());
}

bool FileUtils::mkdir(const QUrl &dirUrl)
{
    QDir d;
    return d.mkdir(dirUrl.toLocalFile());
}

QString FileUtils::dirname(const QUrl &fileUrl)
{
    return QFileInfo(fileUrl.toLocalFile()).path();
}

bool FileUtils::removeFile(const QUrl &fileUrl)
{
    return QFile::remove(fileUrl.toLocalFile());
}

bool FileUtils::copyFile(const QUrl &from, const QUrl &to)
{
    return QFile::copy(from.toLocalFile(), to.toLocalFile());
}

bool FileUtils::fileExists(const QUrl &fileUrl)
{
    return QFile(fileUrl.toLocalFile()).exists();
}

bool FileUtils::dirExists(const QUrl &dirUrl)
{
    return QDir(dirUrl.toLocalFile()).exists();
}

KAJ_END_NAMESPACE
