#include <stdio.h>
#include <stdlib.h>
#define hdr_SIZE 44

typedef struct FMT
{
    char        SubChunk1ID[4];
    int         SubChunk1Size;
    short int   AudioFormat;
    short int   NumChannels;
    int         SampleRate;
    int         ByteRate;
    short int   BlockAlign;
    short int   BitsPerSample;
} fmt;

typedef struct DATA
{
    char        Subchunk2ID[4];
    int         Subchunk2Size;
    int         Data[441000]; 
} data;

typedef struct HEADER
{
    char        ChunkID[4];
    int         ChunkSize;
    char        Format[4];
    fmt         S1;
    data        S2;
} header;



int main()
{
    char nameIn[255], nameOut[255];

    printf("Enter the names of input and output files including file extension:\n");
    scanf ("%s", nameIn);
    //printf("%s\n", nameIn);
    scanf ("%s", nameOut);
    //printf("%s\n", nameOut);


    FILE *input = fopen( nameIn, "rb");
    FILE *output = fopen( nameOut, "wb");
    header hdr;

    if(input == NULL)
    {
        printf("Unable to open wave file (input)\n");
        exit(EXIT_FAILURE);
    }

    fread(&hdr, sizeof(char), hdr_SIZE, input);

    /* Displaying file's metadata (chunks). */
    printf("\n*********************************\n");
    printf("WAVE file's metadata:\n\n");

    printf("%4.4s\n",  hdr.ChunkID );
    printf("%d\n",     hdr.ChunkSize );
    printf("%4.4s\n",  hdr.Format );

    printf("%4.4s\n",  hdr.S1.SubChunk1ID );
    printf("%d\n",     hdr.S1.SubChunk1Size );
    printf("%d\n",     hdr.S1.AudioFormat );
    printf("%d\n",     hdr.S1.NumChannels );
    printf("%d\n",     hdr.S1.SampleRate );
    printf("%d\n",     hdr.S1.ByteRate );
    printf("%d\n",     hdr.S1.BlockAlign );
    printf("%d\n",     hdr.S1.BitsPerSample );

    printf("%4.4s\n",  hdr.S2.Subchunk2ID );
    printf("%d\n",     hdr.S2.Subchunk2Size );
    printf("\n*********************************\n");


    /* Dead end... =( */


    fclose(input);
    fclose(output);

    return 0;
}