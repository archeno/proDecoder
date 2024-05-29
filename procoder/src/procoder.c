#include <procoder/procoder.h>

#define BYTE2WORD(arr) ((arr)[0]+(arr)[1]*256)

static inline void word2Bytes(uint16_t word,  uint8_t *arr, uint8_t *len)
{
    arr[0] = word & 0x0ff;
    arr[1] = word>>8;
    (*len)+=2;
}
/**
 * @brief  json object
 * {
 *     "funcode": 1
 *      "current":2.80   0.01A
 *      "volotate":220v  0.1V
 * }
 *  03 18 01 98 08
 */
/**
 * @brief 
 * 
 * @param obj 
 * @param byteArr 
 * @param len 
 * @return PROCODER_API 
 */
PROCODER_API cJSON * proDecode(const uint8_t *byteArr, uint8_t len)
{
    uint8_t funcCode  = byteArr[0];
    float current  = BYTE2WORD(&byteArr[2*0 +1])* 0.01;
    float voltage  = BYTE2WORD(&byteArr[2*1 +1])* 0.1;
    cJSON *root = cJSON_CreateObject();
    cJSON_AddNumberToObject(root, "funcCode", funcCode);
    cJSON_AddNumberToObject(root, "current", current);
    cJSON_AddNumberToObject(root, "voltage", voltage);
    return  root;

}
PROCODER_API void proEncode(uint8_t *byteArr,  uint8_t *len, const cJSON *obj)
{
    cJSON * funcitem =  cJSON_GetObjectItem(obj, "funcCode");
    cJSON *currentItem = cJSON_GetObjectItem(obj, "current");
    cJSON *voltageItem = cJSON_GetObjectItem(obj, "voltage");

    byteArr[0] =   (int)(cJSON_GetNumberValue(funcitem));
    uint16_t current  = (uint16_t)(cJSON_GetNumberValue(currentItem)/100);
    uint16_t voltage = (uint16_t)(cJSON_GetNumberValue(currentItem)/10);
    (*len)++;
    word2Bytes(current, byteArr+1, len);
    word2Bytes(voltage, byteArr+3, len);
}
