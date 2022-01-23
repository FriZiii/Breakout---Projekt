#include "Main.h"

int main()
{
	//Level
	int bricksOneCount[8]{};
	int bricksTwoCount[8]{};
	int bricksThreeCount[8]{};
	int bricksFourCount[8]{};
	for (int i = 0; i < 8; i++)
	{
		bricksOneCount[i] = 1;
		bricksTwoCount[i] = 1;
		bricksThreeCount[i] = 1;
		bricksFourCount[i] = 1;
	}
		
	//Const values
	const float platformSizeX = 150;
	const float platformSizeY = 25;

	float radiusBall = 15;

	float xBallVelocity = 6;
	float yBallVelocity = 6;

	float velocityX = 15;

	bool menu = true;
	bool game = false;
	bool gameover = false;
	bool won = false;
	bool options = false;
	int maxscore = Maxscore(bricksOneCount, bricksTwoCount, bricksThreeCount, bricksFourCount);
	int* maxscoretest;
	maxscoretest = &maxscore;

	//Time
	sf::Time elapsed_time;
	sf::Clock r;

	//Fonts
	sf::Font font;
	font.loadFromFile("Fonts/BahnPro_Regular.ttf");

	Color colors(85, 158, 199);

	//Sound
	sf::SoundBuffer buffer;
	buffer.loadFromFile("Sounds/Collide.wav");
	sf::Sound sound;
	sound.setBuffer(buffer);

	//Volume
	float volumeLevels = 10;
	sound.setVolume(volumeLevels);
	sf::CircleShape Volume;
	Volume.setRadius(51/2);
	Vector2f optionsPosition((139+(51/2)), 281+(51/2));
	Volume.setPosition(optionsPosition);
	Volume.setFillColor(Color(255, 206, 6));

	//Ball Size
	sf::CircleShape BallSize;
	BallSize.setRadius(51 / 2);
	Vector2f optionsSizeBallPosition((139 + (51 / 2)), 384 + (51 / 2));
	BallSize.setPosition(optionsSizeBallPosition);
	BallSize.setFillColor(Color(255, 206, 6));

	//Ball Speed
	sf::CircleShape BallSpeed;
	BallSpeed.setRadius(51 / 2);
	Vector2f optionsSpeedBallPosition((139 + (51 / 2)), 487 + (51 / 2));
	BallSpeed.setPosition(optionsSpeedBallPosition);
	BallSpeed.setFillColor(Color(255, 206, 6));
	Vector2f ballPositionSHOW(Vector2f(974 - 2*(radiusBall), 511 - 2*(radiusBall)));

	//Platform speed
	sf::CircleShape PlatformSpeed;
	PlatformSpeed.setRadius(51 / 2);
	Vector2f optionsPlatformSpeedPosition((139 + (51 / 2)), 590 + (51 / 2));
	PlatformSpeed.setPosition(optionsPlatformSpeedPosition);
	PlatformSpeed.setFillColor(Color(255, 206, 6));

	sf::Vector2f PlatformSpeedShowPosition(980 - (platformSizeX / 2), 670);

	//Game Backgroud
	sf::Texture GameBackground;
	GameBackground.loadFromFile("IMG/bg.png");
	sf::Sprite GameBackgroundSprite;
	GameBackgroundSprite.setTexture(GameBackground);

	//Breakout logo
	sf::Texture breakoutTexture;
	breakoutTexture.loadFromFile("IMG/breakout.png");
	sf::RectangleShape breakout;
	sf::Vector2f breakoutPosition(640 - (687 / 2), 85);
	breakout.setSize(Vector2f(687, 152));
	breakout.setPosition(breakoutPosition);
	breakout.setTexture(&breakoutTexture);

	//Play logo
	sf::Texture playTexture;
	playTexture.loadFromFile("IMG/play.png");
	sf::RectangleShape play;
	sf::Vector2f playPosition(640 - (284.5 / 2), 287);
	play.setSize(Vector2f(284.5, 118));
	play.setPosition(playPosition);
	play.setTexture(&playTexture);

	//Again logo
	sf::Texture againTexture;
	againTexture.loadFromFile("IMG/again.png");
	sf::RectangleShape again;
	sf::Vector2f againPosition(640 - (284.5 / 2), 287);
	again.setSize(Vector2f(284.5, 118));
	again.setPosition(againPosition);
	again.setTexture(&againTexture);

	//Options logo
	sf::Texture optionsTexture;
	optionsTexture.loadFromFile("IMG/optionsbutton.png");
	sf::RectangleShape optionsLogo;
	sf::Vector2f optionsPositionButton(640 - (284.5 / 2), 425);
	optionsLogo.setSize(Vector2f(284.5, 118));
	optionsLogo.setPosition(optionsPositionButton);
	optionsLogo.setTexture(&optionsTexture);

	//Menu logo
	sf::Texture menuTexture;
	menuTexture.loadFromFile("IMG/menu.png");
	sf::RectangleShape menuLogo;
	sf::Vector2f menuPosition(640 - (284.5 / 2), 425);
	menuLogo.setSize(Vector2f(284.5, 118));
	menuLogo.setPosition(menuPosition);
	menuLogo.setTexture(&menuTexture);

	//Exit logo
	sf::Texture exitTexture;
	exitTexture.loadFromFile("IMG/exit.png");
	sf::RectangleShape exit;
	sf::Vector2f exitPosition(640 - (284.5 / 2), 563);
	exit.setSize(Vector2f(284.5, 118));
	exit.setPosition(exitPosition);
	exit.setTexture(&exitTexture);

	//Gameover Background
	sf::Texture GameOverBackground;
	GameOverBackground.loadFromFile("IMG/blureBg.png");
	sf::Sprite GameOverBackgroundSprite;
	GameOverBackgroundSprite.setTexture(GameOverBackground);

	//Options Background
	sf::Texture OptionsBackground;
	OptionsBackground.loadFromFile("IMG/options.png");
	sf::Sprite OptionsBackgrounSprite;
	OptionsBackgrounSprite.setTexture(OptionsBackground);

	//Credits text 
	sf::Texture creditsTextTexture;
	creditsTextTexture.loadFromFile("IMG/creditsText.png");
	sf::RectangleShape creditsText;
	sf::Vector2f creditsTextPosition(0,0);
	creditsText.setSize(Vector2f(1280, 720));
	creditsText.setPosition(creditsTextPosition);
	creditsText.setTexture(&creditsTextTexture);

	//Random Generator
	srand(time(NULL));
	int random = rand()%2;

	//Window Reder
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Breakout", 4U);
	window.setFramerateLimit(60);

	//Mouse tracking
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

	//Icon of window
	sf::Image windowIcon;
	windowIcon.loadFromFile("IMG/ico256x256.png");
	window.setIcon(256, 256, windowIcon.getPixelsPtr());

	//Cursor
	window.setMouseCursorVisible(false);
	sf::RectangleShape Cursor;	
	sf::Texture cursorTexture;
	cursorTexture.loadFromFile("IMG/cursor.png");
	cursorTexture.setSmooth(true);
	Cursor.setTexture(&cursorTexture);
	Cursor.setSize(Vector2f(40, 40));

	//Platform
	sf::RectangleShape platform;
	sf::Vector2f platformPosition(640 - (platformSizeX / 2), 600);
	platform.setPosition(platformPosition);
	platform.setSize(sf::Vector2f(platformSizeX, platformSizeY));

	//Platform Texture
	sf::Texture platformTexture;
	platformTexture.loadFromFile("IMG/platform.png");
	platform.setTexture(&platformTexture);

	//Ball
	sf::CircleShape ball;
	sf::Vector2f ballPosition(640 - radiusBall, (600 - (2 * radiusBall) - 15));
	ball.setPosition(ballPosition);
	ball.setRadius(radiusBall);
	sf::Texture ballTexture;
	ballTexture.loadFromFile("IMG/ball.png");
	ball.setTexture(&ballTexture);

	//Ball first direction setup
	if (random == 1)
	{
		xBallVelocity = xBallVelocity * (-1);
	}
	if (random == 0)
	{
		xBallVelocity = xBallVelocity * (1);
	}

	//Main loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//Cursor position in float
		Vector2f mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
		//Cursor
		Cursor.setPosition(mousePositionFloat);
		Cursor.setTextureRect(IntRect(0, 0, 481, 487));

		//Render
		if (options == true && gameover == false && menu == false && game == false && won == false)
		{
		window.clear();

		window.draw(GameOverBackgroundSprite);
		window.draw(OptionsBackgrounSprite);

		if (sf::Keyboard::isKeyPressed(Keyboard::Escape))
		{
			menu = true;
			game = false;
			gameover = false;
			won = false;
			options = false;
		}

		sf::RectangleShape BOX;
		BOX.setSize(Vector2f(360, 360));
		BOX.setPosition(Vector2f(794, 281));

		//Volume
		sf::RectangleShape volumebar;
		Color colors(59, 95, 216);
		volumebar.setFillColor(Color::Transparent);
		volumebar.setSize(Vector2f(633, 51));
		volumebar.setPosition(139, 281);

		sf::Texture songTexture;
		songTexture.loadFromFile("IMG/songVolume.png");
		BOX.setTexture(&songTexture);

		Text volumeText;
		volumeText.setFont(font);
		volumeText.setCharacterSize(50);
		volumeText.setFillColor(colors);
		Volume.setOrigin(25, 25);

		// Update/Refresh frequency of timestop
		sf::Time delta_time = sf::milliseconds(800);

		elapsed_time += r.restart();
		int volume = (optionsPosition.x / 58.2) - 2;
		float volumeLevels = volume;
		sound.setVolume(volumeLevels);
		string volumeString = to_string(volume);
		volumeText.setString(volumeString);
		volumeText.setPosition(optionsPosition.x - (volumeText.getGlobalBounds().width / 2), optionsPosition.y - (10 + (volumeText.getGlobalBounds().height / 2)));

		if (sf::Mouse::getPosition(window).y > Volume.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (Volume.getGlobalBounds().top + Volume.getGlobalBounds().height))
		{
			if (sf::Mouse::getPosition(window).x > Volume.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (Volume.getGlobalBounds().left + Volume.getGlobalBounds().width))
			{
				while (elapsed_time >= delta_time)
				{
					sound.play();
					elapsed_time -= delta_time;
				}
				window.draw(BOX);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (optionsPosition.x >= 139 + (51 / 2) && optionsPosition.x <= 772 + (51 / 2))
				{
					if (mousePositionFloat.x >= 139 + (51 / 2) && mousePositionFloat.x <= 722 + (51 / 2))
					{
						optionsPosition = Vector2f(mousePositionFloat.x, optionsPosition.y);
						Volume.setPosition(optionsPosition);
					}
				}
			}
		}
		if (sf::Mouse::getPosition(window).x > Volume.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (Volume.getGlobalBounds().left + Volume.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > Volume.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (Volume.getGlobalBounds().top + Volume.getGlobalBounds().height))
		{
			Cursor.setTextureRect(IntRect(481, 0, 481, 487));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				Cursor.setTextureRect(IntRect(962, 0, 481, 487));
			}
		}
		window.draw(volumebar);
		window.draw(Volume);
		window.draw(volumeText);

		//BallSize
		sf::RectangleShape ballsizeebar;
		ballsizeebar.setFillColor(Color::Transparent);
		ballsizeebar.setSize(Vector2f(633, 51));
		ballsizeebar.setPosition(139, 281 * 2);

		Text ballsizeText;
		ballsizeText.setFont(font);
		ballsizeText.setCharacterSize(50);
		ballsizeText.setFillColor(colors);
		BallSize.setOrigin(25, 25);

		int ballsize = (optionsSizeBallPosition.x / 58.2) - 2;
		radiusBall = (ballsize / static_cast<float>(2)) * 7.5;
		ball.setRadius(radiusBall);
		ball.setPosition(ballPositionSHOW);
		string ballsizeString = to_string(ballsize);
		ballsizeText.setString(ballsizeString);
		ballsizeText.setPosition(optionsSizeBallPosition.x - (ballsizeText.getGlobalBounds().width / 2), optionsSizeBallPosition.y - (10 + (ballsizeText.getGlobalBounds().height / 2)));

		if (sf::Mouse::getPosition(window).y > BallSize.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (BallSize.getGlobalBounds().top + BallSize.getGlobalBounds().height))
		{
			if (sf::Mouse::getPosition(window).x > BallSize.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (BallSize.getGlobalBounds().left + BallSize.getGlobalBounds().width))
			{
				window.draw(ball);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (optionsSizeBallPosition.x >= 139 + (51 / 2) && optionsSizeBallPosition.x <= 772 + (51 / 2))
					{
						if (mousePositionFloat.x >= 139 + (51 / 2) && mousePositionFloat.x <= 722 + (51 / 2))
						{
							optionsSizeBallPosition = Vector2f(mousePositionFloat.x, optionsSizeBallPosition.y);
							BallSize.setPosition(optionsSizeBallPosition);
						}
					}
				}
			}
		}
		if (sf::Mouse::getPosition(window).x > BallSize.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (BallSize.getGlobalBounds().left + BallSize.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > BallSize.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (BallSize.getGlobalBounds().top + BallSize.getGlobalBounds().height))
		{
			Cursor.setTextureRect(IntRect(481, 0, 481, 487));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				Cursor.setTextureRect(IntRect(962, 0, 481, 487));
			}
		}
		window.draw(ballsizeebar);
		window.draw(BallSize);
		window.draw(ballsizeText);

		//BallSpeed
		sf::RectangleShape ballspeedebar;
		ballspeedebar.setFillColor(Color::Transparent);
		ballspeedebar.setSize(Vector2f(633, 51));
		ballspeedebar.setPosition(139, 281 * 3);

		Text ballspeedText;
		ballspeedText.setFont(font);
		ballspeedText.setCharacterSize(50);
		ballspeedText.setFillColor(colors);
		BallSpeed.setOrigin(25, 25);

		int ballspeed = 0;
		ballspeed = (optionsSpeedBallPosition.x / 58.2) - 2;
		string ballspeedString = to_string(ballspeed);
		ballspeedText.setString(ballspeedString);
		ballspeedText.setPosition(optionsSpeedBallPosition.x - (ballspeedText.getGlobalBounds().width / 2), optionsSpeedBallPosition.y - (10 + (ballspeedText.getGlobalBounds().height / 2)));

		ball.setPosition(ballPositionSHOW);

		if (ballPositionSHOW.x < 809 || ballPositionSHOW.x > 1139 - 2 * radiusBall)
		{
			xBallVelocity *= -1;
			sound.play();
		}
		if (ballPositionSHOW.y <= 296 || ballPositionSHOW.y >= 626 - 2*radiusBall)
		{
			yBallVelocity *= -1;
			sound.play();
		}


		if (sf::Mouse::getPosition(window).y > BallSpeed.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (BallSpeed.getGlobalBounds().top + BallSpeed.getGlobalBounds().height))
		{
			if (sf::Mouse::getPosition(window).x > BallSpeed.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (BallSpeed.getGlobalBounds().left + BallSpeed.getGlobalBounds().width))
			{

				window.draw(ball);
				ballPositionSHOW.y += yBallVelocity;
				ballPositionSHOW.x += xBallVelocity;
				ball.setPosition(ballPositionSHOW);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (optionsSpeedBallPosition.x >= 139 + (51 / 2) && optionsSpeedBallPosition.x <= 772 + (51 / 2))
				{
					if (mousePositionFloat.x >= 139 + (51 / 2) && mousePositionFloat.x <= 722 + (51 / 2))
					{
						ballPositionSHOW=(Vector2f(974 - (radiusBall), 511 - (radiusBall )));
						xBallVelocity = ballspeed;
						yBallVelocity = ballspeed;

						optionsSpeedBallPosition = Vector2f(mousePositionFloat.x, optionsSpeedBallPosition.y);
						BallSpeed.setPosition(optionsSpeedBallPosition);
					}
				}
			}
		}
		if (sf::Mouse::getPosition(window).x > BallSpeed.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (BallSpeed.getGlobalBounds().left + BallSpeed.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > BallSpeed.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (BallSpeed.getGlobalBounds().top + BallSpeed.getGlobalBounds().height))
		{
			Cursor.setTextureRect(IntRect(481, 0, 481, 487));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				Cursor.setTextureRect(IntRect(962, 0, 481, 487));
			}
		}
		window.draw(ballspeedebar);
		window.draw(BallSpeed);
		window.draw(ballspeedText);

		//Platform speed
		sf::RectangleShape platformspeedbar;
		platformspeedbar.setFillColor(Color::Transparent);
		platformspeedbar.setSize(Vector2f(633, 51));
		platformspeedbar.setPosition(139, 281 * 4);

		Text platformspeedText;
		platformspeedText.setFont(font);
		platformspeedText.setCharacterSize(50);
		platformspeedText.setFillColor(colors);
		PlatformSpeed.setOrigin(25, 25);

		int platformspeed = 0;
		platformspeed = (optionsPlatformSpeedPosition.x / 58.2) - 2;

		velocityX = 7.5 * platformspeed;

		string platformspeedString = to_string(platformspeed);
		platformspeedText.setString(platformspeedString);
		platformspeedText.setPosition(optionsPlatformSpeedPosition.x - (platformspeedText.getGlobalBounds().width / 2), optionsPlatformSpeedPosition.y - (10 + (platformspeedText.getGlobalBounds().height / 2)));

		platform.setPosition(PlatformSpeedShowPosition);

		if (sf::Keyboard::isKeyPressed(Keyboard::A) || sf::Keyboard::isKeyPressed(Keyboard::Left))
		{
			if (PlatformSpeedShowPosition.x > 0)
				PlatformSpeedShowPosition.x -= velocityX;
		}
		if (sf::Keyboard::isKeyPressed(Keyboard::D) || sf::Keyboard::isKeyPressed(Keyboard::Right))
		{
			if (PlatformSpeedShowPosition.x < 1280 - platformSizeX)
				PlatformSpeedShowPosition.x += velocityX;
		}

		if (sf::Mouse::getPosition(window).y > PlatformSpeed.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (PlatformSpeed.getGlobalBounds().top + PlatformSpeed.getGlobalBounds().height))
		{
			if (sf::Mouse::getPosition(window).x > PlatformSpeed.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (PlatformSpeed.getGlobalBounds().left + PlatformSpeed.getGlobalBounds().width))
			{
				platform.setPosition(PlatformSpeedShowPosition);
				window.draw(platform);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (optionsPlatformSpeedPosition.x >= 139 + (51 / 2) && optionsPlatformSpeedPosition.x <= 772 + (51 / 2))
				{
					if (mousePositionFloat.x >= 139 + (51 / 2) && mousePositionFloat.x <= 722 + (51 / 2))
					{
						optionsPlatformSpeedPosition = Vector2f(mousePositionFloat.x, optionsPlatformSpeedPosition.y);
						PlatformSpeed.setPosition(optionsPlatformSpeedPosition);
					}
				}
			}
		}
		if (sf::Mouse::getPosition(window).x > PlatformSpeed.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (PlatformSpeed.getGlobalBounds().left + PlatformSpeed.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > PlatformSpeed.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (PlatformSpeed.getGlobalBounds().top + PlatformSpeed.getGlobalBounds().height))
		{
			Cursor.setTextureRect(IntRect(481, 0, 481, 487));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				Cursor.setTextureRect(IntRect(962, 0, 481, 487));
			}
		}
		window.draw(platformspeedbar);
		window.draw(PlatformSpeed);
		window.draw(platformspeedText);

		window.draw(Cursor);
		window.display();
	}
		else if (game == true && gameover == false && won == false && menu == false && options == false)
		{
			//Ball Physic
			if (won == false && menu == false)
			{
				if (ballPosition.x < 0 || ballPosition.x >1280 - 2 * radiusBall)
				{
					xBallVelocity *= -1;
					sound.play();
				}
				if (ballPosition.y < 0)
				{
					yBallVelocity *= -1;
					sound.play();
				}
			}

			//DownOver
			if (won == false && menu == false)
			{	
				if (ballPosition.y + (2 * radiusBall) > 660)
				{
					ballPosition.y = ball.getPosition().y;
					ballPosition.x = ball.getPosition().y;
					gameover = true;
					game = false;
				}
			}

			//BouncePlatform
			if (won == false && menu == false)
			{
				if(platformPosition.y <= ballPosition.y + 2 * radiusBall && platformPosition.y + 50 >= ballPosition.y + 2 * radiusBall)
				{
					//Left
					if (ballPosition.x + radiusBall >= platformPosition.x && (ballPosition.x + radiusBall < platformPosition.x + platformSizeX / 3))
					{
						yBallVelocity *= -1;
						xBallVelocity *= -1;
						sound.play();
					}
					//Middle
					if (ballPosition.x + radiusBall >= platformPosition.x + platformSizeX / 3 && (ballPosition.x + radiusBall < platformPosition.x + 2 * (platformSizeX / 3)))
					{
						yBallVelocity *= -1;
						sound.play();
					}
					//Right
					if (ballPosition.x + radiusBall >= platformPosition.x + 2 * (platformSizeX / 3) && (ballPosition.x + radiusBall <= platformPosition.x + platformSizeX))
					{
						yBallVelocity *= -1;
						xBallVelocity *= -1;
						sound.play();
					}
				}
			}

			//Ball Moving 
			if (menu == false && game == true)
			{
				ballPosition.y += yBallVelocity;
				ballPosition.x += xBallVelocity;
				ball.setPosition(ballPosition);
			}

			//Moving platform
			if (won == false && menu == false)
			{
				if (sf::Keyboard::isKeyPressed(Keyboard::A) || sf::Keyboard::isKeyPressed(Keyboard::Left))
				{
					if (platformPosition.x >= 0)
						platformPosition.x -= velocityX;
				}
				if (sf::Keyboard::isKeyPressed(Keyboard::D) || sf::Keyboard::isKeyPressed(Keyboard::Right))
				{
					if (platformPosition.x <= 1280 - platformSizeX)
						platformPosition.x += velocityX;
				}
				platform.setPosition(platformPosition);
			}

			//Game
			window.clear();
			window.draw(GameBackgroundSprite);
			window.draw(ball);
			window.draw(platform);

			//Bricks
			Bricks(bricksOneCount, bricksTwoCount, bricksThreeCount, bricksFourCount, ballPosition, yBallVelocity, xBallVelocity, sound, window, radiusBall);

			//Score
			string points;
			int k = score(bricksOneCount, bricksTwoCount, bricksThreeCount, bricksFourCount);
			points = to_string(k);
			Text scoretxt;
			scoretxt.setFont(font);
			scoretxt.setCharacterSize(55);
			scoretxt.setString("Score: " + points);
			scoretxt.setFillColor(colors);
			scoretxt.setPosition(Vector2f(640 - (scoretxt.getGlobalBounds().width / 2), 10));
			window.draw(scoretxt);

			//Won
			if (k == 88880)
			{
				if (game == true && gameover == false && menu == false && won == false)
				{
						won = true;
						game = false;
				}
			}
			window.display();

		}
		else if (gameover == true && game == false && won == false && menu == false && options == false)
		{

			window.clear();
			window.draw(GameOverBackgroundSprite);

			//GameOVER
			Text GameOver;
			GameOver.setFont(font);
			GameOver.setCharacterSize(155);
			GameOver.setString("Gameover!");
			GameOver.setFillColor(colors);
			GameOver.setPosition(Vector2f(640 - (GameOver.getGlobalBounds().width / 2), 20));
			//Your score
			int k = score(bricksOneCount, bricksTwoCount, bricksThreeCount, bricksFourCount);
			string points = to_string(k);

			Text YourScore;
			YourScore.setFont(font);
			YourScore.setCharacterSize(55);
			YourScore.setString("Your score " + points + " points");
			Color colors(85, 158, 199);
			YourScore.setFillColor(colors);
			YourScore.setPosition(Vector2f(640 - (YourScore.getGlobalBounds().width / 2), 210));
			window.draw(YourScore);

			//Play again
			again.setTextureRect(IntRect(284.5, 0, 284.5, 118));
			if (sf::Mouse::getPosition(window).x > again.getGlobalBounds().left && sf::Mouse::getPosition(window).x<(again.getGlobalBounds().left + again.getGlobalBounds().width) && sf::Mouse::getPosition(window).y>again.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (again.getGlobalBounds().top + again.getGlobalBounds().height))
			{
				Cursor.setTextureRect(IntRect(481, 0, 481, 487));
				again.setTextureRect(IntRect(0, 0, 284.5, 118));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Cursor.setTextureRect(IntRect(962, 0, 481, 487));
					game = true;
					gameover = false;
					menu = false;
					won = false;

					srand(time(NULL));
					random = rand() % 2;

					xBallVelocity = abs(xBallVelocity);
					yBallVelocity = abs(yBallVelocity);

					//}
					//Ball first direction setup
					if (random == 1)
					{
						xBallVelocity = xBallVelocity * (-1);
					}
					if (random == 0)
					{
						xBallVelocity = xBallVelocity;
					}

					platformPosition.x = 640 - (platformSizeX / 2);
					platformPosition.y = 600;

					for (int i = 0; i < 8; i++)
					{
						bricksOneCount[i] = 1;
						bricksTwoCount[i] = 1;
						bricksThreeCount[i] = 1;
						bricksFourCount[i] = 1;
					}
					maxscore = Maxscore(bricksOneCount, bricksTwoCount, bricksThreeCount, bricksFourCount);

					ballPosition.y = (580 - ((2 * radiusBall) - 15));
					ballPosition.x = 640 - radiusBall;
				}
			}
			window.draw(again);

			//Menu
			menuLogo.setTextureRect(IntRect(284.5, 0, 284.5, 118));
			if (sf::Mouse::getPosition(window).x > menuLogo.getGlobalBounds().left && sf::Mouse::getPosition(window).x<(menuLogo.getGlobalBounds().left + menuLogo.getGlobalBounds().width) && sf::Mouse::getPosition(window).y>menuLogo.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (menuLogo.getGlobalBounds().top + menuLogo.getGlobalBounds().height))
			{
				Cursor.setTextureRect(IntRect(481, 0, 481, 487));
				menuLogo.setTextureRect(IntRect(0, 0, 284.5, 118));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Cursor.setTextureRect(IntRect(962, 0, 481, 487));
					sf::Mouse::setPosition(sf::Vector2i(sf::Mouse::getPosition().x, window.getPosition().y + 455));
					menu = true;
					gameover = false;
					won = false;
					game = false;
				}
			}
			window.draw(menuLogo);

			//Exit
			window.draw(exit);
			exit.setTextureRect(IntRect(284.5, 0, 284.5, 118));
			if (sf::Mouse::getPosition(window).x > exit.getGlobalBounds().left && sf::Mouse::getPosition(window).x<(exit.getGlobalBounds().left + exit.getGlobalBounds().width) && sf::Mouse::getPosition(window).y>exit.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (exit.getGlobalBounds().top + exit.getGlobalBounds().height))
			{
				Cursor.setTextureRect(IntRect(481, 0, 481, 487));
				exit.setTextureRect(IntRect(0, 0, 284.5, 118));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Cursor.setTextureRect(IntRect(962, 0, 481, 487));
					window.close();
				}
			}

			window.draw(GameOver);
			window.draw(Cursor);
			window.display();
		}
		else if (won == true && gameover == false && menu == false && game == false && options == false)
		{
			window.clear();
			window.draw(GameOverBackgroundSprite);

			//Won
			Text Won;
			Won.setFont(font);
			Won.setCharacterSize(155);
			Won.setString("U won!");
			Won.setFillColor(colors);
			Won.setPosition(Vector2f(640 - (Won.getGlobalBounds().width / 2), 20));
			window.draw(Won);

			//Your score
			int k = score(bricksOneCount, bricksTwoCount, bricksThreeCount, bricksFourCount);
			string points = to_string(k);

			Text YourScore;
			YourScore.setFont(font);
			YourScore.setCharacterSize(55);
			YourScore.setString("Your score " + points + " points");
			Color colors(85, 158, 199);
			YourScore.setFillColor(colors);
			YourScore.setPosition(Vector2f(640 - (YourScore.getGlobalBounds().width / 2), 210));
			window.draw(YourScore);

			//Again
			window.draw(again);
			again.setTextureRect(IntRect(284.5, 0, 284.5, 118));
			if (sf::Mouse::getPosition(window).x > again.getGlobalBounds().left && sf::Mouse::getPosition(window).x<(again.getGlobalBounds().left + again.getGlobalBounds().width) && sf::Mouse::getPosition(window).y>again.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (again.getGlobalBounds().top + again.getGlobalBounds().height))
			{
				Cursor.setTextureRect(IntRect(481, 0, 481, 487));
				again.setTextureRect(IntRect(0, 0, 284.5, 118));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Cursor.setTextureRect(IntRect(962, 0, 481, 487));
					game = true;
					gameover = false;
					menu = false;
					won = false;

					srand(time(NULL));
					random = rand() % 2;

					xBallVelocity = abs(xBallVelocity);
					yBallVelocity = abs(xBallVelocity);

					//Ball first direction setup
					if (random == 1)
					{
						xBallVelocity = xBallVelocity * (-1);
					}
					if (random == 0)
					{
						xBallVelocity = xBallVelocity;
					}

					platformPosition.x = 640 - (platformSizeX / 2);
					platformPosition.y = 600;

					ballPosition.y = (580 - ((2 * radiusBall) - 15));
					ballPosition.x = 640 - radiusBall;

					for (int i = 0; i < 8; i++)
					{
						bricksOneCount[i] = 1;
						bricksTwoCount[i] = 1;
						bricksThreeCount[i] = 1;
						bricksFourCount[i] = 1;
					}
					maxscore = Maxscore(bricksOneCount, bricksTwoCount, bricksThreeCount, bricksFourCount);

				}
			}

			//Menu
			menuLogo.setPosition(sf::Vector2f(640 - (284.5 / 2), 425));
			menuLogo.setTextureRect(IntRect(284.5, 0, 284.5, 118));
			if (sf::Mouse::getPosition(window).x > menuLogo.getGlobalBounds().left && sf::Mouse::getPosition(window).x<(menuLogo.getGlobalBounds().left + menuLogo.getGlobalBounds().width) && sf::Mouse::getPosition(window).y>menuLogo.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (menuLogo.getGlobalBounds().top + menuLogo.getGlobalBounds().height))
			{
				Cursor.setTextureRect(IntRect(481, 0, 481, 487));
				menuLogo.setTextureRect(IntRect(0, 0, 284.5, 118));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Cursor.setTextureRect(IntRect(962, 0, 481, 487));
					sf::Mouse::setPosition(sf::Vector2i(sf::Mouse::getPosition().x, window.getPosition().y + 455));
					menu = true;
					gameover = false;
					won = false;
					game = false;
				}
			}

			//Exit
			window.draw(exit);
			exit.setTextureRect(IntRect(284.5, 0, 284.5, 118));
			if (sf::Mouse::getPosition(window).x > exit.getGlobalBounds().left && sf::Mouse::getPosition(window).x<(exit.getGlobalBounds().left + exit.getGlobalBounds().width) && sf::Mouse::getPosition(window).y>exit.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (exit.getGlobalBounds().top + exit.getGlobalBounds().height))
			{
				Cursor.setTextureRect(IntRect(481, 0, 481, 487));
				exit.setTextureRect(IntRect(0, 0, 284.5, 118));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Cursor.setTextureRect(IntRect(962, 0, 481, 487));
					window.close();
				}
			}

			window.draw(menuLogo);
			window.draw(Cursor);
			window.display();
		}
		else if (menu == true && gameover == false && won == false && game == false && options == false)
		{
			window.clear();
			window.draw(GameOverBackgroundSprite);
			window.draw(breakout);

			//Play
			window.draw(play);
			play.setTextureRect(IntRect(284.5, 0, 284.5, 118));
			if (sf::Mouse::getPosition(window).x > play.getGlobalBounds().left && sf::Mouse::getPosition(window).x<(play.getGlobalBounds().left + play.getGlobalBounds().width) && sf::Mouse::getPosition(window).y>play.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (play.getGlobalBounds().top + play.getGlobalBounds().height))
			{
				Cursor.setTextureRect(IntRect(481, 0, 481, 487));
				play.setTextureRect(IntRect(0, 0, 284.5, 118));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Cursor.setTextureRect(IntRect(962, 0, 481, 487));
					game = true;
					menu = false;
					gameover = false;
					won = false;


					srand(time(NULL));
					random = rand() % 2;

					xBallVelocity = abs(xBallVelocity);
					yBallVelocity = abs(xBallVelocity);

					//Ball first direction setup
					if (random == 1)
					{
						xBallVelocity = xBallVelocity * (-1);
					}
					if (random == 0)
					{
						xBallVelocity = xBallVelocity;
					}

					platformPosition.x = 640 - (platformSizeX / 2);
					platformPosition.y = 600;
					
					ballPosition.y = (580 - ((2 * radiusBall) - 15));
					ballPosition.x = 640 - radiusBall;

					for (int i = 0; i < 8; i++)
					{
						bricksOneCount[i] = 1;
						bricksTwoCount[i] = 1;
						bricksThreeCount[i] = 1;
						bricksFourCount[i] = 1;
					}
					maxscore = Maxscore(bricksOneCount, bricksTwoCount, bricksThreeCount, bricksFourCount);
				}
			}

			//Options
			window.draw(optionsLogo);
			optionsLogo.setTextureRect(IntRect(284.5, 0, 284.5, 118));
			if (sf::Mouse::getPosition(window).x > optionsLogo.getGlobalBounds().left && sf::Mouse::getPosition(window).x<(optionsLogo.getGlobalBounds().left + optionsLogo.getGlobalBounds().width) && sf::Mouse::getPosition(window).y>optionsLogo.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (optionsLogo.getGlobalBounds().top + optionsLogo.getGlobalBounds().height))
			{
				Cursor.setTextureRect(IntRect(481, 0, 481, 487));
				optionsLogo.setTextureRect(IntRect(0, 0, 284.5, 118));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Cursor.setTextureRect(IntRect(962, 0, 481, 487));

					options = true;
					menu = false;
					game = false;
					gameover = false;
					won = false;
					menu = false;
				}
			}

			//Exit
			window.draw(exit);
			exit.setTextureRect(IntRect(284.5, 0, 284.5, 118));
			if (sf::Mouse::getPosition(window).x > exit.getGlobalBounds().left && sf::Mouse::getPosition(window).x<(exit.getGlobalBounds().left + exit.getGlobalBounds().width) && sf::Mouse::getPosition(window).y>exit.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (exit.getGlobalBounds().top + exit.getGlobalBounds().height))
			{
				Cursor.setTextureRect(IntRect(481, 0, 481, 487));
				exit.setTextureRect(IntRect(0, 0, 284.5, 118));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Cursor.setTextureRect(IntRect(962, 0, 481, 487));
					window.close();
				}
			}
			window.draw(Cursor);
			window.display();
		}
	}
}