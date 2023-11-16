#include <iostream>
#include <fstream>

const int width = 600;
const int height = 800;
const int framesPerSecond = 30;
const int duration = 30;
const int totalFrames = framesPerSecond * duration;

// Function to write an MKV file header
void writeMKVHeader(std::ofstream& mkvFile) {
    // MKV EBML header
    mkvFile << "\x1A\x45\xDF\xA3";

    // EBML version
    mkvFile << "\x42\x86\x81\x01";

    // EBMLMaxIDLength
    mkvFile << "\x42\x86\x82\x04";

    // EBMLMaxSizeLength
    mkvFile << "\x42\x86\x83\x08";

    // DocType
    mkvFile << "\x42\x82\x88\x6D\x61\x74\x72\x6F\x73\x6B\x61";

    // DocTypeVersion
    mkvFile << "\x42\x86\x87\x01";

    // DocTypeReadVersion
    mkvFile << "\x42\x86\x85\x01";
}

// Function to write an MKV video frame
void writeMKVFrame(std::ofstream& mkvFile, int frameNumber) {
    // Frame header
    mkvFile << "\x81\x01";

    // Block header
    mkvFile << "\xA3";

    // Track number
    mkvFile << "\xD7\x81";

    // Block timecode (scaled to milliseconds)
    int64_t timecode = frameNumber * (1000 / framesPerSecond);
    mkvFile.write(reinterpret_cast<char*>(&timecode), sizeof(timecode));

    // SimpleBlock data
    mkvFile << "\x83";

    // Frame data (e.g., RGB values)
    char frame[width * height * 3];
    // Change color every second
    int currentSecond = frameNumber / framesPerSecond;
    int colorIndex = currentSecond % 3;
    char color[] = {0, 0, 0}; // Default black color
    color[colorIndex] = 255; // Set the color of the frame based on the current second
    for (int i = 0; i < width * height; ++i) {
        mkvFile.write(color, sizeof(color));
    }
}

int main() {
    std::ofstream mkvFile("output.mkv", std::ios::out | std::ios::binary);

    if (!mkvFile.is_open()) {
        std::cerr << "Error opening MKV file." << std::endl;
        return -1;
    }

    // Write MKV header
    writeMKVHeader(mkvFile);

    // Write MKV video frames
    for (int frameNumber = 0; frameNumber < totalFrames; ++frameNumber) {
        writeMKVFrame(mkvFile, frameNumber);
    }

    // Close the MKV file
    mkvFile.close();

    std::cout << "MKV file created successfully." << std::endl;

    return 0;
}
