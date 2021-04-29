#include <windows.h> //legit just to hide the console window
#include "lib/nana/gui.hpp" //gui
#include "lib/nana/gui/widgets/label.hpp" //gui
int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE); //hide console window bc its annoying
    nana::form fm;
    fm.caption("BetterFNFCharter");
    nana::label lb{fm, nana::rectangle{10, 10, 100, 100}};
    lb.caption("hi b*tches");
    fm.show();
    nana::exec();
    return 0;
}