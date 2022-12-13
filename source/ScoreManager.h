#pragma once
class ScoreManager
{
public:
	int GetScore();
	void AddScore(int score);
private:
	static ScoreManager* instance;
	ScoreManager();
	int score;
};