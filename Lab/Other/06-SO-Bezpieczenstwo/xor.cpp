#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char** argv) {
    if (argc != 4) {
         std::cout << "SZYFROWANIE XOR \n Uzycie:\n  " << argv[0] << " [plik_wejsciowy] [klucz] [plik_wyjsciowy]\n";
    } else {
        std::ifstream plik_wejsciowy(argv[1], std::ios::binary);
        if (plik_wejsciowy.is_open()) {
            
            std::string klucz = argv[2];
            std::stringstream bufor;
            unsigned int i = 0;
            char znak = plik_wejsciowy.get();
            while (plik_wejsciowy.good()) {
                bufor << static_cast<char>(znak ^ klucz[i]);
                i = (i+1) % klucz.length();
                znak = plik_wejsciowy.get();
            }

            std::ofstream plik_wyjsciowy;
            plik_wyjsciowy.open(argv[3], std::ios::binary | std::ios::trunc);
            if (plik_wyjsciowy.is_open()) {
                plik_wyjsciowy << bufor.str();
                std::cout << "Szyfrowanie z uzyciem klucza " << klucz << " zakonczone sukcesem! \n";
            }
        } else {
            std::cout << "Blad w odczycie pliku '" << argv[1] << "' .\n";
        }
    }
   
     return 0;
}
