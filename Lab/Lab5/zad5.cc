#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;


int main(int argc, char* argv[]) {
    // sprawdz wprowadzone parametry
    if (argc != 4) {
        std::cerr << "Niezgodna liczba parametrow" << std::endl;
        return 1;
    }

    // rozmiar bufora z parametru pierwszego 
    size_t buffer_size_first_parametr = std::stoul(argv[1]);

    // otworz plik wejsniowy i wyjsciowy 
    std::ifstream input_file(argv[2], std::ios::binary);
    std::ofstream output_file(argv[3], std::ios::binary);

    // sprawdz poprawonosc otwarcia plikow
    if (!input_file || !output_file) {
        std::cerr << "Zle otworzone pliki" << std::endl;
        return 1;
    }

    // stworz bufor o rozmiarze z pierwszego parametru
    char* buffer_first = new char[buffer_size_first_parametr];

    // czas poczatkowy
    auto start_time = std::chrono::high_resolution_clock::now();

    // kopiuj plik
    while (input_file)
    {
        input_file.read(buffer_first, buffer_size_first_parametr);
        output_file.write(buffer_first, input_file.gcount());
    }

    // czas koncowy
    auto end_time = std::chrono::high_resolution_clock::now();

    // wyswietlenie i obliczenie czasu kopiowania 
    auto duration_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Czas kopiowania" << duration_time << " ms" << std::endl;
    
    delete[] buffer_first;

    return 0;
}