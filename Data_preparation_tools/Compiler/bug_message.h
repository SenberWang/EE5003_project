//
// Created by YLW20 on 2022/5/19.
//

#ifndef CL_COMPILER_BUG_MESSAGE_H
#define CL_COMPILER_BUG_MESSAGE_H
#ifdef ENV_WIN
#define __FILENAME__ (std::strrchr(__FILE__, '\\') ? std::strrchr(__FILE__, '\\') + 1 : __FILE__)
#endif
#ifdef ENV_DARWIN
#define __FILENAME__ (std::strrchr(__FILE__, '/') ? std::strrchr(__FILE__, '/') + 1 : __FILE__)
#endif
#define WARNING(...) {std::printf("[WARNING] at file \"%s\", line %d, function \"%s\"",  __FILENAME__, __LINE__, __FUNCTION__); \
                     std::printf(__VA_ARGS__); std::printf("\n");}
#define ERROR(...)   {std::printf("[ERROR] at file \"%s\", line %d, function \"%s\"",  __FILENAME__, __LINE__, __FUNCTION__); \
                     std::printf(__VA_ARGS__); std::printf("\n");}
#endif //CL_COMPILER_BUG_MESSAGE_H
