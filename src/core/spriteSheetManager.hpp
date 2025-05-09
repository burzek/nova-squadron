#ifndef EEAF5F71_E869_4A04_9BEC_6AB94C7961CD
#define EEAF5F71_E869_4A04_9BEC_6AB94C7961CD

#include <map>
#include <string>
#include <fstream>
#include "spriteSheet.hpp"

class SpriteSheet;
class SpriteSheetManager {
    private:
        std::unique_ptr<std::map<std::string, std::unique_ptr<SpriteSheet>>> spriteSheetCache;

    public:
        SpriteSheetManager();
        ~SpriteSheetManager();
        void initialize();
        void shutdown();


        // const std::unique_ptr<SpriteSheet> getSpriteSheet(const std::string spriteSheetId);

        void loadSpriteSheets(const std::string assetPath);
        void processSpriteSheetLine(const std::string& spriteSheetLine, const int lineNo);

};

#endif /* EEAF5F71_E869_4A04_9BEC_6AB94C7961CD */
