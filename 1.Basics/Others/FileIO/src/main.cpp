#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct ImageData {
    int magicNum;
    int numItems;
    int numImgs;
    int numRows;
    int numCols;
    std::string file;
};

struct DataSet {
    ImageData labels;
    ImageData images;
};

struct Config {
    std::string name;
    std::string root;
    DataSet train;
    DataSet test;
};

Config parseConfig(const std::string& filename) {
    Config config;
    std::ifstream file(filename);
    std::string line;
    DataSet* currentSet = nullptr; // Pointer to switch between train and test sets

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string key;
        ss >> key;

        if (key == "name:") {
            ss >> config.name;
        } else if (key == "root:") {
            ss >> config.root;
        } else if (line.find("train:") != std::string::npos) {
            currentSet = &config.train;
        } else if (line.find("test:") != std::string::npos) {
            currentSet = &config.test;
        } else if (currentSet) {
            if (line.find("labels:") != std::string::npos) {
                // Parse labels block
                std::getline(file, line); ss = std::istringstream(line); ss >> key >> currentSet->labels.magicNum;
                std::getline(file, line); ss = std::istringstream(line); ss >> key >> currentSet->labels.numItems;
                std::getline(file, line); ss = std::istringstream(line); ss >> key >> currentSet->labels.file;
            } else if (line.find("images:") != std::string::npos) {
                // Parse images block
                std::getline(file, line); ss = std::istringstream(line); ss >> key >> currentSet->images.magicNum;
                std::getline(file, line); ss = std::istringstream(line); ss >> key >> currentSet->images.numImgs;
                std::getline(file, line); ss = std::istringstream(line); ss >> key >> currentSet->images.numRows;
                std::getline(file, line); ss = std::istringstream(line); ss >> key >> currentSet->images.numCols;
                std::getline(file, line); ss = std::istringstream(line); ss >> key >> currentSet->images.file;
            }
        }
    }

    return config;
}

int main() {
    Config config = parseConfig("./config/MNIST.yaml");

    std::cout << "Name: " << config.name << std::endl;
    std::cout << config.train.images.magicNum << std::endl;
    // Add other print statements as needed to display the parsed data

    return 0;
}
