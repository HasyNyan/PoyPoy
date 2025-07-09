#pragma once
#include <System/Scene.h>
namespace Game01 {
USING_PTR(Ufo);
//! @brief チュートリアルシーン
class Ufo : public Object
{
public:
    BP_OBJECT_DECL(Ufo, u8"Game01のUfo");

    //! @brief 初期化
    //! @return 初期化済み
    bool Init() override;
    void Update() override;
    void Draw() override;
    // void Exit() override;
    // void GUI() override;

private:
    // 必要であれば変数をここに追加する
};
}    // namespace Game01

// namespace Game01
