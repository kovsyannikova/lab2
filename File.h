#ifndef FILE_H
#define FILE_H

#include "FileObservable.h"
#include <QFileInfo>

class File : public FileObservable
{
public:
    File(const QString& name);

    void checkFile(); // Метод проверки состояния файла

private:
    // Путь к файлу
    QFileInfo file_;

    // Дата последнего изменения
    QDateTime lastModificationDate_;

    bool exist_ = false;
    qint64 size_ = -1;

};


#endif //FILE_H
