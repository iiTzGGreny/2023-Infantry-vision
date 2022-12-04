#include<thread>
#include "ImageProgress.h"

using namespace std;

int main(void)
{
    ImageProgress main_progress;


    thread produce(&ImageProgress::ImageProducer,&main_progress);




    produce.join();
    return 0;
}
