#include<stdio.h>

int valid_password(const char* str,int size){
	int i,flag_upper=0,flag_lower=0,flag_special=0;
	for(i=0;i<size&&!(flag_upper&&flag_lower&&flag_special);++i){
		if(!flag_upper&&str[i]>='A'&&str[i]<='Z')
			flag_upper=1;
		else if(!flag_lower&&str[i]>='a'&&str[i]<='z')
			flag_lower=1;
		else if(!flag_special&&str[i]>=32&&str[i]<=47||str[i]>=92&&str[i]<=96||str[i]>=123&&str[i]<=126)
			flag_special=1;
	}
	return (flag_upper&&flag_lower&&flag_special)?1:0;
}

void main(){
	char arr[]="AAAAASaaS#@#@##Adv",size=sizeof(arr)/sizeof(arr[0])-1; //i.e. neglecting null character
	printf("Password Status: %s",(valid_password(arr,size)?"valid":"not valid"));
}
