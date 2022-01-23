#include "Main.h"
void Bricks(int bricksOneCount[], int bricksTwoCount[], int bricksThreeCount[], int bricksFourCount[], sf::Vector2f &ballPosition, float &yBallVelocity, float& xBallVelocity, sf::Sound &sound, sf::RenderWindow &window, float& radiusBall)
{
	//Bricks One
	int i = 120, l = 0;
	sf::RectangleShape bricks_One[8];
	for (int l = 0; l < 8; l++)
	{

		bricks_One[l].setSize(sf::Vector2f(120, 50));
		sf::Vector2f rectPossition(i, 95);
		rectPossition.x += 5;
		bricks_One[l].setPosition(rectPossition);

		sf::Texture blockTexture;
		blockTexture.loadFromFile("IMG/blocks.png");
		bricks_One[l].setTexture(&blockTexture);
		bricks_One[l].setTextureRect(IntRect(0, 0, 120, 50));
		if (bricksOneCount[l] == 1)
		{
			if (rectPossition.y <= ballPosition.y && rectPossition.y + 50 >= ballPosition.y || rectPossition.y <= ballPosition.y +2*radiusBall && rectPossition.y + 50 >= ballPosition.y +2*radiusBall)
			{
				if (rectPossition.x <= ballPosition.x && rectPossition.x + 120 >= ballPosition.x || rectPossition.x <= ballPosition.x +2*radiusBall && rectPossition.x + 120 >= ballPosition.x +2*radiusBall)
				{
					yBallVelocity *= -1;
					sound.play();
					bricksOneCount[l] = 0;
				}
			}
		}
		else if (bricksOneCount[l] == 0)
		{
			bricks_One[l].setTextureRect(IntRect(0, 50, 120, 50));
			if (rectPossition.y <= ballPosition.y && rectPossition.y + 50 >= ballPosition.y || rectPossition.y <= ballPosition.y +2*radiusBall && rectPossition.y + 50 >= ballPosition.y +2*radiusBall)
			{
				if (rectPossition.x <= ballPosition.x && rectPossition.x + 120 >= ballPosition.x || rectPossition.x <= ballPosition.x +2*radiusBall && rectPossition.x + 120 >= ballPosition.x +2*radiusBall)
				{
					yBallVelocity *= -1;
					sound.play();
					bricksOneCount[l] = -1;
				}
			}
		}

		if (bricksOneCount[l] == 0 || bricksOneCount[l] == 1)
		{
			window.draw(bricks_One[l]);
		}
		i += 130;
	}

	////Bricks Two
	i = 120;
	l = 0;
	sf::RectangleShape bricks_Two[8];
	for (int l = 0; l < 8; l++)
	{

		bricks_Two[l].setSize(sf::Vector2f(120, 50));
		sf::Vector2f rectPossition(i, 165);
		bricks_Two[l].setPosition(rectPossition);

		sf::Texture blockTexture;
		blockTexture.loadFromFile("IMG/blocks.png");
		bricks_Two[l].setTexture(&blockTexture);
		bricks_Two[l].setTextureRect(IntRect(120, 0, 120, 50));
		if (bricksTwoCount[l] == 1)
		{
			if (rectPossition.y <= ballPosition.y && rectPossition.y + 50 >= ballPosition.y || rectPossition.y <= ballPosition.y +2*radiusBall && rectPossition.y + 50 >= ballPosition.y +2*radiusBall)
			{
				if (rectPossition.x <= ballPosition.x && rectPossition.x + 120 >= ballPosition.x || rectPossition.x <= ballPosition.x +2*radiusBall && rectPossition.x + 120 >= ballPosition.x +2*radiusBall)
				{
					yBallVelocity *= -1;
					sound.play();
					bricksTwoCount[l] = 0;
				}
			}
		}
		else if (bricksTwoCount[l] == 0)
		{
			bricks_Two[l].setTextureRect(IntRect(120, 50, 120, 50));
			if (rectPossition.y <= ballPosition.y && rectPossition.y + 50 >= ballPosition.y || rectPossition.y <= ballPosition.y +2*radiusBall && rectPossition.y + 50 >= ballPosition.y +2*radiusBall)
			{
				if (rectPossition.x <= ballPosition.x && rectPossition.x + 120 >= ballPosition.x || rectPossition.x <= ballPosition.x +2*radiusBall && rectPossition.x + 120 >= ballPosition.x +2*radiusBall)
				{
					yBallVelocity *= -1;
					sound.play();
					bricksTwoCount[l] = -1;
				}
			}
		}

		if (bricksTwoCount[l] == 0 || bricksTwoCount[l] == 1)
		{
			window.draw(bricks_Two[l]);
		}

		i += 130;
	}
	//Bricks Three
	i = 120;
	l = 0;

	sf::RectangleShape bricks_Three[8];
	for (int l = 0; l < 8; l++)
	{

		bricks_Three[l].setSize(sf::Vector2f(120, 50));
		sf::Vector2f rectPossition(i, 235);
		bricks_Three[l].setPosition(rectPossition);

		sf::Texture blockTexture;
		blockTexture.loadFromFile("IMG/blocks.png");
		bricks_Three[l].setTexture(&blockTexture);
		bricks_Three[l].setTextureRect(IntRect(240, 0, 120, 50));
		if (bricksThreeCount[l] == 1)
		{
			if (rectPossition.y <= ballPosition.y && rectPossition.y + 50 >= ballPosition.y || rectPossition.y <= ballPosition.y +2*radiusBall && rectPossition.y + 50 >= ballPosition.y +2*radiusBall)
			{
				if (rectPossition.x <= ballPosition.x && rectPossition.x + 120 >= ballPosition.x || rectPossition.x <= ballPosition.x +2*radiusBall && rectPossition.x + 120 >= ballPosition.x +2*radiusBall)
				{
					yBallVelocity *= -1;
					sound.play();
					bricksThreeCount[l] = 0;
				}
			}
		}
		else if (bricksThreeCount[l] == 0)
		{
			bricks_Three[l].setTextureRect(IntRect(240, 50, 120, 50));
			if (rectPossition.y <= ballPosition.y && rectPossition.y + 50 >= ballPosition.y || rectPossition.y <= ballPosition.y +2*radiusBall && rectPossition.y + 50 >= ballPosition.y +2*radiusBall)
			{
				if (rectPossition.x <= ballPosition.x && rectPossition.x + 120 >= ballPosition.x || rectPossition.x <= ballPosition.x +2*radiusBall && rectPossition.x + 120 >= ballPosition.x +2*radiusBall)
				{
					yBallVelocity *= -1;
					sound.play();
					bricksThreeCount[l] = -1;
				}
			}
		}

		if (bricksThreeCount[l] == 0 || bricksThreeCount[l] == 1)
		{
			window.draw(bricks_Three[l]);
		}

		i += 130;
	}

	//Bricks Four
	i = 120;
	l = 0;

	sf::RectangleShape bricks_Four[8];
	for (int l = 0; l < 8; l++)
	{

		bricks_Four[l].setSize(sf::Vector2f(120, 50));
		sf::Vector2f rectPossition(i, 305);
		bricks_Four[l].setPosition(rectPossition);

		sf::Texture blockTexture;
		blockTexture.loadFromFile("IMG/blocks.png");
		bricks_Four[l].setTexture(&blockTexture);
		bricks_Four[l].setTextureRect(IntRect(360, 0, 120, 50));
		if (bricksFourCount[l] == 1)
		{
			if (rectPossition.y <= ballPosition.y && rectPossition.y + 50 >= ballPosition.y || rectPossition.y <= ballPosition.y +2*radiusBall && rectPossition.y + 50 >= ballPosition.y +2*radiusBall)
			{
				if (rectPossition.x <= ballPosition.x && rectPossition.x + 120 >= ballPosition.x || rectPossition.x <= ballPosition.x +2*radiusBall && rectPossition.x + 120 >= ballPosition.x +2*radiusBall)
				{	
					yBallVelocity *= -1;
					sound.play();
					bricksFourCount[l] = 0;
				}
			}
		}
		else if (bricksFourCount[l] == 0)
		{
			bricks_Four[l].setTextureRect(IntRect(360, 50, 120, 50));
			if (rectPossition.y <= ballPosition.y && rectPossition.y + 50 >= ballPosition.y || rectPossition.y <= ballPosition.y +2*radiusBall && rectPossition.y + 50 >= ballPosition.y +2*radiusBall)
			{
				if (rectPossition.x <= ballPosition.x && rectPossition.x + 120 >= ballPosition.x || rectPossition.x <= ballPosition.x +2*radiusBall && rectPossition.x + 120 >= ballPosition.x +2*radiusBall)
				{
					yBallVelocity *= -1;
					sound.play();
					bricksFourCount[l] = -1;
				}
			}
		}

		if (bricksFourCount[l] == 0 || bricksFourCount[l] == 1)
		{
			window.draw(bricks_Four[l]);
		}

		i += 130;
	}
}