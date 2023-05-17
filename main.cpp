#include <thread>
#include "File.h"
#include "FileObserver.h"

int main() {
    File file("file.txt"); //Создаем объект File и указываем файл который будем отслеживать
    FileObserver observer; //Создаем наблюдателя
    file.Attach(&observer); //Подписываем наблюдателя на файл

    while (true)
    {
        file.checkFile(); //Каждые 100 млс проверяем информацию о файле
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}
