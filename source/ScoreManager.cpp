#include "ScoreManager.h"

ScoreManager::ScoreManager(int startingScore)
{
	score = startingScore;
}

ScoreManager* ScoreManager::GetInstance()
{
	if (instance == nullptr)
		instance = new ScoreManager(0);
	return instance;
}

int ScoreManager::GetScore()
{
	return score;
}

void ScoreManager::AddScore(int score)
{
	this->score += score;
}