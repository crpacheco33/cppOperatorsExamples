/*
Here's a C++ project that uses bitwise operators to implement a simple encryption 
and decryption program based on a bitwise XOR operation. This project allows you 
to encrypt and decrypt text using a secret key:
*/

#include <iostream>
#include <string>

std::string EncryptDecrypt(const std::string& text, const std::string& key) {
    std::string result = text;
    for (size_t i = 0; i < text.length(); ++i) {
        result[i] = text[i] ^ key[i % key.length()];
    }
    return result;
}

int main() {
    std::string secretMessage = "Hello, World!";
    std::string secretKey = "SecretKey";

    // Encrypt the message
    std::string encryptedMessage = EncryptDecrypt(secretMessage, secretKey);
    std::cout << "Encrypted Message: " << encryptedMessage << std::endl;

    // Decrypt the message
    std::string decryptedMessage = EncryptDecrypt(encryptedMessage, secretKey);
    std::cout << "Decrypted Message: " << decryptedMessage << std::endl;

    return 0;
}


/*
In this project, we implement a simple encryption and decryption scheme using the XOR bitwise operator (^). 
The EncryptDecrypt function takes a text and a secret key as input and returns the encrypted or decrypted text, 
depending on how it's used. When encrypting, it applies the XOR operation between each character of the text 
and the corresponding character of the key, repeating the key if necessary.

When you run the program, it will display the encrypted message, and then decrypt it to reveal the original 
message. This demonstrates the reversible nature of the XOR operation when using the same key for encryption 
and decryption.

Please note that this is a basic example for educational purposes, and it should not be used for secure 
encryption. In practice, secure encryption algorithms and libraries should be used for any real-world application 
requiring data security.
*/