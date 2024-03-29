#include "File.h"
#include "FileObserver.h"

#include <thread>

int main()
{
    File file("file.txt"); // Создаем объект File и указываем файл который будем отслеживать
    FileObserver observer; // Создаем наблюдателя

    // Вместо прикрепления наблюдателя FileObserver к издателю File
    // Используем конструкцию QObject::connect для связи сигнала Notify и слота UpdateState

    QObject::connect(&file, &File::Notify, &observer, &FileObserver::UpdateState);

    // Если нужно будет подключать несколько наблюдателей
    //    std::vector<FileObserver> observers(2);

    //    for(auto& observer: observers)
    //    {
    //        QObject::connect(&file, &File::notify, &observer, &FileObserver::update);
    //    }


    while (true)
    {
        file.checkFile(); // Каждые 100 млс проверяем информацию о файле
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
