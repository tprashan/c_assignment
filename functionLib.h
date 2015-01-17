int add(int,int);
int fibo(int ,int*);
int concat_array(int *array1, int len_of_array1, int *array2, int len_of_array2, int *result_array);
int filter(int *array, int length, int threshold, int **result_array);

int reverse(int *array, int length, int *result_array);
int slice(int *array, int lengthOfArray,int start_index,int end_index,int **result_array);
int prime_number(int start_point,int end_point,int **result_array);
int compare_string(char *str1, char *str2);
int my_strcmp(char *str1, char *str2);

int my_int_forEach(int *array,int length,int (*function) (int ,int ));
int my_char_forEach(char *array,int length,int (*function) (char ,int ));
int my_string_forEach(char **array,int length,int (*function) (char*,int ));

int my_int_filter(int *array,int length,int **result_array,int (*function) (int ));
int my_char_filter(char *array,int length,char **result_array,int (*function) (char));
int my_string_filter(char **array,int length,char ***result_array,int (*function) (char*));
int my_float_filter(float *array,int length,float **result_array,float (*function) (float));

int *my_int_map(int *array,int length,int (*function) (int ));
float *my_float_map(float *array,int length,float (*function) (float));
char *my_char_map(char *array,int length,char (*function) (char));
char **my_string_map(char **array,int length,char *(*function) (char* ,int));

int my_int_reduce(int *array,int length,int (*function) (int ,int));

float my_float_reduce(float *array,int length,float initvalue,float (*function) (float ,float));
int my_int_reduce_with_init_value(int *array,int length,int initvalue,int (*function) (int ,int));
int my_char_reduce(char *array,int length,char initvalue,char (*function) (char ,char));
char*my_string_reduce(char **array,int length,char* initvalue,char *(*function) (char* ,char*));

int my_int_indexOf(int *array,int length, int initvalue);
int my_string_indexOf(char * string,char* initSubString);