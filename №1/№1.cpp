#include <iostream>

void replaceWithHalf(double* sequences[], int sizes[], int num_sequences) {
    
    for (int s = 0; s < num_sequences; ++s) {
        double* sequence = sequences[s];
        int size = sizes[s];
        double max_value = sequence[0];
        int max_index = 0;

       
        for (int i = 1; i < size; ++i) {
            if (sequence[i] > max_value) {
                max_value = sequence[i];
                max_index = i;
            }
        }

        
        for (int i = max_index + 1; i < size; ++i) {
            sequence[i] = 0.5;
        }
    }
}

int main() {
    const int num_sequences = 2; 

    int sizes[num_sequences]; 
    double* sequences[num_sequences]; 

    
    for (int s = 0; s < num_sequences; ++s) {
        std::cout << "Enter the size of the " << s + 1 << "-th sequence: ";
        std::cin >> sizes[s];

        sequences[s] = new double[sizes[s]];

        std::cout << "Enter " << sizes[s] << " real numbers for the " << s + 1 << "-th sequence: " << std::endl;
        for (int i = 0; i < sizes[s]; ++i) {
            std::cin >> sequences[s][i];
        }
    }

 
    replaceWithHalf(sequences, sizes, num_sequences);

    
    for (int s = 0; s < num_sequences; ++s) {
        std::cout << "The " << s + 1 << "-th sequence is changed: " << std::endl;
        for (int i = 0; i < sizes[s]; ++i) {
            std::cout << sequences[s][i] << " ";
        }
        std::cout << std::endl;
        delete[] sequences[s]; 
    }

    return 0;
}