#include <iostream>
#include <string>
#include <unordered_map>

std::string caesar_cipher(const std::string& message, int shift, bool direction = true) {
    std::string result = "";

    // Si direction est false, on inverse le décalage pour déchiffrer
    int actual_shift = direction ? shift : (26 - (shift % 26));

    for (char c : message) {
        if (c >= 'A' && c <= 'Z') {
            int index = (c - 'A' + actual_shift) % 26;
            result += static_cast<char>('A' + index);
        } else if (c >= 'a' && c <= 'z') {
            int index = (c - 'a' + actual_shift) % 26;
            result += static_cast<char>('a' + index);
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    std::string ciphertext = "RGNEIDVGPEWXTRAPHHXFJT";
    // dictionnaire qui associe les lettres pouvant être doublées en français à leur index
    std::unordered_map<char, int> doubled_letters = {{'C', 2},  {'F', 5},  {'L', 11},
                                                     {'M', 12}, {'N', 13}, {'P', 15},
                                                     {'R', 17}, {'S', 18}, {'T', 19}};

    std::cout << "Message chiffré : " << ciphertext << "\n";

    for (auto& p : doubled_letters) {
        std::string attempt = caesar_cipher(ciphertext, p.second, false);
        std::cout << "k = " << p.second << " : " << attempt << "\n\n";
    }
}