#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include<random>
#include<ctime>
#include <cstdlib>

using namespace std;
using namespace sf;

float score(int bricksUnoCount[], int bricksDosCount[], int bricksTresCount[], int bricksCuatroCount[]);
int Maxscore(int bricksUnoCount[], int bricksDosCount[], int bricksTresCount[], int bricksCuatroCount[]);
void Bricks(int bricksOneCount[], int bricksTwoCount[], int bricksThreeCount[], int bricksFourCount[], sf::Vector2f &ballPosition, float& xBallVelocity, float &yBallVelocity, sf::Sound &sound, sf::RenderWindow &window, float &radiusBall);