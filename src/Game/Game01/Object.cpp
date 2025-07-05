#include "Object.h";
#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCollisionSphere.h>
namespace Game01 {
bool Stone::Init()
{
    __super::Init();

    SetName(u8"ストーン");
    SetTranslate({0.0f, 10.0f, 0.0f});
    //Collision
    auto col = AddComponent<ComponentCollisionSphere>();
    col->SetRadius(3.0f)->UseGravity();
    col->SetGravity({0.0f, -2.0f, 0.0f});
    return true;
}

void Stone::Update()
{
    Super::Update();
    //投げるとき
    if(isFlying_) {
        AddTranslate(direction_ * speed_);
    }
}

void Stone::Draw()
{
    Super::Draw();
    //描画する位置を取得
    auto pos = cast(GetTranslate());
    //円の色
    auto color = GetColor(0, 255, 255);
    //描画
    DrawSphere3D(pos, 3.0f, 20, color, color, TRUE);
}

void Stone::OnHit(const ComponentCollision::HitInfo& hit_info)
{
    Super::OnHit(hit_info);

    auto hitName = hit_info.hit_collision_->GetOwner()->GetName();
    if(hitName == "Ground") {
        isFlying_ = false;
    }
}

}    // namespace Game01
