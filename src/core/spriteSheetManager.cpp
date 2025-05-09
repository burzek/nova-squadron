#include "spriteSheetManager.hpp"
#include <iostream>
#include <filesystem>

SpriteSheetManager::SpriteSheetManager() {
}



SpriteSheetManager::~SpriteSheetManager() {
    
}

void SpriteSheetManager::initialize() {
    this->spriteSheetCache = std::make_unique<std::map<std::string, std::unique_ptr<SpriteSheet>>>();
    this->spriteSheetCache->clear();
    loadSpriteSheets("assets/sprites.dat");
}

void SpriteSheetManager::shutdown() {
    // if (this->spriteSheetCache) {
    //     auto &mapRef = *(this->spriteSheetCache);
    //     for (const auto &keyVal : mapRef) {
    //         if (keyVal.second) {
    //             keyVal.second->destroy();
    //         }
    //     }
    // }
}


// const std::unique_ptr<SpriteSheet> SpriteSheetManager::getSpriteSheet(const std::string spriteSheetId){
//     return nullptr;
// }

void SpriteSheetManager::loadSpriteSheets(const std::string assetPath) {
    spdlog::debug("Loading sprite sheets from {}", assetPath);
    //load info file
    std::fstream fs;
    fs.open("assets/sprites.dat", std::ios::in);
    if (!fs.is_open()) {
        spdlog::error("Cannot open sprites.dat file");
        std::exit(EXIT_FAILURE);
    }

    int lineNo = 1;
    std::string line;
    while (std::getline(fs, line)) {
        if (line.empty() || line[0] == '#') {
            continue; 
        }
        
       this->processSpriteSheetLine(line, lineNo);
       lineNo++;
    }
}


void SpriteSheetManager::processSpriteSheetLine(const std::string& spriteSheetLine, const int lineNo) {
    spdlog::info("Processing sprite sheet line :{}", spriteSheetLine);

    std::vector<std::string> tokens;
    std::stringstream ss(spriteSheetLine);
    std::string token;

    while (std::getline(ss, token, ',')) {
        tokens.push_back(token);
    }
    if (tokens.size() < 3) {
        spdlog::error("Invalid sprite definition in line {}: {}", lineNo, spriteSheetLine);
        std::exit(EXIT_FAILURE);
    }
    std::string spriteSheetId = tokens[0];
    std::string spriteSheetPath = tokens[1];
    int spriteCount = std::stoi(tokens[2]);
    if (tokens.size() != spriteCount + 3) {
        spdlog::error("Invalid sprite definition in line {}: {}", lineNo, spriteSheetLine);
        std::exit(EXIT_FAILURE);
    }
    std::vector<int> spriteDivPosition;
    for (int i = 3; i < tokens.size(); ++i) {
        spriteDivPosition.push_back(std::stoi(tokens[i]));
    }

    this->spriteSheetCache->emplace(spriteSheetId, std::make_unique<SpriteSheet>(spriteSheetId, spriteSheetPath, spriteCount, spriteDivPosition));
}


