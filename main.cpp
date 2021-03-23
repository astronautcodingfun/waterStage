//watersound https://freesound.org/people/Nox_Sound/sounds/511078/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1900, 768), "Water Scenario");

	Texture bg;
	bg.loadFromFile("waterBg.png");

	float currentFrame = 0;
	float currentFrameBg = 0;

	Clock clock;

	Sprite sBg(bg);

	//sound
	Music music;
	music.openFromFile("511078__nox-sound__ambiance-waterfall-loop-01.ogg");
	music.setVolume(80); //80% 
	music.setLoop(true);
	music.play();

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 600;

		if (time > 20) time = 20;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}


		//bg
		currentFrameBg += 0.005 * time;
		sBg.setTextureRect(IntRect(0, 384 * int(currentFrameBg), 1024, 384));
		if (currentFrameBg > 8) currentFrameBg -= 8;
		sBg.setScale(2, 2);
		//


		window.clear(Color::Black);

		window.draw(sBg);

		window.display();
	}

	return 0;
}




