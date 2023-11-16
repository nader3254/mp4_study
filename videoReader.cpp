// // #include <iostream>
// // #include <fstream>
// // #include <cstdint>

// // // Function to print the box type
// // void printBoxType(const char boxType[4]) {
// //     std::cout << "Box Type: " << boxType[0] << boxType[1] << boxType[2] << boxType[3] << std::endl;
// // }

// // // Function to read and print the header of an MP4 file
// // void readMP4Header(const std::string& filename) {
// //     std::ifstream mp4File(filename, std::ios::in | std::ios::binary);

// //     if (!mp4File.is_open()) {
// //         std::cerr << "Error opening MP4 file: " << filename << std::endl;
// //         return;
// //     }

// //     char fileType[4];
// //     mp4File.read(fileType, sizeof(fileType));
// //     std::cout<<fileType[0]<<std::endl;


// //     if (fileType[0] == 'f' && fileType[1] == 't' && fileType[2] == 'y' && fileType[3] == 'p') {
// //         std::cout << "File Type: MP4" << std::endl;
// //     } else {
// //         std::cerr << "Invalid MP4 file." << std::endl;
// //         mp4File.close();
// //         return;
// //     }

// //     while (!mp4File.eof()) {
// //         char boxSizeBuffer[4];
// //         mp4File.read(boxSizeBuffer, sizeof(boxSizeBuffer));

// //         uint32_t boxSize = (static_cast<uint32_t>(boxSizeBuffer[0]) << 24) |
// //                            (static_cast<uint32_t>(boxSizeBuffer[1]) << 16) |
// //                            (static_cast<uint32_t>(boxSizeBuffer[2]) << 8) |
// //                            static_cast<uint32_t>(boxSizeBuffer[3]);

// //         char boxType[4];
// //         mp4File.read(boxType, sizeof(boxType));

// //         // Print information about the box
// //         printBoxType(boxType);
// //         std::cout << "Box Size: " << boxSize << " bytes" << std::endl;

// //         // Move to the next box
// //         mp4File.seekg(boxSize - 8, std::ios::cur);
// //     }

// //     mp4File.close();
// // }

// // int main() {
// //     // Specify the path to your MP4 file
// //     std::string filename = "/home/nader/Desktop/esp8266/test.mp4";

// //     // Read and print the MP4 file header
// //     readMP4Header(filename);

// //     return 0;
// // }


// // #include <iostream>
// // #include <fstream>
// // #include <vector>

// // using namespace std;

// // int main() {
// //   // Specify the input video file
// //   const string inputVideoFile = "/home/nader/Desktop/esp8266/test.mp4";

// //   // Specify the output file to store the video bytes
// //   const string outputFile = "video_bytes.txt";

// //   // Open the input video file
// //   ifstream inputVideoStream(inputVideoFile, ios::binary);
// //   if (!inputVideoStream.is_open()) {
// //     cout << "Failed to open input video file: " << inputVideoFile << endl;
// //     return 1;
// //   }

// //   // Open the output file
// //   ofstream outputFileStream(outputFile);
// //   if (!outputFileStream.is_open()) {
// //     cout << "Failed to open output file: " << outputFile << endl;
// //     inputVideoStream.close();
// //     return 1;
// //   }

// //   // Read the video bytes and save them to the output file
// //   char byte;
// //   while (inputVideoStream.read(&byte, 1)) {
// //     outputFileStream << byte;
// //   }

// //   // Close the files
// //   inputVideoStream.close();
// //   outputFileStream.close();

// //   cout << "Video bytes successfully saved to file: " << outputFile << endl;

// //   return 0;
// // }


// // #include <iostream>
// // #include <fstream>
// // #include <vector>
// // #include <sstream>

// // using namespace std;

// // int main() {
// //   // Specify the input video file
// //   const string inputVideoFile = "test.mp4";

// //   // Specify the output file to store the converted video bytes
// //   const string outputFile = "video_bytes_string.txt";

// //   // Open the input video file
// //   ifstream inputVideoStream(inputVideoFile, ios::binary);
// //   if (!inputVideoStream.is_open()) {
// //     cout << "Failed to open input video file: " << inputVideoFile << endl;
// //     return 1;
// //   }

// //   // Open the output file
// //   ofstream outputFileStream(outputFile);
// //   if (!outputFileStream.is_open()) {
// //     cout << "Failed to open output file: " << outputFile << endl;
// //     inputVideoStream.close();
// //     return 1;
// //   }

// //   // Read the video bytes and convert them to strings before saving
// //   char byte;
// //   while (inputVideoStream.read(&byte, 1)) {
// //     stringstream ss;
// //     ss << byte;
// //     outputFileStream << ss.str();
// //   }

