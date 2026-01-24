#include <cctype>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

std::string xor_cipher(const std::string& plaintext, const std::string& key) {
    std::string result = "";
    for (size_t i = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];
        if (c != ' ') {
            c ^= key[i % key.length()];
            /* Si c'est un caractère de contrôle, on le convertit avec la notation circonflexe.
               Autrement dit, on inverse le 7e bit pour avoir un caractère ASCII alphabétique et
               on le préfixe par '^'.
            */
            if (std::iscntrl(c)) {
                result += '^';
                c ^= 0x40;
            }
        }
        result += c;
    }

    return result;
}

int main() {
    std::ifstream key_file("clef.txt");
    if (!key_file.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier clef.txt\n";
        return -1;
    }

    auto key = std::string(std::istreambuf_iterator<char>(key_file), std::istreambuf_iterator<char>());
    key_file.close();

    std::ifstream message_file("message.txt");
    if (!message_file.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier message.txt\n";
        return -1;
    }

    auto message = std::string(std::istreambuf_iterator<char>(message_file), std::istreambuf_iterator<char>());
    message_file.close();

    auto ciphertext = xor_cipher(message, key);
    std::ofstream output_file("chiffre.txt", std::ios::trunc);
    if (!output_file.is_open()) {
        std::cout << "Erreur : Impossible d'ouvrir le fichier chiffre.txt\n";
        return -1;
    }

    output_file << ciphertext << std::endl;
    output_file.close();
}