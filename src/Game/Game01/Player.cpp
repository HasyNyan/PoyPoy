#include "Player.h"
namespace Game01 {

bool Player::Init()
{
    __super::Init();

    SetName("Player");
    SetTranslate({0.0f, 5.0f, 0.0f});

    //Collision
    AddComponent<ComponentCollisionCapsule>()->SetRadius(4.0f)->SetHeight(6.0f)->UseGravity();

    //!!
    AddComponent<ComponentModel>("data/model/player.mv1")
        ->SetScaleAxisXYZ(10.0f)
        ->SetTranslate({0.0f, 0.0f, 0.0f})
        ->SetRotationAxisXYZ({0.0f, 0.0f, 0.0f})
        ->UseShader(false);

    //move
    AddComponent<ComponentObjectController>()
        ->SetMoveSpeed(0.3f)
        ->SetRotateSpeed(20.0f)
        ->SetKeys(KEY_INPUT_UP, KEY_INPUT_DOWN, KEY_INPUT_LEFT, KEY_INPUT_RIGHT)
        ->SetCameraKeys(KEY_INPUT_W, KEY_INPUT_S, KEY_INPUT_A, KEY_INPUT_D);

    return true;
}

//! @brief 更新
void Player::Update()
{
    // 毎フレーム動作する
    Super::Update();

    //!!JUMP
    if(IsKeyOn(KEY_INPUT_SPACE) && !is_jump_) {
        is_jump_ = true;
    }

    if(is_jump_) {
        jump_power_ = 0.5f;

        AddTranslate({0, jump_power_, 0});
    }
}

void Player::Draw()
{
    Super::Draw();

    //プレイヤー
    //位置
    auto pos = cast(GetTranslate());
    //円の色
    auto color = GetColor(255, 255, 255);
    //方向
    auto rot = cast(GetRotationAxisXYZ());
    //描画
    //DrawSphere3D(pos, r_, 20, color, color, TRUE);

    //方向をわかる円
    auto model = GetComponent<ComponentModel>();
    if(!model)
        return;
    //方向
    auto dir = model->GetWorldMatrix().axisZ();

    //auto dir = -model->GetTranslate();

    //プレイヤーと離れる距離
    float offset = 1.0f;
    //位置
    float3 cPos = float3(pos.x + dir.x * offset, pos.y + dir.y * offset, pos.z + dir.z * offset);
    //色
    int cColor = GetColor(0, 255, 255);
    //描画
    DrawSphere3D(cast(cPos), 3.0f, 16, cColor, cColor, TRUE);
}

void Player::OnHit(const ComponentCollision::HitInfo& hit_info)
{
    Super::OnHit(hit_info);

    auto hitName = hit_info.hit_collision_->GetOwner()->GetName();
    if(hitName == "Ground") {
        is_jump_    = false;
        jump_power_ = 0.0f;
    }
}

}    // namespace Game01
