#pragma once
#include <System/Scene.h>
namespace Game01 {
//! @brief チュートリアルシーン
class PlayerUI : public Scene::Base
{
public:
    BP_CLASS_DECL(PlayerUI, u8"Game01 の PlayerUI");

    //! @brief 初期化
    //! @return 初期化済み
    bool Init() override;
    void Update() override;
    void Draw() override;
    void Exit() override;
    void GUI() override;

private:
    // 必要であれば変数をここに追加する
};
}    // namespace Game01

// namespace Game01
