#include "File.h"
#include <QString>

File::File(const QString& name, QObject* parent) : QObject(parent), file_(name)
{
}

void File::checkFile()
{
    file_.refresh();

    bool exist = file_.exists(); // Узнаем существует ли файл

    if (exist) //Если файл существует
    {
        qint64 size = file_.size();

        if (size_ != size)
        //Если прошлый размер файла не совпадает с новым, значит файл изменился
        {
            size_ = size; // Запоминаем новый размер файла
            emit Notify(size_); // вместо вызова метода Notify, вызываем сигнал через emit
        }
    }
    else if (exist_)
    //Если файл не существует, но существовал раньше
    {
        emit Notify(-1); //Оповещаем что файл не существует
    }

    exist_ = exist;
}
