#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <QtGlobal>

class IObserver
{
public:
    virtual void UpdateState(qint64 size) = 0; // Виртуальный общий метод для всех наблюдателей
};

#endif //IOBSERVER_H
