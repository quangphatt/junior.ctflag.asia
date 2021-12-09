#include <stdio.h>
#include <string.h>

int checkPassword(char * password) {
    int lenpass = strlen(password);
    if ((lenpass ^ 0xF))    //=> 15 characters  
		return 0;
    if ((strncmp(password, "\x43"
            "T\106{", 0x4) ^ 0x0))   //=> password="CTF{-----------"
		return 0;
    if (password[14] != '}')         //=> password="CTF{----------}"
		return 0;
    const char * pass22 = password + 0x4;    //=> pass22="----------}"
    if ((pass22[0] > '0') & !!(pass22[0] > '0') || (pass22[0] < '0') & !!(pass22[0] < '0')) 
		return 0;
    if (((int) pass22[1] + (0x1B39) ^ 0x1B9B)) 
		return 0;
    if (((int) pass22[2] + (int) pass22[3] ^ 0xDB)) 
		return 0;
    if (((int) pass22[3] - (int) pass22[2] ^ 0xF)) 
		return 0;
    if (pass22[4] - pass22[3] != (char)(-(0x12))) 
		return 0;
    if (((pass22[5] ^ '0') ^ 0x4)) 
		return 0;
    char o_f5c8733d86f = (char) pass22[6] * (char) pass22[5];
    if ((char)(pass22[6] * pass22[5]) != -(0x70)) 
		return 0;
    if (((0xA) * (int) pass22[7] - (0xC) * (int) pass22[8] + (0x13) * (int) pass22[9] ^ 0x7D4)) 
		return 0;
    if (((0x1C) * (int) pass22[7] - (int) pass22[8] + (0x45) * (int) pass22[9] ^ 0x22D2)) 
		return 0;
    if (((0x71) * (int) pass22[7] - (0x7E) * (int) pass22[8] + (0x3E7) * (int) pass22[9] ^ 0x1AB43)) 
		return 0;
    return 1;
}

int main()
{
	char password[128];
	printf("[+] Hay~ nhap password: ");			// CTF{----------}
	gets(password);
	if (0 != checkPassword(password))
		printf("[+] Password dung, flag la %s\n", password);
	else
		printf("[+] Ban da nhap sai password\n");
	return 0;
}
