#include "FileObservable.h"

#include <algorithm>

void FileObservable::Attach(IObserver *observer)
{
    observers.push_back(observer); //Добавляет нового наблюдателя
}

void FileObservable::Detach(IObserver *observer)
{
    //Удаление наблюдателя
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void FileObservable::Notify(qint64 size)
{
    //Провходит по всем наблюдателям из вектора
    for (const auto &observer: observers)
    {
        if (observer != nullptr)
        //Если наблюдатель не нулевой
        {
            //Оповещает всех наблюдателей
            observer->UpdateState(size); //Вызываем функцию для обновления информации
        }
    }
}
