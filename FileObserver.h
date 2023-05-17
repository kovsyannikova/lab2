#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H

#include "IObserver.h"

class FileObserver : public IObserver
{
private:
    qint64 size_ = -1; // размер файла. -1 если файл не существует

public:
    void UpdateState(qint64 size) override; // Переопределяем метод
};


#endif //FILEOBSERVER_H
