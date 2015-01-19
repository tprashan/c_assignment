#include "expr_assert.h"
#include "functionLib.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void test_fibo_number_should_give_the_fibo_series(){
	int *array; 
	array  = (int *)malloc(sizeof(int)*5);
	assertEqual(fibo(5,array),1);
};

void test_fibo_number_should_give_0_when_input_is_0(){
	int *array; 
	array  = (int *)malloc(sizeof(int)*5);
	assertEqual(fibo(0,array),0);
	assertEqual(fibo(-1,array),0);
};

void test_fibo_number_should_give_0_when_input_is_less_than_0(){
	int *array; 
	array  = (int *)malloc(sizeof(int)*5);
	assertEqual(fibo(-1,array),0);
};

void test_fibo_array_ele_are_same_or_not(){
	int *array; 
	array  = (int *)malloc(sizeof(int)*5);
	assertEqual(fibo(5,array),1);
	assertEqual(array[0],1);
	assertEqual(array[1],1);
	assertEqual(array[2],2);
	assertEqual(array[3],3);
	assertEqual(array[4],5);
};

void test_fibo_array_ele_of_7_is_21_or_not(){
	int *array; 
	array  = (int *)malloc(sizeof(int)*8);
	assertEqual(fibo(8,array),1);
	assertEqual(array[7],21);
};

void test_concat_two_array_give_result_array_length_8(){
	int *result_array; 
	int len_of_array1 = 3;
	int len_of_array2 = 5;
	int array1[]={1,2,3};
	int array2[]={4,5,6,7,8};

	result_array  = (int *)malloc(sizeof(int)*8);

	assertEqual(concat_array(array1,len_of_array1,array2, len_of_array2, result_array),8);

	assertEqual(result_array[0],1);
	assertEqual(result_array[1],2);
	assertEqual(result_array[2],3);
	assertEqual(result_array[3],4);
	assertEqual(result_array[4],5);
};

void test_concat_two_array_give_result_array_ele_of_6_is_17(){

	int *result_array; 
	int array1[]={1,12,3};
	int array2[]={4,55,16,17,38};

	result_array  = (int *)malloc(sizeof(int)*8);

	assertEqual(concat_array(array1,3,array2, 5, result_array),8);

	assertEqual(result_array[6],17);
	assertEqual(result_array[7],38);
};


void test_concat_two_array_give_result_array_length_5(){
	int array1[]={1,2};
	int array2[]={3,4,5};
	int result_array[5];

	int *pointer1  = (int *)malloc(sizeof(int)*2);
	int *pointer2= (int *)malloc(sizeof(int)*3);
	int *pointer3 = (int *)malloc(sizeof(int)*5);

	pointer1 = &array1;
	pointer2 = &array2;
	pointer3 = &result_array;

	assertEqual(concat_array(pointer1,2,pointer2,3,pointer3),5);

	assertEqual(result_array[0],1);
	assertEqual(result_array[1],2);
	assertEqual(result_array[2],3);
	assertEqual(result_array[3],4);
	assertEqual(result_array[4],5);

};

void test_filter_an_array_that_gives_greater_than_thrteshold_value(){
	int array1[]={1,21,5,6,12,23,21,25,9,15};
	int *result_array;

	assertEqual(filter(array1,10,13,&result_array),5);

	assertEqual(result_array[0],21);
	assertEqual(result_array[1],23);
	assertEqual(result_array[2],21);
	assertEqual(result_array[3],25);
	assertEqual(result_array[4],15);

};

void test_filter_an_array_that_gives_0_when_arrayLength_is_0(){
	int array1[]={};
	int *result_array;
	assertEqual(filter(array1,0,13,&result_array),0);
};

void test_filter_an_array_that_gives_3_when_arrayLength_is_3(){
	int array1[]={1,21,12,23,9,15};
	int *result_array;
	assertEqual(filter(array1,6,13,&result_array),3);
};

void test_reverse_the_given_array(){
	int array1[]={1,21,5,6,12,23,21,25,9,15};
	int result_array[10];

	int *pointer1  = (int *)malloc(sizeof(int)*10);
	int *pointer2 = (int *)malloc(sizeof(int)*10);

	pointer1 = &array1;
	pointer2 = &result_array;

	assertEqual(reverse(pointer1,10,pointer2),10);

	assertEqual(result_array[0],15);
	assertEqual(result_array[1],9);
	assertEqual(result_array[2],25);
	assertEqual(result_array[3],21);
	assertEqual(result_array[4],23);

};

