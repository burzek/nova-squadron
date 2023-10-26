#ifndef A1AA5383_8C0A_4943_81B8_42AD2381FDA9
#define A1AA5383_8C0A_4943_81B8_42AD2381FDA9

#include <string>
#include <exception>

class GameException : public std::exception {
    private:
        const std::string message;
    public:
        GameException(const std::string& msg) : message(msg) {
        }
        ~GameException() {
        }

        virtual const char* what() const throw () {
        return message.c_str();
   }
};

#endif /* A1AA5383_8C0A_4943_81B8_42AD2381FDA9 */
