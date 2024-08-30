// Task_2_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Data.h"
#include <iostream>
#include <vector>
#include <thread>


void swap1(Data& d1, Data& d2)
{
    std::cout << "Элементы до работы функции swap1" << std::endl;
    std::cout << "cтрока 1 го элемента=" << d1.getValue() << std::endl;
    std::cout << "cтрока 2 го элемента=" << d2.getValue() << std::endl;

    std::lock(d1.m, d2.m);
    std::string tmp = d1.getValue();
    d1.setValue(d2.getValue());
    d2.setValue(tmp);
    std::cout << "Элементы после работы функции swap1" << std::endl;
    std::cout << "cтрока 1 го элемента=" << d1.getValue() << std::endl;
    std::cout << "cтрока 2 го элемента=" << d2.getValue() << std::endl;

    

    d1.m.unlock();
    d2.m.unlock();
}

void swap2(Data& d1, Data& d2)
{
    std::cout << "Элементы до работы функции swap2" << std::endl;
    std::cout << "cтрока 1 го элемента=" << d1.getValue() << std::endl;
    std::cout << "cтрока 2 го элемента=" << d2.getValue() << std::endl;
    std::scoped_lock lock(d1.m, d2.m);
    
   std::string tmp = d1.getValue();
    d1.setValue(d2.getValue());
    d2.setValue(tmp);
    std::cout << "Элементы после работы функции swap2" << std::endl;
    std::cout << "cтрока 1 го элемента=" << d1.getValue() << std::endl;
    std::cout << "cтрока 2 го элемента=" << d2.getValue() << std::endl;
}

void swap3(Data& d1, Data& d2)
{
    std::cout << "Элементы до работы функции swap3" << std::endl;
    std::cout << "cтрока 1 го элемента=" << d1.getValue() << std::endl;
    std::cout << "cтрока 2 го элемента=" << d2.getValue() << std::endl;
    std::scoped_lock lock(d1.m, d2.m);
    std::unique_lock<std::mutex> lock1(d1.m, std::defer_lock);
    std::unique_lock<std::mutex> lock2(d2.m, std::defer_lock);
    lock1.lock();
    lock2.lock();
    std::string tmp = d1.getValue();
    d1.setValue(d2.getValue());
    d2.setValue(tmp);

    std::cout << "Элементы после работы функции swap3" << std::endl;
    std::cout << "cтрока 1 го элемента=" << d1.getValue() << std::endl;
    std::cout << "cтрока 2 го элемента=" << d2.getValue() << std::endl;
    lock1.unlock();
    lock2.unlock();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    

    Data d1("1 element");
    Data d2("2 element");

    std::cout << "Элементы в самом начале работы" << std::endl;
    std::cout << "cтрока 1 го элемента=" << d1.getValue() << std::endl;
    std::cout << "cтрока 2 го элемента=" << d2.getValue() << std::endl;

    std::thread thread1(swap1, std::ref(d1), std::ref(d2));
    std::thread thread2(swap2, std::ref(d1), std::ref(d2));
    std::thread thread3(swap3, std::ref(d1), std::ref(d2));
    
    thread1.join();
    thread2.join();
    thread3.join();

    
}