//includes
//to hide console window
#include <windows.h>
//its vector yay
#include <vector>
//i shouldnt need to explain this, its iostream
#include <iostream>
//t i m e
#include <chrono>
//gui crap (nana libs)
#include "lib/nana/gui.hpp"
#include "lib/nana/gui/widgets/label.hpp"
//its the main one
int main() {
    //hide console window and make window with 320x512 size
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    nana::form fm(nana::API::make_center(320, 512));
    //make vector for grid
    std::vector<std::unique_ptr<nana::label>> lbs;
    //some empty labels but they need to be different for some reason
    nana::label voidlb(fm);
    nana::label voidlb2(fm);
    //set bg colors
    voidlb.bgcolor(nana::colors::blue);
    voidlb2.bgcolor(nana::colors::blue);
    //make the layout
    nana::place layout(fm);
    //so, 64 width area, then 128 width evenly spaces 4x16 grid, everything else is the last section
    layout.div("<voidd weight=64><notearea grid=[4, 16] weight=128><void2electricboogaloo>");
    //now we fill that grid with labels using our vector
    for (int i = 0; i < 64; i++) {
        //first create a temp pointer to nana::label object placed on fm
        lbs.emplace_back(new nana::label(fm));
        //set caption and bg color
        lbs.back()->caption("yo");
        lbs.back()->bgcolor(nana::colors::dark_blue);
        //add to the grid
        layout.field("notearea") << *lbs.back();
    }
    //dont need whats in this vector anymore but we cant clear it or else all of our labels dissapear
    //add our blank labels to layout
    layout["voidd"] << voidlb;
    layout["void2electricboogaloo"] << voidlb2;
    //"compile" layout
    layout.collocate();
    //show form
    fm.show();
    //run our program (actually startes event handling but whatever) this ends when our form closes
    nana::exec();
    //we got through it ok so return 0
    return 0;
}