#include "RoketObject.h";
#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCollisionCapsule.h>
namespace Game01 {
bool Roket::Init()
{
    __super::Init();

    SetName(u8"ロケット");
    SetTranslate({20.0f, 10.0f, 20.0f});
    //Collision
    AddComponent<ComponentCollisionCapsule>()->SetRadius(2.0f)->SetHeight(14.0f)->UseGravity();
    SetGravity({0.0f, -2.0f, 0.0f});

    return true;
}

void Roket::Update()
{
    Super::Update();
    //投げるとき
    if(isFlying_) {
        AddTranslate(direction_ * speed_);
    }
}

void Roket::Draw()
{
    Super::Draw();
    //描画する位置を取得
    auto pos = cast(GetTranslate());
    //円の色
    auto color = GetColor(205, 0, 0);

    DrawCone3D(VGet(pos.x, pos.y + 14.0f, pos.z), VGet(pos.x, pos.y, pos.z), 3, 1, color, color, TRUE);
}

void Roket::OnHit(const ComponentCollision::HitInfo& hit_info)
{
    Super::OnHit(hit_info);

    auto hitName = hit_info.hit_collision_->GetOwner()->GetName();
    if(hitName == "Ground") {
        isFlying_ = false;
    }
}

}    // namespace Game01
