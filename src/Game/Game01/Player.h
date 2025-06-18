#pragma once
#include <System/Scene.h>
namespace Game01 {
USING_PTR(Player);
//! @brief チュートリアルシーン
class Player : public Object
{
public:
    BP_OBJECT_DECL(Player, u8"Game01 の Player");

    //! @brief 初期化
    //! @return 初期化済み
    bool Init() override;

    //! @brief 更新
    void Update() override;

private:
    // 必要であれば変数をここに追加する
};
}    // namespace Game01
