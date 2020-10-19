#include <iostream>
#include <memory>
#include <cmath>
#include <algorithm>

#include <SDL2/SDL.h>

#ifdef _WIN32
# include <SDL2/SDL_main.h>
#endif

constexpr double Pi = acos(-1.);

constexpr int WIDTH = 500, HEIGHT = 500;

int main(int, char**){
	SDL_Init(SDL_INIT_EVERYTHING);

	auto win = std::shared_ptr<SDL_Window>(
			SDL_CreateWindow(
						"–û–∫–Ω–æ –Ω–∞—à–µ–≥–æ –≥—Ä–∞—Ñ–∏—á–µ—Å–∫–æ–≥–æ –ø—Ä–∏–ª–æ–∂–µ–Ω–∏—è",
						SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
						WIDTH, HEIGHT,
						SDL_WINDOW_SHOWN),
			SDL_DestroyWindow);
	if (win == nullptr) {
		std::cerr << "–ü—Ä–∏ —Å–æ–∑–¥–∞–Ω–∏–∏ –æ–∫–Ω–∞ –ø—Ä–æ–∏–∑–æ—à–ª–∞ –æ—à–∏–±–∫–∞: " <<
				SDL_GetError() << std::endl;
		return 1;
	}

	auto ren = std::shared_ptr<SDL_Renderer>(
			SDL_CreateRenderer(win.get(), -1,
					SDL_RENDERER_ACCELERATED |
					SDL_RENDERER_PRESENTVSYNC),
			SDL_DestroyRenderer);
	if (ren == nullptr) {
		std::cerr << "–ü—Ä–∏ —Å–æ–∑–¥–∞–Ω–∏–∏ renderer-–∞ –ø—Ä–æ–∏–∑–æ—à–ª–∞ –æ—à–∏–±–∫–∞: " <<
				SDL_GetError() << std::endl;
		return 1;
	}

	constexpr int  HeightGround 	= 20;

	constexpr int  HeightWall   	= 200;
	constexpr int  WidthWall  		= 250;

	constexpr int  HeightPipe 		= 100;
	constexpr int  WidthPipe  		= 40;

	constexpr int  HeightRoof       = 100;

	constexpr int  HeightWindow		  = 75;
	constexpr int  WidthWindow		  = 75;
	constexpr int  HeightWindowGround = HeightWall / 2;

	constexpr int  HeightDoor		  = 150;
	constexpr int  WidthDoor		  = 15;

	constexpr int  HeightStairs1      = 25;
	constexpr int  WidthStairs1      = 25;
	constexpr int  HeightStairs2      = 15;
	constexpr int  WidthtStairs2      = 15;
	SDL_Event event;
	/*
	SDL_Rect  Example{Õ‡˜‡ÎÓ ÔÓ ı,
					  Õ‡˜‡ÎÓ ÔÓ Û,
					   ÓÌÂˆ ÔÓ ı,
					   ÓÌÂˆ ÔÓ Û
					 };
	 */
	//  «ÂÏÎˇ
	SDL_Rect  RectGround{0,
						 HEIGHT,
						 WIDTH,
						 -HeightGround
						};
	//   ‡Í‡Ò
	SDL_Rect  RectWall{WIDTH / 2 - WidthWall / 2,
					   HEIGHT - HeightGround,
					   WidthWall,
					   -HeightWall
				      };
	//  “Û·‡
	SDL_Rect  RectPipe{WIDTH / 2 + WidthWall / 4,
					   HEIGHT - (HeightGround + HeightWall),
					   WidthPipe,
					   -HeightPipe
				 	  };
	//  ŒÍÌÓ
	SDL_Rect  RectWindow{WIDTH / 2 - WidthWindow / 2,
						 HEIGHT - HeightWindowGround,
						 WidthWindow,
						 -HeightWindow
						};
	//  ƒ‚Â¸ Ë ÒÚÛÔÂÌ¸ÍË
	SDL_Rect  RectDoor{WIDTH / 2 + WidthWall / 2,
					   HEIGHT - HeightGround,
					   WidthDoor,
					   -HeightDoor
					  };

	SDL_Rect  RectStairs1{WIDTH / 2 + WidthWall / 2 + WidthDoor,
						  HEIGHT - HeightGround,
						  WidthStairs1,
						  -HeightStairs1
						 };


	SDL_Rect  RectStairs2{WIDTH / 2 + WidthWall / 2 + WidthDoor + WidthStairs1,
						  HEIGHT - HeightGround,
						  WidthtStairs2,
						  -HeightStairs2
						 };


	for (;;) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) return 0;
		}

		SDL_SetRenderDrawColor(ren.get(), 0, 191, 255, 0);
		SDL_RenderClear(ren.get());

		//  «ÂÏÎˇ
		SDL_SetRenderDrawColor(ren.get(), 0, 0, 0, 0);
		SDL_RenderDrawRect(ren.get(), &RectGround);
		SDL_RenderFillRect(ren.get(), &RectGround);
		//   ‡Í‡Ò
		SDL_SetRenderDrawColor(ren.get(), 139, 69, 18, 0);
		SDL_RenderDrawRect(ren.get(), &RectWall);
		SDL_RenderFillRect(ren.get(), &RectWall);
		//  “Û·‡
		SDL_SetRenderDrawColor(ren.get(), 139, 69, 18, 0);
		SDL_RenderDrawRect(ren.get(), &RectPipe);
		SDL_RenderFillRect(ren.get(), &RectPipe);
		//   ˚¯‡
		SDL_SetRenderDrawColor(ren.get(), 240, 230, 140, 0);
		SDL_RenderDrawLine(ren.get(), WIDTH/2,
									  HEIGHT - (HeightGround + HeightWall + HeightRoof),
									  WIDTH / 2 - WidthWall/1.5,
									  HEIGHT-(HeightGround + HeightWall)
						  );
		SDL_RenderDrawLine(ren.get(), WIDTH/2,
									  HEIGHT - (HeightGround + HeightWall + HeightRoof),
									  WIDTH / 2 + WidthWall/1.5,
									  HEIGHT-(HeightGround + HeightWall)
						  );
		SDL_RenderDrawLine(ren.get(), WIDTH / 2 - WidthWall/1.5,
									  HEIGHT - (HeightGround + HeightWall),
									  WIDTH / 2 + WidthWall/1.5,
									  HEIGHT-(HeightGround + HeightWall)
						  );
		//  ŒÍÌÓ
		SDL_SetRenderDrawColor(ren.get(), 224, 255, 255, 0);
		SDL_RenderDrawRect(ren.get(), &RectWindow);
		SDL_RenderFillRect(ren.get(), &RectWindow);

		//  ƒ‚Â¸ Ë ÒÚÛÔÂÌ¸ÍË
		SDL_SetRenderDrawColor(ren.get(), 160, 82, 45, 0);
		SDL_RenderDrawRect(ren.get(), &RectDoor);
		SDL_RenderFillRect(ren.get(), &RectDoor);

		SDL_SetRenderDrawColor(ren.get(), 0, 0, 0, 0);
		SDL_RenderDrawRect(ren.get(), &RectStairs1);
		SDL_RenderFillRect(ren.get(), &RectStairs1);

		SDL_RenderDrawRect(ren.get(), &RectStairs2);
		SDL_RenderFillRect(ren.get(), &RectStairs2);

		//  OÍÌÓ ˜Â‰‡Í‡
		int radius = 25;
		SDL_SetRenderDrawColor(ren.get(), 224, 255, 255, 0);
		for (double rr = 0; rr < 2 * Pi; rr += 0.01){
			SDL_RenderDrawPoint(ren.get(),
								WIDTH / 2 + radius * cos(rr),
								HEIGHT - HeightGround - HeightWall - radius * 1.5 - radius * sin(rr)
							   );
		}

		SDL_RenderPresent(ren.get());
	}

	return 0;
}

