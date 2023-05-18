#ifndef FILE_H
#define FILE_H

#include <QFileInfo>

// Наследуем класс отслеживающий изменения файла от QObject для объявления сигнала
// базовый класс FileObservable теперь не нужен
class File : public QObject
{
Q_OBJECT
public:
    File(const QString& name, QObject* parent = nullptr);

    void checkFile(); // Метод проверки состояния файла
signals:
    void Notify(qint64 size); // Перенесем Notify и сделаем его сигналом

private:
    // Информация об отслеживающем файле
    QFileInfo file_;

    bool exist_ = false;
    qint64 size_ = -1;
};


#endif //FILE_H
