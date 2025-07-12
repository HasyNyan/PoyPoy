#include "Cpu.h"
namespace Game01 {

bool Cpu::Init()
{
    __super::Init();

    //Name
    SetName("Cpu");
    //pos
    SetTranslate({0.0f, 5.0f, 0.0f});

    //Model
    AddComponent<ComponentModel>("data/model/npc.mv1")->SetScaleAxisXYZ(10.0f)->UseShader(false);

    //Collision
    auto col = AddComponent<ComponentCollisionCapsule>();
    col->SetRadius(4.0f)->SetHeight(8.0f)->UseGravity();
    col->SetGravity({0.0f, -2.0f, 0.0f});

    return true;
}

//! @brief 更新
void Cpu::Update()
{
    // 毎フレーム動作する
    Super::Update();
    //投げるとき
    if(isFlying_) {
        AddTranslate(direction_ * speed_);
    }
}

void Cpu::Draw()
{
    Super::Draw();
}

void Cpu::OnHit(const ComponentCollision::HitInfo& hit_info)
{
    Super::OnHit(hit_info);

    auto hitName = hit_info.hit_collision_->GetOwner()->GetName();
    if(hitName == "Ground") {
    }
}

}    // namespace Game01
