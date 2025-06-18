#include "Player.h"
//#include "Bullet.h"
#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentObjectController.h>
#include <System/Component/ComponentCollisionModel.h>
#include <System/Component/ComponentCollisionCapsule.h>
namespace Game01 {
bool Player::Init()
{
    __super::Init();

    //プレイヤーオブジェクト
    //  auto player = Scene::Object::Create<Object>();
    SetName("Player");
    SetTranslate({0.0f, 5.0f, 0.0f});
    //float3 scale      = {2.0f, 2.0f, 2.0f};
    auto model_comp = AddComponent<ComponentModel>("data/Sample/Player/Model.mv1 ");
    //model_comp->SetScaleAxisXYZ(scale * 0.1);
    auto cap_comp = AddComponent<ComponentCollisionCapsule>();
    cap_comp->SetRadius(3.0f);
    cap_comp->SetHeight(13.0f);
    cap_comp->UseGravity();
    model_comp->SetAnimation({
        {"idle", "data/Sample/Player/Anim/Idle.mv1", 1, 1.0f},
        {"jump", "data/Sample/Player/Anim/Jump.mv1", 1, 1.0f},
        {"walk", "data/Sample/Player/Anim/Walk.mv1", 1, 1.0f},
        // { "walk2",  "data/Sample/Player/Anim/Walk2.mv1", 1, 1.0f},
        // {"dance1", "data/Sample/Player/Anim/Dance1.mv1", 0, 1.0f},
        // {"dance2", "data/Sample/Player/Anim/Dance2.mv1", 0, 1.0f},
        // {"dance3", "data/Sample/Player/Anim/Dance3.mv1", 0, 1.0f},
        // {"dance4", "data/Sample/Player/Anim/Dance4.mv1", 0, 1.0f},
        // {"dance5", "data/Sample/Player/Anim/Dance5.mv1", 0, 1.0f}
    });
    auto obj_control = AddComponent<ComponentObjectController>();
    obj_control->SetMoveSpeed(0.5f);
    obj_control->SetRotateSpeed(20.0f);
    //model_comp->PlayAnimation("walk",true);

    return true;
}
void Player::Update()
{
    Super::Update();
    if(Input::IsKeyDown(KEY_INPUT_SPACE)) {
        // auto   obj = Scene::Object::Create<Bullet>();
        // float3 pos = GetTranslate() + float3{0, 5.0f, 0};
        // obj->SetTranslate(pos);
        //
        // auto model = GetComponent<ComponentModel>();
        // auto dir   = -model->GetWorldMatrix().axisZ();
        //
        // obj->SetDirection(dir);
    }
}
}    // namespace Game01
