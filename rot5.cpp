#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::string rot5(const std::string& message) {
    std::unordered_map<int, char> char_mapping;
    for (int i = 0; i < 26; i++) {
        char_mapping[i] = 'a' + i;
    }

    std::vector<int> indices;
    for (char c : message) {
        if (c == ' ')
            indices.push_back(c);
        else
            indices.push_back((c - 'a' + 5) % 26);
    }

    std::string result;
    result.reserve(indices.size());
    for (int index : indices) {
        if (static_cast<char>(index) == ' ')
            result += ' ';
        else
            result += char_mapping[index];
    }
    return result;
}

int main() {
    std::string message = "la rencontre est prevue a la cafeteria";
    std::cout << "Message original : " << message << "\n";
    std::cout << "Message chiffré : " << rot5(message) << "\n";
}