#include <iostream>

/*饿汉方式：以空间换时间*/
// class Singleton
// {
// private:
//     Singleton() :_data(99) 
//     {
//         std::cout << "懒汉模式，单例对象构造!" << std::endl;
//     }
//     ~Singleton() {}
//     Singleton(const Singleton& ) = delete;
//     Singleton operator=(const Singleton &) = delete;

//     static Singleton _eton;
// private:
//     int _data;
// public:
//     static Singleton& getInstance()
//     {
//         return _eton;
//     }

//     int getData()
//     {
//         return _data;
//     }
// };
// Singleton Singleton::_eton;

/*懒汉方式：懒加载--延迟加载的思想---一个对象在用的时候再进行实例化*/
class Singleton
{
private:
    Singleton() :_data(99)
    {
        std::cout << "懒汉模式：单例对象构造!" << std::endl;
    }
    ~Singleton() {}
    Singleton(const Singleton& ) = delete;
    Singleton operator=(const Singleton& ) = delete;

private:
    int _data;

public:
    static Singleton& getInstance() // C++11之后静态对象的创建是加锁的
    {
        static Singleton _eton;
        return _eton;
    }

    int getData()
    {
        return _data;
    }
};

int main()
{
    std::cout << Singleton::getInstance().getData() << std::endl;
    return 0;
}