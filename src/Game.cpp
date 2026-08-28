
#include <iostream>
#include "Game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_video.h>

Game::Game() {
  isRunning = false;
  std::cout << "Game constructor called" << std::endl;
}

Game::~Game() { std::cout << "Game destructor called" << std::endl; }

void Game::Initialize() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

    std::cerr << "Error Initializing SDL" << std::endl;
    exit(1);
  }

  // create a window
  SDL_DisplayMode displayMode;
  SDL_GetDesktopDisplayMode(0, &displayMode);
  windowWidth = 800; //displayMode.w;
  windowHeight = 600;// displayMode.h;
  window =
      SDL_CreateWindow("My Engine", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED,windowWidth, windowHeight, SDL_WINDOW_BORDERLESS);

  if (!window) {
    std::cerr << "Failed to create window! Error" << SDL_GetError()
              << std::endl;
    exit(1);
  }

  renderer = SDL_CreateRenderer(window, -1, 0);

  if (!renderer) {
    std::cerr << "Failed to create renderer! Error" << SDL_GetError()
              << std::endl;
    exit(1);
  }

  SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
  isRunning = true;
}

void Game::Run() {

  while (isRunning) {
    processInput();
    Update();
    Render();
  }
}

void Game::Destroy() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Game::processInput() {

  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      isRunning = false;
      break;

    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_ESCAPE) {
        isRunning = false;
      }
      break;

    default:
      break;
    }
  }
}

void Game::Update() {}

void Game::Render() {
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderClear(renderer);

  // Todo: Draw something
  SDL_RenderPresent(renderer);
}