void test_reverse_the_given_array_give_3_length(){
	int array1[]={9,3,7};
	int *result_array;
	result_array  = (int *)malloc(sizeof(int)*3);

	assertEqual(reverse(array1,3,result_array),3);
	assertEqual(result_array[0],7);
};

void test_reverse_the_given_array_give_0_length(){
	int array1[]={};
	int *result_array;
	result_array  = (int *)malloc(sizeof(int)*1);

	assertEqual(reverse(array1,0,result_array),0);
};

void test_slice_the_given_array_give_new_array_of_length(){
	int array1[]={1,21,5,6,12,23,21,25,9,15};
	int *result_array;
	assertEqual(slice(array1,10,2,5,&result_array),3);
};

void test_slice_the_given_array_give_new_array_of_5_6_12(){
	int array1[]={1,21,5,6,12,23,21,25,9,15};
	int *result_array;
	assertEqual(slice(array1,10,2,5,&result_array),3);

	assertEqual(result_array[0],5);
	assertEqual(result_array[1],6);
	assertEqual(result_array[2],12);
};

void test_slice_the_given_array_give_0_if_start_index_is_wrong(){
	int array1[]={1,21,5,6,12,23,21,25,9,15};
	int *result_array;
	assertEqual(slice(array1,10,-1,5,&result_array),0);
};

void test_slice_the_given_array_give_0_if_end_index_is_wrong(){
	int array1[]={1,21,5,6,12,23,21,25,9,15};
	int *result_array;
	assertEqual(slice(array1,10,2,11,&result_array),0);
};

void test_slice_the_given_array_give_0_if_end_index_is_smaller_than_start_index(){
	int array1[]={1,21,5,6,12,23,21,25,9,15};
	int *result_array;
	assertEqual(slice(array1,10,7,5,&result_array),0);
};

void test_slice_the_given_array_give_0_if_start_index_is_less_than_0_and_end_index_greater_than_10(){
	int array1[]={1,21,5,6,12,23,21,25,9,15};
	int *result_array;
	assertEqual(slice(array1,10,7,5,&result_array),0);
};

void test_slice_the_given_array_give_0_if_start_index_is_3_and_end_index_minus_1(){
	int array1[]={1,21,5,6,12,23,21,25,9,15};
	int *result_array;
	assertEqual(slice(array1,10,3,-1,&result_array),0);
};


void test_slice_the_given_array_give_new_array_of_5_is_21(){
	int array1[]={1,21,5,6,12,23,21,25,9,15};
	int *result_array;
	assertEqual(slice(array1,10,2,8,&result_array),6);

	assertEqual(result_array[5],25);
};

void test_find_prime_number_in_given_range(){
	int start_point = 1;
	int end_point = 100;
	int *result_array;
	assertEqual(prime_number(start_point,end_point,&result_array),25);
	assertEqual(result_array[0],2);
};

void test_find_prime_number_in_given_range_5th_ele_is_11(){
	int start_point = 1;
	int end_point = 100;
	int *result_array;
	assertEqual(prime_number(start_point,end_point,&result_array),25);
	assertEqual(result_array[4],11);
};

void test_find_prime_number_in_given_range_4th_ele_is_7(){
	int start_point = 2;
	int end_point = 10;
	int *result_array;
	assertEqual(prime_number(start_point,end_point,&result_array),4);
	assertEqual(result_array[3],7);
};

void test_find_prime_number_in_given_high_range(){
	int start_point = 1;
	int end_point = 1000;
	int *result_array;
	assertEqual(prime_number(start_point,end_point,&result_array),168);
};

void test_find_prime_number_in_given_high_prime_number_should_be_21(){
	int start_point = 11;
	int end_point = 100;
	int *result_array;
	assertEqual(prime_number(start_point,end_point,&result_array),21);
};

