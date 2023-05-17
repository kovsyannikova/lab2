#ifndef FILEOBSERVABLE_H
#define FILEOBSERVABLE_H

#include "IObserver.h"
#include <vector>

#include <QtGlobal>

class FileObservable {
public:
    void Attach(IObserver* observer);

    void Detach(IObserver* observer);

    void Notify(qint64 size);

private:
    std::vector<IObserver*> observers;
};


#endif //FILEOBSERVABLE_H
