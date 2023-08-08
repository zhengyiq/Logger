/*
    1. 定义枚举类，枚举出日志等级
    2. 提供转换接口，将枚举转换为对应的字符串
*/
#ifndef __M_LEVEL_H__
#define __M_LEVEL_H__

namespace zyqlog
{
    class LogLevel
    {
    private:
    public:
        enum class value
        {
            UNKNOW = 0,
            DEBUG,
            INFO,
            WARNING,
            ERROR,
            FATAL,
            OFF
        };

        static const char *toString(LogLevel::value level)
        {
            switch (level)
            {
            case LogLevel::value::DEBUG:
                return "DEBUG";
            case LogLevel::value::INFO:
                return "INFO";
            case LogLevel::value::WARNING:
                return "WARNING";
            case LogLevel::value::ERROR:
                return "ERROR";
            case LogLevel::value::FATAL:
                return "FATAL";
            case LogLevel::value::OFF:
                return "OFF";
            }
            return "UNKNOW";
        }
    };
}

#endif