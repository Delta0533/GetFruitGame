#include"Game.h"

using namespace sf;
using namespace std;

int main()
{
    //Init srand
    std::srand(static_cast<unsigned>(time(NULL)));

    //Init Game engine
    Game game;

    while (game.running() && !Keyboard::isKeyPressed(Keyboard::Escape) && !game.getEndGame())
    {
        //update 
        game.update();
        //render
        game.render();

    }

    return 0;
}
