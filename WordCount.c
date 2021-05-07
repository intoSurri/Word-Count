#include<stdio.h>																				1 
#include<string.h>

int GetWordNumber(char string[]);   //���㵥����
int GetCharNumber(char string[]);   //�����ַ���

int main(int argc ,char *argv[]) {
	char buff[1000000];
	char string[100000] = "\0";
	FILE *fp = NULL;
	int sum = 0;
	fp = fopen(argv[2],"r");
	if(fp == NULL) {
		printf("�ļ���ȡʧ�ܣ�\n");
		return -1;
	}
	while(!feof(fp)) {
		if(fgets(buff,1000000,fp) != NULL)
			strcat(string,buff);	//���������ո���з����� 
	} 
	if(strcmp(argv[1],"-c") == 0)
		printf("�ļ����ַ����� %d\n",GetCharNumber(buff));
	else if(strcmp(argv[1],"-w") == 0)
		printf("�ļ��ĵ������� %d\n",GetWordNumber(buff));
}
int GetWordNumber(char string[]) {
	int i, flag, num;
    num = 0;	//���ʸ�����
    flag = 0;	// ��־������ȷ�����ڼ���� 
    for (i = 0; string[i]; i++) {
        if (string[i] == ' '||string[i] == ',') 
		 	flag = 1;	// ��⵽��������ñ�־����Ϊ1 
        else if (flag == 1) {// ���ڼ��ʱ����ʾ������һ�����ʣ���������1 
        	num++;
            flag = 0;	//�ڵ�����ʱ���ñ�־����Ϊ0 
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





