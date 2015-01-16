#include <stdio.h>
#include "math.h"
#include <string.h>

int fibo(int numberOfTerm,int *array)
 {
   if(numberOfTerm>0){
      int first = 1, second = 1,next, i;
      array[0]=1;
      array[1]=1;
      for(i=2;i<numberOfTerm;i++){
         next = first + second;
         first = second;
         second = next;
         array[i]=next;
      }
      return 1;
   };
   return 0;
 } ;


int concat_array(int *array1, int len_of_array1, int *array2, int len_of_array2, int *result_array){
      int i, j ,count=0;
      for(i=0;i<len_of_array1;i++){
         result_array[i] = array1[i];
         count++;
      };
      for(j=0;j<len_of_array2;j++){
         result_array[len_of_array1 + j] = array2[j];
         count++;
      };
      return count;
};

int filter(int *array, int length, int threshold, int **result_array){
   int i,count=0;
   *result_array  = (int *)malloc(sizeof(int)*length);
   for(i=0;i<length;i++){
      if(array[i]>=threshold){
         (*result_array)[count]=array[i];
         count++;
      }
   }
   return count;
};

int reverse(int *array, int length, int *result_array){
   int i,count=0;
   for(i=0;i<length;i++){
      result_array[length-1-i]=array[i];
      count++;
   };
   return count;
};


int slice(int *array, int lengthOfArray,int start_index,int end_index,int **result_array){
      int i,count=0;
      *result_array  = (int *)malloc(sizeof(int)*lengthOfArray);
      if(start_index<0 || end_index>=lengthOfArray || start_index>end_index){
         return 0;
      }
      else{
         for(i=start_index;i<end_index;i++){
            (*result_array)[count]=array[i];
            count++;
         };
      };
      return count;
};

int prime_number(int start_point,int end_point,int **result_array){
   int i,j,count=0;
   int length = end_point - start_point;
   *result_array  = (int *)malloc(sizeof(int)*length);
   if(start_point<0 || end_point<=0 || end_point<start_point){
      return 0;
   }
   else{
      for(i=start_point;i<=end_point;i++){
         int divisor=0;
         for(j=1;j<=i;j++){
            if(i%j==0){
               divisor++;
            }
            if(divisor>=3)
               break;
         };
         if(divisor<=2 && i!=1){
            (*result_array)[count]=i;
            count++;
         };
      };
   };
   return count;
};

int compare_string(char *str1, char *str2){
   int length1,length2,i=0;
   length1 = strlen(str1);
   length2 = strlen(str2);
   if(length1!=length2)
      return 0;
   for(i=0;i<length2;i++){
      if(str1[i]!=str2[i]){
         return 0;
      };
   };
   return 1;
};

int my_strcmp(char *str1, char *str2){
   int length1,length2,length,i=0;
   length1=strlen(str1);
   length2=strlen(str2);

   length=(length1>length2)?length1:length2;
   for(i=0;i<length;i++){
      if(str1[i]!=str2[i]){
         return str1[i]-str2[i];
      };
   };
   return 0;
};

int my_int_forEach(int *array,int length,int (*function)(int ,int )){
   int i;
   int testingArray[length];
   for(i=0;i<length;i++){
      testingArray[i]=(*function)(array[i],i);
   };
   for(i=0;i<length;i++){
      if(testingArray[i]!=array[i])
         return 0;
   }
   return 1;
};


int my_char_forEach(char *array,int length,int (*function) (char ,int )){
   int i;
   char testingArray[length];
   for(i=0;i<length;i++){
      testingArray[i]=(*function)(array[i],i);
   };
   for(i=0;i<length;i++){
      if(testingArray[i]!=array[i])
         return 0;
   }
   return 1;
};

int my_string_forEach(char **array,int length,int (*function) (char *,int )){
   int i;
   for(i=0;i<length;i++){
      (*function)(array[i],i);
   };
   return 1;
};

int my_int_filter(int *array, int length, int **result_array,int (*function) (int )){
   int i,count=0;
   *result_array  = (int *)malloc(sizeof(int)*length);
   for(i=0;i<length;i++){
      if((*function) (array[i] )){
         (*result_array)[count]=array[i];;
         count++;
      };
   }
   return count;
};

int my_char_filter(char *array,int length,char **result_array,int (*function) (char)){
   int i,count=0;
   *result_array  = (char *)malloc(sizeof(char)*length);
   for(i=0;i<length;i++){
      if((*function) (array[i] )){
         (*result_array)[count]=array[i];;
         count++;
      };
   }
   return count;
};

int my_string_filter(char **array,int length,char ***result_array,int (*function) (char*)){
   int i,count=0;
   *result_array  = (char **)malloc(sizeof(int)*length);
   for(i=0;i<length;i++){
      if((*function) (array[i] )){
         (*result_array)[count]=array[i];
         
         count++;
      };
   }
   return count;
};

int my_float_filter(float *array,int length,float **result_array,float (*function) (float)){
   int i,count=0;
   *result_array  = (float *)malloc(sizeof(float)*length);
   for(i=0;i<length;i++){
      if((*function) (array[i] )){
         (*result_array)[count]=array[i];;
         count++;
      };
   }
   return count;
};