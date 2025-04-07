#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<portaudio.h>
#include <stdint.h>

#include "audio.h"

struct WavHeader{
    char riff[4];
    uint32_t overal_size;
    char wave[4];
    char fmt_chunk[4];
    uint32_t fmt_size;
    uint16_t audio_format;
    uint16_t num_channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t bits_per_sample;
    char data_chunk[4];
    uint32_t data_size; 

};

int readWawvFile(const char* filename, struct WavHeader* header, char** data)
{
    FILE* file = fopen(filename, "rb");
    if(!file)
    {
        printf("Error opening file: %s\n", filename);
        return 0;
    }

    size_t read = fread(header, sizeof(struct WavHeader), 1, file);
    if (read != 1) {
        printf("Failed to read WAV header from file\n");
        fclose(file);
        return 0;
    }

    if(strncmp(header->riff, "RIFF", 4) != 0 || strncmp(header->wave, "WAVE", 4) != 0)
    {
        printf("Invalid WAV file format\n");
        fclose(file);
        return 0;
    }

    *data = (char *)malloc(header->data_size);
    if (!*data) {
        printf("Memory allocation failed\n");
        fclose(file);
        return 0;
    }

    size_t data_read = fread(*data, 1, header->data_size, file);
    if (data_read != header->data_size) {
        printf("Failed to read all audio data (read %zu of %u bytes)\n", data_read, header->data_size);
        free(*data);
        fclose(file);
        return 0;
    }

    fclose(file);
    return 1;
}


int playWav(const char* filename)
{
    struct WavHeader header;
    char* data = NULL;

    if(!readWawvFile(filename, &header, &data))
        return 0;

    PaError err;
    PaStream *stream;

    err = Pa_Initialize();
    if(err != paNoError)
    {
        printf("PortAudio error: %s\n", Pa_GetErrorText(err));
        free(data);
        return 0;
    }

    err = Pa_OpenDefaultStream(
        &stream,
        0,
        header.num_channels,
        paInt16,
        header.sample_rate,
        paFramesPerBufferUnspecified,
        NULL,
        NULL
    );

    if(err != paNoError)
    {
        printf("PortAudio error: %s\n", Pa_GetErrorText(err));
        Pa_Terminate();
        free(data);
        return 0;
    }

    err = Pa_StartStream(stream);
    if(err != paNoError)
    {
        printf("PortAudio error: %s\n", Pa_GetErrorText(err));
        Pa_CloseStream(stream);
        Pa_Terminate();
        free(data);
        return 0;
    }

    // Пишем звук в поток
    err = Pa_WriteStream(stream, data, header.data_size / header.block_align);
    if(err != paNoError)
    {
        printf("PortAudio error: %s\n", Pa_GetErrorText(err));
    }

    while ((err = Pa_IsStreamActive(stream)) == 1)
    Pa_Sleep(100);

    Pa_StopStream(stream);
    Pa_CloseStream(stream);
    Pa_Terminate();

    free(data);
    return 1;
}