// //   // Close the files
// //   inputVideoStream.close();
// //   outputFileStream.close();

// //   cout << "Video bytes successfully converted to string and saved to file: " << outputFile << endl;

// //   return 0;
// // }



// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>

// using namespace std;

// const string VIDEO_FRAME_MARKER = "VIDEO FRAME";
// const string SOUND_FRAME_MARKER = "SOUND FRAME";

// int main() {
//   // Specify the input video file
//   const string inputVideoFile = "test.mp4";

//   // Open the input video file in binary mode
//   ifstream inputVideoStream(inputVideoFile, ios::binary);
//   if (!inputVideoStream.is_open()) {
//     cout << "Failed to open input video file: " << inputVideoFile << endl;
//     return 1;
//   }

//   // Read the video data byte by byte
//   char byte;
//   bool isVideoFrame = false;
//   bool isSoundFrame = false;
//   string currentFrameContent = "";

//   while (inputVideoStream.read(&byte, 1)) {
//     // Check if the current byte is the start of a video frame marker
//     if (byte == VIDEO_FRAME_MARKER[0]) {
//       if (currentFrameContent == SOUND_FRAME_MARKER) {
//         // Replace sound frame content with the marker string
//         currentFrameContent = SOUND_FRAME_MARKER;
//       }

//       isVideoFrame = true;
//       currentFrameContent = "";
//     }

//     // Check if the current byte is the start of a sound frame marker
//     if (byte == SOUND_FRAME_MARKER[0]) {
//       if (currentFrameContent == VIDEO_FRAME_MARKER) {
//         // Replace video frame content with the marker string
//         currentFrameContent = VIDEO_FRAME_MARKER;
//       }

//       isSoundFrame = true;
//       currentFrameContent = "";
//     }

//     // Append the current byte to the frame content
//     if (isVideoFrame || isSoundFrame) {
//       currentFrameContent += byte;
//     }

//     // Check if the current byte is the end of a frame marker
//     if (byte == VIDEO_FRAME_MARKER[VIDEO_FRAME_MARKER.length() - 1]) {
//       if (isVideoFrame) {
//         // Replace video frame content with the marker string
//         currentFrameContent = VIDEO_FRAME_MARKER;
//         cout << currentFrameContent << endl;
//       }

//       isVideoFrame = false;
//     }

//     if (byte == SOUND_FRAME_MARKER[SOUND_FRAME_MARKER.length() - 1]) {
//       if (isSoundFrame) {
//         // Replace sound frame content with the marker string
//         currentFrameContent = SOUND_FRAME_MARKER;
//         cout << currentFrameContent << endl;
//       }

//       isSoundFrame = false;
//     }
//   }

//   // Close the input video file
//   inputVideoStream.close();

//   return 0;
// }


#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

int main() {
  std::ifstream mp4File("test.mp4", std::ios::binary);
  if (!mp4File.is_open()) {
    std::cerr << "Error opening MP4 file" << std::endl;
    return 1;
  }

  // Read the size of the ftyp atom
  uint32_t size;
  mp4File.read((char*)&size, sizeof(size));

  // Check if the size is valid
  if (size < 16) {
    std::cerr << "Invalid ftyp atom size" << std::endl;
    mp4File.close();
    return 1;
  }

  // Read the FourCC identifier of the atom
  char fourCC[4];
  mp4File.read(fourCC, 4);

  // Verify that the FourCC is indeed "ftyp"
  if (std::memcmp(fourCC, "ftyp", 4) != 0) {
    std::cerr << "Invalid ftyp atom FourCC" << std::endl;
    mp4File.close();
    return 1;
  }
// if (std::memcmp(fourCC, "ftyp", sizeof(fourCC)) != 0) {
//   std::cerr << "Invalid ftyp atom FourCC" << std::endl;
//   mp4File.close();
//   return 1;
// }

  // Read the major brand
  char majorBrand[4];
  mp4File.read(majorBrand, 4);

  // Read the minor brand
  char minorBrand[4];
  mp4File.read(minorBrand, 4);

  // Read the list of compatible brands (if any)
  std::vector<std::string> compatibleBrands;
  while (size > 0) {
    char brand[4];
    mp4File.read(brand, 4);
    compatibleBrands.push_back(std::string(brand));
    size -= 4;
  }

  // Print the ftyp atom information
  std::cout << "Major brand: " << majorBrand << std::endl;
  std::cout << "Minor brand: " << minorBrand << std::endl;
  std::cout << "Compatible brands: ";
  for (const std::string& brand : compatibleBrands) {
    std::cout << brand << " ";
  }
  std::cout << std::endl;

  mp4File.close();

  return 0;
}