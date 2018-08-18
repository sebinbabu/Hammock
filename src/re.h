#ifdef __cplusplus
extern "C"{
#endif

typedef struct regex_t* re_t;
re_t re_compile(const char* pattern);
int  re_matchp(re_t pattern, const char* text);
int  re_match(const char* pattern, const char* text);

#ifdef __cplusplus
}
#endif