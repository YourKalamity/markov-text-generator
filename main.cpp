#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cstdlib>
#include <ctime>


int getNumber() {
    int option;
    std::cin >> option;
    return option;
}


int main() {
    std::string source;
    int option;
    std::cout << "YourKalamity's Markov Text Generator \n\n";

    std::cout << "Select your source text : \n";
    std::cout << "(1) Shrek \n";
    std::cout << "(2) The Bee Movie \n";

    option = getNumber();

    switch(option) {
        case 1:
            std::cout << "Shrek selected \n\n";
            source = "shrek.txt";
            break;
        case 2:
            std::cout << "The Bee Movie selected \n\n";
            source = "bee.txt";
            break;
    }

    std::string output;
    int counter = 0;
    srand((unsigned int)time(NULL));
    while(counter < 100){
        std::vector<std::string> words;
        std::ifstream file(source);
        std::string line;
        while (getline(file, line)) words.push_back(line);
        output = output + words[rand() % words.size()] + " ";
        counter = counter + 1;
    }

    std::cout << output;
    return 0;

}
