基于cJson 的编解码插件

## API

```c
PROCODER_API  cJSON* proDecode( const uint8_t * byteArr, uint8_t len);
PROCODER_API void proEncode(uint8_t *byteArr, uint8_t *len, const cJSON *obj);
```

## 功能说明

* proDecode 将字节数组解码成json格式数据
* proEncode 将json数据编码成字节数据
