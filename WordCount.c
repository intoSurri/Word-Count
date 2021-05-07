#include<stdio.h>																				1 
#include<string.h>

int GetWordNumber(char string[]);   //计算单词数
int GetCharNumber(char string[]);   //计算字符数

int main(int argc ,char *argv[]) {
	char buff[1000000];
	char string[100000] = "\0";
	FILE *fp = NULL;
	int sum = 0;
	fp = fopen(argv[2],"r");
	if(fp == NULL) {
		printf("文件读取失败！\n");
		return -1;
	}
	while(!feof(fp)) {
		if(fgets(buff,1000000,fp) != NULL)
			strcat(string,buff);	//避免遇到空格或换行符结束 
	} 
	if(strcmp(argv[1],"-c") == 0)
		printf("文件的字符数： %d\n",GetCharNumber(buff));
	else if(strcmp(argv[1],"-w") == 0)
		printf("文件的单词数： %d\n",GetWordNumber(buff));
}
int GetWordNumber(char string[]) {
	int i, flag, num;
    num = 0;	//单词个数当
    flag = 0;	// 标志变量，确定处于间隔处 
    for (i = 0; string[i]; i++) {
        if (string[i] == ' '||string[i] == ',') 
		 	flag = 1;	// 检测到间隔，设置标志变量为1 
        else if (flag == 1) {// 处于间隔时，表示经过了一个单词，单词数加1 
        	num++;
            flag = 0;	//在单词上时，置标志变量为0 
		}
	}
    return num;
}
int GetCharNumber(char string[]) {
	int sum = 0;
	for(int i = 0;string[i] != '\0'; i++){
		if((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z') )
			sum ++;
	}
	return sum;
}





