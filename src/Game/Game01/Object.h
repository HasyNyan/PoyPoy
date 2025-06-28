#pragma once
#include <System/Scene.h>
namespace Game01 {
USING_PTR(Stone);
//! @brief チュートリアルシーン
class Stone : public Object
{
public:
    BP_OBJECT_DECL(Stone, u8"Game01 の Stone");
    //物体の初期化処理
    //初期化処理が行われたかどうか
    bool Init() override;
    //物体の描画処理
    void Draw() override;

private:
    // 必要であれば変数をここに追加する
};
}    // namespace Game01
