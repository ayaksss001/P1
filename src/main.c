#include <stdio.h>//printf(),getchar()

#include "game.h"

int main(void)
{
   
  /*ma_result result;
    ma_engine engine;

    // Инициализация аудиодвижка
    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        printf("Failed to initialize audio engine.\n");
        return -1;
    }

    // Проигрываем аудиофайл
    const char* filename = "1.wav";  // или "music.mp3"
    result = ma_engine_play_sound(&engine, filename, NULL);
    if (result != MA_SUCCESS) {
        printf("Failed to play sound: %s\n", filename);
        ma_engine_uninit(&engine);
        return -1;
    }

    printf("Playing '%s'...\nPress Enter to quit.\n", filename);
    getchar();  // Ждём нажатия Enter

    ma_engine_uninit(&engine);*/


   gameLoop();
   return 0;
}