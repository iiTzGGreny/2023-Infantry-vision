#ifndef IMAGEPROGRESS_H
#define IMAGEPROGRESS_H

#include <thread>
#include <opencv2/opencv.hpp>
#include <mutex>
#include <chrono>
#include "Const.h"

using namespace cv;

#define GYRO_BUFFER_NUM     15
#define FRAME_BUFFER_NUM    6

class ImageProgress
{
private:
    /*--thread control param--*/
    Mutex frame_mutex;

    /*---规则参数---*/
    uint16_t _bullet_speed = 15;    // 收到的弹速
    COLOR _enemy_color;             // 敌方颜色
    Mode _mode = Mode::NORMAL;      // 模式 1：常规， 2：大符，3：小符

    /*---共享资源池---*/
    Mat cap_frame;    // 缓存图片
    std::queue<Mat> frame_buffer;

public:
    /**
     *  @brief  从相机读取图片
     */
    void ImageProducer();
    /**
     *  @brief  图片处理
     */
    void ImageConsumer();
};


#endif // IMAGEPROGRESS_H
