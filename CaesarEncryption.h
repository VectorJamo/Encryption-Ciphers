#pragma once
struct EncryptionStatus {
	bool success;
	char keyOffset;
};

int getEncryptedChar(char c, int keyOffset);
int getDecryptedChar(char c, int keyOffset);

// For encryption and decryption by giving a key beforehand
EncryptionStatus Encrypt(const char* filepath, int keyOffset);
bool Decrypt(const char* filepath, int keyOffset);
