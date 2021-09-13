/*
* Adapted from John Purcell's 'Particle Explosion' project found on the 'C++
* for complete beginners' course (2015). Wrote this code when I was following 
* the course videos.
* 
* The slight change made here is that I made the particles create a 'spiral'
* effect rather than an 'explosion' effect (see Particle.cpp for details). 
*
* May experiment further in the future.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <math.h>

#include "Screen.h"
#include "Swarm.h"

using namespace std;

int main(int argc, char* args[]) {

	srand(time(NULL));
	Screen screen;

	const static int halfHeight = Screen::SCREEN_HEIGHT / 2;
	const static int halfWidth = Screen::SCREEN_WIDTH / 2;

	if (screen.Init() == false) {
		cout << "ERROR" << endl;
	}

	Swarm swarm;

	while (true) {
		// Update and draw particles
		int elapsed = SDL_GetTicks();

		//screen.clear();
		swarm.update(elapsed);

		// Create R, G, B char variables in the range [0,2^8]
		unsigned char green = (1 + sin(elapsed * 0.0001)) * 128;
		unsigned char red = (1 + sin(elapsed * 0.0002)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;

		const Particle* const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];
			int x = (particle.m_x + 1) * halfWidth;
			int y = particle.m_y * halfWidth + halfHeight;

			screen.setPixel(x, y, red, green, blue);
		}

		// Creates 'blur' effect
		screen.boxBlur();

		// Draw the screen
		screen.update();

		// Check for messages/events
		if (screen.ProcessEvents() == false) {
			break;
		}
	}

	screen.Close();

	return 0;
}