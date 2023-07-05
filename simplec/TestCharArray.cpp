#include <stdio.h>
#include <stdlib.h>
#include <string>

// https://github.com/apache/pulsar-client-cpp/pull/294#issuecomment-1619783898

static char *str_malloc_and_copy(const char *s, size_t slen) {
    printf("size: %zu \n",slen);
    char *result = (char *)malloc(slen);
    if (result == NULL) {
        return NULL;
    }
    memcpy(result, s, slen);
    return result;
}

static void get_value(char **value) {
    char *data = (char *)malloc(4);
    data[0] = 0x04;
    data[1] = 0x00;
    data[2] = 0x01;
    data[3] = 0x00;
    auto t = std::string(data, 4);
    printf("str size: %zu \n", t.size());
    *value = str_malloc_and_copy(t.c_str(), t.size());
}

//int main(int argc, char *argv[]) {
//    char *value;
//    get_value(&value);
////    for (int i = 0; i < 4; i++) {
////        printf("%02x ", (unsigned char)value[i]); // print the hexadecimal value of each element
////    }
////    printf("\n"); // print a newline character at the end
//    printf("length: %zu\n", strlen(value));
//    return 0;
//}

int main() {
    char *data = (char *)malloc(4);
    data[0] = 0x04;
    data[1] = 0x00;
    data[2] = 0x01;
    data[3] = 0x00;
    printf("2 The length of the array is %d\n", sizeof(data));
    printf("2 The length of the array is %d\n", sizeof(char));
    
    int len = sizeof(data) / sizeof(char); // calculate the length of the array
    printf("The length of the array is %d\n", len);
    return 0;
}

//static void get_value(char **value_ptr, size_t *value_len) {
//    char *data = (char *)malloc(4);
//    data[0] = 0x01;
//    data[1] = 0x00;
//    data[2] = 0x02;
//    data[3] = 0x00;
//    *value_ptr = data;
//    *value_len = 4;
//}
//
//int main(int argc, char *argv[]) {
//    char *value;
//    size_t len;
//    get_value(&value, &len);
//    printf("length: %zu\n", len);
//    for (size_t i = 0; i < len; i++) {
//        printf("0x%02x%c", value[i], (i < len - 1) ? ' ' : '\n');
//    }
//    return 0;
//}