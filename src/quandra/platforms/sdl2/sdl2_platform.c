#include <SDL.h>
#include "../../qa_platform_impl.h"

/******************************************************************/
QA_HANDLE sdl2_window_create(const char* title, int width, int height)
{
    SDL_Window *window = SDL_CreateWindow(title,
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          width,
                                          height,
                                          SDL_WINDOW_HIDDEN);
    
    if(window == 0){
        SDL_Log("sdl2_window_create() - Fatal error: %s",SDL_GetError());
        return 0;
    }
    
    return window;
}

/******************************************************************/
void sdl2_window_destroy(QA_HANDLE window)
{
    SDL_DestroyWindow((SDL_Window*)window);
}

/******************************************************************/
void sdl2_window_show(QA_HANDLE window)
{
    SDL_ShowWindow((SDL_Window*)window);
}

/******************************************************************/
void sdl2_window_hide(QA_HANDLE window)
{
    SDL_HideWindow((SDL_Window*)window);
}

/******************************************************************/
int _qa_window_impl_init(struct _qa_window_impl *impl)
{
    impl->create_window = &sdl2_window_create;
    impl->destroy_window = &sdl2_window_destroy;
    
    impl->show_window = &sdl2_window_show;
    impl->hide_window = &sdl2_window_hide;
    
    return 0;
}

/******************************************************************/
int sdl2_init(void)
{
    SDL_Log("sdl2_init() - initializing SDL2...");
    
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("sdl2_init() - Fatal Error: %s", SDL_GetError());
        return 1;
    }
    
    struct SDL_version version;
    SDL_GetVersion(&version);
    
    SDL_Log("sdl2_init() - Using SDL2 version: %d.%d.%d",
            version.major, version.minor, version.patch);
 
    return 0;
}

/******************************************************************/
void sdl2_shutdown(void)
{
    SDL_Log("sdl2_shutdown() - Time to quit SDL2, bye!");
    SDL_Quit();
}

/******************************************************************/
int sdl2_exec(void)
{
    
    
    return 0;
}

/******************************************************************/
int _qa_platform_init(struct _qa_platform *platform)
{
    platform->init = &sdl2_init;
    platform->shutdown = &sdl2_shutdown;
    platform->exec = &sdl2_exec;
    
    return 0;
}