void test_find_prime_number_is_given_give_new_array_of_166_is_991(){
	int start_point = 1;
	int end_point = 1000;
	int *result_array;
	assertEqual(prime_number(start_point,end_point,&result_array),168);

	assertEqual(result_array[166],991);
	assertEqual(result_array[167],997);
};

void test_find_prime_number_in_given_high_prime_number_should_be_9592_(){
	int start_point = 2;
	int end_point = 100000;
	int *result_array;
	assertEqual(prime_number(start_point,end_point,&result_array),9592);
};


void test_compare_hii_and_hii_gives_1(){
	char *str1 = "hii", *str2="hii";
	assertEqual(compare_string(str1,str2),1);
};

void test_compare_hello_and_hii_helloooo_0(){
	char *string1="hello", *string2="helloooo";
	assertEqual(compare_string(string1,string2),0);
};

void test_string_compare_hello_and_hello_0(){
	char *string1="hello", *string2="hello";
	assertEqual(my_strcmp(string1,string2),0);
};

void test_string_compare_hello_and_hallo_4(){
	char *string1="hello", *string2="hallo";
	assertEqual(my_strcmp(string1,string2),4);
};

void test_string_compare_hallo_and_hello_minus_4(){
	char *string1="hallo", *string2="hello";
	assertEqual(my_strcmp(string1,string2),-4);
};

void test_string_compare_hallo_and_hellooooo_(){
	char *string1="hello", *string2="hellooooo";
	assertEqual(my_strcmp(string1,string2),-111);
};

void test_string_compare_hellooooo_and_hello_111(){
	char *string1="hellooooo", *string2="hello";
	assertEqual(my_strcmp(string1,string2),111);
};

int print_integer(int x,int index,int *array){
	printf("Number %d",(x+5) );
	printf("........Index%d\n",index );
	return x;
};

void test_forEach_for_integer(){
	int (*function)(int ,int,int *);
	int *array,array1[]={1,3};
	function = &print_integer;
	array=array1;
	assertEqual(my_int_forEach(array, 2, function),1);
};

int print_char(char x,int index,char *array){
	printf("Charcter %c",x );
	printf("........Index%d\n",index );
	return x;
};


void test_forEach_for_char(){
	int (*function)(char ,int,char *array);
	char *array,array1[]={'a','s','d'};
	function = &print_char;
	array=array1;
	assertEqual(my_char_forEach(array, 3, function),1);
};

int print_string(char *x,int index,char **array){
	printf("String %s",x );
	printf("........Index%d\n",index );
	return *x;
};

void test_forEach_for_string(){
	int (*function)(char* ,int,char **array);
	char *array[]={"hello","hiii","ho"};
	function = &print_string;
	assertEqual(my_string_forEach(array, 3, function),1);
};

int greaterThanFive(int x ,int index, int *array){
		return x>5;
};

void test_filter_for_integer_array(){
	int (*function)(int,int, int *array);
	int *array,array1[]={1,3,2,13,4,6};
	int *result_array;
	array=array1;
	function = &greaterThanFive;
	assertEqual(my_int_filter(array, 6,&result_array, function),2);
	assertEqual(result_array[0],13);
};

void test_filter_for_integer_array_should_give_6____of_1_index_of_resArray(){
	int (*function)(int ,int, int *array);
	int *array,array1[]={1,3,2,13,4,6};
	int *result_array;
	array=array1;
	function = &greaterThanFive;
	assertEqual(my_int_filter(array, 6,&result_array, function),2);
	assertEqual(result_array[1],6);
};

void test_filter_for_integer_array_should_give_8____of_2_index_of_resArray(){
	int (*function)(int,int, int *array );
	int *array,array1[]={1,4,8,13,55,3};
	int *result_array;
	array=array1;
	function = &greaterThanFive;
	assertEqual(my_int_filter(array, 6,&result_array, function),3);
	assertEqual(result_array[0],8);
	assertEqual(result_array[2],55);
};

int equalToS(char x ,int index,char *array){
		return x=='S';
};

void test_filter_for_char(){
	int (*function)(char,int,char *array);
	char *array,array1[]={'a','S','d'};
	char *result_array;
	function = &equalToS;
	array=array1;
	assertEqual(my_char_filter(array, 3,&result_array, function),1);
	assertEqual(result_array[0],'S');
};

