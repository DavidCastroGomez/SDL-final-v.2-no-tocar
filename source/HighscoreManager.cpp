#include "HighscoreManager.h"

HighscoreManager* HighscoreManager::instance = nullptr;

HighscoreManager::HighscoreManager() {
    
}

HighscoreManager* HighscoreManager::GetInstance()
{
    if (instance == nullptr) {
        instance = new HighscoreManager();
    }
    
    return instance;
}

void HighscoreManager::LoadScores()
{
    //TODO file system that loads scores in a file
}

void HighscoreManager::SaveScores()
{
    //TODO file system that saves scores to a file
}

void HighscoreManager::AddScore(int score, std::string name)
{
    scores.emplace(score, name);
}

std::map<int, std::string> HighscoreManager::GetScores()
{
    return scores;
}
