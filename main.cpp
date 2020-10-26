#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <AES.h>
#include <AESException.h>

using namespace std;

int main(int argc, char** argv) {
	
	
	
	AES * AESHelper;
	
	
	// 初始 
	try{
		AESHelper = new AES(AES::AES128, AES::ECB, AES::ZeroPadding);
		AESHelper->init("1234567890123456", "1234567890123456");
	} catch (AESException * e){
		printf("%s", e->getDetail());
	}
	
	// 加密 
	unsigned char * encrypted;
	int encryptedSize;
	
	try{
		AESHelper->encrypt("1234", strlen("1234"), &encrypted, &encryptedSize);
	} catch (AESException * e){
		printf("%s", e->getDetail());
	}
	
	// 輸出加密結果 
	printf("加密結果如下:\n\n");
	for(int i=0;i<encryptedSize;i++){
		printf("%02x ", encrypted[i]);
	}
	
	
	
	// ------------------------------------
	printf("\n\n\n");
	// ------------------------------------
	
	
	// 解密
	char * decrypted;
	int decryptedSize; 
	try{
		AESHelper->decrypt(encrypted, encryptedSize, &decrypted, &decryptedSize);
	} catch(AESException * e){
		printf("%s", e->getDetail());
	}
	
	//輸出解密結果
	printf("解密結果如下:\n\n");
	for(int i=0;i<decryptedSize;i++){
		printf("%02x ", decrypted[i]);
	}
	printf("\n");
	for(int i=0;i<decryptedSize;i++){
		printf("%c", decrypted[i]);
	}
	printf("\n");
	
	
	
	system("pause");
	return 0;
}
