#pragma once
#include <System/Scene.h>

namespace Game01 {
USING_PTR(Camera);
//! @brief チュートリアルシーン
class Camera : public Object
{
public:
    BP_OBJECT_DECL(Camera, u8"Game01 の Camera");

    //! @brief 初期化
    //! @return 初期化済み
    bool Init() override;

    //! @brief 更新
    void Update() override;

private:
    // 必要であれば変数をここに追加する
};
}    // namespace Game01
