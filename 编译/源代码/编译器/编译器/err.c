#include <stdio.h>
#include "err.h"
#include "Global_Var.h"
#include "lex.h"
#include "asm.h"
char msg[100][100]= {
	"ȱ��Դ�ļ�",			//0
	"�ļ�������",			//1
	"ȱ��\"",				//2
	"���ɽ��ܵ��ַ�",		//3
	"ȱ�١�'��",			//4
	"�������ű�Χ",		//5
	"��������ͻ",			//6	
	"��������ʧ��",			//7
	"�Ⱥ��Ҳ��ַ��Ƿ�",		//8	
	"��ʧ��;��",			//9
	"�ؼ��ִ���",			//10
	"��ʧ��ʶ��",			//11
	"��ʧ��]��",			//12
	"���ú���δ����",		//13
	"������ǰ0",			//14
	"�βθ�����ƥ��",		//15
	"δ�������",			//16
	"��ʧ��(��",			//17
	"��ʧ��)��",			//18
	"��ʧ��}��",			//19
	"�������ش���",			//20
	"���ʽȱʧ�����",		//21
	"���Ӳ��Ϸ�",			//22
	"��������ֵ",			//23
	"ȱ�١�{��",			//24
	"ȱ��main����",			//25
	"����û�г�ʼ��",		//26
	"������ǰ��",			//27
	"���ֹ���",				//28
	"�ַ������ݴ���",		//29
	"�ַ����ݴ���",			//30
	"��������ʧ��",			//31
	"��������",				//32
	"������������",			//33
	"�ķ��в�������default", //34
	"�����±�Խ��"			//35
};
void endskip() {
	while (errpos < cc) {
		fprintf(out, "-");
		errpos = errpos + 1;
	}
	skipflag = 0;
}
void skipstatement() {
	skipflag = 1;
	while ( sy != ifsy && sy != switchsy &&
		sy != dosy && sy != lbrace && sy != scanfsy &&
		sy != printsy && sy != semicolon && sy != returnsy  && sy!=rbrace)
	{
		insymbol();
	}
	if (sy == semicolon) {
		insymbol();
	}
	if (skipflag)endskip();
}
void skiprparent() {
	skipflag = 1;
	while (sy != rparent)
	{
		insymbol();
	}
	if (skipflag)endskip();
}
void skiprbrack() {
	skipflag = 1;
	while (sy != rbrack )
	{
		insymbol();
	}
	if (skipflag)endskip();
}
void skipcase() {
	skipflag = 1;
	while (sy != rbrace && sy != casesy)
	{
		insymbol();
	}
	if (skipflag)endskip();
}
void skiprbrace() {
	skipflag = 1;
	while (sy != rbrace)
	{
		insymbol();
	}
	if (skipflag)endskip();
}
void skipfacnext() {
	skipflag = 1;
	while (sy != plus && sy != minus && sy != times && sy!=idiv && sy!=rparent && sy!=semicolon)
	{
		insymbol();
	}
	if (skipflag)endskip();
}
void skipfundec() {
	skipflag = 1;
	while (sy != voidsy && sy != intsy && sy != charsy)
	{
		insymbol();
	}
	if (skipflag)endskip();
}
void skipdec() {
	skipflag = 1;
	while ( sy!=intsy && sy!=charsy)
	{
		insymbol();
	}
	if (skipflag)endskip();
}
void skipcondec() {
	skipflag = 1;
	while (sy != constsy && sy != intsy && sy != charsy)
	{
		insymbol();
	}
	if (skipflag)endskip();
}
void skipsem() {
	skipflag = 1;
	while (sy != semicolon)
	{
		insymbol();
	}
	insymbol();
	if (skipflag)endskip();
}
void skiplbrace() {
	skipflag = 1;
	while (sy != lbrace) {
		insymbol();
	}
	if (skipflag)endskip();
}

void err(int n) {
	int i;
	if (errpos == 0) {
		fprintf(out, "*");
	}
	if (cc > errpos) {
		for (i = 3; i < cc - errpos; i++) {
			fprintf(out," ");
		}
		fprintf(out, "^");
		errpos = cc+1;
	}
	printf("��%d�У���%d���ַ���%s\n",linenum,cc,msg[n]);
}