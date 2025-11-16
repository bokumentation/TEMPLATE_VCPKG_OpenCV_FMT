#include <opencv4/opencv2/core/utils/logger.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/videoio.hpp>

#include <fmt/core.h>

int main()
{
    cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_SILENT);
    const int deviceID = 0;

    cv::VideoCapture cap;

    cap.open(deviceID, cv::CAP_ANY);

    if (!cap.isOpened()) {
        fmt::print(stderr, "ERROR: Could not open camera with device ID {}. Check camera connection and driver.\n",
                   deviceID);
        return 1;
    }

    fmt::print("Camera opened successfully (Device ID: {}). Press 'q' to exit.\n", deviceID);

    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

    cv::Mat frame;

    while (true) {
        cap >> frame;

        if (frame.empty()) {
            fmt::print(stderr, "ERROR: Received empty frame. Exiting loop.\n");
            break;
        }


        cv::imshow("Live Video Feed (C++ OpenCV)", frame);

        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    fmt::print("Exiting application.\n");
    cap.release();
    cv::destroyAllWindows();

    return 0;
}