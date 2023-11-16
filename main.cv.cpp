#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Video properties
    int width = 200;
    int height = 200;
    int framesPerSecond = 30;
    int duration = 30; // seconds
    int totalFrames = framesPerSecond * duration;

    // Create a VideoWriter object
    cv::VideoWriter video("output.mp4", cv::VideoWriter::fourcc('m', 'p', '4', 'v'), framesPerSecond, cv::Size(width, height));

    if (!video.isOpened()) {
        std::cerr << "Error opening video file." << std::endl;
        return -1;
    }

    // Create frames and write to the video file
    for (int frameNumber = 0; frameNumber < totalFrames; ++frameNumber) {
        // Create a new frame
        cv::Mat frame(height, width, CV_8UC3, cv::Scalar(0, 0, 0)); // Black background

        // Change color every second
        int currentSecond = frameNumber / framesPerSecond;
        int colorIndex = currentSecond % 3;

        // Set the color of the frame based on the current second
        if (colorIndex == 0) {
            frame.setTo(cv::Scalar(0, 0, 255)); // Red
        } else if (colorIndex == 1) {
            frame.setTo(cv::Scalar(0, 255, 0)); // Green
        } else {
            frame.setTo(cv::Scalar(255, 0, 0)); // Blue
        }

        // Write the frame to the video file
        video.write(frame);

        // Display frame number for verification
        std::cout << "Frame: " << frameNumber + 1 << "/" << totalFrames << std::endl;
    }

    // Release the VideoWriter
    video.release();

    std::cout << "Video file created successfully." << std::endl;

    return 0;
}
