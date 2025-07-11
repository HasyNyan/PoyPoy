#pragma once
#include <System/Scene.h>
namespace Game01 {
USING_PTR(Wood);
//! @brief チュートリアルシーン
class Wood : public Object
{
public:
    BP_OBJECT_DECL(Wood, u8"Game01 の Wood");

    //物体の初期化処理
    //初期化処理が行われたかどうか
    bool Init() override;
    //Update
    void Update() override;
    //物体の描画処理
    void Draw() override;

    void SetDirection(const float3& dir) { direction_ = dir; }
    void SetIsFlying(bool flying) { isFlying_ = flying; }

private:
    // 必要であれば変数をここに追加する
    float3 direction_ = {};
    float  speed_     = 0.2f;
    bool   isFlying_  = false;
    void   OnHit(const ComponentCollision::HitInfo& hit_info) override;
};
}    // namespace Game01
