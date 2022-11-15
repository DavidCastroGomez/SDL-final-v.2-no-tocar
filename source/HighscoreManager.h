#pragma once
#include <map>
#include <string>
class HighscoreManager
{
private:
	static HighscoreManager* instance;
	HighscoreManager();

public:
	std::map<int, std::string> scores;
	static HighscoreManager* GetInstance();
	void LoadScores();
	void SaveScores();
	void AddScore(int, std::string);
	std::map<int, std::string> GetScores();


};


