#include "ImageProgress.h"

using namespace std;

void ImageProgress::ImageProducer()
{
    while(true)
    {
        Mat frame=cv::imread("/home/greny/picture/2.png");   //从路径中读取图片


        if(frame.empty())
        {
            cout<<"empty frame"<<endl;
        }

        frame_mutex.lock();//锁定当前进程
        frame_buffer.push(frame); //将图载入缓冲池内

        while(frame_buffer.size()>FRAME_BUFFER_NUM)
        {
            frame_buffer.pop();
        }
        frame_mutex.unlock();

        this_thread::sleep_for(chrono::milliseconds(1));
    }
}




void ImageProgress::ImageConsumer()
{

}
