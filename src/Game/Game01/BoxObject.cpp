#include "BoxObject.h";
#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCollisionSphere.h>
namespace Game01 {
bool Box::Init()
{
    __super::Init();

    SetName(u8"ボックス");
    SetTranslate({0.0f, 10.0f, 10.0f});
    //Collision
    auto col = AddComponent<ComponentCollisionSphere>();
    col->SetRadius(3.0f)->UseGravity();
    SetGravity({0.0f, -2.0f, 0.0f});

    return true;
}

void Box::Update()
{
    Super::Update();
    //投げるとき
    if(isFlying_) {
        AddTranslate(direction_ * speed_);
    }
}

void Box::Draw()
{
    Super::Draw();
    //描画する位置を取得
    auto pos = cast(GetTranslate());
    //円の色
    auto color = GetColor(205, 133, 63);
    //ボックス描画
    for(int i = 0; i < 2; i++) {
        //前後
        DrawTriangle3D(VGet(pos.x + 3.5f, pos.y - 2.5f, pos.z - 2.5f + 5.0f * i),
                       VGet(pos.x - 3.5f, pos.y - 2.5f, pos.z - 2.5f + 5.0f * i),
                       VGet(pos.x - 3.5f, pos.y + 2.5f, pos.z - 2.5f + 5.0f * i),
                       color,
                       TRUE);

        DrawTriangle3D(VGet(pos.x + 3.5f, pos.y - 2.5f, pos.z - 2.5f + 5.0f * i),
                       VGet(pos.x + 3.5f, pos.y + 2.5f, pos.z - 2.5f + 5.0f * i),
                       VGet(pos.x - 3.5f, pos.y + 2.5f, pos.z - 2.5f + 5.0f * i),
                       color,
                       TRUE);
        //左右
        DrawTriangle3D(VGet(pos.x - 3.5f + 7.0f * i, pos.y - 2.5f, pos.z + 2.5f),
                       VGet(pos.x - 3.5f + 7.0f * i, pos.y - 2.5f, pos.z - 2.5f),
                       VGet(pos.x - 3.5f + 7.0f * i, pos.y + 2.5f, pos.z - 2.5f),
                       color,
                       TRUE);

        DrawTriangle3D(VGet(pos.x - 3.5f + 7.0f * i, pos.y - 2.5f, pos.z + 2.5f),
                       VGet(pos.x - 3.5f + 7.0f * i, pos.y + 2.5f, pos.z + 2.5f),
                       VGet(pos.x - 3.5f + 7.0f * i, pos.y + 2.5f, pos.z - 2.5f),
                       color,
                       TRUE);
        //上下
        DrawTriangle3D(VGet(pos.x - 3.5f, pos.y - 2.5f + 5.0f * i, pos.z + 2.5f),
                       VGet(pos.x - 3.5f, pos.y - 2.5f + 5.0f * i, pos.z - 2.5f),
                       VGet(pos.x + 3.5f, pos.y - 2.5f + 5.0f * i, pos.z - 2.5f),
                       color,
                       TRUE);

        DrawTriangle3D(VGet(pos.x + 3.5f, pos.y - 2.5f + 5.0f * i, pos.z - 2.5f),
                       VGet(pos.x + 3.5f, pos.y - 2.5f + 5.0f * i, pos.z + 2.5f),
                       VGet(pos.x - 3.5f, pos.y - 2.5f + 5.0f * i, pos.z + 2.5f),
                       color,
                       TRUE);
    }
}

void Box::OnHit(const ComponentCollision::HitInfo& hit_info)
{
    Super::OnHit(hit_info);

    auto hitName = hit_info.hit_collision_->GetOwner()->GetName();
    if(hitName == "Ground") {
        isFlying_ = false;
    }
}

}    // namespace Game01
