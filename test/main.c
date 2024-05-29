#include <stdio.h>
#include <procoder/procoder.h>

int main(int argc, char const *argv[])
{
    //decode: 
 //(03 18 01 98 08
    uint8_t data1[] = {0x03, 0x18, 0x01, 0x98, 0x08};
   cJSON *root =  proDecode(data1, sizeof(data1)/sizeof(data1));
   printf("%s", cJSON_Print(root));
   
    return 0;
}
