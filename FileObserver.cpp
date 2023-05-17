#include <iostream>
#include "FileObserver.h"

//Метод выводит информацию если состояние файла изменилось
void FileObserver::UpdateState(qint64 size)
{
    if (size_ != size)
    //Если предыдущий размер файла не совпадает с новым, значит файл изменился
    {
        if (size == -1)
        { //Если размер -1 значит файл не существует
            std::cout << "File doesn't exist" << std::endl;
        } else { //Иначе выводим размер файла
            std::cout << "File exists. Size = " << size << std::endl;
        }
        size_ = size; //Сохраняем новый размер
    }
}
