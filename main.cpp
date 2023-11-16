#include <iostream>
#include <fstream>
#include <cstdint>

// Define the video properties
const int width = 200;
const int height = 200;
const int framesPerSecond = 30;
const int duration = 30; // seconds
const int totalFrames = framesPerSecond * duration;

// Function to write the video file
void writeVideo() {
    std::ofstream videoFile("output.mp4", std::ios::out | std::ios::binary);

    if (!videoFile.is_open()) {
        std::cerr << "Error opening video file." << std::endl;
        return;
    }

    // Write MP4 file header
    const char mp4Header[] = {'m', 'o', 'o', 'v'};
    videoFile.write(mp4Header, sizeof(mp4Header));

    // Write mandatory MP4 headers
    const char ftypHeader[] = {'f', 't', 'y', 'p'};
    const char moovHeader[] = {'m', 'o', 'o', 'v'};
    const char mvhdHeader[] = {'m', 'v', 'h', 'd'};
    const char trakHeader[] = {'t', 'r', 'a', 'k'};
    const char tkhdHeader[] = {'t', 'k', 'h', 'd'};
    const char mdiaHeader[] = {'m', 'd', 'i', 'a'};
    const char mdhdHeader[] = {'m', 'd', 'h', 'd'};
    const char hdlrHeader[] = {'h', 'd', 'l', 'r'};
    const char minfHeader[] = {'m', 'i', 'n', 'f'};
    const char vmhdHeader[] = {'v', 'm', 'h', 'd'};
    const char dinfHeader[] = {'d', 'i', 'n', 'f'};
    const char drefHeader[] = {'d', 'r', 'e', 'f'};
    const char stblHeader[] = {'s', 't', 'b', 'l'};
    const char stsdHeader[] = {'s', 't', 's', 'd'};
    const char avc1Header[] = {'a', 'v', 'c', '1'};
    const char avcCHeader[] = {'a', 'v', 'c', 'C'};
    const char sttsHeader[] = {'s', 't', 't', 's'};
    const char stscHeader[] = {'s', 't', 's', 'c'};
    const char stszHeader[] = {'s', 't', 's', 'z'};
    const char stcoHeader[] = {'s', 't', 'c', 'o'};

    videoFile.write(ftypHeader, sizeof(ftypHeader));
    videoFile.write(moovHeader, sizeof(moovHeader));
    videoFile.write(mvhdHeader, sizeof(mvhdHeader));
    // ... (Continue writing other headers as needed)

    // Write video data
    for (int frameNumber = 0; frameNumber < totalFrames; ++frameNumber) {
        // Create a new frame
        char frame[width * height * 3]; // 3 channels (RGB) per pixel

        // Change color every second
        int currentSecond = frameNumber / framesPerSecond;
        int colorIndex = currentSecond % 3;

        // Set the color of the frame based on the current second
        char color[] = {0, 0, 0}; // Default black color
        if (colorIndex == 0) {
            color[2] = 255; // Red
        } else if (colorIndex == 1) {
            color[1] = 255; // Green
        } else {
            color[0] = 255; // Blue
        }

        // Fill the frame with the selected color
        for (int i = 0; i < width * height; ++i) {
            frame[i * 3] = color[0];
            frame[i * 3 + 1] = color[1];
            frame[i * 3 + 2] = color[2];
        }

        // Write the frame to the video file
        videoFile.write(frame, sizeof(frame));
    }

    // Close the video file
    videoFile.close();

    std::cout << "Video file created successfully." << std::endl;
}

int main() {
    writeVideo();
    return 0;
}
