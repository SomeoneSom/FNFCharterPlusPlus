#include <windows.h> //legit just to hide the console window
#include <thread>
#include <chrono>
#include "lib/nana/gui.hpp" //gui
#include "lib/nana/gui/widgets/label.hpp" //gui
void delay_move(HWND hWnd) {
    RECT desktop;
    GetClientRect(GetDesktopWindow(), &desktop);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    MoveWindow(hWnd, (desktop.right/2) - 640, (desktop.bottom/2) - 360, 1280, 720, true);
}
int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE); //hide console window bc its annoying
    nana::form fm;
    fm.caption("FNFCharter++");
    nana::label lb{fm, nana::rectangle{10, 10, 100, 100}};
    lb.caption("hi b*tches");
    fm.show();
    HWND hWnd = FindWindowA(0, "FNFCharter++");
    std::thread resize (delay_move, hWnd);
    nana::exec();
    resize.join();
    return 0;
}