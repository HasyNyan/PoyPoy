#include "MasterDataRepository.h"

namespace Game01 {
void MasterData::RoadMasterData()
{
    std::ifstream file("data.csv");    // 読み込むCSVファイル名
    std::string   line;

    if(!file.is_open()) {    //ファイルが開けたかを確認
        std::cerr << "ファイルを開けませんでした。" << std::endl;
    }

    while(std::getline(file, line)) {    //1行ずつ読み込む
        std::stringstream ss(line);
        std::string       cell;

        while(std::getline(ss, cell, ',')) {
            std::cout << "セルの内容: " << cell << std::endl;
        }
    }

    file.close();
}
}    // namespace Game01
