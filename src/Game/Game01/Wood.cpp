#include "Wood.h";
#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCollisionSphere.h>
#include <System/Component/ComponentCollisionCapsule.h>
namespace Game01 {
bool Wood::Init()
{
    __super::Init();

    SetName(u8"丸太");
    SetTranslate({0.0f, 10.0f, 0.0f});
    //Collision
    AddComponent<ComponentCollisionCapsule>()->SetRadius(3.0f)->SetHeight(30.0f)->SetRotationAxisXYZ(90.0f)->UseGravity();    // SetGravity()

    return true;
}

void Wood::Update()
{
    Super::Update();
    //投げるとき
    if(isFlying_) {
        AddTranslate(direction_ * speed_);
    }
}

void Wood::Draw()
{
    Super::Draw();
    //描画する位置を取得
    auto pos = cast(GetTranslate());
    //円の色
    auto color = GetColor(0, 0, 255);
    //描画
    DrawCone3D(pos, pos, 90.0f, 30, color, color, TRUE);
}

void Wood::OnHit(const ComponentCollision::HitInfo& hit_info)
{
    Super::OnHit(hit_info);

    auto hitName = hit_info.hit_collision_->GetOwner()->GetName();
    if(hitName == "Ground") {
        isFlying_ = false;
    }
}

}    // namespace Game01
