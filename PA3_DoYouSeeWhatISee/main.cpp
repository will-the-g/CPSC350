#include "SpeakerView.h"
#include <string>

int main(int argc, char** argv){
    string input = argv[1];
    string output = argv[2];
    SpeakerView* speaker = new SpeakerView(input);
    speaker->computeOutput(input, output);
    delete speaker;


    return 0;
}