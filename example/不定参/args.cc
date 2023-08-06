#include <iostream>

using namespace std;

/*C++风格不定参函数的使用*/

void xprintf() // 模板的特化
{
    cout << endl;
}

template<typename T, typename ...Args>
void xprintf(const T& v, Args&& ...args) // 完美转发
{
    cout << v;
    if ((sizeof ...(args)) > 0)
    {
        xprintf(forward<Args>(args)...);
    }
    else
    {
        xprintf();
    }
}

int main()
{
    xprintf("hello", "world", 666);

    return 0;
}