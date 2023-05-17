#include "File.h"
#include <QString>

File::File(const QString& name) : file_(name)
{
}

void File::checkFile()
{
    file_.refresh();

    bool exist = file_.exists(); // Узнаем существует ли файл

    if (exist) //Если файл существует
    {
        qint64 size = file_.size();

        if (!exist || size_ != size)
        //Если прошлый размер файла не совпадает с новым, значит файл изменился
        {
            size_ = size; //Запоминаем новый размер файла
            Notify(size_); //Оповещаем наблюдателй
        }
    }
    else if (exist_)
    //Если файл не существует, но существовал раньше
    {
        Notify(-1); //Оповещаем что файл не существует
    }

    exist_ = exist;
}
