#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H

#include <QObject>

// Наследуем класс наблюдателя от QObject для объявления слота
// Интерфейс IObserver теперь не нужен
class FileObserver : public QObject
{
Q_OBJECT
private:
    qint64 size_ = -1; // размер файла. -1 если файл не существует

public:
    FileObserver(QObject* parent = nullptr) : QObject(parent) {}

public slots:
    // Делаем обработчик уведомлений о состоянии файла слотом
    void UpdateState(qint64 size);
};


#endif //FILEOBSERVER_H
