#pragma once
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <time.h>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Entity.hpp"
#include "Effect.hpp"
#include "defs.hpp"

class Game{
	private:
		struct{
			SDL_Renderer *renderer;
			SDL_Window *window;
			SDL_Texture *background;
			SDL_Texture *titleScreen, *endScreen;
			Mix_Chunk *sounds[soundChannel - 1];
			Mix_Music *music;
			bool running;
		}app;
		struct{
			std::vector <Entity> bullets;
			std::vector <Entity*> fighters;
			std::vector <Entity> powerUp;
			std::vector <Entity> debrises;
			std::vector <std::vector <Effect> > effects;
		}Entities;
		TTF_Font *font;
		SDL_Texture *debrisTexture[4];
		std::stringstream healthText, scoreText, hiScoreText;
		std::fstream file;
		Player player;
		Entity playerBullet, enemyBullet, powerUp, debris;
		Enemy *enemy;
		Effect explosion;
		int enemySpawnTimer, enemyFire;
		int lastY;
		int gameTicks;
		void prepareScene();
		int backgroundX;
		int score, highScore;
		void initGame();
		void initPlayer();
		void titleScreen();
		void endScreen();
		void updateEntities();
		void enterAnimation();
		void getInput();
		void drawBackground();
		void addExplosion(int, int);
		void updateHUD();
		void updateScene();
		void draw(SDL_Texture*, int, int);
		SDL_Texture* loadTexture(std::string);
		bool detectCollision(int, int, int, int, int, int, int, int);
	public:
		void start();
};