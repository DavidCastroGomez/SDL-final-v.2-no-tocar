#pragma once

#define PM ScoreManager::GetInstance()

class ScoreManager
{
public:

	int GetScore();
	void AddScore(int score);
	static ScoreManager* GetInstance();
private:
	static ScoreManager* instance;
	int score;
	ScoreManager(int startingScore);
};