void test_filter_for_char_gives_S_of_resArray_index_0(){
	int (*function)(char,int,char *array);
	char *array,array1[]={'a','s','d','S'};
	char *result_array;
	function = &equalToS;
	array=array1;
	assertEqual(my_char_filter(array, 4,&result_array, function),1);
	assertEqual(result_array[0],'S');
};

int filter_string(char* x,int index,char **array){
	if(!(strcmp(x,"string"))){
		return 1;
	}else
	return 0;
};

void test_filter_for_string(){
	int (*function)(char*,int,char **array);
	char *array[]={"hello","string","ho","string"};
	char **result_array;
	function = &filter_string;
	assertEqual(my_string_filter(array, 4,&result_array, function),2);
	assertEqual(strcmp(result_array[0],"string"),0);
	assertEqual(strcmp(result_array[1],"string"),0);
};

int filter_string_give_hello(char* x,int index,char **array){
	if(!(strcmp(x,"hello"))){
		return 0;
	}else
	return 1;
};

void test_filter_for_string_give_john(){
	int (*function)(char*,int,char **array);
	char *array[]={"hello","john","go","hel","hello"};
	char **result_array;
	function = &filter_string_give_hello;
	assertEqual(my_string_filter(array, 5,&result_array, function),3);
	assertEqual(strcmp(result_array[0],"john"),0);
	assertEqual(strcmp(result_array[1],"go"),0);
	assertEqual(strcmp(result_array[2],"hel"),0);
};


float greaterThanFivePointFive(float x,int index,float *array){
		return x>5;
};

void test_filter_for_float_array(){
	float (*function) (float,int,float *array);
	float *array,array1[]={1.7,3.4,2.6,13.8,4.9,6};
	float *result_array;
	array=array1;
	function = &greaterThanFivePointFive;
	assertEqual(my_float_filter(array, 6,&result_array, function),2);
	assertEqual(result_array[0],13.8);
};

void test_filter_for_float_array_will_give_number_greater_than_five(){
	float (*function) (float,int,float *array);
	float *array,array1[]={1.7,13.4,2.6,13.8,4.9,6};
	float *result_array;
	array=array1;
	function = &greaterThanFivePointFive;
	assertEqual(my_float_filter(array, 6,&result_array, function),3);
	assertEqual(result_array[0],13.4);
	assertEqual(result_array[2],6);
};

int greaterThanEqualToFour(int x,int index,int *array){
	if(x>=4){
		return x;
	}
	return 0;
};

void test_map_for_integer_array(){
	int array[]={1,3,2,13,4,6};
	int *newArray;
	newArray=my_int_map(array, 6, greaterThanEqualToFour);

	assertEqual(newArray[0],0);
	assertEqual(newArray[3],13);
};

int addFiveInEachEleOfArray(int x,int index,int *array){
	return x+5;
};

void test_map_for_integer_array_return_0_or_return_value(){
	int array[]={1,33,2,13};
	int *newArray=my_int_map(array, 4, addFiveInEachEleOfArray);
	assertEqual(newArray[0],6);
	assertEqual(newArray[1],38);
	assertEqual(newArray[2],7);
};

char change_h_into_H(char x,int index,char *array){
	if(x=='h'){
		x='H';
		return x;
	}
	return x;
};

void test_map_for_char(){
	char array[]={'a','h','s','h','H'};
	char *new_Array=my_char_map(array, 5, change_h_into_H);
	assertEqual(new_Array[0],'a');
};

void test_map_for_char_return_H_inplace_of_h(){
	char array[]={'a','h','s','h','H'};
	char *new_Array=my_char_map(array, 5, change_h_into_H);
	assertEqual(new_Array[0],'a');
	assertEqual(new_Array[1],'H');
};

float greaterThanFivePointFour(float x,int index,float *array){
	if(x>=4){
		return x+10;
	};
	return x;
};

void test_map_for_float_array(){
	float array[]={1.7,3.4,2.6,13.8,4.9,6};
	float *new_Array=my_float_map(array, 6, greaterThanFivePointFour);
	assertEqual(new_Array[1],3.4);
	assertEqual(new_Array[3],23.8);
};

char *map_string_give_heaven(char* x,int index,char **array){
	if(!(strcmp(x,"hel"))){
		x="heaven";
		return x;
	}else
	return x;
};

