// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);
    
    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer;
    int file_size;
    // Calculate the file size ??? 
    // How to calculate it correctly ?
    // file_size = header[40] * pow(2, 16) + header[41] * pow(2, 8) + header[42] * pow(2, 0)
    // + header[43] ;
    file_size = 352800;

    printf("file_size = %i", file_size);
    for (int i = 0; i < file_size; i++)
    {
        fread(&buffer, sizeof(int16_t), 1, input);
        // buffer =  buffer * factor;
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }
    
    
    // Close files
    fclose(input);
    fclose(output);
}
