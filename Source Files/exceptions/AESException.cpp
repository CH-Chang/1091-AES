#include <AESException.h>

#include <exception>

AESException::AESException(const int type){
	this->init(type);
} 


void AESException::init(const int type){
	switch(type){
		case AESException::INVILID_KEY_LENGTH:
			this->detail = "Invalid Key Length.";
			break;
		case AESException::INVILID_IV_LENGTH:
			this->detail = "Invalid IV Length.";
			break;
		case AESException::INVALID_PLAINTEXT_LENGHT:
			this->detail = "Invalid Plaintext Length.";
			break;
		case AESException::INVALID_CIPHERTEXT_LENGTH:
			this->detail = "Invalid Ciphertext Length.";
			break;
		default:
			this->detail = "Unknown Error";
			break;
			
	}
}

char * AESException::getDetail(){
	return this->detail;
}

int AESException::getType(){
	return this->type;
}
