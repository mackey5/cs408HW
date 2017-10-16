#include "jsmn.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_TOKENS 10

int main(int argc, char** argv)
{
    int length = 0;

    for (int i = 1; i < argc; i++)
        length += strlen(argv[i]) + 1;

    char *json_string = (char*)malloc(length + 1);
    json_string[0] = 0;

    for (int i = 1; i < argc; i++) {
        strcat(json_string, argv[i]);
        strcat(json_string, " ");
    }

    printf("input json string: %s\n", json_string);
    jsmn_parser parser;
    jsmntok_t* tokens = (jsmntok_t*)malloc(sizeof(jsmntok_t) * MAX_TOKENS);
    jsmn_init(&parser);
    int parsed_tokens =
        jsmn_parse(&parser, json_string, strlen(json_string),
                   tokens, MAX_TOKENS);

    for (int i = 0; i < parsed_tokens; i++) {
        switch (tokens[i].type) {
        case JSMN_UNDEFINED:
            printf("undefined ");
            break;

        case JSMN_OBJECT:
            printf("object ");
            break;

        case JSMN_ARRAY:
            printf("array ");
            break;

        case JSMN_STRING:
            printf("string ");
            break;

        case JSMN_PRIMITIVE:
            printf("primitive ");
            break;
        }

        char tmp = json_string[tokens[i].end];
        json_string[tokens[i].end] = 0;
        printf("\"%s\"\n", &json_string[tokens[i].start]);
        json_string[tokens[i].end] = tmp;
    }
}
