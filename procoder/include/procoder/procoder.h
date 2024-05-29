#ifndef __PROCODER_H__
#define __PROCODER_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
   #ifdef PROCODER_EXPORTS
      #define PROCODER_API __declspec(dllexport)
   #else
      #define PROCODER_API __declspec(dllimport)
   #endif
#else
   #define PROCODER_API
#endif
#include <cJSON/cJSON.h>
#include <stdint.h>
PROCODER_API  cJSON* proDecode( const uint8_t * byteArr, uint8_t len);
PROCODER_API void proEncode(uint8_t *byteArr, uint8_t *len, const cJSON *obj);



#ifdef __cplusplus
}
#endif
#endif // PROCODER_H