void test_map_for_string_give_john(){
	char *array[]={"hello","john","go","hel","hello"};
	char **newArray=my_string_map(array, 5, map_string_give_heaven);
	assertEqual(strcmp(newArray[3],"heaven"),0);
};


int getReduceValue(int x, int y, int index,int *array){
	return x+y;
};

void test_reduce_for_integer_array(){
	int array[]={1,3,2,13,4,6};
	int newArray = my_int_reduce(array, 6, getReduceValue);
	assertEqual(newArray,29);
};

int getReduceValueWithInitValue(int x, int y,int index,int *array){
	return x-y;
};

void test_reduce_for_integer_array_with_initial_value(){
	int array[]={1,3,2,13,4,6};
	int newArray = my_int_reduce_with_init_value(array, 6, 1,getReduceValueWithInitValue);
	assertEqual(newArray,-28);
};

float subtractValueOfArray(float x,float y,int index,float *array){
		if(x>y){
			return x-y;
		};
		return y-x;
};

void test_reduce_for_float_array(){
	float array[]={1.7,3.4,2.6,13.8,4.9,6};
	float initValue = 2.1;
	float result_array=my_float_reduce(array, 6,initValue, subtractValueOfArray);
	assertEqual(result_array,2.5);
};

void test_reduce_for_float_array_give(){
	float array[]={1.7,3.5,2.0,13.8,4.7,6.1};
	float initValue = 8.1;
	float result=my_float_reduce(array, 6,initValue, subtractValueOfArray);
	assertEqual(result,2.1);
};

char giveBiggerNumber(char x ,char y,int index,char *array){
	if(x>y)
		return x;
	return y;
};

void test_reduce_for_char(){
	char array[]={'a','h','s','h','H'};
	char new_Array=my_char_reduce(array, 5,'g', giveBiggerNumber);
	assertEqual(new_Array,'s');
};

char *reduce_string_give_a_big_string_len(char* x,char* y,int index,char **array){
	if(strlen(x)>=strlen(y))
		return x;
	return y;
};

void test_reduce_for_string_give_big_string_len(){
	char *array[]={"hello","john","go","hel","hello"};
	char* initValue = "hii";
	char *newArray=my_string_reduce(array, 5,initValue, reduce_string_give_a_big_string_len);
	assertEqual(strcmp(newArray,array[4]),0);
};

char *reduce_string_give_a_big_string(char* x,char* y,int index,char **array){
	char* destination = malloc(sizeof(char)*100);
	strcpy(destination,x);
	strcat(destination,y);
	return destination;
};

void test_reduce_for_string_give_big_string(){
	char *array[]={"hello","john","go","hel","hello"};
	char* initValue = "hii";
	char *newArray=my_string_reduce(array, 5,initValue, reduce_string_give_a_big_string);
	assertEqual(strcmp(newArray,"hiihellojohngohelhello"),0);
};

void test_find_index_Of_given_int_element(){
	int array[]={1,4,7,3,8};
	int initValue=7;
	int result = my_int_indexOf(array,5,initValue);
	assertEqual(result,2);
};

void test_find_indexOf_given_substring_of_a_string(){
	char* string = "prashant";
	char *initSubString = "ras";
	int result = my_string_indexOf(string,initSubString);
	assertEqual(result,1);
};

void test_find_indexOf_given_substring_of_a_string_return_index_4(){
	char* string = "prashant";
	char *initSubString = "han";
	int result = my_string_indexOf(string,initSubString);
	assertEqual(result,4);
};

void test_find_indexOf_given_substring_of_a_string_return_index_minus_1(){
	char* string = "prashant";
	char *initSubString = "aht";
	int result = my_string_indexOf(string,initSubString);
	assertEqual(result,-1);
};

void test_find_indexOf_return_index_minus_1(){
	char* string = "paramatma";
	char *initSubString = "aht";
	int result = my_string_indexOf(string,initSubString);
	assertEqual(result,-1);
};

void test_find_indexOf_return_index_minus_3(){
	char* string = "paramatma";
	char *initSubString = "ama";
	int result = my_string_indexOf(string,initSubString);
	assertEqual(result,3);
};
