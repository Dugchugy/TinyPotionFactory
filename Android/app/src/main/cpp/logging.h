//
// Created by dugch on 2025-01-03.
//

#ifndef TINY_POTION_FACTORY_LOGGING_H
#define TINY_POTION_FACTORY_LOGGING_H

#include <android/log.h>

#define LOGD( ... ) __android_log_print(ANDROID_LOG_DEBUG, "LOG", __VA_ARGS__)

#define LOGE( ... ) __android_log_print(ANDROID_LOG_DEBUG, "ERROR", __VA_ARGS__)

#endif //TINY_POTION_FACTORY_LOGGING_H
